#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
	int valor;
	struct cel*prox;
}celula;

//insere um elemento após a posição passada no parametro
void insert(celula *list, int x){
    celula *nova = malloc(sizeof(celula));//#12.5555
    nova->valor = x;
    nova->prox = list->prox;
    list->prox = nova;
} 

//deleta um elemento após a posição passada no parâmetro
int delete(celula *list){
    if (list->prox == NULL){ 
        return -1;
    }
    celula *lixo = list->prox;
    int x = lixo->valor;
    list->prox = lixo->prox;
    free(lixo);
    return x;
}

//criar lista com cabeça
celula *createList(){
    celula *cabeca = malloc(sizeof(celula));
    cabeca->prox = NULL;
    return cabeca;
}

// a função para imprimir a lista começa pulando a cabeça
void printList(celula *list){
    celula *aux = list->prox;
    while (aux != NULL){
        printf("%d ->", aux->valor);
        aux = aux->prox;
    }
}

// a função getElement precisa retornar um ponteiro para o elemento na posição desejada
celula *getElement(celula *list, int x){
    x++;
    celula *element = list;
    for (int i = 0; i<x; i++){
        element = element->prox;
    }
    return element;
}

void freeList(celula *list){
    celula *aux;
    while (list != NULL){
        aux = list;
        list = list->prox;
        free(aux);
    }
}

// em caso de lista com cabeça
// facilita a inserção e deleção do primeiro elemento
int main(){
    celula *lista = createList();// Criar lista com cabeça
    insert(lista, 10);
    insert(lista, 20);
    insert(lista, 30);

    printf("Lista com cabeça:\n");
    printList(lista);

    freeList(lista);
    return 0;
}