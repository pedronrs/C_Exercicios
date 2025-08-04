#include <stdio.h>


void bubbleSort(int *v, int tam){
    int i, aux, troca = 1;
    while(troca){
        troca = 0;
        for(i = 0; i < tam-1; i++){
            if(v[i] > v[i+1]){
                troca = 1;
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
        tam--;
    }
}//iterativa


void bubbleSortRec(int *v, int tam){
    if(tam < 2){
        return;
    }
    for(int i = 0; i < tam - 1; i++){
        if(v[i] > v[i+1]){
            int aux = v[i];
            v[i] = v[i+1];
            v[i+1] = aux;
        }
    }
    bubbleSortRec(v, tam-1);    
}

void imprimir(int *v, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("%d", v[i]);
    }
    printf("\n");
}


int main(){
    int vetor[] = {5,8,9,4,10,6,3,7,1,2};
    int tam = 10;
    imprimir(vetor, tam);
    bubbleSortRec(vetor, tam);
    imprimir(vetor, tam);
    
    return 0;

}
