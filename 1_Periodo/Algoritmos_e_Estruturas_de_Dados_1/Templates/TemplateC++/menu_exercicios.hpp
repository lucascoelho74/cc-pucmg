#ifndef MENU_EXERCICIOS_HPP
#define MENU_EXERCICIOS_HPP

#include "exercicios.hpp"

void menuExercicios()
{
  int exercicio = 0;

  do
  {
    std::cout << "+--------------------------+" << std::endl;
    std::cout << "|        EXERCICIOS        |" << std::endl;
    std::cout << "+--------------------------+" << std::endl;
    std::cout << "|     1 > Exercicio 1      |" << std::endl;
    std::cout << "|     2 > Exercicio 2      |" << std::endl;
    std::cout << "|     3 > Exercicio 3      |" << std::endl;
    std::cout << "|     4 > Exercicio 4      |" << std::endl;
    std::cout << "|     5 > Exercicio 5      |" << std::endl;
    std::cout << "|     6 > Exercicio 6      |" << std::endl;
    std::cout << "|     7 > Exercicio 7      |" << std::endl;
    std::cout << "|     8 > Exercicio 8      |" << std::endl;
    std::cout << "|     9 > Exercicio 9      |" << std::endl;
    std::cout << "|    10 > Exercicio 10     |" << std::endl;
    std::cout << "+--------------------------+" << std::endl;
    std::cout << "|        0 > Voltar        |" << std::endl;
    std::cout << "+--------------------------+" << std::endl;
    std::cout << std::endl;
    std::cout << "Digite o numero do exercicio: ";
    std::cin  >> exercicio;
    std::cin.get();
  
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
      default: std::cout << "Opcao invalida!" << std::endl << std::endl;
    }
  } while (exercicio != 0);
}

#endif