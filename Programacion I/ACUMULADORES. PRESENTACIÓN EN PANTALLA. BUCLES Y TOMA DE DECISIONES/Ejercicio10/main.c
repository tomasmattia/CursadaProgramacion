#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int sumaPositivos=0;
    int productoNegativos=1;
    int contador;
    for(contador=0;contador<10;contador++){
        printf("Ingrese un numero: ");
        scanf("%d",&numero);
        system("cls");
        while(numero==0){
                printf("Ingrese un numero que no sea 0: ");
                scanf("%d",&numero);
            }
        if(numero>0){
            sumaPositivos+=numero;
        }
        else{
            productoNegativos*=numero;
        }
        system("cls");
    }
    printf("La suma de todos los positivos da %d y el producto de los negativos %d",sumaPositivos,productoNegativos);
}
