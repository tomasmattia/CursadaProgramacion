#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros[5]={0};
    int numero;
    int posicion;
    int contador;

    for(contador=0;contador<10;contador++){
        printf("Ingrese un numero: ");
        scanf("%d",&numero);
        printf("Ingrese la posicion: ");
        scanf("%d",&posicion);
        numeros[posicion-1]+=numero;
    }

    printf("\n\n");
    printf("Los valores son: ");

    for(contador=0;contador<5;contador++){
        printf("%d ",numeros[contador]);
    }
    return 0;
}
