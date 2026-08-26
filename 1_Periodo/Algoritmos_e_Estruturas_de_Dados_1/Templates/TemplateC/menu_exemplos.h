#ifndef MENU_EXEMPLOS_H
#define MENU_EXEMPLOS_H

#include "exemplos.h"

void menuExemplos()
{
  int exemplo = 0;

  do
  {
    IO_println ( "+--------------------------+" );
    IO_println ( "|         EXEMPLOS         |" );
    IO_println ( "+--------------------------+" );
    IO_println ( "|      1 > Exemplo 1       |" );
    IO_println ( "|      2 > Exemplo 2       |" );
    IO_println ( "|      3 > Exemplo 3       |" );
    IO_println ( "|      4 > Exemplo 4       |" );
    IO_println ( "|      5 > Exemplo 5       |" );
    IO_println ( "|      6 > Exemplo 6       |" );
    IO_println ( "|      7 > Exemplo 7       |" );
    IO_println ( "|      8 > Exemplo 8       |" );
    IO_println ( "|      9 > Exemplo 9       |" );
    IO_println ( "|     10 > Exemplo 10      |" );
    IO_println ( "+--------------------------+" );
    IO_println ( "|        0 > Voltar        |" );
    IO_println ( "+--------------------------+" );
    IO_println ( "" );
    exemplo = IO_readint ( "Digite o numero do exemplo: " );
    IO_println ( "" );
    
    switch (exemplo)
    {
      case 0:                break;
      case 1:  method_01();  break;
      case 2:  method_02();  break;
      case 3:  method_03();  break;
      case 4:  method_04();  break;
      case 5:  method_05();  break;
      case 6:  method_06();  break;
      case 7:  method_07();  break;
      case 8:  method_08();  break;
      case 9:  method_09();  break;
      case 10: method_10();  break;
      default: IO_println ( "Opcao invalida!" );
    }
  } while (exemplo != 0);
}

#endif