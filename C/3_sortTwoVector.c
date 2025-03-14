#include<stdio.h>

int main(){

    int vetor1[5] = {2,4,6,8,10};
    int vetor2[5] = {1,3,5,7,9};
    int vetor3[10];

    int i1=0,i2 = 0;
    int i3, i;


    for(i3 = 0; i3<10; i3++){

        if(i2>=5){
            vetor3[i3] = vetor1[i1];
            i1++;
            continue;
        }

        if(i1>=5){
            vetor3[i3] = vetor2[i2];
            i2++;
            continue;
        }

        if(vetor1[i1]<vetor2[i2] && i1<5){
            vetor3[i3] = vetor1[i1];
             i1++;
        }else{
            vetor3[i3] = vetor2[i2];
            i2++;
        }

    }

    for(i = 0; i<10; i++){
        printf("posição %d valor: %d\n", i, vetor3[i]);
    }
}