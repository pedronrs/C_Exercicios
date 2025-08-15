//Desenvolver uma função que remova todas as ocorrências de um char em uma string.
#include <stdio.h>
//método adotado: reescrever a string sem os caracteres com dois índices no array.
void remove_ch(char* s, char c);

int main()
{
    char ch[30] = "\naaataaaaeaaasaaataaaea\n"; //teste
    printf("%s",ch);
    remove_ch(ch,'a'); //caracter único é passado como aspas simples 
    printf("%s",ch);
    return 0;
}

void remove_ch( char* s, char c)
{
    int j=0; int i=0;
    while(s[i])
    {
        if(s[i]!=c) //dessa forma só copiaremos os caracteres que não sejam "c".
        {
            s[j++] = s[i]; 
        }
        i++;
    }
    s[j] = '\0';//fecha a string com caracter nulo após todas as iterações
}

