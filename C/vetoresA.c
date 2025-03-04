#include <stdio.h>


int main ()
{

	int i, n, soma, media, maior;
	int vet[100];

	soma = 0;

	puts("Entre com um valor inteiro N!");
	scanf("%d", &n);
	puts("Entre com os valores:");
	for( i=0; i < n; i++)
	{
		scanf("%d", &vet[i]);
	}


	for( i=0; i < n; i++)
	{
	
		soma = soma + vet[i];
	}	

	media = soma / n;
	printf("O valor da media e: %d\n", media);

	maior = media;
	for( i=0; i < n; i++)
	{
		if ( maior < vet[i] )
		{
			printf("O elemento vet[%d] = %d e maior que a media!\n", i, vet[i]);
		}
		
	}	

	
}

