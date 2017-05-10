#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <limits.h>
#include "lib.h"

void cargarProgramadores(eProgramador lista[])
{
    int idProgramadores[10] = {0,1,2,3,4,5,6,7,8,9};
    char nombres[10][30]= {"juan","maria","pedro","luis","romina","jose","andrea","pato","luciano","camila"};
    char apellidos[10][30]= {"gomez","perez","rodri","verlo","salo","sepo","zappa","lopez","smith","kopa"};
    int idCategorias[10]= {1,2,1,2,3,1,3,1,2,3};
    int i;
    for(i=0; i<10; i++)
    {
        lista[i].idProgramador = idProgramadores[i];
        strcpy(lista[i].nombre, nombres[i]);
        strcpy(lista[i].apellido, apellidos[i]);
        lista[i].idCategoria = idCategorias[i];
    }
}

void cargarCategorias(eCategorias categorias[])
{
    char desCategoria[3][20]={"Junior","Semi-Senior","Senior"};
    int idCat[3]={1,2,3};
    int pagoxCat[3]={100,200,300};
}

void cargarProyectos(eProyecto proyectos[])
{
    int idProyectosp[5] = {100,101,102,103,104};
    char nombresp[5][30]= {"TBBT","BB","GOT","AHS","SCD"};
    int i;
    for(i=0; i<5; i++)
    {
        proyectos[i].idProyecto = idProyectosp[i];
        strcpy(proyectos[i].nombre, nombresp[i]);
    }
}

void cargar_ProgramadoresXProyecto(eProgramadoresXProyecto programadoresProyectos[])
{
    int programadores[15] = {1,1,1,2,3,4,5,6,7,7,8,8,8,9,9};
    int proyectos[15]= {101,103,104,103,101,101,102,101,101,101,103,102,101,102,104};
    int horas[15]={1,1,1,2,3,4,5,6,7,7,8,8,8,9,9};
    int i;
    for(i=0; i<15; i++)
    {
        programadoresProyectos[i].programador=programadores[i];
        programadoresProyectos[i].proyecto = proyectos[i];
        programadoresProyectos[i].horasAsignadas=horas[i];
    }
}

