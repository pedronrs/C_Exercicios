
#include <stdio.h>

int particionar(int *v, int inicio, int fim){

    // ETAPA 1 - ESCOLHER O PIVÔ QUE SERÁ USADO NAS COMPARAÇÕES. *
    
    // * - o pivô preferencialmente é uma mediana dos elementos , então nesse caso pegaremos o primeiro elemento , o ultimo elemento , e o elemento do meio(primeira posicao + ultima posicao / 2), somaremos e dividiremos por 3.

    int pivo = (v[inicio] + v[fim] + v[(inicio + fim)/2]) / 3;

    // ENQUANTO INICIO FOR MENOR QUE O FIM FAREMOS AS ETAPAS 2, 3 E 4. 

    // ETAPA 2 - PERCORRER O VETOR DA ESQUERDA PARA DIREITA ATÉ ENCONTRAR UM ELEMENTO MAIOR QUE O PIVÔ. 

    // ETAPA 3 - PERCORRER O VETOR DA DIREITA PARA ESQUERDA ATÉ ENCONTRAR UM ELEMENTO MENOR QUE O PIVÔ. 

    // ETAPA 4 - TROCAR ESSES DOIS ELEMENTOS.

    while(inicio < fim){

        while( (inicio < fim) && v[inicio] <= pivo ){
            inicio++;
        }
        
        while( (inicio < fim) && v[fim] > pivo ){
            fim--;
        }

        int aux = v[inicio];

        v[inicio] = v[fim];

        v[fim] = aux;

    }

    return inicio;

}

void quickSort(int *v, int inicio, int fim){
    
    if(inicio < fim){
        
        // vamos chamar a função particiona para que ela capture na variável pos os elementos já posicionados. 
        
        int pos = particionar(v, inicio, fim);

        // após a captura do elemento chamaremos recursivamente a função quickSort para dividir os elementos a partir dos já ordenados (os menores que o elemento posicionado e os maiores que o elemento posicionado).

        quickSort(v, inicio, pos-1);

        quickSort(v, pos, fim);
    }

    // faremos tal procedimento até chegarmos a vetores de 1 elemento com já todos ordenados devidamente (onde inicio == fim);

}



void mostrar(int *v, int tam){
    int i;
    for(i = 0; i <= tam; i++){
        printf("%d", v[i]);
        printf("\n");
    }
}


int main(){

    int vetor[] = {47,35,12,49,56,25,71,83,5,3,1,70,99,10,61}; //tamanho = 15
    
    mostrar(vetor, 14);
    
    quickSort(vetor, 0, 14);
    
    printf("\n""\n");
    
    mostrar(vetor, 14);
    
    return 0;

}
