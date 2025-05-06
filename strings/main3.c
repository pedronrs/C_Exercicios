#include <stdio.h>

int strlen2(char s1[]){
    int i;
    for(i = 0; s1[i]; i++);
    return i;
}


int strcmp2(char s1[], char s2[], int indice){
    int i;
    for(i = 0;s1[i]||s2[i]; i++){
        if(s1[i] < s2[i]){
            return -1;
        }
    }
}


int main(void){
    char s1[20] = "asa";
    printf("%d \n", strlen2(s1));
    return 0;
}


int strcat(s1, s2){

}