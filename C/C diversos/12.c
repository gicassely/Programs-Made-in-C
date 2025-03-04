#include <stdio.h>

int main ()

{
    int peso_homem = 80;  
    int peso_mulher = 45;
    int peso_ganho_h = 2;    
    int peso_ganho_m = 3;
    int ano = 0;

    while (peso_homem >= peso_mulher) 
    {
       peso_homem += peso_ganho_h;
       peso_mulher += peso_ganho_m;
       ano += 1;
    }
    
    printf("Afrânio = %d kg\n", peso_homem); 
    printf("Ermengarda = %d kg\n", peso_mulher);
    printf("Demorará %d anos\n", ano);
}
