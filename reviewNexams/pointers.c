#include <stdio.h>


void main ()
{
	int x = 10;
	int *p = &x;
	
	printf ("%d\n", x);
	printf ("%d\n", *p);
	printf ("%d\n", *(&x));
} 

// copiar um  vetor para outro com ponteiros
for(i=0; i < n; i++){
	*(vetB+i) = *(vetA+1);
}


// inversão de vetores
#include <stdio.h>

void funcao (int *v, int n) 
{
    int *a = v, *b = v+n-1;
    int c;
    
	while (a < b) 
	{
        c = *a;
        *a = *b;
        *b = c;
        
		a++;
        b--;
    }
}


// 
void funcao(char *str){
	char *dest = str;
	while(*str){
		if(*str != ' '){
			*dest++ = *str;
		}
	str++;
	}
	*dest = '\0';
}
void main () 
{
	char string[20];
	
	strcpy (string, "AULA DE FPR");
	
	printf ("antes: %s\n\n", string);
	
	funcao (string);
	
	printf ("depois: %s\n\n", string);
}

// mimico do strcpy 

void funcao( char *str1, char *str2){
	while(str2){
		// o valor apontado por str1 é substituido pelo valor apontado por str2 e ambos se incrementam
		*str1++ = *str2++;
	}
	*str1 = '/0';
}

