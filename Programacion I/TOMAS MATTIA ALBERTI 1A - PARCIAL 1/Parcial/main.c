#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <limits.h>
#include "lib.h"

int main()
{
    eProgramador lista[10];
    eProyecto proyectos[5];
    eProgramadoresXProyecto programadoresProyectos[15];
    eCategorias categorias[3];
    int i;
    int opcion=0;
    char respuesta='s';
    for(i=0;i<10;i++)
    {
        strcpy(lista[i].apellido," ");
        strcpy(lista[i].nombre," ");
        lista[i].idProgramador=0;
        lista[i].idCategoria=0;
    }
    for(i=0;i<5;i++)
    {
        strcpy(proyectos[i].nombre," ");
        proyectos[i].idProyecto=0;
    }
    for(i=0;i<15;i++)
    {
        programadoresProyectos[i].programador=0;
        programadoresProyectos[i].proyecto=0;
        programadoresProyectos[i].horasAsignadas=0;
    }
        cargarProgramadores(lista);
        cargarProyectos(proyectos);
        cargar_ProgramadoresXProyecto(programadoresProyectos);
    do
    {
        opcion=0;
        printf("1- Alta Programador\n");
        printf("2- Modificar Programador\n");
        printf("3- Baja Programador\n");
        printf("4- Asignar Programador a Proyecto\n");
        printf("5- Mostrar Programadores con proyectos\n");
        printf("6- Mostrar Proyectos con programadores\n");
        printf("7- Mostrar Proyectos de un Programador\n");
        printf("8- Mostrar Proyectos mas popular\n");
        printf("9- Salir\n");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                agregarCliente(lista);
                break;
            case 2:
                modificarDatos(lista);
                break;
            case 3:
                eliminarCliente(lista);
                break;
            case 4:
                asignarProgramador(lista,proyectos,programadoresProyectos);
                break;
            case 5:
                mostrarProgramadoresYSusProyectos(lista,proyectos,programadoresProyectos,10,5,15);
                break;
            case 6:
                mostrarProyectosConClientes(lista,proyectos,programadoresProyectos,10,5,15);
                break;
            case 7:
                mostrarProgramadorYsusProyectos(lista,proyectos,programadoresProyectos,10,5,15);
                break;
            case 8:
                proyectoMasPopular(lista,proyectos,programadoresProyectos,10,5,15);
                break;
            case 9:
                respuesta='n';
                break;
            default:
                printf("No es una opcion valida del menu\n");
                break;
        }
        system("pause");
        system("cls");
    }while(respuesta!='n');
    return 0;
}
