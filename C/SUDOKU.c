#include <stdio.h>
#include <stdlib.h>



void **alocaMemoria( int x, int y  )
{
	int **m;
	int i;

	m = (int **)malloc(sizeof(int*)*x);

	for ( i = 0; i < 9; i++ )
	{
		m[i] = (int*)malloc(sizeof(int)*y);

	}
	return(m);
}


void liberaMemoria ( int ** m )
{
	int i,j;

	for ( i = 0; i < 9; i++ )
		for ( j = 0; j < 9; j++ )
		{
			m[i][j] = '0'
		}

	free(m);

	}


}

void verificaMatriz ( void )
{

	for( i = 0; i < 9; i++ ) 
   		{   
   	  		for( j = 0; j < 9; j++ )
      		{
	  			fscanf( Entrada, "%d", &matriz[i][j]);

     		}	
    	}

    i=0
    int x=0;

    int a = 0;
    int b= 0;

    vet[x] = matriz[a][b];
    x++;

    while( '1' )
    {
    	for( j = 0; j < 9; j++ )
    	{
    		for( i= 0; i < 9; i++ )
    		{
    			if ( matriz[i][j] != vet[x];)
    			{
    			vet[x] = matriz[i][j];
    			x++;
    			}
    			else
    				break;
			for( i= 0; i < 9; i++ )
			{
			v[i] = 0;
			x=0;
			}
    	}	
    

    	for( j = 0; j < 9; j++ )
    	{
    		for( i = 0; i < 9; i++ )
    		{
    			if ( matriz[j][i] != vet[x];)
    			{
    			vet[x] = matriz[j][i];
    			x++;
    			}
    			if 
    			{

    			}
			}
			for( i= 0; i < 9; i++ )
			{
				vet[i] = 0;
				x=0;
			}
  		  }	
  		  z == 1;
  	}





    if( z == 1)
    	printf( "Instancia 1" );
    	printf( "SIM" );
    else
    	printf( "Instancia 1" );
    	printf( "NÃO" );



}


int main(int argc, char *argv[])
{
	int l=9;
	int c=9;
	int **matriz;
	int numMatrizes;
	int i,j;

	matriz = alocaMemoria(l,c);

	FILE *Entrada = NULL;

	Entrada = fopen( argv[1], "r" );


	fscanf( Entrada, "%d\n", &numMatrizes );
	
	i=0;

	while( i < numMatrizes )
	{
		verificaMatriz();
		
    	liberaMatriz( matriz );
    	if ( i == (numMatrizes -1) )
    		matriz = alocaMemoria(l,c);	
    }











	fclose( Entrada );

}