int obtenerEspacioLibre(eProgramador lista[])
{
    int i;
    int resultado;
    int flagEspacio=0;
    for(i=0; i<10; i++)
    {
        if(lista[i].idCategoria==0) // SI ENCUENTRA LUGAR
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

void agregarCliente(eProgramador lista[])
{
    int ubicacionLista=obtenerEspacioLibre(lista);
    char auxNombre[100]= {};
    char auxApellido[100]= {};
    int largo;
    int i;
    int auxCat=0;
    if(ubicacionLista==-1) // SI NO HAY ESPACIO
    {
        printf("Se completo el espacio, necesita borrar un cliente\n");
    }
    else // SI HAY ESPACIO
    {
        lista[ubicacionLista].idProgramador=ubicacionLista;
        printf("Ingrese el apellido: ");
        fflush(stdin);
        gets(auxApellido);
        while(strlen(auxApellido)>49)
        {
            printf("Demasiado extenso, reingrese el apellido: ");
            fflush(stdin);
            gets(auxApellido);
        }
        largo=strlen(auxApellido);
        for(i=0; i<largo; i++)
        {
            auxApellido[i]=toupper(auxApellido[i]);
        }
        strcpy(lista[ubicacionLista].apellido,auxApellido);
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(auxNombre);
        while(strlen(auxNombre)>49)
        {
            printf("Demasiado extenso, reingrese el nombre: ");
            fflush(stdin);
            gets(auxNombre);
        }
        largo=strlen(auxNombre);
        for(i=0; i<largo; i++)
        {
            auxNombre[i]=toupper(auxNombre[i]);
        }
        strcpy(lista[ubicacionLista].nombre,auxNombre);
        printf("Ingresar categoria (1/2/3): ");
        fflush(stdin);
        scanf("%d",&auxCat);
        while(auxCat<1 || auxCat>3 || isalpha(auxCat))
        {
            printf("Error, reingresar categoria (1/2/3): ");
            fflush(stdin);
            scanf("%d",&auxCat);
        }
        lista[ubicacionLista].idCategoria=auxCat;
    }
}

int buscarPorId(eProgramador lista[])
{
    int i;
    int resultado;
    int flagId=0;
    int idProgramador;
    printf("Ingrese el ID del Programador a buscar: ");
    scanf("%d",&idProgramador);
    for(i=0; i<20; i++)
    {
        if(idProgramador==lista[i].idProgramador && lista[i].idCategoria!=0)
        {
            resultado=i;
            flagId=1;
            break;
        }
    }
    if(flagId==0)
    {
        resultado=-1;
    }
    return resultado;
}

void eliminarCliente(eProgramador lista[])
{
    int ubicacionLista=buscarPorId(lista);
    char respuesta='n';
    if(ubicacionLista==-1) // SI EL DNI NO EXISTE
    {
        printf("El ID ingresado es erroneo\n");
    }
    else // SI EL DNI EXISTE
    {
        printf("\nID: %d\tNOMBRE: %s\tAPELLIDO: %s\tCATEGORIA: %d",lista[ubicacionLista].idProgramador,lista[ubicacionLista].nombre,lista[ubicacionLista].apellido,lista[ubicacionLista].idCategoria);
        printf("\nDesea eliminarlo? s/n: ");
        fflush(stdin);
        scanf("%c",&respuesta);
        if(respuesta=='s')
        {
            lista[ubicacionLista].idCategoria=0;
            printf("Persona eliminada de la lista\n");
        }
        else
        {
            printf("Accion cancelada\n");
        }
    }
}

void mostrarOrdenado(eProgramador lista[])
{
    int i,j;
    eProgramador aux= {};
    for(i=0; i<10-1; i++)
    {
        for(j=i+1; j<10; j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
    for(i=0; i<10; i++)
    {
        if(lista[i].idCategoria!=0 && lista[i].idProgramador>=0)
        {
            printf("\nID: %d\tNOMBRE: %s\tAPELLIDO: %s\tCATEGORIA: %d",lista[i].idProgramador,lista[i].nombre,lista[i].apellido,lista[i].idCategoria);
        }
    }
    printf("\n");
}

void modificarDatos(eProgramador lista[])
{
    int opcion=0;
    char auxNombre[100]={};
    char auxApellido[100]={};
    int auxCat=0;
    int i;
    int largo;
    int idModificar=buscarPorId(lista);
    if(idModificar==-1 || lista[idModificar].idCategoria==0) // SI EL DNI NO EXISTE
    {
        printf("El ID ingresado es erroneo\n");
    }
    else
    {
        printf("Ingrese que dato desea modificar: \n");
        printf("1- NOMBRE\n");
        printf("2- APELLIDO\n");
        printf("3- CATEGORIA\n");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                printf("Ingrese el nuevo NOMBRE: ");
                scanf("%s",auxNombre);
                while(strlen(auxNombre)>49)
                {
                    printf("Demasiado extenso, reingrese el nombre: ");
                    fflush(stdin);
                    gets(auxNombre);
                }
                largo=strlen(auxNombre);
                for(i=0; i<largo; i++)
                {
                    auxNombre[i]=toupper(auxNombre[i]);
                }
                strcpy(lista[idModificar].nombre,auxNombre);
                break;
            case 2:
                printf("Ingrese el nuevo APELLIDO: ");
                scanf("%s",auxApellido);
                while(strlen(auxApellido)>49)
                {
                    printf("Demasiado extenso, reingrese el apellido: ");
                    fflush(stdin);
                    gets(auxApellido);
                }
                largo=strlen(auxApellido);
                for(i=0; i<largo; i++)
                {
                    auxApellido[i]=toupper(auxApellido[i]);
                }
                strcpy(lista[idModificar].apellido,auxApellido);
                break;
            case 3:
                printf("Ingrese la nueva CATEGORIA (1/2/3): ");
                fflush(stdin);
                scanf("%d",&auxCat);
                while(auxCat<1 || auxCat>3 || isalpha(auxCat))
                {
                    printf("Error, reingresar categoria (1/2/3): ");
                    fflush(stdin);
                    scanf("%d",&auxCat);
                }
                lista[idModificar].idCategoria=auxCat;
                break;
            default:
                printf("No es una opcion valida: ");
                break;
            }
        }
}

void mostrarProyectos(eProyecto proyectos[])
{
    int i;
    printf("PROYECTOS: \n");
    printf("ID\tNOMBRE\n");
    for(i=0;i<5;i++)
    {
        printf("%d\t%s\n",proyectos[i].idProyecto,proyectos[i].nombre);
    }
}

int obtenerProyectoXProgramador(eProgramadoresXProyecto programadoresProyectos[],eProyecto proyectos[])
{
    int i,j;
    int resultado;
    int flagEspacio=0;
    for(i=0; i<15; i++)
    {
        for(j=0;i<5;i++)
        {
            if(programadoresProyectos[i].proyecto==proyectos[j].idProyecto) // SI ENCUENTRA LUGAR
            {
                resultado=i;
                flagEspacio=1;
                break;
            }
        }
    }
    if(flagEspacio==0)
    {
        resultado=-1;
    }
    return resultado;
}

void asignarProgramador(eProgramador lista[],eProyecto proyectos[],eProgramadoresXProyecto programadoresProyectos[])
{
    int i;
    int auxProyecto;
    int auxProgramador;
    int flagProyecto;
    int flagProgramador;
    int horasAsignar;
    mostrarOrdenado(lista);
    mostrarProyectos(proyectos);
    int idModificar=buscarPorId(lista);
    int espacioProyecto=obtenerProyectoXProgramador(programadoresProyectos,proyectos);
    if(espacioProyecto==-1) // SI EL DNI NO EXISTE
    {
        printf("No hay espacio para asignar mas\n");
    }
    else
    {
        if(idModificar==-1 || lista[idModificar].idCategoria==0) // SI EL DNI NO EXISTE
        {
            printf("El ID ingresado es erroneo\n");
        }
        flagProgramador=0;
        flagProyecto=0;
        do
        {
            printf("Ingrese el ID de Proyecto a Asignar: ");
            scanf("%d",&auxProyecto);
            for(i=0;i<5;i++)
            {
                if(proyectos[i].idProyecto==auxProyecto)
                {
                    flagProyecto=1;
                    break;
                }
            }
        }while(flagProyecto==0);
        programadoresProyectos[espacioProyecto].proyecto=auxProyecto;
        do
        {
            printf("Ingrese el ID de Programador a Asignar: ");
            scanf("%d",&auxProgramador);
            for(i=0;i<10;i++)
            {
                if(proyectos[i].idProyecto==auxProgramador)
                {
                    flagProgramador=1;
                    break;
                }
            }
        }while(flagProgramador==0);
        programadoresProyectos[espacioProyecto].proyecto=auxProgramador;
        printf("Ingrese la cantidad de horas a asignar: ");
        scanf("%d",&horasAsignar);
        programadoresProyectos[espacioProyecto].horasAsignadas=horasAsignar;
    }
}

void mostrarProgramadoresYSusProyectos(eProgramador lista[],eProyecto proyectos[],eProgramadoresXProyecto programadoresProyectos[],int tamprog, int tamproyect, int tampxp)
{
    int i,j,k;
    for(i=0; i<tamprog; i++)
    {
        if(lista[i].idCategoria!=0)
        {
            printf("%s TRABAJA EN: \t",lista[i].nombre);
            for(j=0;j<tampxp;j++)
            {
                if(lista[i].idProgramador==programadoresProyectos[j].programador)
                {
                    for(k=0; k<tamproyect; k++)
                    {
                        if(programadoresProyectos[j].proyecto==proyectos[k].idProyecto)
                        {
                            printf("%s\t",proyectos[k].nombre);
                        }
                    }
                }
            }
            printf("\n");
        }
    }
}

void mostrarProyectosConClientes(eProgramador lista[],eProyecto proyectos[],eProgramadoresXProyecto programadoresProyectos[],int tamprog, int tamproyect, int tampxp)
{
    int cantprogramadores=0;
    int i,j,k;
    for(i=0;i<tamproyect;i++)
    {
        cantprogramadores=0;
        printf("%s: ",proyectos[i].nombre);
        for(j=0;j<tampxp;j++)
        {
            if(proyectos[i].idProyecto==programadoresProyectos[j].proyecto)
            {
                for(k=0;k<tamprog;k++)
                {
                    if(programadoresProyectos[j].programador==lista[k].idProgramador)
                    {
                        printf("%s %s\t",lista[k].nombre,lista[k].apellido);
                        cantprogramadores+=1;
                    }
                }
            }
        }
        printf("Trabajan %d programadores",cantprogramadores);
        printf("\n");
    }
}

void mostrarProgramadorYsusProyectos(eProgramador lista[],eProyecto proyectos[],eProgramadoresXProyecto programadoresProyectos[],int tamprog, int tamproyect, int tampxp)
{
    int i,j,k;
    mostrarOrdenado(lista);
    int progMostrar;
    int flag=0;
    printf("Ingrese el ID de Programador a mostrar: ");
    scanf("%d",&progMostrar);
    for(i=0;i<tamprog;i++)
    {
        if(progMostrar==lista[i].idProgramador)
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
        printf("El programador %s trabaja en : ",lista[i].nombre);
        for(j=0;j<tampxp;j++)
        {
            if(progMostrar==programadoresProyectos[j].programador)
            {
                for(k=0;k<tamproyect;k++)
                {
                    if(programadoresProyectos[j].proyecto==proyectos[k].idProyecto)
                    {
                        printf("%s ",proyectos[k].nombre);
                    }
                }
            }
        }
        printf("\n");
    }
}

void proyectoMasPopular(eProgramador lista[],eProyecto proyectos[],eProgramadoresXProyecto programadoresProyectos[],int tamprog, int tamproyect, int tampxp)
{
    int i,j;
    ePopular popularidadProyecto[5]={};
    int cont;
    int maximo=0;
    for(i=0;i<tamproyect;i++)
    {
        cont=0;
        popularidadProyecto[i].idProyect=proyectos[i].idProyecto;
        for(j=0;j<tampxp;j++)
        {
            if(proyectos[i].idProyecto==programadoresProyectos[j].proyecto)
            {
                cont+=1;
            }
        }
        popularidadProyecto[i].cont=cont;
        if(cont>maximo)
        {
            maximo=cont;
        }
    }
    for(i=0;i<tamproyect;i++)
    {
        if(popularidadProyecto[i].cont==maximo)
        {
            printf("El proyecto con mas programadores es %s\n",proyectos[i].nombre);
        }
    }
}
