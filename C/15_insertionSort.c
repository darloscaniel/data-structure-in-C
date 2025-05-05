#include <stdio.h>

void insertionSort(int v[], int n){

    //inicializamos i como 1 pois assumimos que o primeiro elemento esta ordenado!
    for (int i = 1; i<n; i++){
        int insert = v[i];//guardamos o valor que queremos ordenar 
        int j = i-1;

        while(j >= 0 && v[j] > insert){
            v[j + 1] = v[j];//aqui estamos empurrando o elemento maior para a direita
            j--;
        } 

        v[j+1] = insert;
    }
 
}

void printVector(int v[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){

    int vetor[] = {14,15,55,39,70,38,33,45,40,63,36,75,19};

    insertionSort(vetor, 13);
    printVector(vetor,13);

    return 0;
}