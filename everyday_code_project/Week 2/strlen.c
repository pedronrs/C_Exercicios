//Escreva a função strlen do <string.h>

int strlen(char* s)
{
    int i;
    for(i = 0; s[i] != '\0'; i++); //Enquanto a condição for satisfeita o i vai incrementar.
    return i;
}
