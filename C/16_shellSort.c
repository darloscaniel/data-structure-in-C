#include <stdio.h>

//obs: o shellsort demonstra realmente algum impacto em vetores com um grande numero de elementos
// com essa sequencia de gaps, em um vetor válido para testes, se aproxima de O(n log n)
// se colocarmos em numeros a complexidade estimada esta entre O(n^1.25) e O(n^1.5)

void shellSort(int v[], int n){
    int gaps[] = {4,1};//sequencia de Ciura para vetor de 10 elementos
    int gapJumps = sizeof(gaps)/ sizeof(gaps[0]);

//loop para os gaps, aplicamos apenas os gaps abaixo do numero de elementos do vetor
    for(int g = 0; g<gapJumps; g++){
        int gap = gaps[g];

        for(int i = gap; i<n; i++){//inicializamos o i no gap e comparamos com primeiro elemento
            int insert = v[i];
            int j = i;

            while(j>= gap && v[j-gap] > insert){
                v[j] = v[j-gap];
                j-=gap;
            }

            v[j] = insert; 
        }
    }
}

void printVector(int v[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){

    int vetor[] = {9, 0, 2, 5, 6, 4, 1, 3, 7, 8};

    shellSort(vetor, 10);
    printVector(vetor,10);
    
    return 0;
}