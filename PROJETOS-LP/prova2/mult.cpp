
#include <iostream>
using namespace std;

int MultiplicaM(int **matrizA,int linhasA,int colunasA,
                int **matrizB,int linhasB,int colunasB,
                int **matrizC,int linhasC,int colunasC)
{
    int i,j,k;

    int**resposta;
    int**resultado;

    resposta = new int*[linhasA];
    for(i=0; i<linhasA; i++)
    {
        resposta[i]=new int[colunasB];
    }

    if(colunasA==linhasB)
    {
        for(i=0; i<linhasA; i++)
        {
            for(j=0; j<colunasB; j++)
            {
                resposta[i][j]=0;
                for(k=0; k<(colunasA-1); k++)
                {
                    resposta[i][j]=(matrizA[i][k]*matrizB[k][j])+(matrizA[i][k+1]*matrizB[k+1][j]);
                }
            }
        }

        cout<<endl<<"Matriz A x B =";
        for(i=0; i<linhasA; i++)
        {
            cout<<endl;
            for(j=0; j<colunasB; j++)
            {
                cout<<resposta[i][j]<<" ";
            }

        }
    }
    else
    {
        cout<<"\nNao da pra multiplicar a matriz A pela B\n";
    }



    resultado = new int*[linhasA];
    for(i=0; i<colunasC; i++)
    {
        resultado[i]=new int[colunasC];
    }

    if(colunasB==linhasC)
    {
        for(i=0; i<linhasA; i++)
        {
            for(j=0; j<colunasC; j++)
            {
                resultado[i][j]=0;
                for(k=0; k<(colunasC-1); k++)
                {
                    resultado[i][j]=(resposta[i][k]*matrizC[k][j])+(resposta[i][k+1]*matrizC[k+1][j]);
                }
            }
        }

        cout<<endl<<"Matriz A x B x C = ";
        for(i=0; i<linhasA; i++)
        {
            cout<<endl;
            for(j=0; j<colunasB; j++)
            {
                cout<<resultado[i][j]<<" ";
            }

        }
    }
    else
    {
        cout<<"\nNao da pra multiplicar a matriz (AxB) pela matriz C\n";
    }


    for(i=0; i<linhasA; i++)
    {
        delete[]resultado[i];
    }
    delete[]resultado;

    for(i=0; i<linhasA; i++)
    {
        delete[]resposta[i];
    }
    delete[]resposta;
}

