#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"
#define TAMPRO 50
#define TAMPROY 1000
#define TAMPROXPRO 5

void inicializarTodo(eProgramador listaProgramadores[],eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[],eCategoria categorias[])
{
    int i;
    for(i=0; i<TAMPRO; i++)
    {
        listaProgramadores[i].idProgramador=0;
        listaProgramadores[i].idCategoria=0;
        strcpy(listaProgramadores[i].apellido," ");
        strcpy(listaProgramadores[i].nombre," ");
    }
    for(i=0; i<TAMPROY; i++)
    {
        listaProyectos[i].idProyecto=0;
        strcpy(listaProyectos[i].nombreProyecto," ");
    }
    for(i=0; i<TAMPROXPRO; i++)
    {
        listaProgramadoresEnProyectos[i].programador=0;
        listaProgramadoresEnProyectos[i].programador=0;
        listaProgramadoresEnProyectos[i].horasAsignadas=0;
    }
    for(i=0; i<3; i++)
    {
        strcpy(categorias[i].descCategoria," ");
        categorias[i].idCategoria=0;
        categorias[i].pagoXHora=0;
    }
}

void cargarProyectos(eProyecto listaProyectos[])
{
    int i;
    int id[5]= {500,501,502,503,504};
    char nombre[5][30]= {"PROX","SAS","VOLTA","NAVI","TESLA"};
    for(i=0; i<5; i++)
    {
        listaProyectos[i].idProyecto=id[i];
        strcpy(listaProyectos[i].nombreProyecto,nombre[i]);
    }
}

void cargarCategorias(eCategoria categorias[])
{
    int i;
    char descCategoria[][30]= {"Junior","Semi-Senior","Senior"};
    int idCategoria[]= {1,2,3};
    int pagoXHora[]= {100,200,300};
    for(i=0; i<3; i++)
    {
        strcpy(categorias[i].descCategoria,descCategoria[i]);
        categorias[i].idCategoria=idCategoria[i];
        categorias[i].pagoXHora=pagoXHora[i];
    }
}

void mostrarListadoProyectos(eProyecto listaProyectos[])
{
    int i;
    printf("PROYECTOS\n");
    for(i=0; i<TAMPROY; i++)
    {
        if(listaProyectos[i].idProyecto!=0)
        {
            printf("ID: %d NOMBRE: %s\n",listaProyectos[i].idProyecto,listaProyectos[i].nombreProyecto);
        }
    }
}

