#include "stdio.h"
#include "stdlib.h"
int main(int argc, char const *argv[]){

int max, col, lin, i, j, aux, x, y;
int r[512][512], g[512][512], b[512][512], vetor[9], red[512][512], green[512][512], blue[512][512];
char px[3];
scanf("%s", px);
scanf("%d", &col);
scanf("%d", &lin);
scanf("%d", &max);

for(i=0 ; i < lin ; i++) {
	for(j=0 ; j < col ; j++) {
		scanf("%d%d%d ", &r[i][j],&g[i][j],&b[i][j]);
		red[i][j]=r[i][j];
		green[i][j]=g[i][j];
		blue[i][j]=b[i][j];
	}
}
for(i=1 ; i < lin - 1 ; ++i){
	for(j=1 ; j < col - 1 ; ++j){
		vetor[0]= r[i-1][j-1];
		vetor[1]= r[i-1][j];
		vetor[2]= r[i-1][j+1];
		vetor[3]= r[i][j-1];
		vetor[4]= r[i][j];
		vetor[5]= r[i][j+1];
		vetor[6]= r[i+1][j-1];
		vetor[7]= r[i+1][j];
		vetor[8]= r[i+1][j+1];
		//-------------------------ordena
		for (x=9-1 ; x >= 1 ; x--){
    		for (y=0 ; y < x ; y++){
     			if (vetor[y] > vetor[y+1]) {
      				aux = vetor[y];
      				vetor[y] = vetor[y+1];
      				vetor[y+1] = aux;
     			}
  			}
		}
		//-------------------------------
		red[i][j]=vetor[4];
	}
}
for(i=1 ; i < lin - 1 ; ++i){
	for(j=1 ; j < col - 1 ; ++j){
		vetor[0]= g[i-1][j-1];
		vetor[1]= g[i-1][j];
		vetor[2]= g[i-1][j+1];
		vetor[3]= g[i][j-1];
		vetor[4]= g[i][j];
		vetor[5]= g[i][j+1];
		vetor[6]= g[i+1][j-1];
		vetor[7]= g[i+1][j];
		vetor[8]= g[i+1][j+1];
		//-------------------------ordena
		for (x=9-1 ; x >= 1 ; x--){
    		for (y=0 ; y < x ; y++){
     			if (vetor[y] > vetor[y+1]) {
      				aux = vetor[y];
      				vetor[y] = vetor[y+1];
      				vetor[y+1] = aux;
     			}
  			}
		}
		//-------------------------------
		green[i][j]=vetor[4];
	}
}
for(i=1 ; i < lin - 1 ; ++i){
	for(j=1 ; j < col - 1 ; ++j){
		vetor[0]= b[i-1][j-1];
		vetor[1]= b[i-1][j];
		vetor[2]= b[i-1][j+1];
		vetor[3]= b[i][j-1];
		vetor[4]= b[i][j];
		vetor[5]= b[i][j+1];
		vetor[6]= b[i+1][j-1];
		vetor[7]= b[i+1][j];
		vetor[8]= b[i+1][j+1];
		//-------------------------ordena
  		for (x=9-1 ; x >= 1 ; x--){
    		for (y=0 ; y < x ; y++){
     			if (vetor[y] > vetor[y+1]) {
      				aux = vetor[y];
      				vetor[y] = vetor[y+1];
      				vetor[y+1] = aux;
     			}
  			}
		}
		//-------------------------------
		blue[i][j]=vetor[4];
	}	
}

printf("%s\n", px );
printf("%d\n", col );
printf("%d\n", lin );
printf("%d\n", max );
for (i=0 ; i < lin ; i++){
	for (j=0 ; j < col ; j++){
      	printf("%d %d %d    ", red[i][j],green[i][j],blue[i][j]);
    }
	printf("\n");
  }
}