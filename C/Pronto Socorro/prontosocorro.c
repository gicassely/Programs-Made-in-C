#include<stdio.h>
#include<stdlib.h>

#define TAM_NOME 45
#define TAM_DOENCA 30

#define MIN_RISCO 0
#define MAX_RISCO 100
#define MIN_QI 0
#define MAX_QI 10

#define INSERIR 1
#define ATENDER 2
#define LISTAR 3
#define AJUDA 4
#define SAIR 5

#define TRUE 1
#define	FALSE 0

//	Definição das estruturas utilizadas:	//
typedef struct PACIENTE{
	char nome[TAM_NOME];
	char doenca[TAM_DOENCA];
	int risco;
	int q_i;
}PACIENTE;

typedef struct CELULA *APONT;

typedef struct CELULA{
	PACIENTE paciente;
	APONT prox;
}CELULA;

typedef struct LISTA{
	APONT primeiro, ultimo;
}LISTA;

//	Cabeçalho das funções	//
void inserir(LISTA *lista_espera);
void atender(LISTA *lista_espera);
void listar(LISTA lista_espera);
void faz_lista_vazia(LISTA *l);
void inserir_na_lista(PACIENTE p, LISTA *l);
PACIENTE retirar_da_lista(APONT ant, LISTA *l);
int lista_vazia(LISTA l);
void imprimir_cabecalho();
void exibir_menu_principal();
void exibir_menu_atendimento();
void imprimir_paciente(PACIENTE p);
void imprimir_ajuda();
void retorno_ao_menu();
void atendimento(APONT p, LISTA *lista_espera);
int obter_grau_p();
int obter_qi();
int confirmar_dados(PACIENTE p);
APONT maior_qi(LISTA l);
APONT buscar_qi(int q_i, LISTA l);

int main(){
	int opcao;
	LISTA lista_espera;
	
	faz_lista_vazia(&lista_espera);
	do{
		exibir_menu_principal();
		scanf("%d", &opcao);
		getchar();
		switch(opcao){
			case(INSERIR):	inserir(&lista_espera);
					break;
			case(ATENDER):	atender(&lista_espera);
					break;
			case(LISTAR):	listar(lista_espera);
					break;
			case(AJUDA):	imprimir_ajuda();
					break;
			case(SAIR):	system("clear");
					exit(0);
			default:	imprimir_cabecalho();
					printf("Opcao invalida!\n");
					retorno_ao_menu();
		}
	}while(opcao != SAIR);
}


//	Operações principais	//
void inserir(LISTA *lista_espera){
	PACIENTE paciente;
	int confirmacao, indicacao;

	imprimir_cabecalho();
	printf("-Inserir paciente\n");

	printf("  Digite o nome do paciente:\n  ");
	scanf("%[^\n]", paciente.nome);
	getchar();

	printf("\n  Digite a doenca do paciente:\n  ");
	scanf("%[^\n]", paciente.doenca);
	getchar();

	paciente.risco = obter_grau_p();

	do{
		printf("\n  Alguem indicou este paciente:\n");
		printf("  0 - NAO\n");
		printf("  1 - SIM\n  ");
		scanf("%d", &indicacao);
		if(indicacao != TRUE && indicacao != FALSE)
			printf("\n  Opcao invalida!\n");
	}while(indicacao != TRUE && indicacao != FALSE);

	if(indicacao == TRUE)
		paciente.q_i = obter_qi();
	else
		paciente.q_i = MIN_QI;

	confirmacao = confirmar_dados(paciente);
	if(confirmacao == TRUE){
		inserir_na_lista(paciente, lista_espera);
		printf("Paciente inserido.\n");
	}
	else
		printf("Paciente nao inserido.\n");

	retorno_ao_menu();
}

void atender(LISTA *lista_espera){
	int opcao, q_i;
	APONT paciente;

	imprimir_cabecalho();
	printf("-Atender paciente\n");

	if(lista_vazia(*lista_espera)){
		printf("\n  Nao ha pacientes na lista de espera.\n");
		retorno_ao_menu();
		return;
	}
	
	exibir_menu_atendimento();

	scanf("%d", &opcao);
	getchar();

	switch(opcao){
		case(1):	paciente = lista_espera->primeiro;
					break;
		case(2):	paciente = maior_qi(*lista_espera);
					break;
		case(3):	printf("  Qual indicacao deseja buscar?\n");
					q_i = obter_qi();
					paciente = buscar_qi(q_i, *lista_espera);
					if(paciente == NULL){
						printf("  Nao existe paciente com esta indicacao.\n");
						retorno_ao_menu();
						return;
					}
					break;
		case(4):	printf("  Atendimento cancelado.\n");
					retorno_ao_menu();
					return;
		default:	printf("  Opcao invalida!\n");
					retorno_ao_menu();
					return;
	}

	atendimento(paciente, lista_espera);
}

