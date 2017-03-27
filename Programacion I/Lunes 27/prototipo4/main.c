#include <stdio.h>
#include <stdlib.h>

int sumar(void);

int main()
{
    int resultado;
    resultado=sumar();
    printf("El resultado es: %d",resultado);
    return 0;
}

int sumar(void)
{
    int num1;
    int num2;
    int resultado;
    printf("Ingrese un numero: ");
    scanf("%d",&num1);
    printf("Ingrese otro numero: ");
    scanf("%d",&num2);
    resultado=num1+num2;
    return resultado;
}
