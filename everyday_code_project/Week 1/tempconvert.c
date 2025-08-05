// Implementar uma função que converta determinada temperatura em graus Celsius para graus Fahrenheit.
#include <stdio.h>

float temperature_convert_ctf(float celsius);

int main ()
{
    float celsius = 32.0;
    float fahrenheit = temperature_convert_ctf(celsius);
    printf("%.1f° Celsius equals to %.1f°F Fahrenheit.", celsius, fahrenheit);
    return 0;
}

float temperature_convert_ctf(float celsius)
{
    // equação base F = (C x (9/5)) + 32
    
    float fahrenheit = (celsius * 1.8) + 32; 

    return fahrenheit;
}