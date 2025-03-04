#include <stdio.h>
#include <stdlib.h>

typedef struct Cor {
    int red;
    int green;
    int blue;
} Cor;

typedef struct Coordenadas{
    int x;
    int y;
} Coord;

typedef struct Texto{
    char *text;
} Texto;

typedef struct No{
    No *next;
    No *prev;
    Texto *texto;
    Coord *coord;
    Cor *cor;
} No;

typedef struct Fila {
    No *begin;
    No *end;
    int size;
} Fila;
