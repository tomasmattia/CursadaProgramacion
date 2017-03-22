#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int sumaSerie;
    for(numero=0;numero<100;numero++){
        if(numero%3==0){
            sumaSerie+=numero;
        }
    }
    printf("La suma de la serie da: %d", sumaSerie);
}
