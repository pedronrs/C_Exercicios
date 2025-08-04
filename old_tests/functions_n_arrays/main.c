#include <stdio.h>

void exibirMultiplos(int N, int A, int B);

int main (void){
    int n = 5;
    int a = 5;
    int b = 20;
    exibirMultiplos(n,a,b);
    return 0;
}

void exibirMultiplos(int N, int A, int B){
    for(int i = A; i <= B; i++){
        if(i % N == 0){
            printf(" %d é múltiplo de %d\n", i, N);
        }
    }
}

