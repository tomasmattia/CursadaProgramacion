#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int numero;
    int mayor=INT_MIN;
    int menor=INT_MAX;
    int contador;
    for(contador=0;contador<5;contador++){
        printf("Ingrese un numero: ");
        scanf("%d",&numero);
        if(numero>mayor){
            mayor=numero;
        }
        if(numero<menor){
            menor=numero;
        }
        system("cls");
    }
    printf("Mayor: %d\nMenor: %d",mayor,menor);
    return 0;
}
