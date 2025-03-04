#include <stdio.h>

	int main(){

	
		float valorQw,valor_reais,valor_comdesconto,salario, qta_gastaQw;

	printf("Entre com salario minimo e a quantidade de quilowatts:");
	scanf("%f %f", &salario, &qta_gastaQw);
	valorQw= salario/ 700;
	valor_reais= valorQw * qta_gastaQw;
	valor_comdesconto= valor_reais * 0.9;
	printf("Valor em reais de cada quilowatt: %f\n", valorQw);
	printf("Valor em reais a ser pago: %f\n", valor_reais);
	printf("Valor a ser pago com desonto de 10%%: %f\n", valor_comdesconto);

}
	