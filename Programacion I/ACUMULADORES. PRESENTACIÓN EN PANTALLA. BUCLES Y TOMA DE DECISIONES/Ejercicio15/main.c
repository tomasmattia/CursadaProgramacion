#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int numero;
    int maximo= INT_MIN;
    int contador;
    for(contador=0;contador<3;contador++){
        printf("Ingrese un numero %d/3: ",contador+1);
        scanf("%d",&numero);
        if(numero>maximo){
            maximo=numero;
        }
    }
    printf("El numero mayor es %d",maximo);
    return 0;
}
