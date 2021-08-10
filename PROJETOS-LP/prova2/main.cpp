
#include <iostream>
#include <string.h>
#include "funsoes.h"

using namespace std;

int main()
{

    //matrizes
    int**A,**B,**C;

    //auxiliares
    int i,j;

    //aloc
    int nA,mA;
    cout<<"Linhas de A "<<endl;
    cin>>nA;
    cout<<"Colunas:"<<endl;
    cin>>mA;
    A=new int*[nA];
    for(i=0; i<nA; i++)
    {
        A[i] =  new int[mA];
    }

    int nB,mB;
    cout<<"Linhas de B "<<endl;
    cin>>nB;
    cout<<"Colunas:"<<endl;
    cin>>mB;
    B=new int*[nB];
    for(i=0; i<nB; i++)
    {
        B[i] =  new int[mB];
    }

    int nC,mC;
    cout<<"Linhas de C:"<<endl;
    cin>>nC;
    cout<<"Colunas:"<<endl;
    cin>>mC;
    C=new int*[nC];
    for(i=0; i<nC; i++)
    {
        C[i] =  new int[mC];
    }
//------------------------------------------------------------------------------------------------
    cout<<endl<<"Matriz A:"<<endl;
    desenhaM(A,nA,mA);
    cout<<endl<<"Matriz B:"<<endl;
    desenhaM(B,nB,mB);
    cout<<endl<<"Matriz C:"<<endl;
    desenhaM(C,nC,mC);
//------------------------------------------------------------------------------------------------
    MultiplicaM(A,nA,mA,B,nB,mB,C,nC,mC);
//------------------------------------------------------------------------------------------------
    for(i=0; i<nA; i++)
    {
        delete[]A[i];
    }
    delete[]A;
    for(i=0; i<nB; i++)
    {
        delete[]B[i];
    }
    delete[]B;
    for(i=0; i<nC; i++)
    {
        delete[]C[i];
    }
    delete[]C;

    return 0;
}

