// Fazer uma função que calcule MMC entre dois números
// Fazer uma função que calcule MDC entre dois números
#include <stdio.h>

int calculate_mmc(int number1, int number2);

int calculate_mdc(int number1, int number2);

int main()
{
    
    int operation, number1, number2;

    printf("0 - MDC    1 - MMC :");
    scanf("%d", &operation);

    //sendo 0 == null 
    if(!operation)
    {
        //mdc
        int mdc;
        printf("Digite os termos da operação:");
        scanf("%d %d", &number1, &number2);
        mdc = calculate_mdc(number1, number2);
        printf("\nO MDC desses números é: %d", mdc);
        
    }else
    {
                //mmc
        int mmc;
        printf("Digite os termos da operação:");
        scanf("%d %d", &number1, &number2);
        mmc = calculate_mmc(number1, number2);
        printf("\nO MMC desses números é: %d", mmc);
        
    }   


    return 0;
}

int calculate_mdc(int number1, int number2)
{
    while(number2)
    {
        int calc = number1 % number2;
        number1 = number2;
        number2 = calc;
    }
    return number1;
}

int calculate_mmc(int number1, int number2)
{
    int calc = (number1 * number2) / calculate_mdc(number1, number2);

    return calc;
}
