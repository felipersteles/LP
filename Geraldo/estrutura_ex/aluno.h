#ifndef _ALUNO_
#define _ALUNO_
typedef struct _ALUNO_ {
    char nome[100];
    long matricula;
    char curso[30];
}Aluno;

int buscarPorNome(Aluno *vet, int n,
                  char *busca);
int buscarPorMatricula(Aluno *vet, int n,
                  long busca);
#endif
