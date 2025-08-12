//Revisão FAC

//Vetores 

//vetor[] == *vetor  // parâmetros

void funcao(int v[], int qtd, int a, int b)
{
    int i;

    v[0] = a;

    for(i = 1; i < qtd; i++)
    {
        v[i] = v[i - 1] + b;
    }
}//PA em b com base no valor inicial de a.

