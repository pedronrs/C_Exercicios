//Desenvolver uma função que verifique se uma string s é ou não um palíndromo.
#include <stdio.h>
int palindromo_v( char* s);

int main()
{
    char palindromo[] = "ana";
    char naopalindromo[] = "sagradas";
    palindromo_v(palindromo);
    palindromo_v(naopalindromo); 
    return 0;
}

int palindromo_v(char* s)
{
    char c;
    int i,size=0;
    while(s[size]){size++;}; //strlen
    int j = size -1;
    while(i < j)
    {
        if(s[i] != s[j])
        {
            return 0; // não é palíndromo
        }
        i++;
        j--;
    }
    return 1;
}