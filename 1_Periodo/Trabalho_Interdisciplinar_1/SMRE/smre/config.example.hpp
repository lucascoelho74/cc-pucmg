// MODELO DE CONFIGURACAO
// Copie este arquivo para "config.hpp" e preencha com os dados da sua
// rede. O config.hpp real e ignorado pelo git e NAO deve ser commitado.
//   cp config.example.hpp config.hpp

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

// =====================================================================
//  CONFIG PARA ESP32-S3 — VERSAO MINIMA
//
//  Esta versao roda com o custo mais baixo possivel: alem da placa, o
//  unico componente e UM potenciometro. LED RGB, buzzer, OLED, botao e
//  o segundo potenciometro foram removidos do projeto.
//
//  O diagnostico agora sai todo pelo Serial Monitor (115200), que ja
//  vem pela USB e nao custa nada.
//
//  Regras de pinagem do S3:
//   - Potenciometro (analogico) SO em ADC1 = GPIO1..GPIO10 (funciona
//     com Wi-Fi ligado). No S3, ADC2 nao funciona com Wi-Fi.
//   - Evitar: GPIO0/3/45/46 (strapping), GPIO19/20 (USB), GPIO26-32
//     e vizinhos (flash/PSRAM).
// =====================================================================

// ---------- Wi-Fi ----------
// ATENCAO: o ESP32-S3 so conecta em redes 2.4 GHz. Um SSID "_5G"
// nunca vai conectar — use a rede 2.4 do mesmo roteador.
#define WIFI_SSID "SUA_REDE_2.4GHZ"
#define WIFI_PASSWORD "SUA_SENHA_WIFI"

// ---------- Backend (o que conversa com o Drogon) ----------
// Este cliente fala HTTP cru (sem TLS e sem seguir redirect), entao:
//  - NAO usar a porta 3000 do host: e o painel do EasyPanel.
//  - NAO usar 80/443: o dominio redireciona para HTTPS.
//  - Caminho certo: porta publicada no servico do backend no EasyPanel
//    (Ports: host 3100 -> container 3000) + liberar 3100/tcp no firewall.
// O contrato e POST /data + GET /config — NAO trocar por /dados
// (isso e do outro backend, incompativel com este firmware).
#define SERVER_HOST "sixsevenapi.nerv3.xyz"
#define SERVER_PORT 3100
#define SERVER_PATH "/data"          // POST das leituras
#define SERVER_CONFIG_PATH "/config" // GET da configuracao (E_b, timer)

// ---------- Identidade desta conexao/hardware ----------
#define CONNECTION_ID 5

// ---------- Pinos (ESP32-S3) ----------
// Unico componente externo: o potenciometro da energia recebida (E_r),
// em ADC1. A energia base (E_b) nao e mais lida por hardware — ela vem
// exclusivamente do backend, via GET /config.
#define PIN_POT_RECEIVED 1   // ADC1_CH0 — energia recebida (E_r)

#define ADC_MAX 4095

// ---------- Tempos (ms) ----------
#define SEND_INTERVAL 1000
#define READ_INTERVAL 1000
#define RECONNECT_INTERVAL 5000
#define BOOT_WIFI_WAIT 3000
// 1500 era para backend na LAN; via internet (VPS) a primeira conexao
// TCP pode passar disso e virar timeout intermitente (-11).
#define HTTP_TIMEOUT 4000

// ---------- Filtro / logica ----------
#define WINDOW_SIZE 10
#define STABLE_THRESHOLD 150

#endif
