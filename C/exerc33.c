#include <stdio.h>


	int main(){

		int tempo, Vmedia, distancia;
		float litros;


		printf("Entre com o tempo gasto na viagem e a velocidade media:");
		scanf("%d %d", &tempo, &Vmedia);
		distancia= tempo * Vmedia;
		litros= distancia / 12;
		printf("%d\n", distancia);
		printf("%f\n", litros);	




	}