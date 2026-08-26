#ifndef MENU_EXEMPLOS_HPP
#define MENU_EXEMPLOS_HPP

#include "exemplos.hpp"

void menuExemplos()
{
  int exemplo = 0;

  do
  {
    std::cout << "+--------------------------+" << std::endl;
    std::cout << "|         EXEMPLOS         |" << std::endl;
    std::cout << "+--------------------------+" << std::endl;
    std::cout << "|      1 > Exemplo 1       |" << std::endl;
    std::cout << "|      2 > Exemplo 2       |" << std::endl;
    std::cout << "|      3 > Exemplo 3       |" << std::endl;
    std::cout << "|      4 > Exemplo 4       |" << std::endl;
    std::cout << "|      5 > Exemplo 5       |" << std::endl;
    std::cout << "|      6 > Exemplo 6       |" << std::endl;
    std::cout << "|      7 > Exemplo 7       |" << std::endl;
    std::cout << "|      8 > Exemplo 8       |" << std::endl;
    std::cout << "|      9 > Exemplo 9       |" << std::endl;
    std::cout << "|     10 > Exemplo 10      |" << std::endl;
    std::cout << "+--------------------------+" << std::endl;
    std::cout << "|        0 > Voltar        |" << std::endl;
    std::cout << "+--------------------------+" << std::endl;
    std::cout << std::endl;
    std::cout << "Digite o numero do exemplo: ";
    std::cin  >> exemplo;
    std::cin.get();

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
      default: std::cout << "Opcao invalida!" << std::endl << std::endl;
    }
  } while (exemplo != 0);
}

#endif