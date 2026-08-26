// 1649061_lucas_coelho_diniz
/*
  Para compilar em terminal (janela de comandos):
  Linux  : gcc -o main main.c
  Windows: gcc -o main main.c

  Para executar em terminal (janela de comandos):
  Linux  : ./main
  Windows: main
*/

// ----------------------------------------------------------------
// DEPENDENCIAS
// ----------------------------------------------------------------

#include "menu_exemplos.h"
#include "menu_exercicios.h"
#include "menu_extras.h"

int main()
{
  srand (time(NULL));
  int categoria = 0;
  
  do
  {
    IO_println ( "+----------------------------+" );
    IO_println ( "|       MENU PRINCIPAL       |" );
    IO_println ( "+----------------------------+" );
    IO_println ( "|   1 > Exemplos             |" );
    IO_println ( "|   2 > Exercicios           |" );
    IO_println ( "|   3 > Exercicios Extras    |" );
    IO_println ( "+----------------------------+" );
    IO_println ( "|   0 > Finalizar programa   |" );
    IO_println ( "+----------------------------+" );
    IO_println ( "" );
    categoria = IO_readint ( "Digite o numero da categoria: " );
    IO_println ( "" );
    
    switch (categoria)
    {
      case 0:                   break;
      case 1: menuExemplos();   break;
      case 2: menuExercicios(); break;
      case 3: menuExtras();     break;
      default: IO_println ( "Opcao invalida! Tente novamente." );
    }
  } while (categoria != 0);

  IO_pause ( "Pressione ENTER para finalizar o programa." );

  return 0;
}

