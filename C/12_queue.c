#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
	int valor;
	struct cel*prox;
}celula;


void insertInQueue(celula **start, celula **end, int element){
    celula *new = malloc(sizeof(celula));
    new->valor = element;
    new->prox = NULL;
    if(*end == NULL){
        *end = *start = new;
    }
    else{
        (*end)->prox = new;
        *end = new;
    }
}

int removeInQueue(celula **start, celula **end){
    if(*start == NULL){
        return -999;
    }

    celula *lixo = *start;
    int x = lixo->valor;
    *start = (*start)->prox;

    if(*start == NULL){
        *end = *start;
    }

    free(lixo);
    return x;
}

void freeQueue(celula **start){
    while (*start != NULL){
        celula *lixo = *start;
        free(lixo);
        *start = (*start)->prox;
    }
}

void printQueue(celula *list){
	celula *aux = list;
    while (aux != NULL){
        printf("%d ->", aux->valor);
        aux = aux->prox;
    }
}

int main() {
    celula *start = NULL;
    celula *end = NULL;

    insertInQueue(&start, &end, 10);
    insertInQueue(&start, &end, 20);
    insertInQueue(&start, &end, 30);

    printQueue(start);

    printf("removed: %d\n", removeInQueue(&start, &end));
    printQueue(start);

    freeQueue(&start); // Limpa toda a memória

    return 0;
}