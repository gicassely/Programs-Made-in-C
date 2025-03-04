/*Suponha uma pilha P com elementos do tipo float que � implementada como um vetor unidimensional.
Defina um m�dulo de biblioteca com uma estrutura de dados adequada, fun��es para inserir e extrair um elemento de
Q, e uma func�o que testa se a pilha est� vazia ou n�o. As fun��es devem conter mecanismos pr�prios para um reuso
econ�mico de mem�ria.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "operacoes.h"


int main ()
{
  float *P; // Pilha P
  int o; //menu
  int i; //contador
  int k = 0; //tamanho da pilha
  
  P = calloc (1,sizeof(float));
  while(o != 4)
    {
      printf("o que deseja fazer?\n");
      printf("1- Inserir elemento na pilha\n");
      printf("2- Remover elemento da pilha\n");
      printf("3- Imprimir pilha\n");
      printf("4- Sair do programa\n");
      scanf("%d",&o);
      if (o == 1)
	{
	  inserepilha(P,k);
	  k++;
	}
      if (o == 2)
	if (vaziapilha(k) == 0)
	  {
	    removepilha(P,k);
	    k--;
	  }
	else
	  printf("pilha vazia!!!\n");
      if (o == 3)
	for(i=k-1;i>=0;i--)
	  printf("%f\n",P[i]);
    }
}
