#include <stdio.h>

int main(){
    return 0;
}


//   XX.XXX.XXX/YYYY-ZZ\0 string corretamente escrita tem strlen == 19


int busca_cnpj(char* cnpj, char* inscricao, char* dverificador)
{
    int i;
    int j;
    int t_inscricao = 9;
    int t_matriz = 4; 
    int t_verificador = 2;
    char vmatriz[4]= '0001';
    char matriz[t_matriz];

    

    int validador = validar_digitos(cnpj);
    if(!validador){return 0;};//deu errado}
    
    for(i=0; i < t_inscricao; i++)
    {
        cnpj[i] = inscricao[i];
    }



    for(j=0; j < t_matriz+1; j++)
    {
        matriz[j] = cnpj[t_inscricao++];
    }

    if(strcmp(matriz,vmatriz))
    {
        return 1;
    }
    
    for(int z=0; z < t_verificador;z++)
    {
        dverificador[z] = cnpj[t_matriz+t_inscricao+1];
    }


    return 0;
}



int validar_digitos(char* cnpj)
{
    int tam = strlen(cnpj);

    if(cnpj[2] != '.' || cnpj[6]  != '.' || cnpj[10] != '/' || cnpj[15] != '-' || cnpj[18] == '0'){return 0;};
    
    //percorrer a string
    
    for(int i=0; i < tam; i++)
    {
        if(cnpj[i] >= '0' && cnpj[i] >= '9')
        {
            return 1;
        }
    }
    return 0;
}
