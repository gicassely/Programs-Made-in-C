#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "libmatriz.h"

int main ()
{
  int m=0;
  char **matriz;
  int linhas,colunas;
  int i;
  
  cria_m(matriz, linhas, colunas);
  while (m != 2)
    {      
      printf("o que deseja fazer?\n");
      printf("1- Redimensionar matriz\n");
      printf("2- Sair do programa\n");
      scanf("%d",&m);
      
      if (m == 1)
	{
	  redimensiona_m(matriz,linhas,colunas);
	  for (i=0;i<linhas;i++)
	    gets(matriz[i]);
	  for (i=0;i<linhas;i++)
	    puts(matriz[i]);
	}
    }
}
