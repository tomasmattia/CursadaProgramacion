#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/*
1- mostrar cada uno
2- mostrar clientes con sus series
3- por cada serie los clientes que la estan viendo
4- todos los clientes que ven una serie en particular (El usuario ingresa el titulo)
5- La serie menos popular
6- Todas las series que ven los clientes de nombre "Juan"
*/


int main()
{
    eCliente clientes[10];
    eSerie series[5];
    eClientes_Series clientesSeries[20];
    cargarClientes(clientes);
    cargarSeries(series);
    cargarCliente_Serie(clientesSeries);
    int tamCli=10;
    int tamSer=5;
    int tamClienSer=20;
    int respuesta='s';
    int opcion=0;
    do
    {
        opcion=0;
        printf("1 - Mostrar cada lista\n");
        printf("2 - Mostrar clientes con sus series\n");
        printf("3 - Por cada serie los clientes que la estan viendo\n");
        printf("4 - Todos los clientes que ven una serie en particular\n");
        printf("5 - La serie menos popular\n");
        printf("6 - Todas las series que ven los clientes de nombre \"Juan\"\n");
        printf("7 - Salir\n");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                mostrarClientes(clientes);
                mostrarSeries(series);
                break;
            case 2:
                mostrarClientesConSeries(clientes,series,clientesSeries,tamCli,tamClienSer,tamSer);
                break;
            case 3:
                mostrarSeriesConClientes(clientes,series,clientesSeries,tamCli,tamClienSer,tamSer);
                break;
            case 4:
                mostrarClientesUnaSerie(clientes,series,clientesSeries,tamCli,tamClienSer,tamSer);
                break;
            case 5:
                serieMenosPopular(clientes,series,clientesSeries,tamCli,tamClienSer,tamSer);
                break;
            case 6:
                seriesJuan(clientes,series,clientesSeries,tamCli,tamClienSer,tamSer);
                break;
            case 7:
                respuesta='n';
                break;
            default:
                printf("No es una opcion valida\n");
                break;
        }
        system("pause");
        system("cls");
    }while(respuesta=='s');

    return 0;
}
