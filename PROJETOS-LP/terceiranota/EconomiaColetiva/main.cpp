
#include <iostream>
#include <fstream>
#include "doadores.h"
#include "funsoes.h"
#include <windows.h>

using namespace std;

int main()
{

    int menu;

    sistema();

    while(menu != 0 )
    {

        centralizar("ESCOLHA UMA OPCAO");
        cout<<"\n1:DOAR\n2:SOLICITAR DOACAO\n3:VERIFICAR PENDENTES\n0:SAIR\nESCOLHA: "; //opçoes
        cin>>menu;

        switch(menu)
        {
        case 1: // quando for doar
        {

            doadores doar;

            system("cls");
            fflush(stdin);
            centralizar("SEU NOME");
            cout<<"\nINFORME: ";
            cin.getline(doar.nome,100);

            fflush(stdin);
            cout<<"\n";
            centralizar("SUA DOACAO");
            cout<<"\nINFORME: ";
            cin.getline(doar.item,100);

            doar.disponibilidade = 0;

            gravaRegistro("queremdoar.txt",doar);
            converteCSV("queremdoar.txt","doaram.csv");

            system("cls");

            fflush(stdin);

            cout<<"0:SAIR\n1:VOLTAR AO INICIO\nINFORME A OPCAO: ";

            cin>>menu;

            system("cls");

            break;
        }
        case 2: // quando for escolher o que receber
        {
            system("cls");
            doadores querem;

            if(imprimeDoadores("queremdoar.txt")==0)
            {

                fflush(stdin);
                cout<<"\n";
                centralizar("SEU NOME");
                cout<<"\nINFORME: ";
                cin.getline(querem.nome,100);

                fflush(stdin);
                cout<<"\n";
                centralizar("O QUE QUER");
                cout<<"\nINFORME: ";
                cin.getline(querem.item,100);

                querem.respondido = 0;

                gravaRegistro("querem.txt",querem);
                convertCSV("querem.txt","doaram.csv");


                system("cls");

                cout<<"0:SAIR\n1:VOLTAR AO INICIO\nINFORME A OPCAO: ";

                cin>>menu;

                system("cls");

                break;
            }
            else
            {

                system("pause");
                system("cls");

                break;
            }
        }
        case 3:
        {
            system("cls");

            doadores pendente;
            char resposta[100];

            int qtdQ = qtdRegistro("querem.txt");
            int qtdQD = qtdRegistro("queremdoar.txt");

            doadores *recebem;
            doadores *doam;

            recebem = carregaArquivo("querem.txt");
            doam = carregaArquivo("queremdoar.txt");

            fflush(stdin);
            centralizar("SEU NOME");
            cout<<"\nINFORME: ";
            cin.getline(pendente.nome,100);

            system("cls");

            imprimePendentes("queremdoar.txt","querem.txt",pendente.nome);

            fflush(stdin);
            cout<<"\n";
            centralizar("DESTINATARIO DA DOACAO");
            cout<<"\nINFORME (OU DIGITE SAIR): ";

            cin.getline(resposta,100);

            if(strcmp(resposta,"sair")==0)
            {
                system("cls");

                break;
            }
            else
            {
                for(int i=0; i<qtdQ; i++)
                {
                    if(strcmp(recebem[i].nome,resposta)==0)
                    {
                        for(int j=0; j<qtdQD; j++)
                        {
                            if(strcmp(recebem[i].item,doam[j].item)==0)
                            {
                                doam[j].disponibilidade = 1;
                                recebem[i].respondido = 1;
                            }
                        }
                    }
                }

                editaRegistro("queremdoar.txt",doam);
                converteCSV("queremdoar.txt","doaram.csv");
                editaRegistro("querem.txt",recebem);
                convertCSV("querem.txt","recebem.csv");

                delete[]recebem;
                delete[]doam;

                system("cls");

                fflush(stdin);

                cout<<"0:SAIR\n1:VOLTAR AO INICIO\nINFORME A OPCAO: ";

                cin>>menu;

                system("cls");

                break;

            }
        }
        }
    }

    return 0;
}
