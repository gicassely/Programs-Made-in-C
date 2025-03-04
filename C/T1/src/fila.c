#include<stdio.h>
#include<stdlib.h>
#include "fila.h"


// Cria uma fila vazia.
// O parâmetro tipo pode assumir apenas um dos valores: 1(texto); 2(cor); 3(ponto);
// Retorna NULL se houve erro na criação da fila
Fila *cria(int limite, int tipo) {
    Fila *fila = (Fila*) malloc(limite*(sizeof(Fila)));
    fila->end = NULL;
    fila->limite = limite;
    fila->tam = 0;
    fila->tipo = tipo;
    return fila;
}

// Manipula os dados e os manda para a função de inserção enquanto não
// der erro.
int interface(Fila *fila) {
    char txt[2];
    if (fila->tipo == 1) {
        printf("Texto %d:\n", fila->tam+1);
        while (getchar()!='\n');
        fgets(txt, 2, stdin);
        //scanf("%c", txt);
        while (insere(txt, fila)==1) {
            printf("Texto %d:\n", fila->tam+1);
            while (getchar()!='\n');
            fgets(txt, 2, stdin);
            //scanf("%c", txt);
        }
        return 1;
    } else if (fila->tipo == 2) {
        Cor *cor = (Cor*) malloc(sizeof(Cor));
        printf("Vermelho: ");
        scanf("%d", &(cor->red));
        printf("Verde: ");
        scanf("%d", &(cor->green));
        printf("Azul: ");
        scanf("%d", &(cor->blue));
        insere(cor, fila);
        return 1;
    }
    else {
        Coord *coord = malloc(sizeof(Coord));
        printf("Coordenada x: ");
        scanf("%d", &(coord->x));
        printf("Coordenada y: ");
        scanf("%d", &(coord->y));
        insere(coord, fila);
        return 1;
    }
}

// Insere o elemento no fim da fila
// Retorna 0 se houve erro na inserção e 1 caso contrário;
int insere(void *data, Fila *fila) {
    if (fila->tam < (fila->limite)) {
        No *new = (No*) malloc(sizeof(No));
        if (fila->tam == 0) {
            new->data = (char*) data;
            new->next = NULL;
            fila->begin = fila->end = new;
            fila->tam++;
            return 1;
        } else {
            new->data = data;
            new->next = NULL;
            fila->end->next = new;
            fila->end = new;
            fila->tam++;
            return 1;
        }
    } else {
        printf("Limite excedido\n");
        return 0;
    }
}

// Remove o primeiro elemento da fila
// Retorna 0 se houve erro na remoção, e 1 caso contrário;
int retira(Fila *fila) {
    if (ehVazia(fila) == 1)
        return 0;
    No *tmp = fila->begin;
    fila->begin = fila->begin->next;
    free(tmp);
    fila->tam--;
    return 1;
}

// Retorna 1 se a fila está vazia, 0 caso contrário;
int ehVazia(Fila *fila) {
    if (fila->tam == 0)
        return 1;
    return 0;
}

// Retorna 1 se a fila está cheia, 0 caso contrário.
int ehCheia(Fila *fila) {
    if (fila->tam == fila->limite)
        return 1;
    return 0;
}

void imprime(Fila *fila) {
    int i = 1;
    No *tmp = malloc(sizeof(No));
    tmp = fila->begin;
    printf("\n FILA\n");
    while (i<=fila->tam) {
        //void *data;
        if (fila->tipo==1){
            char *data = (char*)tmp->data;
            printf("Texto %d: %c\n", i, *data);
        }
        if (fila->tipo==2) {
            Cor *data = (Cor*)tmp->data;
            int r, b, g;
            r = data->red;
            b = data->blue;
            g = data->green;
            printf("\nCor %d:\n R: %d, B: %d, G: %d\n", i, r, b, g);
        }
        if (fila->tipo==3) {
            Coord *data = (Coord*)tmp->data;
            int x, y;
            x = data->x;
            y = data->y;
            printf("\nCoordenada %d:\n x: %d, y: %d\n", i, x, y);
        }
        tmp = tmp->next;
        i++;
    }
}
