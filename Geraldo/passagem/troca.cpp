#include <iostream>
using namespace std;

// [a] e [b], e depois troca
void troca (int *a, int *b){
    int aux;
    cout << *a << " " << *b << "\n";
    aux = *a;
    *a = *b;
    *b = aux;
    cout << *a << " " << *b << "\n";
}

