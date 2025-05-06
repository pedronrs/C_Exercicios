#include <stdio.h>

int funcao(int A, int B);

int main (void) {
    int ab;
    ab = funcao(13,4);
    printf("%d", ab);
    return 0;
}



int funcao(int A, int B){
    if(A >= B){
        return funcao(A-B, B);
    }
    else{
        return A;
    }
}