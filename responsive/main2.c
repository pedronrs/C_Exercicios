#include <stdio.h>
#include <string.h>


int contarCharDistintos(char *s){
    int contador = 0;
    int tamanho = strlen(s);
    for (int i = 0; i < tamanho; i++){
        int charNovo = 1;
        for(int j = 0; j < i; j++){
            if(s[j] == s[i]){
                charNovo = 0;

            }
        }
        if(charNovo){
            contador++;
        }
    }
    return contador;
}



int main() {

    return 0;
}