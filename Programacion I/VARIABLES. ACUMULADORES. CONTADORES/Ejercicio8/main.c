#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base;
    int altura;
    float superficie;
    printf("Ingrese la base del triangulo: ");
    scanf("%d",&base);
    system("cls");
    printf("Ingrese la altura del triangulo: ");
    scanf("%d",&altura);
    system("cls");
    superficie=base*((float)altura/2);
    printf("La superficie del triangulo es de %.2f",superficie);
}
