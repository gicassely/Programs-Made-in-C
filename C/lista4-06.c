#include <stdio.h>
#define TAM 5

int main( int argc, char* argv[])
{
   int vetSomalinhas[TAM], vetSomacolunas[TAM], matriz[TAM][TAM];
   int i, j, somalinhas, somacolunas;

   somalinhas = 0;
   somacolunas = 0;

   printf( "Entre com a matriz 5x5 elemento por elemento:\n" );
		
   for( i = 0; i < 5; i++ ) 
   {   
   	  for( j = 0; j < 5; j++ )
      {
	  scanf( "%d", &matriz[i][j]);

      }	
   }
  printf( "\n" );
   for( i = 0; i < 5; i++ )
   {  
   	  somalinhas= 0;
      for( j = 0; j < 5; j++ )
      {
	  somalinhas= somalinhas + matriz[i][j];
	 	
      }	
  	  vetSomalinhas[i] = somalinhas;
   }
   for( j = 0; j < 5; j++ )
   { 
   	  somacolunas = 0;
      for( i = 0; i < 5; i++ )
      {
	  somacolunas= somacolunas+ matriz[i][j];
	  
      }	
      vetSomacolunas[j] = somacolunas;

   }
  
   for (i = 0; i < 5; i++ )
   {
        for( j = 0; j < 5; j++ )
    	{
    		printf( "%d ", matriz[i][j] );
        }
        printf( "\n" );
   }
   printf( "\n" );
   for (i = 0; i < 5; i++ )
   {

   		printf( "%d ", vetSomalinhas[i]);
   }

   printf("\n\n");

   for (i = 0; i < 5; i++ )
   {

   		printf( "%d ", vetSomacolunas[i]);
   }

   printf("\n\n");

   
	





}