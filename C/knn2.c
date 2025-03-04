	#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

float** LerArquivo(FILE *f,int *lin,int *col){
	float **M;
	fscanf(f,"%d %d",lin, col);
	M = malloc (*lin * sizeof (float *));
	for (int i = 0; i < *lin; i++)
		M[i] = malloc ((*col+1) * sizeof (float));

	//printf("LIN %d\n",*lin );
	for (int i=0; i<*lin; i++){
		for(int j=0; j<=*col; j++){
			fscanf(f," %f ",&M[i][j]);
		}
	}
	return M;
}

void liberarMatriz(float **M,int lin){
	for(int i=0; i<lin;i++){
		//printf("%d - %d \n",i,lin );
		free(M[i]);
	}
	free(M);
}

float distancia_euclidiana(float *u, float *v, int tam){
	float aux,sum;
	sum =0;
	for (int i=0; i<tam; i++){
		aux = u[i] - v[i];
		sum += aux * aux;
	}
	return sqrt(sum);
}

void encontra_kmenores(float *dist,int *k_menor,int k,int lintr){
	int menor;
	for(int i=0; i<k; i++){
		menor = 0;
		for(int j=0;j<lintr;j++){
			if (dist[menor] > dist[j]){
				menor = j;
			}
		}
		k_menor[i] = menor;
		dist[menor] = FLT_MAX;
	}
}

int encontra_classe(int *k_menor,float **treinamento,int col,int k){
	int count[10] = {0,0,0,0,0,0,0,0,0,0};
	int pos,maior;
	for(int i = 0; i<k; i++){
		//printf("%d - %d - %d\n",k_menor[i],col,i);
		pos = (int)treinamento[k_menor[i]][col];
		count[pos]++;
	}

	maior = 0;
	for(int i=1; i<10; i++){
		if (count[maior]<count[i])
			maior = i;
	}
	return maior;
}

void imprime_m_confusao(int m_confusao[10][10]){
	int exemp_corretos = 0;
	int total = 0;
	float tx_acerto;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if(i==j)
				exemp_corretos +=m_confusao[i][j];
			total += m_confusao[i][j];
			printf("%5d ", m_confusao[i][j]);

		}
		printf("\n");
	}
	printf("Acertos :%d\n",exemp_corretos);
	printf("Total   :%d\n",total);
	tx_acerto = (float)exemp_corretos/(float)total;
	printf("Taxa de reconhecimento : %.2f\n",tx_acerto);
}
void inicializa_matriz_conf(int m_confusao[10][10]){
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			m_confusao[i][j] = 0;
		}
	}
}

float insere_menor(float *dist,int *k_menor,int k,float novo,int pos){
	float aux;
	float maior;
	int pos_aux;
	for (int i = 0; i < k; i++)
	{
		if (dist[i] > novo){
			pos_aux = k_menor[i];
			aux = dist[i];
			k_menor[i] = pos;
			dist[i] = novo;
			pos = pos_aux;
			novo = aux;
		}

	}
	maior = dist[k-1];
	return maior;
}
int main(int argc, char const *argv[])
{
	if(argc != 4){
		printf("<Executavel> <ArquivoTeste> <ArquivoTreinamento> <k>\n");
		return 1;
	}
	float ** teste;
	float ** treinamento;
	int lint,colt;
	int lintr,coltr;
	int posX,posY;
	int m_confusao[10][10];
	int k = atoi(argv[3]);
	FILE *fteste = fopen(argv[1],"r");
	FILE *ftreinamento = fopen(argv[2],"r");
	teste = LerArquivo(fteste,&lint,&colt);
	treinamento = LerArquivo(ftreinamento,&lintr,&coltr);

	inicializa_matriz_conf(m_confusao);
	int **k_menor;
	k_menor = malloc (lint * sizeof (int*));
	for (int i = 0; i < lint; i++)
	{
		k_menor[i] = malloc(k*sizeof(int));
	}

	float **dist = malloc (lint * sizeof (float*));
	for(int i=0;i<lint;i++){
		dist[i] = malloc (k * sizeof (float));
	}

	for (int i = 0; i < lint; i++)
	{
		for (int j = 0; j < k; j++)
		{
			dist[i][j] = FLT_MAX;
		}
	}

	float aux;
	float maior;
//	for(int i=0; i<lint; i++){
	for(int i=0; i<lintr; i++){
		for (int j = 0; j < k; j++)
		{
			dist[i][j] = distancia_euclidiana(teste[i], treinamento[j],colt);
			k_menor[i][j] = j;
		}
		maior = k_menor[i][k-1];
		//for(int j=k; j<lintr;j++){
		for(int j=k; j<lintr;j++){
			aux = distancia_euclidiana(teste[i], treinamento[j],colt);
			if(aux < maior){
				maior = insere_menor(dist[i],k_menor[i],k,aux,j);
			}
		}

//		encontra_kmenores(dist[i],k_menor,k,lintr);
//		encontra_kmenores(dist[i],k_menor,k,10000);
		posX = encontra_classe(k_menor[i],treinamento,coltr,k);
		posY = (int)teste[i][colt];
//		printf("i:%d x:%d y:%d\n",i,posX,posY);
		m_confusao[posX][posY]++;

	}

	imprime_m_confusao(m_confusao);
/*	for (int aux=0; aux<k; aux++){
		printf("%5d ",k_menor[aux]);
	}
//	printf("\n");
//	printf("%d\n",posX);
	for (int aux=0; aux<k; aux++){
		printf("%5f ",dist[0][aux]);
	}
	printf("\n");
*/
	//printf("TESTE\n");
	/*------FINALIZAR--------*/
	for (int i = 0; i < lint; i++)
	{
		free(k_menor[i]);
	}
	free(k_menor);
	liberarMatriz(dist,lint);
	liberarMatriz(teste,lint);
	liberarMatriz(treinamento,lintr);


	return 0;
}