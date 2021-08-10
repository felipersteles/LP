
#include <iostream>
#include <fstream>
#include <string.h>
#include "doadores.h"
#include <windows.h>
using namespace std;

int qtdRegistro(char *arquivo)
{
    ifstream tmp(arquivo);
    int n = 0;
    if (tmp.good()) //saber se o arquivo n esta corrompido
    {
        tmp.seekg(0, tmp.end);  //movimenta ponteiro
        n = tmp.tellg(); //para dizer pos atual
        tmp.close();
    }
    return n / sizeof(doadores);
}

doadores *carregaArquivo(char *arquivo)
{
    int n = qtdRegistro(arquivo);

    doadores *aux = new doadores[n];
    ifstream entrada(arquivo);

    if (aux != NULL)
    {
        if (entrada.good())
        {
            entrada.read((char *)aux,
                         n* sizeof(doadores));
            entrada.close();
        }
    }

    return aux;
}

void gravaRegistro(char *arquivo, doadores dado)
{
    ofstream saida;
    saida.open(arquivo, fstream::out |
               fstream::app);
    // char *
    saida.write((char *)&dado, sizeof(doadores));

    saida.close();
}

void editaRegistro(char *arquivo, doadores *dado)
{

    int n = qtdRegistro(arquivo);

    ofstream saida;
    saida.open(arquivo);

    saida.write((char *)dado, n*sizeof(doadores));

    saida.close();
}

void sistema()
{
    system("title  Economia Coletiva ");
}

void centralizar(char* texto)
{
    char len;
    len=strlen(texto);

    int pos=(int)((80-len)/2);

    for (int i=0; i<pos; i++)
    {
        cout<< " ";
    }

    cout<<texto;
}

void converteCSV(char *arquivotxt, char *arquivocsv)
{
    doadores *dado = carregaArquivo(arquivotxt);

    int n = qtdRegistro(arquivotxt);

    ofstream saida;
    saida.open(arquivocsv);

    for (int i=0; i<n; i++)
    {
        if(dado[i].disponibilidade==0)
        {
            saida << dado[i].nome <<";"<< dado[i].item <<";DISPONIVEL PARA RETIRADA"<<endl;
        }
        if(dado[i].disponibilidade==1)
        {
            saida << dado[i].nome <<";"<< dado[i].item <<";JA ENTREGUE"<<endl;
        }
    }

    delete[]dado;
    saida.close();
}

void convertCSV(char *arquivotxt, char *arquivocsv)
{
    doadores *dado = carregaArquivo(arquivotxt);

    int n = qtdRegistro(arquivotxt);

    ofstream saida;
    saida.open(arquivocsv);

    for (int i=0; i<n; i++)
    {
        if(dado[i].respondido = 0){
            saida << dado[i].nome <<";"<< dado[i].item <<";PENDENTE"<<endl;
        }

        if(dado[i].respondido = 1){
            saida << dado[i].nome <<";"<< dado[i].item <<";JA RECEBEU"<<endl;
        }
    }

    delete[]dado;
    saida.close();
}

int imprimeDoadores(char *arquivo)
{
    doadores *dado;
    int n = qtdRegistro(arquivo);
    dado = carregaArquivo(arquivo);

    int aux=1;

    for (int i=0; i<n; i++)
    {
        if(dado[i].disponibilidade==0)
        {
            aux=0;
            cout<<strupr(dado[i].nome)<<" | "<<strupr(dado[i].item)<<" | DISPONIVEL PARA RETIRADA\n";
        }
    }

    if(aux==1 || arquivo == NULL)
    {
        centralizar("SEM DOACOES DISPONIVEIS");
        cout<<endl;
        return aux;
    }

    return 0;

    delete[]dado;
}

void imprimePendentes(char *arquivo1,char *arquivo2, char *nome)
{

    int qtdQD = qtdRegistro(arquivo1);
    int qtdQ = qtdRegistro(arquivo2);


    doadores *recebem;
    doadores *doam;

    doam = carregaArquivo(arquivo1);
    recebem = carregaArquivo(arquivo2);

    int aux = 0;

    for(int i=0; i<qtdQD; i++)
    {
        if(strcmp(doam[i].nome, nome)==0 && doam[i].disponibilidade == 0)
        {
            aux++;
            for(int j=0; j<qtdQ; j++)
            {
                if(strcmp(doam[i].item,recebem[j].item)==0 && recebem[j].respondido == 0)
                {
                    cout<<strupr(recebem[j].nome)<<" QUER O(A) "<<strupr(recebem[j].item)<<endl;
                }
            }
        }
    }

    if(aux==0){
        centralizar("SEM PENDENTES");
    }

    delete[]doam;
    delete[]recebem;
}

char encontra(char *onde, char*oque)
{
    char *aux;

    aux = strstr(onde,oque);
    if(aux!=NULL)
    {
        return strlen(onde)-strlen(aux);
    }
    return -1;
}
