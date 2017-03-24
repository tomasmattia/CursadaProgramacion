#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int aux;
    printf("Ingrese un numero: ");
    scanf("%d",&num1);
    system("cls");
    printf("Ingrese otro numero: ");
    scanf("%d",&num2);
    system("cls");
    aux=num1;
    num1=num2;
    num2=aux;
    printf("El valor del primero es %d y del segundo %d",num1, num2);
    return 0;
}
