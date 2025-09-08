#include <stdio.h>
//faça uma função que dada uma matriz M mxn de reais, gere a matriz M^t, sua transposta

//Uma matriz transposta é obtida invertendo as linhas pelas colunas da matriz original, sendo portanto cada elemento da linha l  e coluna c na matriz original passa a posição c e l na transposta.

void mat_transp(int lin, int col, float matriz[lin][col], float transposta[col][lin]//sendo a transposta tendo suas ordens mxn trocadas para nxm)
{
    int i,j;
    for(i=0; i < lin; i++)
    {
        for(j=0; j < col; j++)
        {
            transposta[j][i] = matriz[i][j]; //inverte-se os índices para trocar os elementos.
        }
    }
}

//Desenvolver uma função que verifique se um número x se encontra na linha L da matriz M mxn.

int x_in_mat(int lin, int col, int matriz[lin][col], int x, int l) //considerando l como válido.
{
    int j;
    for(j=0; j < col; j++)
    {
        if(x == matriz[l][j]){return 1;}//quando x é encontrado na linha l.
    }
    return 0;
}

//Desenvolver uma função que gere uma matriz M nxn' onde os termos são os valores de 1 + a ordem (i+j+1). 
/*EXEMPLO
M 5x5:

1   2   3   4   5
2   3   4   5   6
3   4   5   6   7
4   5   6   7   8
5   6   7   8   9
*/

void mat_nxn(int ordem, int matriz[ordem][ordem])
{
    int i,j;
    for(i=0; i < ordem; i++)
    {
        for(j=0; j < ordem; j++)
        {
            matriz[i][j] = i+j + 1;
        }
    }
}

//Fazer uma função que determine se a matriz M nxn' é simétrica.


//uma matriz quadrada é determinada simétrica se sua transposta compõe os mesmos termos.

int mat_sim(int ordem, int matriz[ordem][ordem])
{
    int i, j; 
    for(i=0; i < ordem; i++)
    {
        for(j=i+1; j < ordem; j++) //j = i+1 para contemplar apenas o triângulo inferior com o superior
        {
            if(matriz[i][j] != matriz[j][i]){return 0;}
        }
    }
    return 1;
}

//Implementar uma função que dada uma matriz M mxn, gere um vetor V de tamanho n, onde cada elemento do vetor consiste na soma dos elementos de uma coluna de M. Ou seja, o elemento v[0] consiste na soma dos elementos da primeira coluna de M , o elemento v[1] consiste na soma dos elementos da segunda coluna de M, e assim por diante.

















//Considere uma loja que mantém em uma matriz o total vendido por cada funcionário por todos os meses do ano (tendo portanto 12 linhas e 10 colunas sendo as colunas os 10 funcionários). Pede-se o desenvolvimento de uma função para cada item abaixo
/*
a. Calcular o total vendido durante o ano;

b. Dado um mês fornecido pelo usuáriom determinar o total vendido nesse mês.

c. Dado um funcionário fornecido pelo usuário, determinar o total vendido por ele durante o ano;

d. Determinar o mês com maior índice de vendas;

e. Determinar o funcionário que menos vendeu durante o ano.
*/