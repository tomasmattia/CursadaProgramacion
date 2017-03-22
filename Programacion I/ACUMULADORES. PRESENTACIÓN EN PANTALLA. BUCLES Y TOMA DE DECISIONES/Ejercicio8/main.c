#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d",&numero);
    if(numero==0){
        printf("El numero es cero");
    }
    else{
        if(numero>0){
            printf("El numero es positivo");
        }
        else{
            printf("El numero es negativo");
        }
    }

}
