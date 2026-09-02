#include <stdio.h>

#define MAX 1256

int ehFim(char texto[]) {
   return (texto[0] == 'F' && texto[1] == 'I' && texto[2] == 'M' && texto[3] == '\0');
} // end ehFim

int subString(char vet[]) {
    int resp = 0;
    int presente[256];
    int inicio = 0;
    int fim;
    int i;
    int tam;

    for (i = 0; i < 256; i++) {
        presente[i] = 0;
    } // end for

    for (fim = 0; vet[fim] != '\0'; fim++) {
        while (presente[(unsigned char) vet[fim]] == 1) {
                presente[(unsigned char) vet[inicio]] = 0;   // o que sai da janela deixa de estar presente
                inicio++;                          // a janela encolheu pela esquerda
        } // end while
        presente[(unsigned char) vet[fim]] = 1;
        tam = fim - inicio + 1; // O "+1" é porque a janela inclui as duas pontas: de inicio=0 a fim=2 são 3 caracteres, não 2
        if (tam > resp){
            resp = tam;
        } // end if
    } // end for

    return resp;
} // end subString

int main (){
    char vet[MAX];
    int acabou = 0;
    int i;

    while (acabou == 0 && fgets(vet, MAX, stdin) != NULL) {
        // anda ate o \n (ou \r, ou o fim da string) e corta ali
        i = 0;
        while (vet[i] != '\0' && vet[i] != '\n' && vet[i] != '\r') {
            i++;
        } // end while
        vet[i] = '\0';

        acabou = ehFim(vet);
        if (acabou == 0) {
            printf ("%d\n", subString(vet));
        } // end if
    } // end while

    return 0;
} // end main