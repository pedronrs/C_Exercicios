//Implementar uma função que, dada uma string s, determine a quantidade de caracteres distintos em s.
#include <stdio.h>
#include <string.h>

int char_distinto(char* s)
{
    int i,j=0,tamanho,cont=0; //inicializa as variáveis que vamos precisar 
    tamanho = strlen(s);
    for(i = 0; i < tamanho; i++)
    {
        //precisamos de uma flag para saber quando de fato um caractere distinto é encontrado
        int char_encontrado = 0;
        
        //Aqui iremos iterar para cada caractere todos os seus antecessores para encontrar um igual.
        for(j = 0; j < i; j++)
        {
            if(s[i] == s[j])
            {
                char_encontrado = 1;
            } 
        }
        if(!char_encontrado){cont++;}//não achado o caractere contamos para os distintos
    }
    return cont;
}










 
/*Implementar uma função que, dadas duas
strings s1 e s2, crie uma nova string – s3 –
contendo todos os caracteres de s1 que não
estejam em s2.
Nota: em s3, não devem existir caracteres
repetidos.
*/

void string3( char* string1, char* string2, char* string3)
{ 
    int t_s1 = strlen(string1); //para iterarmos sobre toda a string precisamos dos tamanhos delas.
    int t_s2 = strlen(string2);
    int index_s3 = 0; //precisamos de um tamanho especifico declarado para string3;

    for(int i = 0;i < t_s1; i++)
    {
        int char_lido_s2 = 0; //verificam se o caractere já existe em alguma das duas strings.
        int char_lido_s3 = 0;
        char char_atual = string1[i]; //verifica somente o caractere atual para todos os laços.

        for(int j = 0; j < t_s2; j++)
        {
            if(char_atual == string2[j])
            {
                char_lido_s2 = 1;
            }
        }
        for(int k = 0; k < index_s3; k++)
        {
            if(char_atual == string3[k])
            {
                char_lido_s3 = 1;
            }
        }
        if(!(char_lido_s2 || char_lido_s3)) //se após todas as iterações os verficadores continuarem nulos , escreveremos o char na string3.
        {
            string3[index_s3] = char_atual;
            index_s3++; 
        }
        }
        string3[index_s3] = '\0'; //adicionando o fim da string3.
    }

/*Desenvolver uma função, que dada uma string s e dada uma posição p desta string, crie duas novas strings, s1 com os caracteres
  de s a p-1. e s2 com os caracteres da posição p a última. 
Caso p seja uma posição inválida, a função deverá retornar o valor 0, caso contrário, procederá com a criação das duas strings e
retornará o valor 1.
*/

int split_str( char* s, char* split1, char* split2, int pos) //split - onde vão ser guardadas as strings separadas.
{
    int i;int size = strlen(s);

    if (pos > size || pos < 0)
    {
        return 0;
    }//ocorrência para pos inválida

    for(i=0; i < pos; i++) //iteração ocorrendo para todos os caracteres até a posição desejada.
    {
        split1[i] = s[i]; //escrita
    }
    split1[i] = '\0'; 
    int j=0;
    for(i=pos; i < size; i++) //iterando sobre i agora valendo o total da posição até o tamanho da string s para o restante.
    {
        split2[j] = s[i];
    }
    split2[j] = '\0';
    return 1; 
}







/*Desenvolver uma função que remova de uma string s os caracteres compreendidos entre as posições p1 e p2.
 * Caso p1 ou p2 seja uma posição inválida, a função deverá retornar o valor 0 e a remoção de caracteres solicitada não será 
 * realizada; caso o contrário, deverá retornar 1 e proceder com o que foi pedido.
*/

int remove_char_from_str(char* s, int pos1, int pos2)
{
    int size = strlen(s);
    if(pos1 > pos2 || pos2 >= size){return 0;}
    strcpy(&s[pos1], &s[pos2+1]);
    return 1;
}
