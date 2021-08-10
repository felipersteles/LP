
#include<iostream>
using namespace std;

int printM(int **matriz, int ordem){

    int i,j;

        for (i=0;i<ordem;i++){
            cout<<endl;
            for (j=0;j<ordem;j++){
                cout<<matriz[i][j]<<" ";
        }
    }
}

int printV(int *vetor, int termos){

    int i;

    for (i=0;i<termos;i++){
        cout<<"Vetor["<< i <<"] = "<<vetor[i]<<endl;
    }
}
