#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "lib.h"

int main()
{
    int opcion;
    char respuesta='s';
    ArrayList* totalTareas=al_newArrayList();
    ArrayList* tareasAlta=al_newArrayList();
    ArrayList* tareasBaja=al_newArrayList();
    do
    {
        opcion=0;
        menu();
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                if(cargarTareas(totalTareas)==0)
                {
                    printf("Listas cargadas con exito\n");
                }
                break;
            case 2:

                printf("Tareas Total :\n");
                mostrarTareas(totalTareas);
                ordenarTareas(totalTareas,tareasAlta,tareasBaja);
                printf("Tareas Alta :\n");
                if(tareasAlta->len(tareasAlta)==0)
                {
                    printf("No hay tareas de alta prioridad por resolver \n");
                }
                mostrarTareas(tareasAlta);
                printf("Tareas Baja :\n");
                if(tareasBaja->len(tareasBaja)==0)
                {
                    printf("No hay tareas de baja prioridad por resolver \n");
                }
                mostrarTareas(tareasBaja);
                break;
            case 3:
                tareasAlta->sort(tareasAlta,ordenarPorTiempo,0);
                printf("Tareas Alta :\n");
                if(tareasAlta->len(tareasAlta)==0)
                {
                    printf("No hay tareas de alta prioridad por resolver \n");
                }
                mostrarTareas(tareasAlta);
                tareasBaja->sort(tareasBaja,*ordenarPorTiempo,0);
                printf("Tareas Baja :\n");
                if(tareasBaja->len(tareasBaja)==0)
                {
                    printf("No hay tareas de baja prioridad por resolver \n");
                }
                mostrarTareas(tareasBaja);
                break;
            case 4:
                resolverUnaTarea(tareasAlta,tareasBaja);
                break;
            case 5:
                guardarTareas(tareasAlta,tareasBaja);
                break;
            case 6:
                respuesta='n';
                break;
            default:
                break;
        }
        system("pause");
        system("cls");
    }
    while(respuesta!='n');
    return 0;
}
