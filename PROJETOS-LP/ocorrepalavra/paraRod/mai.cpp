#include <iostream>
#include <string.h>
#include "teles.h"
using namespace std;

char encontra(char *onde, char*oque);

int main(){

    //matriz
    char**mat;

    //ordem
    cout<<"Ordem da matriz:\n";
    int n;
    cin>>n;

    //aloc
    mat=new char*[n];
    int i; //auxiliar i
    for(i=0;i<n;i++){
        mat[i]= new char[n];
    }

    cout<<"Matriz:\n";
    desenhaM(mat,n); //faz a matriz

    //palavra que busca
    char palavra[100];
    cout<<"Buscas?";
    cin>>palavra;

    int local,cont=0;
    for(i=0;i<n;i++){
        local = encontra( mat[i] , palavra);
        if(local>=0){
            cont++;
        }
    }

    if (cont>0){
        cout<<"Ocorre "<<cont<<" vezes";
    }else{
        cout<<"Nao ocorre";
    }

    return 0;
}

char encontra(char *onde, char*oque){
    char *aux;

    aux = strstr(onde,oque);
    if(aux!=NULL){
        return strlen(onde)-strlen(aux);
    }
    return -1;
}
