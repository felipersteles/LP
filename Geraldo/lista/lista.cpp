#include "lista.h"
#include <iostream>
#include <string.h>

using namespace std;

lista *criar(aluno *dado) {
    lista *novo = new lista[1];
    if (novo!=NULL) {
        novo->dado = dado;
        novo->prox = NULL;
    }
    return novo;
}
int inserir(lista **cab, aluno *dado) {
    //inserir um novo no na lista
    //1) considerar sempre no inicio
    lista *novo = criar(dado);
    if (novo == NULL) return 0; //deu erro
    if (*cab == NULL) { //lista vazia
        *cab = novo;
    }
    else { //lista não vazia
        novo->prox = *cab;
        *cab = novo;
    }

    return 1;
}

aluno *remover(lista **cab, char *criterio) {
    //3 CASOS: do inicio, do meio e do fim

    //ache o camarada -> atualizar os ponteiros
    if (*cab == NULL) return NULL;

    //ta na cabeça?
    lista *atual = *cab;
    lista *back, *ant;
    aluno *ret_dado;

    if (strcmp (atual->dado->nome, criterio) == 0) {
        back = *cab;  //backup da cab
        ret_dado =atual->dado;  //backup do aluno
        *cab = atual->prox; //atualiza cab
        delete []atual; //remove elemento
        return ret_dado; //devolve aluno
    }
    //tirando do meio ou do fim
    else {
        while (atual->prox != NULL) {
            ant = atual;
            atual = atual->prox;

            if (strcmp (atual->dado->nome, criterio) == 0) {
                back = atual;  //backup do atual
                ret_dado =atual->dado;  //backup do aluno
                ant->prox = atual->prox; //atualiza anterior
                delete []atual; //remove elemento
                return ret_dado; //devolve aluno
            }
        }
    }



}

aluno *buscar(lista *cab, char *criterio) {
    lista *tmp = cab;
    while (tmp != NULL) {
        if (tmp->dado != NULL)
            if (strcmp(tmp->dado->nome, criterio) == 0)
                return tmp->dado;
    }
    return NULL;
}

lista *buscarTodos(lista *cab, char *criterio) {
    lista *tmp = cab;
    lista *resp = NULL;
    while (tmp != NULL) {
        if (tmp->dado != NULL)
            if (strcmp(tmp->dado->nome, criterio) == 0)
                inserir(&resp, tmp->dado);
    }
    return resp;
}

void imprimir(lista *cab) {
    lista *tmp = cab;
    cout << "Na lista: " << endl;
    while (tmp != NULL) {
        if (tmp->dado != NULL)
            cout << tmp->dado->nome << ":" <<
                    tmp->dado->mat << endl;

        tmp = tmp->prox;
    }


}
