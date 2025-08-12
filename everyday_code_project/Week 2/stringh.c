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
    for(i = 0;s2[i] != '\0'; i++)
    {
        s1[i] = s2[i];
    }
    s1[i] = '\0';    
}

//Escreva a função strcmp do <string.h>
int strcmp( char* s1, char* s2)
{
    int i;
    for(i = 0; s1[i] || s2[i]; i++)
    {
        if(s1[i] > s2[i])
        {
            return 1;
        }
        if(s1[i] < s2[i])
        {
            return -1;
        }
    }
    return 0;
}

//Escreva a função strcat do <string.h>
void strcat( char* s1, char* s2)
{
    int i;
    int size = strlen(s1);
    for(i = 0; s2[i] != '\0'; i++)
    {
        s1[size] = s2[i]; 
    }
    s2[i] = '\0';
} 