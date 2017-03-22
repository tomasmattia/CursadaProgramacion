#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d",&numero);
    if(numero%2==0){
        printf("%d es un numero par", numero);
    }
    else{
        printf("%d es un numero impar", numero);
    }
}
