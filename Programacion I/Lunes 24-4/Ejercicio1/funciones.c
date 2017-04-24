#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"

#define MAX 10

int obtenerEspacioLibre(EProgramador plantel[])
{
    int i;
    int resultado;
    int flagEspacio=0;
    for(i=0; i<MAX; i++)
    {
        if(plantel[i].id==0)
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

void agregarProgramador(EProgramador plantel[],ECategoria categorias[])
{
    int catCheck=0;
    int i,numcat;
    int x=obtenerEspacioLibre(plantel);
    if(x==-1)
    {
        printf("Se completo el plantel, necesita borrar uno\n");
    }
    else
    {
        plantel[x].id=x+1;
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(plantel[x].nombre);
        do
        {
            printf("Ingresar categoria ");
            printf("(Junior:1 SemiSenior:2 Senior:3):  ");
            scanf("%d",&numcat);
            for(i=0; i<3; i++)
            {
                if(numcat==categorias[i].id)
                {
                    catCheck=1;
                    break;
                }
            }
        }
        while(catCheck==0);
        plantel[x].idCategoria=numcat;
        printf("Ingresar el sueldo: ");
        scanf("%f",&plantel[x].sueldo);
    }

}

int buscarPorId(EProgramador plantel[])
{
    int i;
    int resultado;
    int flagId=0;
    int id;
    printf("Ingrese el ID a buscar: ");
    scanf("%d",&id);
    for(i=0; i<MAX; i++)
    {
        if(id==plantel[i].id)
        {
            resultado=i;
            flagId=1;
        }
    }
    if(flagId==0)
    {
        resultado=-1;
    }
    return resultado;
}

void mostrarOrdenado(EProgramador plantel[],ECategoria categorias[])
{
    char desCat[20];
    int i,cat;
    for(i=0; i<MAX; i++)
    {
        if(plantel[i].id!=0)
        {
            cat=plantel[i].idCategoria-1;
            strcpy(desCat,categorias[cat].descripcion);
            printf("\nID: %d\tNOMBRE: %s\t CATEGORIA: %s\t SUELDO: %f",plantel[i].id,plantel[i].nombre,desCat,plantel[i].sueldo);
        }
    }
    printf("\n");
}

void eliminarProgramador(EProgramador plantel[])
{
    int x=buscarPorId(plantel);
    char respuesta='n';
    if(x==-1)
    {
        printf("El ID ingresado es erroneo\n");
    }
    else
    {
        printf("\nD: %d\tNOMBRE: %s\t CATEGORIA: %d\t SUELDO: %f",plantel[x].id,plantel[x].nombre,plantel[x].idCategoria,plantel[x].sueldo);
        printf("\nDesea eliminarlo? s/n: ");
        fflush(stdin);
        scanf("%c",&respuesta);
        if(respuesta=='s')
        {
            plantel[x].id=0;
            printf("Programador eliminado del plantel\n");
        }
        else
        {
            printf("Accion cancelada\n");
        }
    }
}

void categoriaMayor(EProgramador plantel[],ECategoria categorias[])
{
    int junior=0,senior=0,semisenior=0;
    int catMayor;
    char nomCatMayor[10];
    int i;
    for(i=0; i<MAX; i++)
    {
        if(plantel[i].id!=0)
        {
            switch(plantel[i].idCategoria)
            {
            case 1:
                junior+=1;
                break;
            case 2:
                semisenior+=1;
                break;
            case 3:
                senior+=1;
            }
        }
    }
    if(junior>=semisenior && junior>=senior)
    {
        catMayor=junior;
        strcpy(nomCatMayor,"Junior");
    }
    else
    {
        if(semisenior>=senior)
        {
            catMayor=semisenior;
            strcpy(nomCatMayor,"Semi Senior");
        }
        else
        {
            catMayor=senior;
            strcpy(nomCatMayor,"Senior");
        }
    }
    printf("La categoria mayor es %s con %d programadores\n",nomCatMayor,catMayor);
}

void modificarProgramador(EProgramador plantel[],ECategoria categorias[])
{
    int cat,i;
    char nombre[20]= {};
    int numcat;
    int catCheck=0;
    float sueldo;
    int modificacion=0;
    char desCat[20];
    int x=buscarPorId(plantel);
    if(x==-1)
    {
        printf("El ID ingresado es erroneo\n");
    }
    else
    {
        if(plantel[x].id!=0)
        {
            cat=plantel[x].idCategoria-1;
            strcpy(desCat,categorias[cat].descripcion);
            printf("\nID: %d\tNOMBRE: %s\t CATEGORIA: %s\t SUELDO: %f\n",plantel[x].id,plantel[x].nombre,desCat,plantel[x].sueldo);
            printf("Que desea modificar? (Nombre: 1/Categoria: 2/Sueldo: 3) :");
            scanf("%d",&modificacion);
            switch(modificacion)
            {
            case 1:
                printf("Ingrese el nuevo nombre: ");
                fflush(stdin);
                gets(nombre);
                strcpy(plantel[x].nombre,nombre);
                break;
            case 2:
                do
                {
                    printf("Ingrese la nueva categoria ");
                    printf("(Junior:1 SemiSenior:2 Senior:3):  ");
                    scanf("%d",&numcat);
                    for(i=0; i<3; i++)
                    {
                        if(numcat==categorias[i].id)
                        {
                            catCheck=1;
                            break;
                        }
                    }
                }
                while(catCheck==0);
                plantel[x].idCategoria=numcat;
                cat=plantel[x].idCategoria-1;
                strcpy(desCat,categorias[cat].descripcion);
                break;
            case 3:
                printf("Ingrese el nuevo sueldo: ");
                scanf("%f",&sueldo);
                plantel[x].sueldo=sueldo;
            }
            printf("Programador modificado: \n");
            printf("\nID: %d\tNOMBRE: %s\t CATEGORIA: %s\t SUELDO: %f\n",plantel[x].id,plantel[x].nombre,desCat,plantel[x].sueldo);

        }
    }
}

void mostrarUnProgramador(EProgramador plantel[],ECategoria categorias[])
{
    int cat;
    char desCat[20];
    int x=buscarPorId(plantel);
    if(x==-1)
    {
        printf("El ID ingresado es erroneo\n");
    }
    else
    {
        if(plantel[x].id!=0)
        {
            cat=plantel[x].idCategoria-1;
            strcpy(desCat,categorias[cat].descripcion);
            printf("\nID: %d\tNOMBRE: %s\t CATEGORIA: %s\t SUELDO: %f\n",plantel[x].id,plantel[x].nombre,desCat,plantel[x].sueldo);
        }
    }
}
