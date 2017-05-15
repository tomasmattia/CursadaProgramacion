#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funciones.h"

void inicializarMatrizBondis(float matrizBondis[][13])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<13;j++)
        {
            matrizBondis[i][j]=0;
        }
    }
}

float checkearNumero(float numero,int minimo,int maximo)
{
    float checkNum=numero;
    while(checkNum<minimo || checkNum>maximo)
    {
        printf("Por Favor reingrese: ");
        scanf("%f", &checkNum);
    }
    return checkNum;
}

void mostrarGananciasXLinea(float matrizBondis[][13])
{
    int i;
    for(i=0;i<12;i++)
    {
        printf("La ganancia total de los colectivos %d fue de %.2f\n",i+1,matrizBondis[3][i]);
    }
    printf("\n");
}

void mostrarGananciasXBondi(float matrizBondis[][13])
{
    int i;
    for(i=0;i<3;i++)
    {
        printf("La ganancia total de la linea %d fue de %.2f\n",i+1,matrizBondis[i][12]);
    }
    printf("\n");
}

void mostrarGananciaTotal(float matrizBondis[][13])
{
    float sumaTotal;
    int i;
    for(i=0;i<3;i++)
    {
        sumaTotal+=matrizBondis[i][12];
    }
    matrizBondis[3][12]=sumaTotal;
    printf("La ganancia total de las 3 lineas fue de %.2f\n",sumaTotal);
    printf("\n");
}

void mostrarMatriz(float matrizBondis[][13])
{
    int i,j,x;
    printf("BONDIS: ");
    for(i=0;i<13;i++)
    {
        if(i==12)
        {
            printf("TOTAL");
        }
        else
        {
            printf(" B%d  ",i+1);
        }
    }
    printf("\n");
    for(i=0;i<4;i++)
    {
        x=i;
        if(x==3)
        {
            printf("TOTALES: ");
        }
        else
        {
            printf("LINEA %d: ",x+1);
        }
        for(j=0;j<13;j++)
        {
            printf("%.2f ",matrizBondis[i][j]);
        }
        printf("\n");
    }
}

void ingresoPlanilla(float matrizBondis[][13])
{
        int linea;
        int colectivo;
        float ingreso;
        int maximo=INT_MAX;
        printf("Ingrese la linea: ");
        fflush(stdin);
        scanf("%d",&linea);
        linea=checkearNumero(linea,1,3);

        printf("Ingrese el numero de colectivo: ");
        fflush(stdin);
        scanf("%d",&colectivo);
        colectivo=checkearNumero(colectivo,1,12);

        printf("Ingrese las ganancias: ");
        fflush(stdin);
        scanf("%f",&ingreso);
        ingreso=checkearNumero(ingreso,0,maximo);

        matrizBondis[linea-1][colectivo-1]+=ingreso;
        matrizBondis[linea-1][12]+=ingreso;
        matrizBondis[3][colectivo-1]+=ingreso;
}
