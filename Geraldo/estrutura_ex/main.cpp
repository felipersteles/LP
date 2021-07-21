#include <stdlib.h>
#include <iostream>
#include "aluno.h"

using namespace std;

int main() {
    Aluno *alunos;
    int n, i, op = -1, res;
    char buscaNome[100];
    long buscaMatricula;


    //1: alocar alunos
    cout << "Informe qtd alunos:";
    cin >> n;
    alunos = new Aluno[n];

    //2:preencher alunos
    for (i=0; i<n; i++) {
        cin.ignore(1);
        cout << "Nome[" << i+1 << "]:";
        //gets
        //scanf("%[^\n]", alunos[i].nome)
        cin.getline(alunos[i].nome, 100);

        cin.ignore(0);
        cout << "Matricula[" << i+1 << "]:";
        cin >> alunos[i].matricula;

        cin.ignore(1); //fflush(stdin)
        cout << "Curso[" << i+1 << "]:";
        cin.getline(alunos[i].curso, 30);

    //    cout << alunos[i].nome << alunos[i].matricula << alunos[i].curso;
    }

    system("cls");

    //3:permitir busca
    while (op != 0) {
        cout << "Menu:\n1:buscar por nome\n2:buscar por matricula\n0:sair\nDigite opcao: ";
        cin >> op;
        switch (op){
            case 1:
                cin.ignore(1);
                cin.getline(buscaNome, 100);
                res = buscarPorNome(alunos, n, buscaNome);
                if (res >=0) {
                    cout << "Achei";
                }
                else {
                    cout << "N achei";
                }
                break;
            case 2:
                cin >> buscaMatricula;
                res = buscarPorMatricula(alunos, n, buscaMatricula);
                if (res >=0) {
                    cout << "Achei";
                }
                else {
                    cout << "N achei";
                }
                break;
            default:
                cout << "1 por nome,\n2 por matricula\n 0 sai";
        }
        system("pause");
        system("cls");


    }


    delete []alunos;

}

