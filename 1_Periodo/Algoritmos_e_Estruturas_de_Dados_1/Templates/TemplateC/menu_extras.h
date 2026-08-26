#ifndef MENU_EXTRAS_H
#define MENU_EXTRAS_H

#include "extras.h"

void menuExtras()
{
  int extra = 0;

  do
  {
    IO_println ( "+--------------------------+" );
    IO_println ( "|          EXTRAS          |" );
    IO_println ( "+--------------------------+" );
    IO_println ( "|       1 > Extra 1        |" );
    IO_println ( "|       2 > Extra 2        |" );
    IO_println ( "+--------------------------+" );
    IO_println ( "|        0 > Voltar        |" );
    IO_println ( "+--------------------------+" );
    IO_println ( "" );
    extra = IO_readint ( "Digite o numero do extra: " );
    IO_println ( "" );

    switch (extra)
    {
      case 0:         break;
      case 1: e1();   break;
      case 2: e2();   break;
      default: IO_println ( "Opcao invalida!" );
    }
  } while (extra != 0);
}

#endif