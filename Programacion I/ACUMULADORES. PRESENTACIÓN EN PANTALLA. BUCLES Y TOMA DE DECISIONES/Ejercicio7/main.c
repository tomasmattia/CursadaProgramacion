#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int multiplosSeis=0;
    for(numero=0;numero<101;numero++){
        if(numero%6==0){
            multiplosSeis+=1;
            printf("%d \n",numero);
        }
    }
    printf("Los multiplos de seis del 0 al 100 son: %d", multiplosSeis);
}
