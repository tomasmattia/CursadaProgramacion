#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contador;
    printf("Ingrese un numero :");
    scanf("%d",&numero);
    if(numero>0){
        for(contador=1;contador<=numero;contador++)
        {
        printf("%d\n",contador);
        }
    }
    else{
        if(numero<0){
            for(contador=-1;contador>=numero;contador--)
            {
            printf("%d\n",contador);
            }
        }
        else{
            if(numero==0){
                printf("%d", numero);
            }
        }
    }

    return 0;
}
