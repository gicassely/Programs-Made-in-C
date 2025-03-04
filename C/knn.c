#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	float dist;
	int class;
} distClasse;

typedef struct {
	float *caract;
	int classe;
} charaVector;

	float acertos;

//retorna o indice da maior distancia na lista
int maior(distClasse *list, int k){
	int maior = 0;
	for(int i = 0; i < k; i++){
		if(list[i].dist == -1){//-1 eh o valor para "infinito"
			return i;
		}else if(list[i].dist > list[maior].dist){
			maior = i;
		}
	}
	return maior;
}

//calcula a distancia (quase euclidiana) entre obj e base
float distancia(charaVector obj, charaVector base, int numCar){
	float dist = 0;
	for(int i = 0; i < numCar; i++){
		float diff = obj.caract[i]-base.caract[i];
		dist += diff * diff;
	}
	
	return dist;
}

//retorna classe predominante
int predominante(distClasse *list, int c){

	distClasse *listaPontuada = (distClasse *) malloc(c * sizeof(distClasse));//dist sendo numero de ocorrencias, ignorando class
	for(int i = 0; i < c; i++){
		listaPontuada[i].dist = 0;
	}
		
	for(int i = 0; i < c; i++){
		listaPontuada[list[i].class].dist += 1;
	}

	return maior(listaPontuada, c);
}

//deve classificar obj de acordo com base
void knn(charaVector obj, charaVector *base, int tamBase, int numCar, int **confusao, int k, int c){

	//lista de distClasse baseada na distancia que só guarda as K entradas menores. Insercoes devem ser feitas no Max(list.dist)
	distClasse *list = (distClasse *) calloc(k, sizeof(distClasse));
	for(int i = 0; i < k; i++){
		list[i].dist = -1;
	}

		for(int i = 0; i < tamBase; i++){
			float dist = distancia(obj, base[i], numCar);
			int indMaior = maior(list,k);
			if(dist < list[indMaior].dist || list[indMaior].dist == -1){
				list[indMaior].dist = dist;
				list[indMaior].class = base[i].classe;
		}
	}
	
	int classe = predominante(list, c);

	confusao[obj.classe][classe]++;
	if(obj.classe == classe)
		acertos++;

}

void main (int argc, char** argv){
	
	int numObj = 0;
	int numObjTest = 0;
	int numCar = 0;
	int numCarTest = 0;
	int k;
	int c;
	FILE *in;
	
	charaVector *base;
	charaVector objEstudo;
	int **confusao;
	
	if(argc < 4){
		//TODO: mexer na sintaxe
		printf("sintaxe: knn <k> <base_de_treinamento> <base_de_teste>\n");
		exit(-1);
	}else{
		k = atoi(argv[1]);
		c = 0; //atoi(argv[2]); //#classes
		in = fopen(argv[2], "r");
	}
	
	fscanf(in, "%d", &numObj);
	fscanf(in, "%d", &numCar);
	
	//preenche a base de treinamento
	base = (charaVector *) calloc(numObj, sizeof(charaVector));
	for(int i = 0; i < numObj; i++){
		base[i].caract = calloc(numCar, sizeof(float));
		for(int j = 0; j < numCar; j++){
			fscanf(in,"%f",&base[i].caract[j]);
		}
		fscanf(in, "%d", &base[i].classe);
		if(base[i].classe + 1 > c){
			c = base[i].classe + 1;
		}
		
		if(i % 500 == 0)
			fprintf(stderr, "aprendendo #%d\n",i);
	}
	
	fclose(in);
	//TODO: possivel erro, mexer logo, pegar testes do teclado ou arquivo
	in = fopen(argv[3], "r");
	fscanf(in, "%d", &numObjTest);
        fscanf(in, "%d", &numCarTest);
	
	//testa numero de caracteristicas
	if(numCarTest != numCar){
		printf("numero de caracteristicas de teste diferentes da base de treinamento");
		exit(-1);
	}
	
	//inicializa confusao
	confusao = (int **) malloc(c * sizeof(int *));
	for(int m = 0; m < c; m++){
		confusao[m] = (int *) calloc(c, sizeof(int));
	}
	
	if(confusao == NULL){
		printf("Falha ao alocar matriz confusao\n");
		exit(-1);
	}

	objEstudo.caract = calloc(numCarTest, sizeof(float));
	//classifica um objeto por iteração
	for(int i = 0; i < numObjTest; i++){
		for(int j = 0; j < numCarTest; j++){
			//le todas caracteristicas
			fscanf(in, "%f", &objEstudo.caract[j]);
		}
		fscanf(in, "%d", &objEstudo.classe);
		
		if(i % 50 == 0)
			fprintf(stderr, "classificando #%d\n",i);
		
		//classificação propriamente dita
		knn(objEstudo, base, numObj, numCar, confusao, k, c);
	}

	//imprime confusao
	for(int i = 0; i < c; i++){
		for(int j = 0; j < c; j++){
			fprintf(stdout,"%d\t",confusao[i][j]);
		}
		fprintf(stdout,"\n");
	}
	
	fprintf(stdout,"acertos = %0.f, acuracia = %f", acertos, (acertos/numObjTest));
	
}
