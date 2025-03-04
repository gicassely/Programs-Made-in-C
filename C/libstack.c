#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "libstack.h"

int inserepilha (float *P, int n_notas)
{
  float n; //numero a ser inserido na pilha
  int t = 0;
  
  while (t==0)
    {
      printf("digite a nota que deseja inserir (entre 0 e 10):  ");
      scanf("%f",&n);
      if ((n>=0)&&(n<=10))
	{
	  P[n_notas] = n;
	  t=1;
	}
    }
      
  P = realloc (P,(n_notas+1)*sizeof(float));
};

int vaziapilha (int k)
{
  if (k == 0)
    return 1;
  else
    return 0;
};

int removepilha(float *P, int k)
{
  if (k == 1)
    P = calloc (1, sizeof(float));
  else
    P = realloc (P,(k-1)*sizeof(float));
};
