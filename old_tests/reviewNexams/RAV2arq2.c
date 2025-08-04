#include <stdio.h>
#include <limits.h> //INT_MIN INT_MAX

int intersecao(char* nomeArqA, char* nomeArqB, char* nomeArqC);

void main()
{
    char nomeArquivoA[30],char nomeArquivoB[30],char nomeArquivoC[30];

    printf("Nome do arquivo A: ");
    gets(nomeArquivoA);
    
    printf("Nome do arquivo B: ");
    gets(nomeArquivoB);
    
    printf("Nome do arquivo C: ");
    gets(nomeArquivoC);

    if(intersecao(nomeArquivoA, nomeArquivoB, nomeArquivoC) == 1){
        printf("Arquivo gerado com sucesso.");
    }else{
        printf("Erro na geração do arquivo");
    }
}


int intersecao(char* nomeArqA, char* nomeArqB, char* nomeArqC){
    FILE *arqA, *arqB, *arqC;
    int fimA, fimB, fimC;

    arqA = fopen(nomeArqA, "r");
    arqB = fopen(nomeArqB, "r");
    arqC = fopen(nomeArqC, "w");

    if(!arqA || !arqB || !arqC){
        fclose(arqA);
        fclose(arqB);
        fclose(arqC);
        return 0;
    }
    else{
        fimA = 0;
        fimB = 0;

        if(fscanf(arqB, "%d", &valorB)==EOF){
            fimB = 1;
        }
    }
}



// Faça uma função que, dado um arquivo A contendo números reais, um por linha, crie um novo arquivo B 
// contendo os mesmos elementos de A, porém ordenados decrescentemente e sem repetição.
// Arquivos

int gerarArqOrd(char *nomeArqA, char nomeArqB*);

int determinarMaiorValor(char *nomeArq, float limite, float *valor);


void main(){
    char nomeArqA[30], nomeArqB[30];
    printf("Nome Arquivo A: ");
    gets(nomeArqA);

    printf("Nome Arquivo B: ");
    gets(nomeArqB);


    // se conseguir gerar o arquivo
    if(gerarArqOrd(nomeArqA, nomeArqB) == 1){
        printf("\n\nArquivo %s gerado com sucesso.", nomeArqB);
    }
    else{
        printf("\n\nArquivo %s falhou.", nomeArqB);
    }
}

int gerarArqOrd(char *nomeArqA, char nomeArqB*){
    FILE *arqB;
    float limite, valor;

    arqB = fopen(nomeArqB, "w");

    if(!arqB){
        return 0;
    }else{
        limite = INT_MAX;
        // enquanto houver valores em A
        while(determinarMaiorValor(nomeArqA, limite, &valor)== 1){
            fprintf(arqB, "%.1f\n", valor);

            limite = valor;
        }
        fclose(arqB);

        return 1;
    }

}

int determinarMaiorValor(char *nomeArq, float limite, float *valor){
    FILE *arq;
    float numero, maior, alterouMaior;

    arq = fopen(nomeArq, "r");

    if(!arq){
        return -1;
    }else{
        maior = INT_MIN;
        alterouMaior = 0;

        while(fscanf(arq, "%f", &numero)!= EOF){
            if(numero < limite){
                if(numero > maior){
                    maior = numero;
                    alterouMaior = 1;
                }
            }
        }
        fclose(arq);

        if(alterouMaior == 1){
            *valor = maior;

            return 1;
        }
        return 0;
    }
}
