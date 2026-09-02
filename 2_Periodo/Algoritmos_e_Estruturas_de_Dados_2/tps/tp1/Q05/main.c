#include <stdio.h>

#define MAX 256

int tamanho(char texto[]) {
   int i = 0;
   while (texto[i] != '\0') {
      i++;
   } // end while
   return i;
} // end tamanho

int leLinha(char texto[]) {
   int leu = (fgets(texto, MAX, stdin) != NULL);
   int tam;

   if (leu != 0) {
      tam = tamanho(texto);
      while (tam > 0 && (texto[tam - 1] == '\n' || texto[tam - 1] == '\r')) {
         tam--;
         texto[tam] = '\0';
      } // end while
   } // end if

   return leu;
} // end leLinha

int converter(char texto[]) {
   int resp = 0;
   int i = 0;
   int negativo = 0;
   int valido;

   if (texto[0] == '-') {
      negativo = 1;
      i = 1;
   } // end if

   valido = (texto[i] != '\0');

   while (texto[i] != '\0') {
      if (texto[i] >= '0' && texto[i] <= '9') {
         resp = resp * 10 + (texto[i] - '0');
      } else {
         valido = 0;
      } // end if
      i++;
   } // end while

   if (valido == 0) {
      resp = 0;
   } else if (negativo != 0) {
      resp = -resp;
   } // end if

   return resp;
} // end converter

int somarDigitos(int num) {
   int soma = 0;

   if (num < 0) {
      num = -num;
   } // end if

   while (num != 0) {
      soma = soma + (num % 10);
      num = num / 10;
   } // end while

   return soma;
} // end somarDigitos

int main() {
   char linha[MAX];

   while (leLinha(linha) != 0) {
      printf("%d\n", somarDigitos(converter(linha)));
   } // end while

   return 0;
} // end main