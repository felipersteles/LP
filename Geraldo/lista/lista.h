#ifndef _LISTA_

#define _LISTA_

#include "aluno.h"
typedef struct _lista_ {
    aluno *dado;
    struct _lista_ *prox;
}lista;

lista *criar(aluno *dado);

int inserir(lista **cab, aluno *dado);

void imprimir(lista *cab);
//não implementados
aluno *buscar(lista *cab, char *criterio);

lista *buscarTodos(lista *cab, char *criterio);

aluno *remover(lista **cab, char *criterio);

void limpar(lista **cab);

aluno *listaPos(lista *cab, int pos);

#endif
