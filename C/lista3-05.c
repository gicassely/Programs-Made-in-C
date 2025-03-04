#include  <stdio.h>


	

	int main ( int argc, char *argv[])
	{

		int i, somaQuadrados ;

		puts("Os numeros inteiros de 1 a 100:");
		for(i=1; i <= 100; i++)
		{
			printf("%d ", i );
		}
		puts( "\n");
		for(i=1; i <= 100; i++)
		{
			somaQuadrados = somaQuadrados + i * i;
		}
		printf( "A soma dos quadrados desses numeros: %d", somaQuadrados  );
		puts( "\n");






	}