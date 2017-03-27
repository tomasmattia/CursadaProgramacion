#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int y;
    printf("Ingrese un numero: ");
    scanf("%d",&x);
    printf("Ingrese un numero: ");
    scanf("%d",&y);
    suma(x,y);
    return 0;
}

int suma(x,y){
    int resultado;
    resultado=x+y;
    printf("%d",resultado);
}
