// 1649061_lucas_coelho_diniz
/*
  Para compilar em terminal (janela de comandos):
  Linux  : g++ -o main main.cpp
  Windows: g++ -o main main.cpp

  Para executar em terminal (janela de comandos):
  Linux  : ./main
  Windows: main
*/

// ----------------------------------------------------------------
// DEPENDENCIAS
// ----------------------------------------------------------------

#include "menu_exemplos.hpp"
#include "menu_exercicios.hpp"
#include "menu_extras.hpp"

int main()
{
  int categoria = 0;
  
  do
  {
      std::cout << "+----------------------------+" << std::endl;
      std::cout << "|       MENU PRINCIPAL       |" << std::endl;
      std::cout << "+----------------------------+" << std::endl;
      std::cout << "|   1 > Exemplos             |" << std::endl;
      std::cout << "|   2 > Exercicios           |" << std::endl;
      std::cout << "|   3 > Exercicios Extras    |" << std::endl;
      std::cout << "+----------------------------+" << std::endl;
      std::cout << "|   0 > Finalizar programa   |" << std::endl;
      std::cout << "+----------------------------+" << std::endl;
      std::cout << std::endl;
      std::cout << "Digite o numero da categoria: ";
      std::cin  >> categoria;
      std::cin.get();
      std::cout << std::endl;

      switch (categoria)
      {
        case 0:                   break;
        case 1: menuExemplos();   break;
        case 2: menuExercicios(); break;
        case 3: menuExtras();     break;
        default: std::cout << "Opcao invalida! Tente novamente." << std::endl << std::endl;
      }
    } while (categoria != 0);

  std::cout << "Pressione ENTER para sair...";
  std::cin.get();

  return 0;
}