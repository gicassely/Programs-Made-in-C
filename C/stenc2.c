#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>


#define SIZE 5

void main(){	

double *A;
double *B;
int i,j;
         A = malloc(sizeof(int *) * SIZE);
	 B = malloc(sizeof(int *) * SIZE);


	for (int i=0; i<SIZE; ++i){
		for (int j=1; j<SIZE-1;++j){
			A[i][j]=50;
			B[i][j]=50;
		}
	}
	for (int i=0; i<SIZE; ++i){
		A[i][SIZE-1]=0;
		B[i][SIZE-1]=0;
	}
	for (int i=0; i<SIZE; ++i){
		A[i][0]=100;
		B[i][0]=100;	
	}
	 printf ("%f ", A[i][j]);
                
	printf ("\n");

	for (int i=0; i<SIZE; i++){
		for (int j=1; j<SIZE;j++){
		printf ("%f ", A[i][j]);
			}
  
		printf ("\n");
}
	for (int i=0; i<SIZE; i++){
		for (int j=1; j<SIZE;j++){
			B[i][j]=(A[i][j+1]+A[i][j-1]+A[i+1][j]+A[i-1][j]/50);

			
}
 
	

