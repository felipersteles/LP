#include <iostream>
#include "biblioteca.h"
using namespace std;

int main() {
    int *vetor;
    int min, max;
    int i;
    vetor = new int [5];
    for (i=0; i<5; i++)
        vetor[i] = i+1;

    for (i =0; i<5; i++)
        cout << vetor[i] << "\n";

    minMax(&vetor, 5,
           &min, &max);

    for (i =0; i<5; i++)
        cout << vetor[i] << "\n";


}
//int **matriz
/*
int **coOcorrencia(int **m,
                   int lin,
                   int col) {

    int **ret;
    //alocar
    //preencher


    return ret;
}

void coOcorrencia(int **m,
                   int lin,
                   int col,
                  int ***ret ) {
    //alocar
    *ret = new int *[lin]
    for (i= ...)
        *ret[i]

}
*/
