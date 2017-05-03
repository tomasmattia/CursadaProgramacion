#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void cargarSeries(eSerie series[])
{
    int idSerie[5]= {100,101,102,103,104};
    int estado[5]= {1,1,1,1,1};
    char titulo[5][30]= {"TBBT","BB","GOT","AHS","SCD"};
    int temporadas[5]= {9,7,7,6,1};
    char genero[5][30]= {"Comedia","Policial","Ciencia Ficcion","Terror","Comedia"};

    int i;
    for(i=0; i<5; i++)
    {
        series[i].idSerie = idSerie[i];
        strcpy(series[i].titulo, titulo[i]);
        series[i].estado = estado[i];
        series[i].temporadas = temporadas[i];
        strcpy(series[i].genero, genero[i]);
    }
}
void cargarClientes(eCliente clientes[])
{
    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombres[10][30]= {"juan","maria","pedro","luis","romina","jose","andrea","patricia","luciano","camila"};
    int estado[10]= {1,1,1,1,1,1,1,1,1,1};

    int i;

    for(i=0; i<10; i++)
    {
        clientes[i].idCliente = id[i];
        strcpy(clientes[i].nombre, nombres[i]);
        clientes[i].estado = estado[i];

    }

}

void cargarCliente_Serie(eClientes_Series clientesSeries[])
{

    int cliente[20] = {1,1,1,2,2,3,4,4,5,5,5,7,8,8,8,9,10,10,10,10};
    int serie[20]= {101,102,103,104,103,101,101,102,104,101,101,101,101,102,103,102,101,103,102,104};
    int i;

    for(i=0; i<20; i++)
    {
        clientesSeries[i].idCliente=cliente[i];
        clientesSeries[i].idSerie = serie[i];
    }

}

void mostrarClientes(eCliente clientes[])
{
    int i;
    printf("\tCLIENTES\n");
    printf("ID\tNOMBRE\n");
    for(i=0; i<10; i++)
    {
        printf("%d\t%s\n",clientes[i].idCliente,clientes[i].nombre);
    }
}

void mostrarSeries(eSerie series[])
{
    int i;
    printf("SERIES\n");
    printf("ID\tTITULO\tTEMP\tGENERO\n");
    for(i=0; i<5; i++)
    {
        printf("%d\t%s\t%d\t%s\n",series[i].idSerie,series[i].titulo,series[i].temporadas,series[i].genero);
    }
}

void mostrarClientesConSeries(eCliente clientes[],eSerie series[],eClientes_Series clientesSeries[],int tamCli,int tamClienSer,int tamSer)
{
    int i,j,k;
    int flag=0;
    for(i=0; i<tamCli; i++)
    {
        flag=0;
        if(clientes[i].estado==1)
        {
            printf("%s mira: \t",clientes[i].nombre);
            for(j=0;j<tamClienSer;j++)
            {
                if(clientes[i].idCliente==clientesSeries[j].idCliente)
                {
                    for(k=0; k<tamSer; k++)
                    {
                        if(clientesSeries[j].idSerie==series[k].idSerie)
                        {
                            printf("%s\t",series[k].titulo);

                        }
                    }
                   flag=1;
                }
            }
            if(flag==0)
            {
                printf("No mira ninguna serie");
            }
            printf("\n");
        }
    }
}

void mostrarSeriesConClientes(eCliente clientes[],eSerie series[],eClientes_Series clientesSeries[],int tamCli,int tamClienSer,int tamSer)
{
    int i,j,k;
    int flag=0;
    for(i=0;i<tamSer;i++)
    {
        flag=0;
        printf("%s: ",series[i].titulo);
        for(j=0;j<tamClienSer;j++)
        {
            if(series[i].idSerie==clientesSeries[j].idSerie)
            {
                for(k=0;k<tamCli;k++)
                {
                    if(clientesSeries[j].idCliente==clientes[k].idCliente)
                    {
                        printf("%s ",clientes[k].nombre);
                    }
                }
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("Nadie mira esta serie");
        }
        printf("\n");
    }
}

void mostrarClientesUnaSerie(eCliente clientes[],eSerie series[],eClientes_Series clientesSeries[],int tamCli,int tamClienSer,int tamSer)
{
    int i,j,k;
    mostrarSeries(series);
    int serieMostrar;
    int flag=0;
    int flagCantidad=0;
    printf("Ingrese el ID de serie a mostrar: ");
    scanf("%d",&serieMostrar);
    for(i=0;i<serieMostrar;i++)
    {
        if(serieMostrar==series[i].idSerie)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("El ID ingresado no existe\n");
    }
    else
    {
        flagCantidad=0;
        printf("A la serie %s la ven: ",series[i].titulo);
        for(j=0;j<tamClienSer;j++)
        {
            if(serieMostrar==clientesSeries[j].idSerie)
            {
                for(k=0;k<tamCli;k++)
                {
                    if(clientesSeries[j].idCliente==clientes[k].idCliente)
                    {
                        printf("%s ",clientes[k].nombre);
                    }
                }
                flagCantidad=1;
            }
        }
        if(flagCantidad==0)
        {
            printf("Nadie mira esta serie");
        }
        printf("\n");
    }
}

void serieMenosPopular(eCliente clientes[],eSerie series[],eClientes_Series clientesSeries[],int tamCli,int tamClienSer,int tamSer)
{
    int i,j;
    eLoser popularidadSerie[5]={};
    eLoser aux={};
    for(i=0;i<tamSer;i++)
    {
        popularidadSerie[i].idSerie=series[i].idSerie;
        for(j=0;j<tamClienSer;j++)
        {
            if(series[i].idSerie==clientesSeries[j].idSerie)
            {
                popularidadSerie[i].cont+=1;
            }
        }
        if(i==0 || popularidadSerie[i].cont<aux.cont)
        {
            aux.cont=popularidadSerie[i].cont;
        }
    }
    for(i=0;i<tamSer;i++)
    {
        if(aux.cont==popularidadSerie[i].cont)
        {
            for(j=0;j<tamSer;j++)
            {
                if(popularidadSerie[i].idSerie==series[j].idSerie)
                {
                    printf("La serie menos popular es %s\n",series[i].titulo);
                }
            }
        }
    }
}

void seriesJuan(eCliente clientes[],eSerie series[],eClientes_Series clientesSeries[],int tamCli,int tamClienSer,int tamSer)
{
    int i,j,k;
    for(i=0;i<tamCli;i++)
    {
        if(strcmp(clientes[i].nombre,"juan")==0)
        {
            for(j=0;j<tamClienSer;j++)
            {
                if(clientes[i].idCliente==clientesSeries[j].idCliente)
                {
                    for(k=0;k<tamSer;k++)
                    {
                        if(clientesSeries[j].idSerie==series[k].idSerie)
                        {
                            printf("%s ",series[k].titulo);
                        }
                    }
                }
            }
        }
    }
    printf("\n");
}
