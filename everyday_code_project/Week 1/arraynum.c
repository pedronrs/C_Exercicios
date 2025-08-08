//Desenvolver uma função que determine o número de ocorrências de um número inteiro x em um vetor A.
#include <stdio.h>

int numX_in_array( int x, int vetA[], int vetTam);

int main() 
{
    int vetA[] ={1,2,1,1}; 
    int vetTam = sizeof(vetA) / sizeof(vetA[0]);
    int result = numX_in_array(1,vetA, vetTam);
    printf("%d", result);
    return 0;
}

int numX_in_array(int x, int vetA[], int vetTam)
{
    int cont=0;
    for(int i = 0; i < vetTam; i++ )
    {
        if(vetA[i] == x)
        {
            cont++;
        }
    }
    return cont;
}
