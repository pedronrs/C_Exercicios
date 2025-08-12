#include <stdio.h>

//Escreva a função strlen do <string.h>

int strlen(char* s)
{
    int i;
    for(i = 0; s[i] != '\0'; i++); //Enquanto a condição for satisfeita o i vai incrementar.
    return i;
}
//Escreva a função strcpy do <string.h>

void strcpy( char* s1, char* s2)
{
    int i; 
    // o laço for percorre a string até encontrar o fim e incrementa o índice i.
    for(i = 0;s2[i] != '\0'; i++)
    {
        s1[i] = s2[i]; // cópia do caractere da sequência.
    }
    s1[i] = '\0';  //finaliza a string após a cópia.
}

//Escreva a função strcmp do <string.h>
int strcmp( char* s1, char* s2)
{
    int i;
    //somente quando as duas strings tiverem encontrado o fim ele vai parar de comparar.
    for(i = 0; s1[i] || s2[i]; i++)
    {
        if(s1[i] > s2[i])
        {
            return 1; // condição onde s2 tem prioridade alfabética. 
        }
        if(s1[i] < s2[i])
        {
            return -1; // condição onde s1 tem prioridade alfabética.
        }
    }
    return 0;
}

//Escreva a função strcat do <string.h>
void strcat( char* s1, char* s2)
{
    int i;
    int size = strlen(s1); //  garante que s2 comece a ser escrita em s1 assim que ela encontra o fim. 
    for(i = 0; s2[i] != '\0'; i++)
    {
        s1[size] = s2[i];
        size++; 
    }
    s1[size] = '\0';
} //sem strlen seria: int size=0 while(s1[size] != '\0'){ size++; }