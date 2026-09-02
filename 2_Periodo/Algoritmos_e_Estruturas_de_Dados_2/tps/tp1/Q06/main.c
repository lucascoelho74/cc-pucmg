#include <stdio.h>
#include <stdbool.h>

bool ehFim(char texto[]) {
   return (texto[0] == 'F' && texto[1] == 'I' && texto[2] == 'M' && texto[3] == '\0');
} // end ehFim

int tamanho(char vet[]){
    int i = 0;
    while (vet[i] != '\0'){
        i++;
    } // end while
    return i;
} // end tamanho

char minuscula(char c){
    char resp = c;
    if (c >= 'A' && c <= 'Z'){
        resp = c + 32;
    } // end if
    return resp;
} // end minuscula

bool ehAnagrama(char vet1[], char vet2[]){
    int contagem[256];
    int i;
    bool resp = 1;
    int size1 = 0, size2 = 0;
    size1 = tamanho (vet1);
    size2 = tamanho (vet2);
    if (size1 != size2){
        resp = 0;
    }else {
        for (i = 0; i < 256; i++) {
            contagem[i] = 0;
        }
        for (i = 0; i < size1; i++) {
            contagem[ (int) minuscula(vet1[i]) ]++;
        } // end for
        for (i = 0; i < size2; i++) {
            contagem[ (int) minuscula(vet2[i]) ]--;
        } // end for
        for (i = 0; i < 256; i++) {
            if (contagem[i] != 0) {
                resp = 0;
            } // end if
        } // end for
    }
    return resp;
} // end ehAnagrama

int main(){
    char vet1[256];
    char vet2[256];

    scanf ("%s %s",vet1, vet2);
    while (!ehFim(vet1)) {
        if (ehAnagrama(vet1, vet2)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        scanf ("%s %s",vet1, vet2);
    } // end while

    return 0;
} // end main