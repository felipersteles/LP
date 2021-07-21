#include <iostream>
#include "lista.h"
#include "aluno.h"

using namespace std;

int main() {
    lista *elementos = NULL;
    aluno *tmp;
    int i=0;
    char criterio[100];

    while (i<3) {
        tmp = new aluno[1];
        cin >> tmp->nome >> tmp->mat;
        inserir(&elementos, tmp);
        imprimir(elementos);
        i++;
    }

    while (1) {
        cin >> criterio;
        tmp = remover(&elementos, criterio);
        delete []tmp;
        imprimir(elementos);
    }
}

/*
int mainadaptado(){

    doadores doador;
    doadores receptor;
    doadores pendente;

    int qtdD;//quantidade de doadores

    int i,j;
    int local;

    int menu = -1;
    while(menu!=0)
    {
        centralizar("TEM INTERESSE EM:");
        cout<<endl<<"1:DOAR\n2:RECEBER\n3:PENDENTES\n0:SAIR\nESCOLHA A OPCAO: ";

        cin >> menu;

        switch (menu)
        {
        case 1:
        {

            system("cls");

            fflush(stdin);
            centralizar("DIGITE SEU NOME: ");
            cin.getline(doador.nome,100);

            system("cls");

            fflush(stdin);

            cout<<"\nINFORME A DOACAO: ";
            cin.getline(doador.item,100);

            doador.disponibilidade = 0;

            gravaRegistro("queremdoar.txt",doador);

            system("cls");
            centralizar("OBRIGADO POR DOAR. SUA DOACAO FAZ O BEM ACONTECER!");

            cout<<"\n0:SAIR\n1:VOLTAR AO INICIO\nINFORME A OPCAO: ";
            cin>>menu;


            system("cls");
            break;
        }

        case 2:
        {

            system("cls");

            fflush(stdin);
            centralizar("DIGITE SEU NOME: ");
            cin.getline(receptor.nome,100);

            system("cls");
            centralizar("ITENS DISPONIVEIS:");

            int qtd = qtdRegistro("queremdoar.txt");

            imprimeCSV("queremdoar.txt",qtd);

            cout<<endl<<endl;
            centralizar("O QUE ALMEJA?");
            cout<<"\nINFORME: ";

            fflush(stdin);
            cin.getline(receptor.item,100);

            doadores *vaux = carregaArquivo("queremdoar.txt",qtd);

            for(i=0; i<qtd; i++)
            {
                local = encontra(vaux[i].item,pendente.item);

                if((local>=0))
                {
                    vaux[i].disponibilidade = 1;
                }

            }

            editaRegistro("queremdoar.txt",vaux);

            gravaCSV("queremdoar.txt","doaram.csv");
            delete[]vaux;



            system("cls");
            centralizar("BOA SORTE NA ESPERA");

            cout<<"\n0:SAIR\n1:VOLTAR AO INICIO\nINFORME A OPCAO: ";
            cin>>menu;
            break;
        }
        case 3:
        {
            system("cls");
            fflush(stdin);
            centralizar("DIGITE SEU NOME: ");
            cin.getline(pendente.nome,100);


            break;

        }
        break;
        }
    }


}*/
