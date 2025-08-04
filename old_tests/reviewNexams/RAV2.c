#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// STRUCTS
// QUESTAO 2 LISTA

// nome e data de aniversario
// TData é composto por dia e mes;
typedef struct {
    int dia;
    int mes;
} TData;

typedef struct {
    char nome[50];
    TData data;
} TPessoa;

// Function to count birthdays in a given month
int aniversarianteMes(TPessoa vet[], int tam, int mesProcurado) {
    int count = 0;
    for (int i = 0; i < tam; i++) {
        if (vet[i].data.mes == mesProcurado) { // Corrected access to month
            count += 1;
        }
    }
    return count; // Return the count
}

int main(void) {
    int tam = 5;
    TPessoa vetor[tam];

    // Populate the array with some test data
    strcpy(vetor[0].nome, "Alice");
    vetor[0].data.dia = 10;
    vetor[0].data.mes = 5; // May

    strcpy(vetor[1].nome, "Bob");
    vetor[1].data.dia = 22;
    vetor[1].data.mes = 8; // August

    strcpy(vetor[2].nome, "Charlie");
    vetor[2].data.dia = 5;
    vetor[2].data.mes = 5; // May

    strcpy(vetor[3].nome, "David");
    vetor[3].data.dia = 15;
    vetor[3].data.mes = 1; // January

    strcpy(vetor[4].nome, "Eve");
    vetor[4].data.dia = 30;
    vetor[4].data.mes = 5; // May

    // ---
    // Test for the aniversarianteMes function
    // ---

    int mesDoBeijinho = 5; // Let's say "mes do beijinho" is May
    int numAniversariantes = aniversarianteMes(vetor, tam, mesDoBeijinho);

    printf("There are %d people celebrating their birthday in month %d.\n", numAniversariantes, mesDoBeijinho);

    // Another test case
    int mesOutro = 8; // August
    numAniversariantes = aniversarianteMes(vetor, tam, mesOutro);
    printf("There are %d people celebrating their birthday in month %d.\n", numAniversariantes, mesOutro);
    
    // Another test case where there are no birthdays
    int mesSemNiver = 12; // December
    numAniversariantes = aniversarianteMes(vetor, tam, mesSemNiver);
    printf("There are %d people celebrating their birthday in month %d.\n", numAniversariantes, mesSemNiver);

    return 0;
}