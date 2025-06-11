#include <stdio.h>
#define MAX_CURSOS 100

typedef struct{
    int codigo_Curso;
    float nota_Enade;
    float num_IDD;
    float num_Doutores;
    float num_Mestres;
    float regime_Trabalho;
    float org_DPedagogica;
    float infraestrutura;
    float op_AmpliacaoAcadProf;
    int num_Alunos;

    float cpcContinuoCalculado;
    int cpcFaixaCalculado;
}TCurso;


float calculoCPCContinuo(TCurso curso){
    const float pesos[8] = {0.20, 0.35, 0.15, 0.075, 0.075, 0.075, 0.05, 0.025};
    const float notas[8] = {
        curso.nota_Enade,
        curso.num_IDD,
        curso.num_Doutores,
        curso.num_Mestres,
        curso.regime_Trabalho,
        curso.org_DPedagogica,
        curso.infraestrutura,
        curso.op_AmpliacaoAcadProf
    };
    float cpc_Cont = 0.0;
    int i;

    for (i = 0; i < 8; i++) {
        cpc_Cont += notas[i] * pesos[i];
    }
    return cpc_Cont;
}


int determinarFaixa(float cpc) {
    if (cpc < 0.945) {
        return 1;
    } else if (cpc < 1.945) {
        return 2;
    } else if (cpc < 2.945) {
        return 3;
    } else if (cpc < 3.945) {
        return 4;
    } else { 
        return 5;
    }
}


int cadastraCurso(char *nomeArq, TCurso cursos[]){
    // declarando variáveis
    FILE *arq;
    int indiceV = 0;

    // tentando abrir o arquivo
    arq = fopen(nomeArq, "r");
    
    // tratamento de erros
    if(!arq){
        printf("Não foi possível abrir esse arquivo.");
        return -1; 
    }

    //Enquanto o arquivo tiver 10 leituras para serem feitas nas suas linhas sequentes ele irá alterar o índice para a nova leitura até o fim do arquivo.

    while(indiceV < MAX_CURSOS && fscanf(arq, "%d|%f|%f|%f|%f|%f|%f|%f|%f|%d",
      &cursos[indiceV].codigo_Curso,
      &cursos[indiceV].nota_Enade,
      &cursos[indiceV].num_IDD,
      &cursos[indiceV].num_Doutores,
      &cursos[indiceV].num_Mestres,
      &cursos[indiceV].regime_Trabalho,
      &cursos[indiceV].org_DPedagogica,
      &cursos[indiceV].infraestrutura,
      &cursos[indiceV].op_AmpliacaoAcadProf,
      &cursos[indiceV].num_Alunos) == 10)
      {
          indiceV++;
      }
    fclose(arq);
    //  indiceV irá retornar a quantidade de cursos inscritos na instituição para ser feita a média entre os cursos
    return indiceV;

}



float calculaIGC(TCurso cursos[], int num_cursos){
    float somaCPC = 0;
    
    int somaAlunos = 0;
    
    // tratamento de erros (caso não haja cursos para serem calculados.)
    if(!num_cursos){
        return 0;
    }

    for(int i= 0; i < num_cursos; i++){
        somaCPC += cursos[i].cpcContinuoCalculado * cursos[i].num_Alunos;
        somaAlunos += cursos[i].num_Alunos;      
    }

    if(!somaAlunos){
        return 0;
    }

    return somaCPC / somaAlunos;

}


void exibirRelatorio(TCurso cursos[], int num_cursos){
    int i;
    for(i = 0; i < num_cursos; i++){
        printf("Curso Codigo: %d\n", cursos[i].codigo_Curso);
        printf("  - CPC Continuo: %.4f\n", cursos[i].cpcContinuoCalculado);
        printf("  - CPC Faixa:    %d\n", cursos[i].cpcFaixaCalculado);
        printf("  - Situacao:     %s\n", (cursos[i].cpcFaixaCalculado < 3) ? "Insatisfatorio" : "Satisfatorio");
    }
}


int main() {
    TCurso cursos[MAX_CURSOS];
    int numCursosLidos;
    int i;
    float igc_instituicao;
    char nome_arquivo[100]; 

    // perguntar para o usuário o arquivo a ser lido 
    printf("Digite o nome do arquivo de dados a ser lido (ex: cursos.txt): ");
    fgets(nome_arquivo, sizeof(nome_arquivo), stdin);

    // verificando se o arquivo existe e é não nulo
        i = 0;
    while (nome_arquivo[i] != '\0') {
        if (nome_arquivo[i] == '\n') {
            nome_arquivo[i] = '\0';
            break; 
        }
        i++;
    }

    numCursosLidos = cadastraCurso(nome_arquivo, cursos);

    if (numCursosLidos <= 0) {
        printf("Encerrando o programa.\n");
        return 1;
    }
    
    printf("\n%d cursos foram lidos com sucesso do arquivo '%s'.\n", numCursosLidos, nome_arquivo);

    for (i = 0; i < numCursosLidos; i++) {
        cursos[i].cpcContinuoCalculado = calculoCPCContinuo(cursos[i]);
        cursos[i].cpcFaixaCalculado = determinarFaixa(cursos[i].cpcContinuoCalculado);
    }

    exibirRelatorio(cursos, numCursosLidos);

    igc_instituicao = calculaIGC(cursos, numCursosLidos);
    printf("\n>>> Indice Geral de Cursos (IGC) da Instituicao: %.4f\n", igc_instituicao);

    return 0;
}
