#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int acumulador=0;
    int contador;
    for(contador=0;contador<5;contador++){
        printf("Ingrese un numero: ");
        scanf("%d",&numero);
        system("cls");
        acumulador+=numero;
    }
    printf("La suma da %d", acumulador);
}
