#include <stdio.h>
#include <math.h>

int man ()
{   
    float a, b, c, delta, raiz1, raiz2;
    char opcao;
    printf("Digite o A, B e C da equa��o. (Ax� + Bx + C)\n");
    scanf("%f %f %f\n", &a, &b, &c);
    delta = (b * b) - (4 * a * c); 
    if (delta > 0) {
       raiz1 = ( (- b) + (sqrt(delta)) ) / (2 * a);
       raiz2 = ( (- b) - (sqrt(delta)) ) / (2 * a);
       printf("O resultado da equa��o %fx� + (%fx) + (%f) � igual a: %f e %f", a, b, c, raiz1, raiz2);
       printf("Digite T para sair ou qualquer outra letra para calcular mais raizes.");
       scanf("%c", opcao);
       while (opcao != 't');
       {
           printf("Digite o A, B e C da equa��o. (Ax� + Bx + C)\n");
           scanf("%f %f %f\n", &a, &b, &c);
           delta = (b * b) - (4 * a * c);
           if (delta > 0) {
              raiz1 = ( (- b) + (sqrt(delta)) ) / (2 * a);
              raiz2 = ( (- b) - (sqrt(delta)) ) / (2 * a);
              printf("O resultado da equa��o %fx� + (%fx) + (%f) � igual a: %f e %f", a, b, c, raiz1, raiz2);
              printf("Digite T para sair ou qualquer outra letra para calcular mais raizes.");
              scanf("%c", opcao);
           }
           else
              printf("O delta foi negativo. N�o existem ra�zes reais.");
       }
    }
    else
       printf("O delta foi negativo. N�o existem ra�zes reais.");
}  
