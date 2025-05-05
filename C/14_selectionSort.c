#include <stdio.h>

void selectionSort(int v[], int n){

    for(int i = 0; i < n ; i++){
        int menor = i;
        for (int j = i+1; j < n; j++){
            if(v[j]<v[menor]){
                menor = j;
            }
        }

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

}