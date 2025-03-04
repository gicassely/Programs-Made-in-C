#include <stdio.h>

#define TAM 10

void ler_matr(int matr[][TAM])
{
    int i, j;
    for (i = 0; i <= 10; i++)
       for (j = 0; j <= 10; j++)
       {
          scanf("%d", &matr[i][j]);
        }
}



int main ()
{
    int m[TAM] [TAM];
    int m2[TAM] [TAM];
    ler_matr(m);
    ler_matr(m2);
    
}
