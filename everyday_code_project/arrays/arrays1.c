//Desenvolver uma função que exiba os múltiplos de N compreendidos no intervalo definido por A e B.
#include <stdio.h>

void multiples_of_number(int number, int numA, int numB);

int main ()
{
   multiples_of_number(5, 10, 42); 
    return 0;
}

void multiples_of_number(int number, int numA, int numB)
{
    printf("Multiples of %d between %d and %d:\n", number, numA, numB);
    for(int i= numA; i <= numB; i++)
    {
        if(i % number == 0)
        {
            printf("%d\n", i );
        };
    };
};



