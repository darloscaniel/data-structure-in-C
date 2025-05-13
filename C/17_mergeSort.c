#include <stdio.h>

int merge(int v[], int left, int mid, int right){

    int result[right-left];// vetor para armazenar o resultado
    int leftIndex = left;// índice para o vetor da esquerda
    int rightIndex = mid; // índice para o vetor da direita
    int index = 0;// índice para o vetor ordenado

    //enquanto houver elementos nos dois vetores é feito uma comparação
    while(leftIndex < mid && rightIndex < right){
        if(v[leftIndex] <= v[rightIndex]){
            result[index++] = v[leftIndex++];
        }else{
            result[index++] = v[rightIndex++];
        } 
    }

    //caso acabe as posições de algum dos vetores adiciona o restante ao result
    while(leftIndex < mid){
        result[index++] = v[leftIndex++];
    }
    while(rightIndex < right){
        result[index++] = v[rightIndex++];
    }

    // ordena o vetor de acordo com o resultado gerado
    for (int i = 0; i<index; i++){
        v[left + i] = result[i];
    }
}

void mergeSort(int v[], int left, int right){
    //só aplicará se tiver mais de um elemento no vetor
    if(left+1 < right){
        int mid = left + (right-left)/2; //meio do vetor
        mergeSort(v, left, mid);//instancia o vetor da esquerda
        mergeSort(v, mid, right);//instancia o vetor da direita
        merge(v, left, mid, right);//faz o merge dos dois vetores após fechar a instancia
    }
}

void printVector(int v[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){

    int vector[] = {87, 90, 71, 65, 33, 36, 12, 9, 52, 79};
    int len = sizeof (vector)/sizeof(vector[0]);

    mergeSort(vector, 0, len-1);
    printVector(vector, len-1);

    return 0;
}