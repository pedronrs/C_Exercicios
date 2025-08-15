//Desenvolver uma função que remova todas as ocorrências de um char em uma string.
#include <stdio.h>

//método adotado: reescrever a string sem os caracteres num array auxiliar
int num_removes_char( char* s, char c)
{
    int size=0;int j=0; int i=0;
    while(s[size])
    {size++;}
    char s_aux[size+1]; //+1 caracter nulo

    while(s[i])
    {
        if(s[i]!=c)
        {
            s_aux[j++] = s[i];
            
        }
        i++;
    }
    s_aux[j] = '\0';
    return j;
}


int main()
{
    return 0;
}

