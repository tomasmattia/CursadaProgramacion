#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funciones.h"


int main()
{
    float matrizBondis[4][13];
    char respuesta='s';
    inicializarMatrizBondis(matrizBondis);
    do
    {
        ingresoPlanilla(matrizBondis);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c",&respuesta);
        system("cls");

    }while(respuesta=='s');
    mostrarGananciasXLinea(matrizBondis);
    mostrarGananciasXBondi(matrizBondis);
    mostrarGananciaTotal(matrizBondis);
    mostrarMatriz(matrizBondis);

    return 0;
}
