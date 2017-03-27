#include <stdio.h>
#include <stdlib.h>

int sumar(int,int);

int main()
{
    int num1;
    int num2;
    int resultado;
    printf("Ingrese un numero: ");
    scanf("%d",&num1);
    printf("Ingrese otro numero: ");
    scanf("%d",&num2);
    resultado=sumar(num1,num2);
    printf("Resultado: %d",resultado);
    return 0;
}

int sumar(int x,int y)
{
    int resultado;
    resultado=x+y;
    return resultado;
}
