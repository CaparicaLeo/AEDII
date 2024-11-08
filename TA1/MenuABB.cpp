#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

#include "ABB.h"

int main()
{
   no *T, *p;
   int x, c;

   T = ini_AB(T);

   do
   {
      system("cls");
      printf("\n");
      printf("1 - Insere Item na ARVORE DE BUSCA BINARIA\n");
      printf("2 - EM ORDEM -  Lista Itens da ARVORE DE BUSCA BINARIA - Em-Ordem\n");
      printf("3 - PRE-ORDEM - Lista Itens da ARVORE DE BUSCA BINARIA - Pre-Ordem\n");
      printf("4 - POS-ORDEM - Lista Itens da ARVORE DE BUSCA BINARIA - Pos-Ordem\n");
      printf("5 - PERCURSO EM LARGURA - TA1\n");
      printf("6 - BUSCA Item na ARVORE DE BUSCA BINARIA\n");
      printf("7 - Sair\n");
      printf("\n Escolha: ");

      cin >> c;

      switch (c)
      {
      case 1:
         cout << " \nEntre com o item a ser inserido: ";
         cin >> x;
         T = insere_AB(T, x);
         break;
      case 2:
         emOrdem_AB(T);
         printf("\n");
         espera();
         break;
      case 3:
         preOrdem_AB(T);
         printf("\n");
         espera();
         break;
      case 4:
         posOrdem_AB(T);
         printf("\n");
         espera();
         break;
      case 5:
         percursoEmLargura(T);
         espera();
         break;
      case 6:
         cout << " \nEntre com o item a ser procurado: ";
         cin >> x;
         buscaAB(T, x);
         espera();
         break;
      case 7:
         exit(0);
         break;
      };
   } while (c != 7);
}

void espera()
{
   cout << "Aperte qualquer botão pra sair" << endl;
   getch();
}
