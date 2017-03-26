#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador;
    int division;
    int divisores=0;
    int primos=0;
    for(contador=2;contador<101;contador++){
        for(division=1;division<=contador/2;division++){
            if(contador%division==0){
                divisores+=1;
            }
        }
        if(divisores<2){
            primos+=1;
            printf("%d\n",contador);
        }
        divisores=0;
    }
    printf("Primos: %d",primos);
    return 0;
}
