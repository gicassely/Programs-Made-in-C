#include <stdio.h>

int main ()
{
  float vet[30];
  int k = 1;
  int i = 0;
  int j = 0;
  float val = 0;
  while (k <= 30)
  {
     scanf("%f", &vet[i]);
     i++;
     k++;
  }
  while (j < 30)
  {
     val += vet[j];
     j++;
  }
  printf("%f\n", val);
}    