void listar(LISTA lista_espera){
	APONT aux;
	imprimir_cabecalho();
	printf("-Exibir lista de espera\n\n");

	if(lista_vazia(lista_espera)){
		printf("  Nao ha pacientes na lista de espera.\n");
		retorno_ao_menu();
		return;
	}

	for(aux = lista_espera.primeiro->prox; aux != NULL; aux = aux->prox){
		imprimir_paciente(aux->paciente);
		printf("\n");
	}
	retorno_ao_menu();
}

//	Operações com lista	//
void faz_lista_vazia(LISTA *l){
	l->primeiro = (APONT)malloc(sizeof(CELULA));
	l->ultimo = l->primeiro;
	l->ultimo->prox = NULL;
}

void inserir_na_lista(PACIENTE p, LISTA *l){
	/*
		Se a lista não estiver vazia, encontra a posição correta para inserir,
		deixando os pacientes em ordem de periculosidade. Em caso de empate,
		o paciente que está a mais tempo na lista fica na frente.
	*/
	APONT aux, novo;
	if(lista_vazia(*l))
		aux = l->ultimo;
	else{
		aux = l->primeiro;
		while(aux->prox != NULL && aux->prox->paciente.risco >= p.risco)
			aux = aux->prox;
	}

	novo = (APONT)malloc(sizeof(CELULA));	
	novo->paciente = p;	
	novo->prox = aux->prox;
	aux->prox = novo;
	
	if(novo->prox == NULL)
		l->ultimo = novo;
}

PACIENTE retirar_da_lista(APONT ant, LISTA *l){
	PACIENTE p;
	APONT aux;

	aux = ant->prox;
	ant->prox = aux->prox;
	if(ant->prox == NULL)
		l->ultimo = ant;

	p = aux->paciente;
	free(aux);
	return p;
}

int lista_vazia(LISTA l){
	return (l.primeiro == l.ultimo);
}

//	Procedimentos de impressão	//
void imprimir_cabecalho(){
	system("clear");
	printf("	PRONTO SOCORRO\n\n");
}

void exibir_menu_principal(){
	imprimir_cabecalho();
	printf("Digite uma das seguintes opcoes:\n");
	printf("1 - Inserir novo paciente na lista de espera.\n");
	printf("2 - Atender um paciente.\n");
	printf("3 - Exibir lista de espera.\n");
	printf("4 - Ajuda.\n");
	printf("5 - Sair.\n\n ");
}

void exibir_menu_atendimento(){
	printf("  Qual paciente deseja priorisar?\n");
	printf("  1 - Maior grau de periculosidade;\n");
	printf("  2 - Principal indicacao;\n");
	printf("  3 - Indicacao especifica;\n");
	printf("  4 - Cancelar.\n  ");
}

void imprimir_paciente(PACIENTE p){
	printf("Nome: %s\n", p.nome);
	printf("Doenca: %s\n", p.doenca);
	printf("Grau de Periculosidade: %d\n", p.risco);
	printf("Indicacao: %d\n\n", p.q_i);
}

void imprimir_ajuda(){
	imprimir_cabecalho();
	printf("-Ajuda\n");

	printf("	*Dados dos pacientes:\n");
	printf("		O software armazena os seguintes dados dos pacientes:\n");
	printf("		> NOME\n");
	printf("		  Nome do paciente.\n");
	printf("		> DOENCA\n");
	printf("		  Doenca diagnosticada no paciente.\n");
	printf("		> GRAU DE PERICULOSIDADE\n");
	printf("		  Risco de vida do paciente.\n");
	printf("		  E definido por um valor entre %d e %d.\n", MIN_RISCO, MAX_RISCO);
	printf("		  %d representa paciente sem risco de vida;\n", MIN_RISCO);
	printf("		  %d representa paciente com risco de vida maximo.\n", MAX_RISCO);
	printf("		> INDICACAO\n");
	printf("		  Valor que representa o nivel de prioridade no atendimento\n");
	printf("		  que o paciente possui, de acordo com a importancia da\n");
	printf("		  pessoa que o indicou.\n");
	printf("		  E definido por um valor entre %d e %d.\n", MIN_QI, MAX_QI);
	printf("		  %d representa paciente sem indicacao;\n", MIN_QI);
	printf("		  %d representa paciente indicado por pessoa altamente\n", MAX_RISCO);
	printf("		  influente.\n\n");

	printf("  Tecle <ENTER> para continuar.");
	getchar();
	imprimir_cabecalho();
	printf("-Ajuda\n");

	printf("	*Operacoes:\n");
	printf("		> INSERIR\n");
	printf("		  Insere um novo paciente na lista de espera.\n");
	printf("		  O paciente sera posicionado antes dos demais pacientes com\n");
	printf("		  menos risco de vida, e apos os com risco igual, ou maior.\n");
	printf("		> ATENDER\n");
	printf("		  Atender um paciente consiste em encontrar um paciente de\n");
	printf("		  acordo com um certo parametro (grau de periculosidade,\n");
	printf("		  indicacao mais importante ou indicacao especifica). Os dados\n");
	printf("		  do paciente serao exibidos para que o medico responsavel\n");
	printf("		  possa atende-lo. O paciente, entao, sera removido da lista\n");
	printf("		  de espera.\n");
	printf("		> LISTAR\n");
	printf("		  Exibe todos os pacientes da lista de espera por ordem de\n");
	printf("		  periculosidade.\n\n");

	retorno_ao_menu();
}

