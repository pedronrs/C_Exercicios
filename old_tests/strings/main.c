#include <stdio.h>
#include <string.h>



int main(void) {
    // Testes para a função ehPalindromo
    char teste1[] = "arara";
    char teste2[] = "ana";
    char teste3[] = "reviver";
    char teste4[] = "casa";
    char teste5[] = "ovo";
    char teste6[] = "radar";
    char teste7[] = "banana";
    char teste8[] = "A";
    char teste9[] = "socorrammesubinoonibusemmarrocos"; // maior palíndromo da língua portuguesa
    
    printf("Testando palíndromos:\n");
    printf("'%s' é palíndromo? %s\n", teste1, ehPalindromo(teste1, strlen(teste1)) ? "Sim" : "Não");
    printf("'%s' é palíndromo? %s\n", teste2, ehPalindromo(teste2, strlen(teste2)) ? "Sim" : "Não");
    printf("'%s' é palíndromo? %s\n", teste3, ehPalindromo(teste3, strlen(teste3)) ? "Sim" : "Não");
    printf("'%s' é palíndromo? %s\n", teste4, ehPalindromo(teste4, strlen(teste4)) ? "Sim" : "Não");
    printf("'%s' é palíndromo? %s\n", teste5, ehPalindromo(teste5, strlen(teste5)) ? "Sim" : "Não");
    printf("'%s' é palíndromo? %s\n", teste6, ehPalindromo(teste6, strlen(teste6)) ? "Sim" : "Não");
    printf("'%s' é palíndromo? %s\n", teste7, ehPalindromo(teste7, strlen(teste7)) ? "Sim" : "Não");
    printf("'%s' é palíndromo? %s\n", teste8, ehPalindromo(teste8, strlen(teste8)) ? "Sim" : "Não");
    printf("'%s' é palíndromo? %s\n", teste9, ehPalindromo(teste9, strlen(teste9)) ? "Sim" : "Não");
    
    return 0;
}

int ehPalindromo(char palavra[], int tamanho) {
    int inicio = 0;
    int fim = tamanho - 1;
    
    while (inicio < fim) {
        if (palavra[inicio] != palavra[fim]) {
            return 0; // Não é palíndromo
        }
        inicio++;
        fim--;
    }
    return 1; // É palíndromo
}

