#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <limits.h>
#include "misFunciones.h"

int obtenerEspacioLibre(ECliente lista[])
{
    int i;
    int resultado;
    int flagEspacio=0;
    for(i=0; i<20; i++)
    {
        if(lista[i].estado==0) // SI ENCUENTRA LUGAR
        {
            resultado=i;
            flagEspacio=1;
            break;
        }
    }
    if(flagEspacio==0)
    {
        resultado=-1;
    }
    return resultado;
}

void agregarCliente(ECliente lista[])
{
    int x=obtenerEspacioLibre(lista);
    char auxNombre[100]= {};
    if(x==-1) // SI NO HAY ESPACIO
    {
        printf("Se completo el espacio, necesita borrar una persona\n");
    }
    else // SI HAY ESPACIO
    {
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(auxNombre);
        while(strlen(auxNombre)>49)
        {
            printf("Demasiado extenso, reingrese el nombre: ");
            fflush(stdin);
            gets(auxNombre);
        }
        strcpy(lista[x].nombre,auxNombre);
        printf("Ingresar edad: ");
        scanf("%d",&lista[x].edad);
        printf("Ingresar DNI: ");
        scanf("%d",&lista[x].dni);
        lista[x].estado=1;
    }
}

int buscarPorDni(ECliente lista[])
{
    int i;
    int resultado;
    int flagDni=0;
    int dni;
    printf("Ingrese el dni a buscar: ");
    scanf("%d",&dni);
    for(i=0; i<20; i++)
    {
        if(dni==lista[i].dni && lista[i].estado==1)
        {
            resultado=i;
            flagDni=1;
            break;
        }
    }
    if(flagDni==0)
    {
        resultado=-1;
    }
    return resultado;
}

void eliminarCliente(ECliente lista[])
{
    int x=buscarPorDni(lista);
    char respuesta='n';
    if(x==-1 && lista[x].estado==0) // SI EL DNI NO EXISTE
    {
        printf("El dni ingresado es erroneo\n");
    }
    else // SI EL DNI EXISTE
    {
        printf("\nDNI: %d\tNOMBRE: %s\t EDAD: %d",lista[x].dni,lista[x].nombre,lista[x].edad);
        printf("\nDesea eliminarlo? s/n: ");
        fflush(stdin);
        scanf("%c",&respuesta);
        if(respuesta=='s')
        {
            lista[x].estado=0;
            printf("Persona eliminada de la lista\n");
        }
        else
        {
            printf("Accion cancelada\n");
        }
    }
}

void mostrarOrdenado(ECliente lista[])
{
    int i,j;
    ECliente aux= {};
    for(i=0; i<20-1; i++)
    {
        for(j=i+1; j<20; j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
    for(i=0; i<20; i++)
    {
        if(lista[i].estado==1)
        {
            printf("\nDNI: %d\tNOMBRE: %s\t EDAD: %d",lista[i].dni,lista[i].nombre,lista[i].edad);
        }
    }
    printf("\n");
}

