#include <stdio.h>
int contarCaracteres(char *nomeArq);

int main (void){
    char nomeArquivo[30];
    int resposta;

    printf("NOME DO ARQUIVO: ");
    gets(nomeArquivo);

    resp = contarCaracteres(nomeArquivo);

    switch(resp){
        case -1 : printf("Erro ao abrir o arquivo %s.", nomeArquivo);
        break;

        case 0: printf("O arquivo %s está vazio.", nomeArquivo);

        case 1: printf("Há %d caracteres no arquivo %s.", resp, nomeArquivo);
    }
}

int contarCaracteres(char *nomeArq){
    FILE *arq;
    int cont = 0;
    char ch;

    arq = fopen(nomeArq, "r");

    if(!arq){
        return -1;
    }
    while(fscanf(arq,"%c",&ch)!= EOF){
        cont++;
    }
    fclose(arq);
    return cont;
}

