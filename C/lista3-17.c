#include <stdio.h>
#define TAM  1000


int main (int argc , char *argv[])
{
	int i,n;
	int v[TAM];
	int somaTermos;
	v[0]= 1;
	v[1]= 1;



	printf("Entre com o valor do N-ésimo termo:" );
	scanf("%d", &n);
	if ( n <= 0)
	{
		printf("Valor  invalido!\n");
	}

		if (n == 1) 
		{
			printf ("%d\n", n);
		}
	
		if ( n > 1)
		{	printf("%d,", v[0]);
			printf("%d,", v[1]);
			for (i=1 ; i < n - 1  ; i ++)
			{
			v[i+1] = v[i] + v[i -1]; 
			somaTermos = v[i + 1];
			printf("%d,", somaTermos);
			}
		}
}	
