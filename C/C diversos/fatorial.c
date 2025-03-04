#include <stdio.h>

int main ()
{   
    int a, b, fat, aux;
    printf("Digite o numero para obter o seu fatorial\n");
    scanf("%d", &a);
    fat = 1;
    aux = a;
    while (b < aux);
    {
      if (a != 0)
      { 
         fat = fat * a; 
         a -= 1;  
         b += 1;
      }
    }
  
    printf("O resultado de %d! é: %d\n", aux, fat);
}
