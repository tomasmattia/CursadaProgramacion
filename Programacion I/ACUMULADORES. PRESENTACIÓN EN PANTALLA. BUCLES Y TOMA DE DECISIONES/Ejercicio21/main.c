#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    for(numero=1;numero<101;numero++){
        if(numero%3==0 && numero%7==0){
            printf("Multiplo de 3 y 7: %d\n",numero);
        }
        else{
            if(numero%3==0){
            printf("Multiplo de 3: %d\n",numero);
            }
            else{
                if(numero%7==0){
                    printf("Multiplo de 7: %d\n",numero);
                }
            }
        }

    }
    return 0;
}
