#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int numero;
    int maximo=INT_MIN;
    int contador;
    for(contador=0;contador<4;contador++){
        printf("Ingrese un numero: ");
        scanf("%d",&numero);
        if(numero>maximo){
            maximo=numero;
        }
        system("cls");
    }
    printf("El maximo es: %d",maximo);
    return 0;
}
