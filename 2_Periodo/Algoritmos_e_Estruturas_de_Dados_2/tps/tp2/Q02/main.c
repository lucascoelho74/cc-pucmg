#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// gcc main.c -o main
// ./main < Q02/pub.in > meu.out
// diff meu.out Q02/pub.out

#define MAX_VEICULOS 1000
#define MAX_COMBUSTIVEIS 5
#define TAM_STRING 100
#define TAM_LINHA 500
#define TAM_DATA 20
#define TAM_SAIDA 1000
#define NUM_CAMPOS 15

typedef struct {
	int ano;
	int mes;
	int dia;
} Data;

typedef struct {
	int id;
	char marca[TAM_STRING];
	char modelo[TAM_STRING];
	int ano;
	char categoria[TAM_STRING];
	char combustivel[MAX_COMBUSTIVEIS][TAM_STRING];
	int numCombustiveis; // em C o arranjo nao guarda o proprio tamanho
	int cilindros;
	double cilindrada;
	char transmissao[TAM_STRING];
	char tracao[TAM_STRING];
	double consumoCidade;
	double consumoEstrada;
	double co2;
	bool turbo;
	Data dataRegistro;
} Veiculo;

/**
 * Copia a string origem (ate o '\0') para destino.
 * Substitui o strcpy, que nao esta na lista de funcoes permitidas.
 */
void copiarString(char* destino, char* origem){
	int i = 0;
	while(origem[i] != '\0'){
		destino[i] = origem[i];
		i++;
	} // while
	destino[i] = '\0';
} // copiarString()

/**
 * Corta a string no primeiro '\r' ou '\n' encontrado.
 * Necessario porque o fgets guarda a quebra de linha e o csv usa \r\n.
 */
void removerQuebraLinha(char* s){
	int i = 0;
	while(s[i] != '\0' && s[i] != '\r' && s[i] != '\n'){
		i++;
	} // while
	s[i] = '\0';
} // removerQuebraLinha()

/**
 * Converte uma string no formato AAAA-MM-DD para um registro Data.
 */
Data parseData(char* s){
	Data d;
	d.ano = 0;
	d.mes = 0;
	d.dia = 0;
	sscanf(s, "%d-%d-%d", &d.ano, &d.mes, &d.dia);
	return d;
} // parseData()

/**
 * Escreve em buffer a data no formato DD/MM/AAAA.
 */
void formatData(Data d, char* buffer){
	sprintf(buffer, "%02d/%02d/%04d", d.dia, d.mes, d.ano);
} // formatData()

/**
 * Cria um Veiculo a partir de uma linha do csv (campos separados por ',').
 * A linha recebida e alterada pelo strtok.
 * Quem chama fica responsavel por liberar o ponteiro retornado.
 */
Veiculo* parseVeiculo(char* s){
	Veiculo* v = (Veiculo*) malloc(sizeof(Veiculo));
	char* campos[NUM_CAMPOS];
	int n = 0;

	// separa todos os campos antes de tratar o combustivel,
	// pois o strtok so consegue percorrer uma string de cada vez
	char* token = strtok(s, ",");
	while(token != NULL && n < NUM_CAMPOS){
		campos[n] = token;
		n++;
		token = strtok(NULL, ",");
	} // while

	v->id = atoi(campos[0]);
	copiarString(v->marca, campos[1]);
	copiarString(v->modelo, campos[2]);
	v->ano = atoi(campos[3]);
	copiarString(v->categoria, campos[4]);
	v->cilindros = atoi(campos[6]);
	v->cilindrada = atof(campos[7]);
	copiarString(v->transmissao, campos[8]);
	copiarString(v->tracao, campos[9]);
	v->consumoCidade = atof(campos[10]);
	v->consumoEstrada = atof(campos[11]);
	v->co2 = atof(campos[12]);
	v->turbo = (strcmp(campos[13], "true") == 0);
	v->dataRegistro = parseData(campos[14]);

	// combustivel pode ter mais de um valor separado por ';'
	v->numCombustiveis = 0;
	token = strtok(campos[5], ";");
	while(token != NULL && v->numCombustiveis < MAX_COMBUSTIVEIS){
		copiarString(v->combustivel[v->numCombustiveis], token);
		v->numCombustiveis++;
		token = strtok(NULL, ";");
	} // while

	return v;
} // parseVeiculo()

