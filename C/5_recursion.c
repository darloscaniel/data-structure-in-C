#include <stdio.h>

int MaximoR(int v[], int n) {
    if (n == 1) {
        return v[0];
    } else {
        int x;
        x = MaximoR(v, n - 1);

        if (x > v[n - 1]) {
            return x;
        } else {
            return v[n - 1];
        }
    } 
}

int main() {
    int vetor[] = {3, 1, 7, 4, 9, 2};

    printf("Maior elemento: %d\n", MaximoR(vetor, 6));

    return 0;
}
