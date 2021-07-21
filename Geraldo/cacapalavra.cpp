#include <iostream>
#include <string.h>

using namespace std;

/**
funcao busca a string oque na string onde
 param onde: string
 param oque: string
 return local na string onde começa a string oque, -1 caso contrário
*/
int encontra(char *onde, char *oque);

int main() {
    char **caca, **caca_transp, palavra[100] = {""};
    int i,j;
    int n, local;

    cout << "Digite o tamanho do caça-palavra: ";
    cin >> n;

    caca = new char *[n];
    caca_transp = new char *[n];
    if (caca == NULL) return 0;
    for (i=0; i<n; i++) {
        caca[i] = new char[n];
        caca_transp[i] = new char[n];
        //implemente a volta
    }

    cout << "Informe o caça palavras:\n";
    for (i=0; i<n; i++)
        cin >> caca[i];

    //calculando transposta da matriz
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            caca_transp[j][i] = caca[i][j];

    for (i=0; i<n; i++)
        cout << caca[i] << " | " << caca_transp[i] << endl;

    cout << "Digite a palavra: ";
    cin  >> palavra;

    while (strcmp (palavra, "sair")!=0) {
        for (i=0; i<n; i++) {
            //procurando nas linhas
            local = encontra(caca[i], palavra);
            if (local >= 0)
                cout << "Encotrada na linha " << i +1 <<
                    " coluna " << local +1 << "\n";

            //procurando nas colunas
            local = encontra(caca_transp[i], palavra);
            if (local >= 0)
                cout << "Encotrada na coluna " << i +1 <<
                    " linha " << local +1 << "\n";
        }

        cout << "Digite a palavra (ou sair): ";
        cin  >> palavra;
    }

    for (i=0; i<n; i++) {
        delete []caca[i];
        delete []caca_transp[i];
    }
    delete []caca;
    delete []caca_transp;

}

int encontra(char *onde, char *oque){
    char *aux;
    if ((onde == NULL) || (oque == NULL))
        return -1;

    aux = strstr(onde, oque);
    if (aux != NULL) {
        return strlen(onde) - strlen(aux);
    }
    return -1;
}
