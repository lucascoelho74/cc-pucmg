#ifndef MENU_EXTRAS_HPP
#define MENU_EXTRAS_HPP

#include "extras.hpp"

void menuExtras()
{
  int extra = 0;

  do
  {
    std::cout << "+--------------------------+" << std::endl;
    std::cout << "|          EXTRAS          |" << std::endl;
    std::cout << "+--------------------------+" << std::endl;
    std::cout << "|       1 > Extra 1        |" << std::endl;
    std::cout << "|       2 > Extra 2        |" << std::endl;
    std::cout << "+--------------------------+" << std::endl;
    std::cout << "|        0 > Voltar        |" << std::endl;
    std::cout << "+--------------------------+" << std::endl;
    std::cout << std::endl;
    std::cout << "Digite o numero do extra: ";
    std::cin  >> extra;
    std::cin.get();

    switch (extra)
    {
      case 0:         break;
      case 1: e1();   break;
      case 2: e2();   break;
      default: std::cout << "Opcao invalida!" << std::endl << std::endl;
    }
  } while (extra != 0);
}

#endif