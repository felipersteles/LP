#include <iostream>
#include <string.h>
using namespace std;

char encontra(char *onde, char*oque);

int main()
{
    char *frase;
    char T[100];
    char palavra[20];
    char subs[20];
    char *aux;

    int n;

    cout<<"Digite a frase T\n";
    cin.getline(T,100);

    n = strlen(T);
    frase = new char[n];
    strcpy(frase,T);

    cout<<"Digite a palavra A\n";
    cin>>palavra;
    cout<<"Digite a nova palavra B\n";
    cin>>subs;

    int i,local;

    for(i=0; i<strlen(T); i++)
    {
        local = encontra(frase,palavra);
        if(local>=0)
        {
            aux = strstr(frase,palavra);
            strcpy(aux,subs);
        }
    }

    cout<<endl<<frase;

    delete[]frase;

    return 0;
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
