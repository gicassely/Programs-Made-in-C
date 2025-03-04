#include <stdio.h>


typedef struct cor {
    int red;
    int green;
    int blue;
} Cor;

typedef struct coord {
    int x;
    int y;
} Coord;

typedef struct Node {
    void *data;
    struct Node *next;
} No;

typedef struct fila {
    No *begin;
    No *end;
    int limite;
    int tam;
    int tipo;
} Fila;

int insere(void *data, Fila *fila);

Fila *cria(int limite, int tipo);

int interface(Fila *fila);

int retira(Fila *f);

int ehVazia(Fila *f);

int ehCheia(Fila *f);

void imprime(Fila *f);
