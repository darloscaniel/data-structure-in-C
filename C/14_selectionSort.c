#include <stdio.h>

//Algoritmo de complexidade O(n²)
void selectionSort(int v[], int n){
    // Percorre todas as posições do vetor
    for(int i = 0; i < n ; i++){
        // Assume que o menor elemento está na posição i
        int menor = i;

        // Procura no restante do vetor algum elemento menor que o atual
        for (int j = i+1; j < n; j++){
            if(v[j] < v[menor]){
                menor = j;  // Atualiza a posição do menor elemento encontrado
            }
        }

        // Se encontrou um elemento menor que o da posição i, realiza a troca
        if(menor != i){
            int aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;   
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
   
    int vetor[] = {3, 0, 1, 8, 7, 2, 5, 4, 9, 6};

    selectionSort(vetor, 10);

    printVector(vetor, 10);

    return 0;  
}