/**
 * Escreve em buffer o veiculo no formato
 * [id ## marca ## modelo ## ... ## turbo ## dataRegistro].
 */
void formatVeiculo(Veiculo v, char* buffer){
	char data[TAM_DATA];
	int pos = 0; // quantidade de caracteres ja escritos no buffer

	formatData(v.dataRegistro, data);

	pos += sprintf(buffer + pos, "[%d ## %s ## %s ## %d ## %s ## [", v.id, v.marca, v.modelo, v.ano, v.categoria);
	for(int i = 0; i < v.numCombustiveis; i++){
		if(i > 0){
			pos += sprintf(buffer + pos, ",");
		} // if
		pos += sprintf(buffer + pos, "%s", v.combustivel[i]);
	} // for
	pos += sprintf(buffer + pos, "] ## %d ## %.1f ## %s ## %s", v.cilindros, v.cilindrada, v.transmissao, v.tracao);
	pos += sprintf(buffer + pos, " ## %.2f ## %.2f ## %.1f", v.consumoCidade, v.consumoEstrada, v.co2);
	pos += sprintf(buffer + pos, " ## %s ## %s]", v.turbo ? "true" : "false", data);
} // formatVeiculo()

/**
 * Le todos os veiculos do csv, descartando o cabecalho.
 * Devolve o arranjo alocado e guarda em n a quantidade efetivamente lida.
 * Se o arquivo nao puder ser aberto, devolve o arranjo vazio (n = 0).
 */
Veiculo* lerCsv(char* caminhoArquivo, int* n){
	Veiculo* veiculos = (Veiculo*) malloc(MAX_VEICULOS * sizeof(Veiculo));
	char linha[TAM_LINHA];
	int cont = 0;

	FILE* arquivo = fopen(caminhoArquivo, "r");
	if(arquivo != NULL){
		fgets(linha, TAM_LINHA, arquivo); // descarta o cabecalho
		while(cont < MAX_VEICULOS && fgets(linha, TAM_LINHA, arquivo) != NULL){
			removerQuebraLinha(linha);
			if(linha[0] != '\0'){
				Veiculo* v = parseVeiculo(linha);
				veiculos[cont] = *v;
				free(v);
				cont++;
			} // if
		} // while
		fclose(arquivo);
	} // if

	*n = cont;
	return veiculos;
} // lerCsv()

/**
 * Pesquisa sequencial pelo id; devolve a posicao ou -1 se nao achar.
 */
int pesquisar(Veiculo* veiculos, int n, int id){
	int resp = -1;
	for(int i = 0; i < n && resp == -1; i++){
		if(veiculos[i].id == id){
			resp = i;
		} // if
	} // for
	return resp;
} // pesquisar()

/**
 * Le os ids da entrada padrao ate encontrar -1 e mostra
 * o veiculo correspondente a cada um deles.
 */
int main(){
	// Veiculo* veiculos = lerCsv("/tmp/veiculos.csv", &n); -> versao do Verde
	int n = 0;
	Veiculo* veiculos = lerCsv("veiculos.csv", &n);

	char linha[TAM_STRING];
	char saida[TAM_SAIDA];

	int lidos = scanf("%99s", linha);
	while(lidos == 1 && strcmp(linha, "-1") != 0){
		int id = atoi(linha);
		int pos = pesquisar(veiculos, n, id);
		if(pos != -1){
			formatVeiculo(veiculos[pos], saida);
			printf("%s\n", saida);
		} // if
		lidos = scanf("%99s", linha);
	} // while

	free(veiculos);
	return 0;
} // main()
