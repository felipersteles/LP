
#include <iostream>
using namespace std;

int printM(int **matriz, int linha, int coluna)
{

    int i,j;

    cout<<endl;
    for(i=0; i<linha; i++)
    {
        for(j=0; j<coluna; j++)
        {
            cout<<matriz[i][j];
        }
        cout<<endl;
    }
}

int desenhaM(int **matriz, int linha,int coluna)
{

    int i,j;

    for(i=0; i<linha; i++)
    {
        for(j=0; j<coluna; j++)
        {
            cin>>matriz[i][j];
        }
    }
}

char desenhaV(char *vetor, int ordem)
{
    int i;

    for(i=0; i<ordem; i++)
    {
        cin>>vetor[i];
    }
}




