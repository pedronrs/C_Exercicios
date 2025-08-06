//Desenvolver uma função que calcule o n-ésimo termo da sequência de Fibonacci.
#include <stdio.h>

int fibonacci_term(int n);


int main()
{
    int n;
    
    printf("Digite o n° termo a ser buscado na sequência: ");
    
    scanf("%d", &n);

    while( n <= 0)
    {
        printf(" %d não é válido \n Digite o n° termo a ser buscado na sequência: ", n);

        scanf("%d", &n);

    }
    
    int result = fibonacci_term(n);

    printf("\n O %d° termo da sequência de fibonacci é: %d\n", n, result);

    return 0;
}

int fibonacci_term(int n)
{
    int a = 0, b = 1, c, i = 2;
    
    if(n == 1)
    {
        return a;
    }
    if(n == 2)
    {
        return b;
    }
    while(i < n)
    {
        c = a + b; //próximo termo
        a = b; //anda com o termo 
        b = c; //anda com o termo (antecessor)
        i++;
    }
    return c;
}
