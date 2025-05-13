#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
	int valor;
	struct cel*prox;
}celula;

//função que insere um valor na lista após o ponteiro passado no parâmetro
void Insere(celula *p, int x){
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->valor = x;
    nova->prox = p->prox;
    p->prox = nova;
}

int main(){
    celula LST1;
    LST1.valor = 10;
    LST1.prox = NULL;

    Insere(&LST1 , 20);

    celula* atual = &LST1;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");

    return 0;
}