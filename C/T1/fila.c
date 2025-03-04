
//Cria uma fila vazia, cujo tamanho máximo é limite.
//Se valor de limite é 0 (zero), fila pode ter qualquer tamanho
//(limitado apenas pela disponibilidade de memória
//definida pelo sistema operacional).  Retorna
//NULL se houve erro na criação da fila. O parâmetro
//tipo pode assumir apenas um dos valores: 1(texto); 2(cor); 3(ponto);
Fila *cria(int limite, int tipo) {
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    fila->begin = NULL;
    fila->end = NULL;
    fila->size = 0;
    if (tipo == 1)
    return fila;
}


//Insere o elemento o no início da fila, retornando o valor 0 caso haja
//erro e 1 caso contrário;
int insere(No *o, Fila *fila) {
    No *new = (No*) malloc(sizeof(No));
    if (fila->size == 0) {
        fila->begin = new;
        fila->end = new;
        new->next = NULL;
        new->prev = NULL;
        fila->size++;
        return 1;
    }
    //o primeiro elemento da fila terá o novo como prev
    fila->begin->prev = new;
    new->next = fila->begin;
    fila->size++;
    fila->begin = new;
}

//Remove o primeiro elemento da fila através do parâmetro o, retornando o valor 0
//se houve erro na remoção, e 1 caso contrário;
int retira(No *o, Fila *f) {

}


//Retorna 1 se a fila está vazia, 0 caso contrário;
int ehVazia(Fila *f) {

}


//Retorna 1 se a fila está cheia, 0 caso contrário. Se fila não tem limitação de tamanho,
//retorna 0.
int ehCheia(Fila *f){

}
