#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int cuadradoNumero;
    printf("Ingrese un numero: ");
    scanf("%d",&numero);
    while(numero<=0){
        printf("Ingrese un numero mayor a 0: ");
        scanf("%d",&numero);
    }
    cuadradoNumero=numero*numero;
    printf("El cuadrado del numero ingresado es %d",cuadradoNumero);
}
