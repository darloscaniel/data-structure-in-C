#include <stdio.h>

//função para dividir o array em dois após encontrar a posição do pivô
int partition(int v[], int left, int right){
    int pivot = v[right];
    int i = left-1;

    //vamos fazendo a troca dos elementos menores que o pivô nas primeiras posições
    for(int j = left; j < right; j++){
        if(v[j] <= pivot){
            ++i;
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
    // após varrer todo o vetor, posicionamos o pivô corretamente
    int aux2 = v[i+1];
    v[i+1] = v[right];
    v[right] = aux2;

    return i+1;
}

void quickSort(int v[], int left, int right){
    //só aplicará se tiver mais de um elemento no vetor
    if(left < right){
        int pivot = partition(v, left, right);//ordenamos o pivô
        quickSort(v, left, pivot-1);//instancia um vetor para valores menores que o pivô
        quickSort(v, pivot+1, right);//instancia um vetor para valores maiores que o pivô   
    }
}

void printVector(int v[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){

    int vector[] = {38, 55, 15, 39, 70, 14, 33, 45, 40, 63, 19, 75, 36};
    int len = sizeof (vector)/sizeof(vector[0]);

    quickSort(vector, 0, len-1);
    printVector(vector, len-1);

    return 0;
}