#include <stdio.h>

// Algoritmo com complexidade entre O(n) -> se o vetor ja estiver ordenado e O(n²), pode variar de caso pra caso
// para o vetor aplicado nesse algoritmo a complexidade é próximo de O(n²)
void insertionSort(int v[], int n){

    // Começa no segundo elemento , pois a comparação será feita com o elemento anterior
    for (int i = 1; i < n; i++){
        int insert = v[i];  // Valor que queremos inserir na parte ordenada do vetor
        int j = i - 1;      // Índice do elemento anterior a i

        // Enquanto estivermos dentro do vetor e o elemento na posição j for maior que insert
        while (j >= 0 && v[j] > insert){
            v[j + 1] = v[j]; // Move o elemento maior uma posição para a direita (empurrando-o)
            j--;             // Move para o próximo elemento à esquerda para continuar comparando
        } 

        // Insere o valor 'insert' na posição correta 
        v[j + 1] = insert;
    }
}

void printVector(int v[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n"); 
}

int main(){

    int vetor[] = {14, 15, 55, 39, 70, 38, 33, 45, 40, 63, 36, 75, 19};

    insertionSort(vetor, 13);

    printVector(vetor, 13);

    return 0; 
}
