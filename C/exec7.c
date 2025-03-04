#include <stdio.h>


	int main(){

		int num, dezena;



		printf("Entre com um numero de quatro algarismos:");
		scanf("%d", &num);
		dezena= (int)(num % 100) / 10;
		printf("%d\n", dezena);


	} 
