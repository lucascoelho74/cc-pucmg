#include <stdio.h>

int ehFim(char texto[]) {
    return (texto[0] == 'F' && texto[1] == 'I' && texto[2] == 'M' && texto[3] == '\0');
} // end ehFim

int somenteVogais(char texto[], int i) {
    int resp;
    if (texto[i] == '\0') {
        if (i == 0) {
            resp = 0; // string vazia nao conta
        } else {
            resp = 1;
        } // end if
    } else if (texto[i] != 'a' && texto[i] != 'e' && texto[i] != 'i' &&
               texto[i] != 'o' && texto[i] != 'u') {
        resp = 0;
    } else {
        resp = somenteVogais(texto, i + 1);
    } // end if
    return resp;
} // end somenteVogais

int somenteConsoantes(char texto[], int i) {
    int resp;
    if (texto[i] == '\0') {
        if (i == 0) {
            resp = 0; // string vazia nao conta
        } else {
            resp = 1;
        } // end if
    } else if (!(texto[i] >= 'a' && texto[i] <= 'z')) {
        resp = 0; // nao e letra minuscula
    } else if (texto[i] == 'a' || texto[i] == 'e' || texto[i] == 'i' ||
               texto[i] == 'o' || texto[i] == 'u') {
        resp = 0; // e letra, mas e vogal
    } else {
        resp = somenteConsoantes(texto, i + 1);
    } // end if
    return resp;
} // end somenteConsoantes

int ehInteiro(char texto[], int i) {
    int resp;
    if (texto[i] == '\0') {
        if (i == 0) {
            resp = 0; // string vazia nao conta
        } else {
            resp = 1;
        } // end if
    } else if (i == 0 && (texto[0] == '-' || texto[0] == '+') && texto[1] != '\0') {
        resp = ehInteiro(texto, i + 1); // sinal so vale na primeira posicao
    } else if (!(texto[i] >= '0' && texto[i] <= '9')) {
        resp = 0;
    } else {
        resp = ehInteiro(texto, i + 1);
    } // end if
    return resp;
} // end ehInteiro

int ehReal(char texto[], int i) {
    int resp;
    if (texto[i] == '\0') {
        if (i == 0) {
            resp = 0; // string vazia nao conta
        } else {
            resp = 1;
        } // end if
    } else if (i == 0 && (texto[0] == '-' || texto[0] == '+') && texto[1] != '\0') {
        resp = ehReal(texto, i + 1); // sinal so vale na primeira posicao
    } else if (texto[i] >= '0' && texto[i] <= '9') {
        resp = ehReal(texto, i + 1);
    } else if ((texto[i] == '.' || texto[i] == ',') && texto[i + 1] != '\0') {
        resp = ehInteiro(texto, i + 1); // depois do separador, so digitos
    } else {
        resp = 0;
    } // end if
    return resp;
} // end ehReal

int main() {
    char texto[1000];
    int lidos;

    lidos = scanf(" %999[^\n]", texto);
    while (lidos != EOF && !ehFim(texto)) {
        if (somenteVogais(texto, 0)) {
            printf("SIM ");
        } else {
            printf("NAO ");
        } // end if

        if (somenteConsoantes(texto, 0)) {
            printf("SIM ");
        } else {
            printf("NAO ");
        } // end if

        if (ehInteiro(texto, 0)) {
            printf("SIM ");
        } else {
            printf("NAO ");
        } // end if

        if (ehReal(texto, 0)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        } // end if

        lidos = scanf(" %999[^\n]", texto);
    } // end while
    return 0;
} // end main