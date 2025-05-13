#include <stdio.h>

int main(){
  
    int P, i, j, vet[10], quant;

    while(P<=0 || P>10){
        printf("insira quantas posições o vetor possuirá (Máximo 10):");
        scanf("%d", &P); 
    }


    for (i = 0; i<P; i++){
        printf("Digite o elemento na posição %d: ", i);
        scanf("%d", &vet[i]);
    }
    quant = 0;
    for(i = 0; i<P; i++){
            int primo = 1;
                if(vet[i] == 1){
                    primo = 0;
                } else {
                    for (j = 2; j * j<= vet[i]; j++){
                        if (vet[i] % j == 0){
                            primo = 0;
                            break;
                        }
                    }
            }
            if(primo == 1){
                printf("O número %d na posição %d é primo!\n", vet[i], i);
                quant= quant+1;
            }
        }
        printf("a quantidade de primos é: %d", quant);
    return 0;
}