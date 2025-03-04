#include<stdio.h>
#include "fila.h"


int main() {
    Fila *fila;
    int limite, tipo, continua = 1;
    char txt;
    printf("Digite o limite de elementos da sua fila: \n");
    scanf("%d", &limite);
    printf("Agora, digite o número correspondente ao tipo da fila: \n");
    scanf("%d", &tipo);
    fila = cria(limite, tipo);
    if ((fila->tipo > 3) || (fila->tipo < 1))
        printf("O número %d não corresponde a nenhum tipo de fila.\n", fila->tipo);
    while ((continua==1) && (ehCheia(fila)==0)) {
        interface(fila);
        printf("Para finalizar o programa, digite 0. Para continuar, digite 1.\n");
        scanf("%d", &continua);
    }
    if (ehVazia(fila) == 1)
        printf("Lista vazia.\n");
    if (ehCheia(fila) == 1)
        printf("Lista cheia.\n");
    imprime(fila);
    if (retira(fila) == 1)
        printf("Primeiro item da fila removido com sucesso.\n");
    imprime(fila);
}
