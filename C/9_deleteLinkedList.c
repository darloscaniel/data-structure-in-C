#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
	int valor;
	struct cel*prox;
}celula;

//remove o elemento da lista após o p passado como parâmetro
int deleteElement(celula *p) { 
    if(p->prox != NULL) {
      celula *lixo = p -> prox;
      int x = lixo -> valor;
      p -> prox = lixo -> prox;
      free(lixo);
      return x;
    } else {
      return -999;
    }
}

int main(){

    celula *lista = NULL;
    celula LST1;
    celula LST2;
    celula LST3;

    lista = &LST1;

    LST1.valor = 10;
    LST1.prox = &LST2;

    LST2.valor = 20;
    LST2.prox = &LST3;

    LST3.valor = 30;
    LST3.prox = NULL;

// Imprime a lista antes da remoção
    celula* atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");

    deleteElement(lista);

    //imprime a lista após a remoção
    atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");

    return 0;

}