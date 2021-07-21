#include <stdlib.h>

void minMax(int **vetor, int n,
            int *min, int *max){
    int i;
    *vetor = new int [5];
    int *vet = *vetor;

    for (i=0; i<5; i++)
        vet[i] = rand();
    vet[0] = 100;
    *min = vet[0];
    *max = vet[0];

    for (i=1; i<n; i++) {
        if (vet[i] < *min)
            *min = vet[i];
        if (vet[i] > *max)
            *max = vet[i];
    }
}

