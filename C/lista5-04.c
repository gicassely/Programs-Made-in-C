#include <stdio.h>


int main( int argc, char* argv[])
{
	
	int i,j;

	FILE *hEntrada = NULL;
	int matriz[15][5];
	
	int vetor1[75];

	int k=0;
	int l=0;
	
	int aux;
	int contador=0;
	int elemento;
	


	hEntrada = fopen( "matriz.txt", "r" );

	for( i = 0; i < 15; i++ ) 
    {   
   	  for( j = 0; j < 5; j++ )
      {
	  fscanf( hEntrada, "%d", &matriz[i][j]);

      }	
    }

      
    for (i = 0; i < 15; i++ )
   	  {
   	    for( j = 0; j < 5; j++ )
    	{
    		printf( "%d ", matriz[i][j] );
        }
        printf( "\n" );
      }
   
  

   for( i=0; i < 15; i++)
   {
      for( j = 0; j < 5; j++ )
      {	
   		vetor1[k] = matriz[i][j];
      	k++;
      }
   
   }
   

 	for( i=0; i<74; i++ )
 	{
          for( j=i+1; j<75; j++ )
          {
               if( vetor1[i] > vetor1[j] )
               {
                   aux = vetor1[i];
                   vetor1[i] = vetor1[j];
                   vetor1[j] = aux;
               }
           }
    }


    elemento = vetor1[0];

   
    for( i=0; i<75; i++ )
    {
    	if( elemento == vetor1[i])
    	{
    		contador++;

    	}
    	else
    	{
    		printf( "O elemento %d aparece %d\n", elemento, contador);
    		elemento = vetor1[i];
    		contador = 1;

    	}
	}
	printf( "O elemento %d aparece %d\n", elemento, contador);

	
}
