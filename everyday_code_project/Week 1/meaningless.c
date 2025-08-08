/*Implementar uma função que dado um número inteiro N, exiba uma sequência de números como as ilustradas no exemplo a seguir:
- Exemplo N = 3 :  (1 2)(1 3)(2 1)(2 3)(3 1) (3 2)*/
#include <stdio.h>

void meaningless_function(int n);

int main()
{
    int n = 5;
    meaningless_function(n);
    return 0;
}


void meaningless_function(int n)
{
    if( n < 2)
    {
        printf("O valor de N não pode ser menor que 2.");
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i != j)
            {
                printf("(%d %d) ", i , j );
            }
        }
    }
}