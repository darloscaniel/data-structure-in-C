#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
	int valor;
	struct cel*prox;
}celula;

int main(){

    celula LST1;
    LST1.valor = 10;
    LST1.prox = NULL;

    celula LST2;
    LST2.valor = 20;
    LST2.prox = NULL;

    LST1.prox = &LST2;

    celula* atual = &LST1;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");

    return 0;

}