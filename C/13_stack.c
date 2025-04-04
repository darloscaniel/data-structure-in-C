#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
	int valor;
	struct cel*prox;
}celula;

celula *createStack(){
    celula *top = malloc(sizeof(celula));
    top->prox = NULL;
    return top;
}

void push(celula *list, int x){
    celula *nova = malloc(sizeof(celula));
    nova->valor = x;
    nova->prox = list->prox;
    list->prox = nova;
} 

int pop(celula *list){
    if (list->prox == NULL){ 
        return -1;
    }
    celula *lixo = list->prox;
    int x = lixo->valor;
    list->prox = lixo->prox;
    free(lixo);
    return x;
}

void printStack(celula *list){
    celula *aux = list->prox;
    while (aux != NULL){
        printf("%d ->", aux->valor);
        aux = aux->prox;
    }
}

void freeStack(celula *list){
    celula *aux;
    while (list != NULL){
        aux = list;
        list = list->prox;
        free(aux);
    }
}

int main(){
    celula *stack = createStack(); // Criando pilha com cabeça

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printStack(stack);

    int valor = pop(stack);
    printf("removed: %d\n", valor);

    printStack(stack);

    freeStack(stack);
    return 0;
}
