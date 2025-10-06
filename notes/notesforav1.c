//STRUCTS 
#include <stdio.h>

typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;
//PREENCHIMENTO DE UM VETOR DE STRUCTS VIA TECLADO
void preencherProdutos(Produto vet[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        printf("--- Produto %d ---\n", i + 1);
        printf("Digite o ID: ");
        scanf("%d", &vet[i].id);
        
        printf("Digite o Nome: ");
        scanf(" %[^\n]", vet[i].nome);
        
        printf("Digite o Preco: ");
        scanf("%f", &vet[i].preco);
    }
}
//BUSCA DE UM PRODUTO POR ID EM UM VETOR
int buscarProdutoPorId(Produto vet[], int tam, int idBusca) {
    int i;
    for (i = 0; i < tam; i++) {
        if (vet[i].id == idBusca) {
            return i;
        }
    }
    return -1;
}

//EXIBIÇÃO FORMATADA DOS DADOS DE UM VETOR DE STRUCTS
void exibirProdutos(Produto vet[], int tam) {
    int i;
    printf("\n--- Lista de Produtos ---\n");
    printf("%-5s | %-20s | %s\n", "ID", "Nome", "Preco (R$)");
    printf("------------------------------------------\n");
    for (i = 0; i < tam; i++) {
        printf("%-5d | %-20s | %.2f\n", vet[i].id, vet[i].nome, vet[i].preco);
    }
}

//MATRIZES
#define LIN 10
#define COL 10

//EXIBIR MATRIZ PARA TESTE
void exibirMatriz(int M[][COL], int numLin, int numCol) {
    int i, j;
    for (i = 0; i < numLin; i++) {
        for (j = 0; j < numCol; j++) {
            printf("%4d\t", M[i][j]);
        }
        printf("\n");
    }
}

//SOMA DOS ELEMENTOS DE UMA COLUNA ESPECÍFICA DA MATRIZ
int somarColunaMatriz(int M[][COL], int numLin, int indiceColuna) {
    int i;
    int soma = 0;
    if (indiceColuna >= COL || indiceColuna < 0) {
        return 0;
    }
    for (i = 0; i < numLin; i++) {
        soma = soma + M[i][indiceColuna];
    }
    return soma;
}

//TROCAR POSIÇÃO ENTRE DUAS LINHAS DA MATRIZ 
void trocarLinhasMatriz(int M[][COL], int numCol, int linhaA, int linhaB) {
    int j, temp;
    if (linhaA >= LIN || linhaB >= LIN || linhaA < 0 || linhaB < 0) {
        return;
    }
    for (j = 0; j < numCol; j++) {
        temp = M[linhaA][j];
        M[linhaA][j] = M[linhaB][j];
        M[linhaB][j] = temp;
    }
}

//STRINGS
#include <string.h>

//OCORRÊNCIAS DE UM CHAR EM UMA STRING 
int contarCaractere(char str[], char caractere) {
    int i = 0;
    int contador = 0;
    while (str[i] != '\0') {
        if (str[i] == caractere) {
            contador++;
        }
        i++;
    }
    return contador;
}

//CONVERSÃO DE TODOS OS CHARS DE UMA STRING PARA MAIÚSCULO
void paraMaiusculo(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        i++;
    }
}

//VERIFICADOR DE EXISTÊNCIA DE UMA SUBSTRING
int buscaSubstring(char texto[], char sub[]) {
    int i, j, k;
    int tamTexto = strlen(texto);
    int tamSub = strlen(sub);

    if (tamSub > tamTexto) {
        return 0;
    }

    for (i = 0; i <= tamTexto - tamSub; i++) {
        k = i;
        j = 0;
        while (texto[k] == sub[j] && sub[j] != '\0') {
            k++;
            j++;
        }
        if (sub[j] == '\0') {
            return 1;
        }
    }
    return 0;
}

// FUNCOES GERAIS 
// OBTEM STATUS DO ALUNO ENTRE 3 ESCOLHAS 
int obterStatusAluno(float notaAV1, float notaAV2) {
    float media = (notaAV1 + notaAV2) / 2.0;
    
    if (media >= 7.0) {
        return 1; // Aprovado
    } else if (media >= 4.0) {
        return 3; // Em Avaliação Final
    } else {
        return 2; // Reprovado
    }
}

// SOMA DA DIAGONAL PRINCIPAL NUMA MATRIZ
int somarDiagonalPrincipal(int M[][DIM], int dim) {
    int i;
    int soma = 0;
    for (i = 0; i < dim; i++) {
        soma += M[i][i];
    }
    return soma;
}

//VERIFICADOR DE VOGAIS
int ehLetraVogal(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return 1;
    }
    return 0;
}

//COPIA SUBSTRING A PARTIR DO TAMANHO E INICIO
void copiarSubstring(char destino[], char origem[], int inicio, int tamanho) {
    int i, j = 0;
    for (i = inicio; i < inicio + tamanho && origem[i] != '\0'; i++) {
        destino[j] = origem[i];
        j++;
    }
    destino[j] = '\0';
}

//VERIFICA ANAGRAMAS
int saoAnagramas_Busca(char s1[], char s2[]) {
    int i, j;
    int encontrou;
    
    int tam1 = strlen(s1);
    int tam2 = strlen(s2);

    if (tam1 != tam2) {
        return 0;
    }

    char s2_copia[100];
    strcpy(s2_copia, s2);

    for (i = 0; i < tam1; i++) {
        encontrou = 0;
        for (j = 0; j < tam2; j++) {
            if (s1[i] == s2_copia[j]) {
                encontrou = 1;
                s2_copia[j] = '\0'; 
                break;
            }
        }
        if (encontrou == 0) {
            return 0;
        }
    }

    return 1;
}