//	Outras funções	//
void retorno_ao_menu(){
	printf("\n  Tecle <ENTER> para voltar ao menu.");
	getchar();
}

void atendimento(APONT p, LISTA *lista_espera){
	/*
		O paciente que será atendido, é o próximo após o paciente
		apontado por 'p'. Isso facilitará a remoção do paciente da
		lista de espera.
	*/
	PACIENTE atendido;

	if(p->prox == NULL){
		printf("ERRO: Paciente nao encontrado!\n");
		retorno_ao_menu();
		return;
	}

	atendido = retirar_da_lista(p, lista_espera);
	imprimir_cabecalho();
	printf("Atendendo paciente.\n\n");
	printf("Dados do paciente:\n");
	imprimir_paciente(atendido);

	printf("Tecle <ENTER> ao terminar o atendimento.\n");
	getchar();

	imprimir_cabecalho();
	printf("Atendimento finalizado.\n");
	retorno_ao_menu();
}

int obter_grau_p(){
	int risco;

	do{
		printf("\n  Digite o grau de periculosidade do paciente:\n  ");
		scanf("%d", &risco);
		getchar();
		if(risco < MIN_RISCO || risco > MAX_RISCO)
			printf("\n  Opcao invalida!\n");
	}while(risco < MIN_RISCO || risco > MAX_RISCO);

	return risco;
}

int obter_qi(){
	int q_i, indicacao;

	do{
		printf("\n  Insira o grau de influencia da pessoa que o indicou:\n  ");
		scanf("%d", &q_i);
		getchar();
		if(q_i < MIN_QI || q_i > MAX_QI)
			printf("\n  Opcao invalida!\n");
	}while(q_i < MIN_QI || q_i > MAX_QI);

	return q_i;
}

int confirmar_dados(PACIENTE p){
	int confirmacao;
	
	imprimir_cabecalho();
	printf("Dados do paciente:\n\n");
	imprimir_paciente(p);

	do{
		printf("Digite:\n");
		printf("1 - para confirmar os dados;\n");
		printf("0 - cancelar.\n");
		scanf("%d", &confirmacao);
		getchar();
		if(confirmacao != TRUE && confirmacao != FALSE)
			printf("\nOpcao invalida!\n");
	}while(confirmacao != TRUE && confirmacao != FALSE);

	return confirmacao;
}

APONT maior_qi(LISTA l){
	/*
		Esta função encontra o paciente com maior "Q.I.",
		em caso de empate, será retornado o que está a mais
		tempo na lista de espera.
		(O apontador retornado é o anterior ao paciente escolhido)
	*/
	APONT aux, maiorQI = l.primeiro;

	for(aux = l.primeiro; aux->prox != NULL; aux = aux->prox){
		if(aux->prox->paciente.q_i > maiorQI->prox->paciente.q_i)
			maiorQI = aux;
	}
	return maiorQI;
}

APONT buscar_qi(int q_i, LISTA l){
	/*
		Esta função busca o paciente com o "Q.I." desejado que
		está a mais tempo na lista de espera. Se não houver
		nenhum paciente com este "Q.I.", retorna 'NULL'.
		(O apontador retornado é o anterior ao paciente escolhido)
	*/
	APONT aux = l.primeiro;
	while(aux->prox != NULL && aux->prox->paciente.q_i != q_i)
		aux = aux->prox;

	if(aux = l.ultimo)
		return NULL;
	return aux;
}
