#include <stdio.h>

void soma(int *a, int b){
	*a = *a + b;
	}

int main(){
	int a = 20;
	int b = 10;
	int *c = &a;
	
	soma(c,b);
    printf("%d\n", a);// 30
    //printf("%d\n", *a);// Erro removido
    printf("%p\n", (void*)&a); // Endereço de 'a' (ex: 0x500)
    printf("%p\n", (void*)c); // Endereço de 'a' pois "c" recebe &a
    printf("%p\n", (void*)&c); // Endereço de 'c'
    printf("%d\n", *c); // 30 pois acessa o endereço de 'a'

    return 0;
}

