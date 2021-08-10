
#include <iostream>
#include "biblioteca.h"
using namespace std;

int main(){

    int i,j;
    int n;

    cout<<"Ordem da matriz:"<<endl;
    cin>>n;

    //aloc mat
    int**mat;
    mat=new int*[n];
    for(i=0;i<n;i++){
        mat[i]=new int[n];
    }


   //desenha mat
   cout<<"Matriz: "<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    cout<<endl;

    magica(mat,n);

    //delete mat
    for(i=0;i<n;i++){
        delete[]mat[i];
    }
    delete[]mat;

    return 0;
}
