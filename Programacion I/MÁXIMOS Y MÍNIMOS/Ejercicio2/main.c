#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    float cantidadLluvia;
    int dia;
    int mayorLluvia=INT_MIN;
    int menorLluvia=INT_MAX;
    int diaMayor;
    int diaMenor;
    int totalLluvia=0;
    float promedio;
    for(dia=1;dia<31;dia++){
        printf("Ingrese los mm de agua caida: ");
        scanf("%f",&cantidadLluvia);
        totalLluvia+=cantidadLluvia;
        if(cantidadLluvia>mayorLluvia){
            mayorLluvia=cantidadLluvia;
            diaMayor=dia;
        }
        if(cantidadLluvia<menorLluvia){
            menorLluvia=cantidadLluvia;
            diaMenor=dia;
        }
    }
    promedio=(float)totalLluvia/dia;
    printf("El dia que mas llovio fue: %d\n",diaMayor);
    printf("El dia que menos llovio fue: %d\n",diaMenor);
    printf("El promedio fue: %.2f\n",promedio);
    return 0;
}
