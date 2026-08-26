#ifndef MENU_EXERCICIOS_H
#define MENU_EXERCICIOS_H

#include "exercicios.h"

void menuExercicios()
{
  int exercicio = 0;

  do
  {
    IO_println ( "+--------------------------+" );
    IO_println ( "|        EXERCICIOS        |" );
    IO_println ( "+--------------------------+" );
    IO_println ( "|     1 > Exercicio 1      |" );
    IO_println ( "|     2 > Exercicio 2      |" );
    IO_println ( "|     3 > Exercicio 3      |" );
    IO_println ( "|     4 > Exercicio 4      |" );
    IO_println ( "|     5 > Exercicio 5      |" );
    IO_println ( "|     6 > Exercicio 6      |" );
    IO_println ( "|     7 > Exercicio 7      |" );
    IO_println ( "|     8 > Exercicio 8      |" );
    IO_println ( "|     9 > Exercicio 9      |" );
    IO_println ( "|    10 > Exercicio 10     |" );
    IO_println ( "+--------------------------+" );
    IO_println ( "|        0 > Voltar        |" );
    IO_println ( "+--------------------------+" );
    IO_println ( "" );
    exercicio = IO_readint ( "Digite o numero do exercicio: " );
    IO_println ( "" );

    switch (exercicio)
    {
      case 0:         break;
      case 1:  p1();  break;
      case 2:  p2();  break;
      case 3:  p3();  break;
      case 4:  p4();  break;
      case 5:  p5();  break;
      case 6:  p6();  break;
      case 7:  p7();  break;
      case 8:  p8();  break;
      case 9:  p9();  break;
      case 10: p10(); break;
      default: IO_println ( "Opcao invalida!" );
    }
  } while (exercicio != 0);
}

#endif