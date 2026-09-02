#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

int tamanho(char texto[]) {
   int i = 0;
   while (texto[i] != '\0') {
      i++;
   } // end while
   return i;
} // end tamanho

bool ehFim(char texto[]) {
   return (texto[0] == 'F' && texto[1] == 'I' && texto[2] == 'M' && texto[3] == '\0');
} // end ehFim

char* cifra(char origem[], char destino[], int i) {
   if (origem[i] == '\0') {
      destino[i] = '\0';
   } else {
      destino[i] = origem[i] + 3;
      cifra(origem, destino, i + 1);
   } // end if
   return destino;
} // end cifra

int main() {
  char linha[MAX];
  char cifrada[MAX];
  bool fim = false;

  while (fim == false && fgets(linha, MAX, stdin) != NULL) {
    int tam = tamanho(linha);
    if (tam > 0 && linha[tam - 1] == '\n') {
        linha[tam - 1] = '\0';
    } // end if

    if (ehFim(linha) == true) {
        fim = true;
    } else {
        printf("%s\n", cifra(linha, cifrada, 0));
    } // end if
  } // end while

   return 0;
} // end main