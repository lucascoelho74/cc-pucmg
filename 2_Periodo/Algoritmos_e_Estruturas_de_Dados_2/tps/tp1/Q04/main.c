#include <stdio.h>

#define MAX 1256

int ehFim(char texto[]) {
   return (texto[0] == 'F' && texto[1] == 'I' && texto[2] == 'M' && texto[3] == '\0');
} // end ehFim

int tamanho (char vet[]) {
    int tam= 0;
    while (vet[tam]!='\0'){
        tam ++;
    } // end while
    return tam;
} // end tamanho

char* inverte(char vet[], int tam) {
    int i;
    int j;
    char aux;

    i = 0;
    j = tam - 1;
    while (i < j) {
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
        i++;
        j--;
    } // end while

    return vet;
} // end inverte

int main() {
    char vet[MAX];
    int tam;

    while (scanf(" %1255[^\n]", vet) == 1 && ehFim(vet) == 0) {
        tam = tamanho(vet);
        printf("%s\n", inverte(vet, tam));
    } // end while

    return 0;
} // end main
