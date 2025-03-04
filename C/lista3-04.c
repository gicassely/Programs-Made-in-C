#include <stdio.h>


	

	int main ( int argc, char * argv [])
	{

		int i, j, n = 10;
		int vetor[10];
		int metade;

		puts( "Entre com os 10 valores inteiros:" );
		for ( i=0; i < n; i++ )
		{
			scanf( "%d", &vetor[i]);

		}
		for ( j= 0; j < n ; j ++)
		{
			metade = vetor[j] / 2;
			printf( "%d ", metade);
		}


		puts( "\n" );	








	}