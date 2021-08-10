
int qtdRegistro(char *arquivo);

doadores *carregaArquivo(char *arquivo);

void gravaRegistro(char *arquivo, doadores dado);

void editaRegistro(char *arquivo, doadores*dado);

void sistema();

void centralizar(char* texto);

void converteCSV(char *arquivotxt, char *arquivocsv);

void convertCSV(char *arquivotxt, char *arquivocsv);

char encontra(char *onde, char*oque);

int imprimeDoadores(char *arquivo);

void imprimePendentes(char *arquivo1,char *arquivo2, char *nome);
