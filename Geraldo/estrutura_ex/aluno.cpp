#include "aluno.h"
#include <string.h>
int buscarPorNome(Aluno *vet, int n,
                  char *busca)
{
    int i;

    for (i=0; i<n; i++)
        if (strcmp (vet[i].nome, busca) == 0)
            return i;

    return -1;
}
int buscarPorMatricula(Aluno *vet, int n,
                  long busca)
{
    int i;

    for (i=0; i<n; i++)
        if (vet[i].matricula == busca)
            return i;

    return -1;
}

