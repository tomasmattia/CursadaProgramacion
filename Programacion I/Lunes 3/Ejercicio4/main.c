#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros[5];
    int numeros2[5];
    int contador;
    for(contador=0;contador<5;contador++){
        printf("Ingrese un numero (%d/5): ",contador+1);
        scanf("%d",&numeros[contador]);
        numeros2[contador]=numeros[contador]*2;
    }
    printf("\nEl primer array : ");
    for(contador=0;contador<5;contador++){
        printf("%d ",numeros[contador]);
    }
    printf("\nEl segundo array : ");
    for(contador=0;contador<5;contador++){
        printf("%d ",numeros2[contador]);
    }

    return 0;
}
