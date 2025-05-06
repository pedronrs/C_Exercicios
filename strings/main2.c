#include <stdio.h>
#include <string.h>
void removerCaracteres (char string[], char caracter);

void removerCaracteres (char string[], char caracter)
{
	char strAux[strlen(string)+1];
	int i, j;
	
	//copiando para 'strAux' os caracteres de 'string' 
	//diferentes de 'caracter'
	for (i=0,j=0;string[i];i++)
	{
		//verificando se 'string[i]' é diferente de 'caracter'
		if (string[i] != caracter)
		{
			strAux[j] = string[i];
			j++;
		}
	}
	
	//finalizando 'strAux'
	strAux[j] = '\0';
	
	//copiando 'strAux' para a string original
	strcpy (string, strAux);
}
void main ()
{
	//declaração de variáveis
	char string[20], letra;
	int numero;
	
	//lendo a string
	printf ("Entre com a string: ");
	gets (string);
	
	//lendo a letra a ser removida
	printf ("\nLetra a ser removida: ");
	//fflush(stdin);
	scanf ("%c", &letra);
	
	//exibindo a string antes da remoção
	printf ("\n\nAntes da remocao: %s", string);
	
	//chamando a função
	removerCaracteres (string, letra);

	//exibindo a string depois da remoção
	printf ("\n\nDepois da remocao: %s", string);
}
