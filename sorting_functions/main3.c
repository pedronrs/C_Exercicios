#include <stdio.h>

void selectionSort(int *v, int tam){
    
}


void selectionSortRec(int *v, int inicio, int tam){
    if(inicio >= tam){return;}
    int i, menor;
    menor = inicio;
    for(i = inicio + 1; i < tam; i++){
        if(v[i] < v[menor]){
            menor = i;
        }
    }
    int aux = v[inicio];
    v[inicio] = v[menor];
    v[menor] = aux;
    selectionSortRec(v, inicio+1, tam);
}

void imprimir(int *v, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("%d", v[i]);
    }
    printf("\n");
}

int main(){
    int vetor[] = {5,8,9,4,6,3,7,1,2};
    int tam = 9;
    imprimir(vetor, tam);
    selectionSortRec(vetor, 0 ,tam);
    imprimir(vetor, tam);
    
    return 0;

}
