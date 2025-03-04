#include <stdio.h>

int main (int argc, char const *argv[]){
int vetor[100], media, numero, i, j, soma, maiores[100], n;
scanf("%d", &numero);
n = 0;
for( i=0 ; i < numero ; i++) {
	scanf("%d", &vetor[i]);
	soma = soma + vetor[i];
}

media = (soma/numero);
printf("%d\n", media );

for (j=0 ; j < numero ; j++) {
	if (vetor[j] > media) {
		maiores[n] = vetor[j];
		n++;
	}
}
for (n=0 ; n < numero ; n++){
	printf("%d\n", maiores[n] );
}
return 0;
}