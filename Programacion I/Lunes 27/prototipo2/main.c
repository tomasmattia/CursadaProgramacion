#include <stdio.h>
#include <stdlib.h>

void sumar();

int main()
{
    int num1;
    int num2;
    printf("Ingrese un numero: ");
    scanf("%d",&num1);
    printf("Ingrese otro numero: ");
    scanf("%d",&num2);
    sumar(num1,num2);
    return 0;
}

void sumar(num1,num2)
{
    int resultado;
    resultado=num1+num2;
    printf("Resultado: %d",resultado);
}
