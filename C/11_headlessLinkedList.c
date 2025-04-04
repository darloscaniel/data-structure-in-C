#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
	int valor;
	struct cel*prox;
}celula;

void insert(celula **list, int x){
	celula *nova = malloc(sizeof(celula));
	nova->valor = x;
	nova->prox = *list;
	*list = nova;
}

int delete(celula **list){
	if (*list == NULL) {
        return -1;
    }
	celula *lixo = *list;
	int x = lixo->valor;
	*list = lixo->prox;
	free(lixo);
	return x;
}

void freeList(celula **list){
	celula *aux;
	while (*list != NULL){
		aux = *list;
		*list = (*list)->prox;//utilizamos o *list entre parenteses pois no parâmetro passamos um ponteiro para o ponteiro
		free(aux);
	}
}

void printList(celula *list){
	celula *aux = list;
    while (aux != NULL){
        printf("%d ->", aux->valor);
        aux = aux->prox;
    }
}

celula *getElement(celula *list, int x){
    celula *element = list;
    for (int i = 0; i<x; i++){
        element = element->prox;
    }
    return element;
}


int main() {
    celula *lista = NULL;  // Lista inicialmente vazia

    // Inserindo elementos na lista
    insert(&lista, 10);
    insert(&lista, 20);
    insert(&lista, 30);

    printf("Lista encadeada sem cabeça:\n");
    printList(lista);

    // Removendo elementos
    printf("Removendo: %d\n", delete(&lista));
    printList(lista);

    freeList(&lista);
    return 0;
}

