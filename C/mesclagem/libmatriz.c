#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "libmatriz.h"

int criar_m (char **matriz, int linhas, int colunas)  {

	int i;

	printf("Digite o numero de linhas e colunas (respectivamente):");
	scanf("%d, %d", &linhas, &colunas);
	
	matriz= calloc (linhas, sizeof(char *));
	for (i=0;i<linhas;i++)
		matriz[i]= calloc (colunas, sizeof(char));

};
int redimensionar_m (char **matriz, int linhas, int colunas) {

	int i;

	printf("Quantas linhas e colunas a matriz terá?");
	scanf("%d %d", &linhas, &colunas);

	matriz=realloc(matriz, (linhas)*sizeof(char*));
	for (i=0; i<linhas; i++)
		matriz[i]=realloc(matriz[i], (colunas)*sizeof(char));

};












	

