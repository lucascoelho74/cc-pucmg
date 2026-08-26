# SMRE — Sistema de Mitigação de Ruído Elétrico com ESP32-S3

Sistema completo de monitoramento de energia: um **hardware (ESP32-S3)** lê,
filtra e envia medições para um **backend em C++ (Drogon + MySQL)** hospedado
em VPS, e um **site (Next.js)** mostra os dados em dashboards com gráficos e
permite configurar o hardware remotamente.

```
┌──────────────┐  POST /data (leituras)   ┌──────────────┐        ┌─────────┐
│    ESP32-S3  │ ───────────────────────► │   Backend    │ ◄────► │  MySQL  │
│  (hardware)  │ ◄─────────────────────── │  C++/Drogon  │        └─────────┘
└──────────────┘  GET /config (E_b,timer) └──────▲───────┘
                                                 │ rewrites (rede interna)
                                          ┌──────┴───────┐
                                          │     Site     │ ◄── usuário (browser)
                                          │   Next.js    │
                                          └──────────────┘
```

O backend é sempre o intermediário: o site nunca fala com o hardware e o
hardware nunca é acessado de fora — ele **envia** leituras e **puxa** a própria
configuração, no intervalo definido pelo usuário no site.

## 📄 Documentação e apresentação

- **[Relatório do projeto](relatorio.pdf)**
- **[PIT — vídeo de apresentação](https://drive.google.com/file/d/137V0aXunH3p66cYB-xy81Lja_CCOf6IH/view?usp=sharing)**

## 🔌 O hardware (foco do projeto)

Firmware em C++/Arduino para **ESP32-S3 (N16R8)**, na pasta
[`SixSeven_Projects/`](SixSeven_Projects/).

### O que ele faz

> **Versão mínima:** o projeto foi reduzido ao menor custo possível. Além da
> placa, o único componente é **um potenciômetro**. LED RGB, buzzer, OLED,
> botão e o segundo potenciômetro foram removidos — todo o feedback sai pelo
> Serial Monitor, que já vem pela USB e não custa nada.

1. **Mede energia** por um potenciômetro: `E_r` (energia recebida, a leitura
   em si). Leituras a cada 1 s no ADC1 — único ADC do S3 que funciona com
   Wi-Fi ligado. A energia base `E_b` não é mais lida por hardware: vem
   exclusivamente do backend, via `GET /config`.
2. **Filtra e deriva métricas** localmente, com média móvel de janela 10:
   `M_er` (média da recebida), `V_mer` (distância entre leitura e média) e
   `M_vmer` (média das variações). O sinal é considerado **estável** quando
   `V_mer ≤ 150`.
3. **Conversa com o backend** por HTTP:
   - `POST /data` — envia a leitura completa a cada `timer` ms;
   - `GET /config?id=N` — busca `E_b` e `timer` configurados no site, ou
     seja, **o dashboard manipula o hardware sem abrir conexão com ele**.
4. **Se recupera sozinho**: reconexão de Wi-Fi em background e logs de
   diagnóstico no Serial Monitor (115200) para cada etapa — boot, Wi-Fi,
   IP, e código HTTP de cada envio.

### Pinagem (ESP32-S3)

| Componente | GPIO | Nota |
|---|---|---|
| Potenciômetro E_r | 1 | ADC1_CH0 — único componente externo |

Sem botão, o hardware opera sempre que estiver alimentado.

### Como compilar o firmware

1. Arduino IDE com o core **esp32 by Espressif Systems 3.x** (Boards Manager).
2. Bibliotecas: **nenhuma** — o firmware usa só `WiFi.h` e `HTTPClient.h`,
   que já vêm no core do ESP32.
3. Placa **ESP32S3 Dev Module** com: `USB CDC On Boot: Enabled`,
   `Flash Size: 16MB`, `PSRAM: OPI PSRAM`.
4. Ajuste `SixSeven_Projects/config.hpp` (Wi-Fi 2.4 GHz, servidor e
   `CONNECTION_ID` — o id da conexão criada no site) e grave.

## 🗂️ Estrutura do repositório

| Pasta | Conteúdo |
|---|---|
| [`SixSeven_Projects/`](SixSeven_Projects/) | Firmware do ESP32-S3 |
| [`backend/`](backend/) | API C++ (Drogon) + MySQL — [README próprio](backend/README.md) com rotas e arquitetura |
| [`app/`](app/) | Front Next.js (dashboard, login, conexões e dispositivos) |
| [`DEPLOY.md`](DEPLOY.md) | Guia de deploy na VPS com Docker/EasyPanel |

Para rodar tudo localmente com Docker:

```bash
cp .env.example .env   # ajuste as senhas
docker compose up --build
# front: http://localhost:3001 · backend: http://localhost:3000/health
```

## 👥 Integrantes

- Arthur Victor Alves
- Lucas Coelho
- Francisco Viotti
- Matheus Assis
- Vinícius Raposo
