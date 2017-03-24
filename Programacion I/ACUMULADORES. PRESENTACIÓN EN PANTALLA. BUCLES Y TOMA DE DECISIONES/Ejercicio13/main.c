#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contador;
    int multiTres=0;
    printf("Ingrese un numero: ");
    scanf("%d",&numero);
    for(contador=1;contador<=numero;contador++){
        if(contador%3==0){
            multiTres+=1;
        }
    }
    printf("Desde la unidad hasta el %d hay %d multiplos de 3",numero, multiTres);
    return 0;
}
