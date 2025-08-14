//Desenvolver uma função que, dada uma string s, crie uma substring que inicie na posição p de s e contenha n caracteres.

void position_string( char* s, int p, int n, char* ns);

int main ()
{
    char string[] = "stringsubstring";
    int position = 6; //posição onde iremos começar a ler a string
    int number = 9; //tamanho para substring da função
    char newstring[number+1]; // assume como tamanho máximo do substring toda a string + o caractere nulo 
    position_string(string, position, number, newstring); 
    return 0;
}

void position_string(char* s, int p, int n, char* ns)
{   
    int i,size_s=0; //assumindo-se uma execução onde não se sabe o tamanho da string
    while(s[size_s]){size_s++;} //strlen
    for(i=0;i<n;i++)
    {
        ns[i] = s[p+i]; //grava somente a substring em ns
    }
    ns[i] = '\0';   
    printf("entrada: %s \nsaída: %s ", s , ns);
}

