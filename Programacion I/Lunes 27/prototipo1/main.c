#include <stdio.h>
#include <stdlib.h>

void sumar(void);

int main()
{
    sumar();
    return 0;
}

void sumar(void)
{
    int num1;
    int num2;
    int resultado;
    printf("Ingrese un numero: ");
    scanf("%d",&num1);
    printf("Ingrese otro numero: ");
    scanf("%d",&num2);
    resultado=num1+num2;
    printf("Resultado: %d",resultado);
}
