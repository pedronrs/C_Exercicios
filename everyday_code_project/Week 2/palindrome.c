//Desenvolver uma função que verifique se uma string s é ou não um palíndromo.
#include <stdio.h>
int palindromo_v( char* s);

int main()
{
    int result;
    char palindromo[] = "ana";
    char naopalindromo[] = "sagradas";
    palindromo_v(palindromo);
    palindromo_v(naopalindromo);
    return 0;
}

int palindromo_v(char* s)
{
    char c;
    int i =0;int size=0;
    while(s[size]){size++;}; //strlen
    int j = size -1;
    while(i < j) //laço comparando primeiro e ultimo digito
    {
        if(s[i] != s[j])
        {
            printf("%s não é palíndromo", s);
            return 0; 
        }
        i++; 
        j--;
    }
    printf("%s é palíndromo", s);
    return 1;
}