int buscarEspacioLibre(eProgramador listaProgramadores[])
{
    int i;
    int flagEspacio;
    for(i=0; i<TAMPRO; i++)
    {
        flagEspacio=0;
        if(listaProgramadores[i].idProgramador==0 && listaProgramadores[i].idCategoria==0)
        {
            flagEspacio=1;
            break;
        }
    }
    if(flagEspacio==1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int buscarPorId(eProgramador listaProgramadores[],int idABuscar)
{
    int i;
    int flagId=0;
    for(i=0; i<TAMPRO; i++)
    {
        if(listaProgramadores[i].idProgramador==idABuscar && listaProgramadores[i].idCategoria!=0)
        {
            flagId=1;
            break;
        }
    }
    if(flagId==1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

void validarString(char stringAValid[], int maximo)
{
    int largo=strlen(stringAValid);
    while(largo>maximo)
    {
        printf("Se excedio del tamano reingrese: ");
        stringAValid=gets(stringAValid);
        largo=strlen(stringAValid);
    }
}

int checkearNumero(int numero,int minimo,int maximo)
{
    int checkNum=numero;
    while(checkNum<minimo || checkNum>maximo)
    {
        printf("Por Favor reingrese: ");
        fflush(stdin);
        scanf("%d", &checkNum);
    }
    return checkNum;
}

void agregarProgramador(eProgramador listaProgramadores[])
{
    int lugarEnLista=buscarEspacioLibre(listaProgramadores);
    char aux[100]= {};
    int auxNum;
    if(lugarEnLista<0)
    {
        printf("Se ocuparon todos los lugares\n");
    }
    else
    {
        listaProgramadores[lugarEnLista].idProgramador=(lugarEnLista+1);
        printf("Ingrese el nombre del programador: ");
        fflush(stdin);
        gets(aux);
        validarString(aux,50);
        strcpy(listaProgramadores[lugarEnLista].nombre,aux);
        printf("Ingrese el apellido del programador: ");
        fflush(stdin);
        gets(aux);
        validarString(aux,50);
        strcpy(listaProgramadores[lugarEnLista].apellido,aux);
        printf("Ingrese la categoria del programador: ");
        fflush(stdin);
        scanf("%d",&auxNum);
        auxNum=checkearNumero(auxNum,1,3);
        listaProgramadores[lugarEnLista].idCategoria=auxNum;
    }
    //printf("%d %s %s %d\n",listaProgramadores[lugarEnLista].idProgramador,listaProgramadores[lugarEnLista].nombre,listaProgramadores[lugarEnLista].apellido,listaProgramadores[lugarEnLista].idCategoria);
}

void modificarProgramador(eProgramador listaProgramadores[])
{
    int idModificar;
    int opcion=0;
    char aux[100]= {};
    int auxNum=0;
    printf("Ingrese el ID del programador a modificar: ");
    scanf("%d",&idModificar);
    idModificar=buscarPorId(listaProgramadores,idModificar);
    if(idModificar<0)
    {
        printf("El ID ingresado no corresponde a ningun programador\n");
    }
    else
    {
        printf("ID: %d NOMBRE: %s %s CATEGORIA: %d\n",listaProgramadores[idModificar].idProgramador,listaProgramadores[idModificar].nombre,listaProgramadores[idModificar].apellido,listaProgramadores[idModificar].idCategoria);
        printf("Que desea modificar?\n");
        printf("1- NOMBRE\n");
        printf("2- APELLIDO\n");
        printf("3- CATEGORIA\n");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese el nuevo nombre: ");
            fflush(stdin);
            gets(aux);
            validarString(aux,50);
            strcpy(listaProgramadores[idModificar].nombre,aux);
            break;
        case 2:
            printf("Ingrese el nuevo apellido: ");
            fflush(stdin);
            gets(aux);
            validarString(aux,50);
            strcpy(listaProgramadores[idModificar].apellido,aux);
            break;
        case 3:
            printf("Ingrese la nueva categoria: ");
            fflush(stdin);
            scanf("%d",&auxNum);
            auxNum=checkearNumero(auxNum,1,3);
            listaProgramadores[idModificar].idCategoria=auxNum;
            break;
        default:
            printf("No es una opcion valida\n");
            break;
        }
    }
}

void eliminarProgramador(eProgramador listaProgramadores[])
{
    int idEliminar;
    char respuesta='s';
    printf("Ingrese el ID del programador a eliminar: ");
    scanf("%d",&idEliminar);
    idEliminar=buscarPorId(listaProgramadores,idEliminar);
    if(idEliminar<0)
    {
        printf("El ID ingresado no corresponde a ningun programador\n");
    }
    else
    {
        printf("ID: %d NOMBRE: %s %s CATEGORIA: %d\n",listaProgramadores[idEliminar].idProgramador,listaProgramadores[idEliminar].nombre,listaProgramadores[idEliminar].apellido,listaProgramadores[idEliminar].idCategoria);
        printf("Desea eliminarlo? s/n: ");
        fflush(stdin);
        scanf("%c",&respuesta);
        if(respuesta=='s')
        {
            listaProgramadores[idEliminar].idCategoria=0;
            listaProgramadores[idEliminar].idProgramador=0;
            printf("Accion completada\n");
        }
        else
        {
            printf("Accion cancelada\n");
        }
    }
}

void ordenarProgramadoresyProyectos(eProgramador listaProgramadores[],eProyecto listaProyectos[])
{
    int i,j;
    eProgramador auxProg= {};
    eProyecto auxProy= {};
    for(i=0; i<TAMPRO-1; i++)
    {
        for(j=i+1; j<TAMPRO; j++)
        {
            if(listaProgramadores[i].idProgramador>listaProgramadores[j].idProgramador && listaProgramadores[i].idProgramador!=0 && listaProgramadores[j].idProgramador!=0)
            {
                auxProg=listaProgramadores[i];
                listaProgramadores[i]=listaProgramadores[j];
                listaProgramadores[j]=auxProg;
            }
        }
    }
    for(i=0; i<TAMPROY-1; i++)
    {
        for(j=i+1; j<TAMPROY; j++)
        {
            if(listaProyectos[i].idProyecto>listaProyectos[j].idProyecto && listaProyectos[i].idProyecto!=0 && listaProyectos[j].idProyecto!=0)
            {
                auxProy=listaProyectos[i];
                listaProyectos[i]=listaProyectos[j];
                listaProyectos[j]=auxProy;
            }
        }
    }
}

void mostrarListadoProgramadores(eProgramador listaProgramadores[])
{
    int i;
    int flagEstado=0;
    for(i=0; i<TAMPRO; i++)
    {
        if(listaProgramadores[i].idCategoria!=0)
        {
            flagEstado=1;
            printf("ID: %d\tNOMBRE: %s %s\tCATEGORIA: %d\n",listaProgramadores[i].idProgramador,listaProgramadores[i].nombre,listaProgramadores[i].apellido,listaProgramadores[i].idCategoria);
        }
    }
    if(flagEstado==0)
    {
        printf("No hay programadores cargados\n");
    }
}


int buscarEspacioLibreEnProyectos(eProgramadoresEnProyectos listaProgramadoresEnProyectos[])
{
    int i;
    int flagEspacio;
    for(i=0; i<TAMPROXPRO; i++)
    {
        flagEspacio=0;
        if(listaProgramadoresEnProyectos[i].horasAsignadas==0)
        {
            flagEspacio=1;
            break;
        }
    }
    if(flagEspacio==1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int buscarPorIdProyecto(eProyecto listaProyectos[],int idABuscar)
{
    int i;
    int flagId=0;
    for(i=0; i<TAMPRO; i++)
    {
        if(listaProyectos[i].idProyecto==idABuscar)
        {
            flagId=1;
            break;
        }
    }
    if(flagId==1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

void cargarProgramadorEnProyecto(eProgramador listaProgramadores[],eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[])
{
    int hayEspacio=buscarEspacioLibreEnProyectos(listaProgramadoresEnProyectos);
    int idABuscarProgramador;
    int idABuscarProyecto;
    int horasAAsignar;
    if(hayEspacio<0)
    {
        printf("No hay mas lugares para asignar\n");
    }
    else
    {
        printf("Ingrese el ID del programador: ");
        fflush(stdin);
        scanf("%d",&idABuscarProgramador);
        idABuscarProgramador=buscarPorId(listaProgramadores,idABuscarProgramador);
        while(idABuscarProgramador<0)
        {
            printf("El ID ingresado no corresponde a ningun programador, reingrese: ");
            fflush(stdin);
            scanf("%d",&idABuscarProgramador);
            idABuscarProgramador=buscarPorId(listaProgramadores,idABuscarProgramador);
        }
        listaProgramadoresEnProyectos[hayEspacio].programador=listaProgramadores[idABuscarProgramador].idProgramador;
        printf("Ingrese el ID del proyecto: ");
        fflush(stdin);
        scanf("%d",&idABuscarProyecto);
        idABuscarProyecto=buscarPorIdProyecto(listaProyectos,idABuscarProyecto);
        while(idABuscarProyecto<0)
        {
            printf("El ID ingresado no corresponde a ningun proyecto, reingrese: ");
            fflush(stdin);
            scanf("%d",&idABuscarProyecto);
            idABuscarProyecto=buscarPorIdProyecto(listaProyectos,idABuscarProyecto);
        }
        listaProgramadoresEnProyectos[hayEspacio].proyecto=listaProyectos[idABuscarProyecto].idProyecto;
        printf("Ingrese la cantidad de horas a asignar: ");
        scanf("%d",&horasAAsignar);
        while(horasAAsignar<0)
        {
            printf("El valor de horas debe ser positivo: ");
            scanf("%d",&horasAAsignar);
        }
        listaProgramadoresEnProyectos[hayEspacio].horasAsignadas=horasAAsignar;
    }
}

void mostrarListadoProgramadoresProyectosYSueldos(eProgramador listaProgramadores[],eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[],eCategoria categorias[])
{
    int i,j,k;
    int horasTrabajadas;
    int flagEstado=0;
    int categoria;
    int sueldo;
    int precioHora;
    for(i=0; i<TAMPRO; i++)
    {
        horasTrabajadas=0;
        sueldo=0;
        if(listaProgramadores[i].idCategoria!=0 && listaProgramadores[i].idProgramador!=0)
        {
            categoria=(listaProgramadores[i].idCategoria)-1;
            flagEstado=1;
            printf("ID: %d\tNOMBRE: %s %s\tCATEGORIA: %s\n",listaProgramadores[i].idProgramador,listaProgramadores[i].nombre,listaProgramadores[i].apellido,categorias[categoria].descCategoria);
            printf("TRABAJA EN:\n");
            precioHora=categorias[categoria].pagoXHora;
            for(j=0; j<TAMPROXPRO; j++)
            {
                if(listaProgramadores[i].idProgramador==listaProgramadoresEnProyectos[j].programador)
                {
                    for(k=0; k<TAMPROY; k++)
                    {
                        horasTrabajadas=0;
                        if(listaProgramadoresEnProyectos[j].proyecto==listaProyectos[k].idProyecto)
                        {
                            printf("%s -",listaProyectos[k].nombreProyecto);
                            horasTrabajadas+=listaProgramadoresEnProyectos[j].horasAsignadas;
                            sueldo=horasTrabajadas*precioHora;
                            printf("TRABAJA %d HORAS Y COBRA %d POR ESTA ASIGNACION\n",horasTrabajadas,sueldo);
                        }
                    }
                }
            }
        }
    }
    if(flagEstado==0)
    {
        printf("No hay programadores cargados\n");
    }
}

void mostrarProgramadoresYSusProyectos(eProgramador listaProgramadores[],eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[])
{
    int i,j,k;
    for(i=0; i<TAMPRO; i++)
    {
        if(listaProgramadores[i].idCategoria!=0)
        {
            printf("%s TRABAJA EN: ",listaProgramadores[i].nombre);
            for(j=0; j<TAMPROXPRO; j++)
            {
                if(listaProgramadores[i].idProgramador==listaProgramadoresEnProyectos[j].programador)
                {
                    for(k=0; k<TAMPROY; k++)
                    {
                        if(listaProgramadoresEnProyectos[j].proyecto==listaProyectos[k].idProyecto)
                        {
                            printf("%s ",listaProyectos[k].nombreProyecto);
                        }
                    }
                }
            }
            printf("\n");
        }
    }
    /*for(i=0;i<TAMPROXPRO;i++)
    {
        if(listaProgramadoresEnProyectos[i].horasAsignadas!=0)
        {
            printf("%d %d %d\n",listaProgramadoresEnProyectos[i].programador,listaProgramadoresEnProyectos[i].proyecto,listaProgramadoresEnProyectos[i].horasAsignadas);
        }
    }*/
}

void mostrarProyectosConProgramadores(eProgramador listaProgramadores[],eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[])
{
    int cantProgramadores=0;
    int i,j,k;
    for(i=0; i<TAMPROY; i++)
    {
        if(listaProyectos[i].idProyecto!=0)
        {
            cantProgramadores=0;
            printf("%s: ",listaProyectos[i].nombreProyecto);
            for(j=0; j<TAMPROXPRO; j++)
            {
                if(listaProyectos[i].idProyecto==listaProgramadoresEnProyectos[j].proyecto && listaProyectos[j].idProyecto!=0)
                {
                    for(k=0; k<TAMPRO; k++)
                    {
                        if(listaProgramadoresEnProyectos[j].programador==listaProgramadores[k].idProgramador)
                        {
                            printf("%s %s -\t",listaProgramadores[k].nombre,listaProgramadores[k].apellido);
                            cantProgramadores+=1;
                        }
                    }
                }
            }
            printf("Trabajan %d programadores",cantProgramadores);
            printf("\n");
        }
    }
}

void mostrarProgramadorYsusProyectos(eProgramador listaProgramadores[],eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[])
{
    int i,j,k;
    mostrarListadoProgramadores(listaProgramadores);
    int progMostrar;
    int flag=0;
    printf("Ingrese el ID de Programador a mostrar: ");
    scanf("%d",&progMostrar);
    for(i=0; i<TAMPRO; i++)
    {
        if(progMostrar==listaProgramadores[i].idProgramador)
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
        printf("El programador %s trabaja en : ",listaProgramadores[i].nombre);
        for(j=0; j<TAMPROXPRO; j++)
        {
            if(progMostrar==listaProgramadoresEnProyectos[j].programador)
            {
                for(k=0; k<TAMPROY; k++)
                {
                    if(listaProgramadoresEnProyectos[j].proyecto==listaProyectos[k].idProyecto)
                    {
                        printf("%s ",listaProyectos[k].nombreProyecto);
                    }
                }
            }
        }
        printf("\n");
    }
}

void proyectoMasPopular(eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[])
{
    int i,j;
    eWinner popularidadProyecto[5]= {};
    int cont;
    int maximo=0;
    for(i=0; i<TAMPROY; i++)
    {
        if(listaProyectos[i].idProyecto!=0)
        {
            cont=0;
            popularidadProyecto[i].proyecto=listaProyectos[i].idProyecto;
            for(j=0; j<TAMPROXPRO; j++)
            {
                if(listaProyectos[i].idProyecto==listaProgramadoresEnProyectos[j].proyecto && listaProyectos[j].idProyecto!=0)
                {
                    cont+=1;
                }
            }
            popularidadProyecto[i].cantProgramadores=cont;
            if(cont>maximo)
            {
                maximo=cont;
            }
        }
    }
    for(i=0; i<TAMPROY; i++)
    {
        if(maximo==0)
        {
            printf("No hay programadores asignados en ningun proyecto\n");
            break;
        }
        if(popularidadProyecto[i].cantProgramadores==maximo && maximo!=0 && listaProyectos[i].idProyecto!=0)
        {
            printf("El proyecto con mas programadores es %s\n",listaProyectos[i].nombreProyecto);
        }
    }
}

int checkearAsignaciones(eProgramador listaProgramadores[])
{
    int i;
    int flagAsignaciones=0;
    for(i=0; i<TAMPRO; i++)
    {
        if(listaProgramadores[i].idProgramador!=0 && listaProgramadores[i].idCategoria!=0)
        {
            flagAsignaciones=1;
            break;
        }
    }
    if(flagAsignaciones==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


