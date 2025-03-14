#include <stdio.h>

int main(){

    int vet[11], x, i, P, j, aux;

while(P<=0 || P>10){
    printf("insira quantas posições o vetor terá (máximo 10): \n");
    scanf("%d", &P);
}

for(i=0; i<P; i++){
    printf("insira o valor da posição %d\n", i);
    scanf("%d", &vet[i]);
}

printf("insira um valor para X\n");
scanf("%d", &x);

vet[P] = x;
P++;

for(i = 0; i<P-1; i++){
    for(j=0; j< P-i-1; j++){
        
        if(vet[j]>vet[j+1]){
            aux = vet[j];
            vet[j] = vet[j+1];
            vet[j+1] = aux;
        }
    }
}

for(i = 0; i<P; i++){
    printf("posição %d valor: %d\n", i, vet[i]);
}
}