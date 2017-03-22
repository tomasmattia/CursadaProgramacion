#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int numerosMayores=0;
    int numerosMenores=0;
    int ceros=0;
    int contador;
    for(contador=0;contador<10;contador++){
        printf("Ingrese el numero %d /10 : ", contador+1);
        scanf("%d",&numero);
        if(numero==0){
            ceros+=1;
        }
        else{
            if(numero>0){
                numerosMayores+=1;
            }
            else{
                numerosMenores+=1;
            }
        }
        system("cls");
    }
    printf("La cantidad de numeros mayores fue de %d , de numeros menores %d y de ceros %d",numerosMayores,numerosMenores,ceros);
}
