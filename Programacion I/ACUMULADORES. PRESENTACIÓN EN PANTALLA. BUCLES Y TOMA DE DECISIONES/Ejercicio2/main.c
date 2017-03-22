#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int numerosImpares=0;
    for(numero=0;numero<=100;numero++){
        if(numero%2!=0){
            printf("%d \n",numero);
            numerosImpares+=1;
        }
    }
    printf("Hay %d numeros impares de 0 a 100",numerosImpares);
}
