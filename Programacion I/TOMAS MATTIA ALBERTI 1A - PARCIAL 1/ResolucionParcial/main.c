#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"
#define TAMPRO 5
#define TAMPROY 5
#define TAMPROXPRO 5

int main()
{
    eProgramador listaProgramadores[TAMPRO];
    eProyecto listaProyectos[TAMPROY];
    eCategoria categorias[3];
    eProgramadoresEnProyectos listaProgramadoresEnProyectos[TAMPROXPRO];
    inicializarTodo(listaProgramadores,listaProyectos,listaProgramadoresEnProyectos,categorias);
    cargarProyectos(listaProyectos);
    cargarCategorias(categorias);
    char respuesta='s';
    int opcion;
    do
    {
        ordenarProgramadoresyProyectos(listaProgramadores,listaProyectos);
        opcion=0;
        if(checkearAsignaciones(listaProgramadores)==0)
        {
            printf("1- Agregar programador\n");
            printf("9- Salir\n");
            fflush(stdin);
            scanf("%d",&opcion);
            system("cls");
            while(opcion!=1 && opcion!=9)
            {
                printf("Mientras no haya ningun programador asignado esta son las opciones validas\n");
                printf("1- Agregar programador\n");
                printf("9- Salir\n");
                fflush(stdin);
                scanf("%d",&opcion);
                system("cls");
            }
        }
        else
        {
            printf("1- Agregar programador\n");
            printf("2- Modificar programador\n");
            printf("3- Eliminar programador\n");
            printf("4- Sumar programador a proyecto\n");
            printf("5- Mostrar programadores con horas\n");
            printf("6- Mostrar asignaciones a proyectos\n");
            printf("7- Mostrar un programador\n");
            printf("8- Proyecto mas demandante\n");
            printf("9- Salir\n");
            fflush(stdin);
            scanf("%d",&opcion);
        }
        switch(opcion)
        {
        case 1:
            agregarProgramador(listaProgramadores);
            break;
        case 2:
            modificarProgramador(listaProgramadores);
            break;
        case 3:
            eliminarProgramador(listaProgramadores);
            break;
        case 4:
            mostrarListadoProgramadores(listaProgramadores);
            mostrarListadoProyectos(listaProyectos);
            cargarProgramadorEnProyecto(listaProgramadores,listaProyectos,listaProgramadoresEnProyectos);
            break;
        case 5:
            mostrarListadoProgramadoresProyectosYSueldos(listaProgramadores,listaProyectos,listaProgramadoresEnProyectos,categorias);
            break;
        case 6:
            mostrarProyectosConProgramadores(listaProgramadores,listaProyectos,listaProgramadoresEnProyectos);
            break;
        case 7:
            mostrarProgramadorYsusProyectos(listaProgramadores,listaProyectos,listaProgramadoresEnProyectos);
            break;
        case 8:
            proyectoMasPopular(listaProyectos,listaProgramadoresEnProyectos);
            break;
        case 9:
            respuesta='n';
            break;
        default:
            printf("No es una entrada valida del menu\n");
            break;

        }
        system("pause");
        system("cls");

    }
    while(respuesta!='n');
    return 0;
}
