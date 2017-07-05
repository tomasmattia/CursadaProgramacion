#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "ArrayList.h"
#include "lib.h"

void menu(void)
{
    printf("1- Cargar lista de tareas\n");
    printf("2- Particionar por prioridad\n");
    printf("3- Ordenar\n");
    printf("4- Resolver tareas\n");
    printf("5- Generar\n");
    printf("6- Salir\n");
}

eTarea* newTarea()
{
    eTarea* returnAux=NULL;
    eTarea* nuevaTarea=(eTarea*)malloc(sizeof(eTarea));
    if(nuevaTarea!=NULL)
    {
        strcpy(nuevaTarea->nombre,"");
        nuevaTarea->prioridad=0;
        nuevaTarea->tiempo=0;
        returnAux=nuevaTarea;
    }
    return returnAux;
}

int cargarTareas(ArrayList* totalTareas)
{
    FILE *fp;
    int returnAux=-1;
    eTarea* unaTarea;
    char* nombre=(char*)malloc(sizeof(char)*15);
    char* prioridad=(char*)malloc(sizeof(char)*10);
    char* tiempo=(char*)malloc(sizeof(char)*10);
    fp = fopen("tareas.csv","r");
    if(fp!=NULL)
    {
        while(!feof(fp))
        {
            unaTarea=(eTarea*)malloc(sizeof(eTarea));
            if(unaTarea!=NULL)
            {
                if(feof(fp))
                {
                    break;
                }
                fscanf(fp,"%[^,],%[^,],%[^\n]\n",nombre,prioridad,tiempo);

                strcpy(unaTarea->nombre,nombre);
                unaTarea->prioridad=atoi(prioridad);
                unaTarea->tiempo=atoi(tiempo);

                totalTareas->add(totalTareas,unaTarea);

                returnAux=0;
            }
        }

    }
    fclose(fp);
    return returnAux;
}

void ordenarTareas(ArrayList* totalTareas,ArrayList* tareasAlta, ArrayList* tareasBaja)
{
    eTarea* unaTarea=newTarea();
    int i;
    for(i=0;i<totalTareas->len(totalTareas);i++)
    {
        unaTarea=totalTareas->get(totalTareas,i);
        if(unaTarea->prioridad==1)
        {
            tareasAlta->add(tareasAlta,unaTarea);
        }
        if(unaTarea->prioridad==0)
        {
            tareasBaja->add(tareasBaja,unaTarea);
        }
    }
    totalTareas->clear(totalTareas);
}

void mostrarUnaTarea(eTarea* unaTarea)
{
    printf("NOMBRE: %s / PRIORIDAD: %d / TIEMPO: %d\n",unaTarea->nombre,unaTarea->prioridad,unaTarea->tiempo);
}

void mostrarTareas(ArrayList* listaTareas)
{
    eTarea* unaTarea;
    int i;
    for(i=0;i<listaTareas->len(listaTareas);i++)
    {
        unaTarea=listaTareas->get(listaTareas,i);
        mostrarUnaTarea(unaTarea);
    }
}

int ordenarPorTiempo(void* tareaA,void* tareaB)
{
    int returnAux=0;
    if(((eTarea*)tareaA)->tiempo > ((eTarea*)tareaB)->tiempo)
    {
        returnAux=1;
    }
    if(((eTarea*)tareaA)->tiempo < ((eTarea*)tareaB)->tiempo)
    {
        returnAux=-1;
    }
    return returnAux;
}

void resolverUnaTarea(ArrayList* tareasAlta, ArrayList* tareasBaja)
{
    eTarea* unaTarea;
    int i;
    if(tareasAlta->len(tareasAlta)!=0)
    {
        i=tareasAlta->len(tareasAlta)-1;
        unaTarea=tareasAlta->pop(tareasAlta,i);
    }
    else
    {
        printf("No hay tareas de alta prioridad por resolver\n");
        i=tareasBaja->len(tareasBaja)-1;
        unaTarea=tareasBaja->pop(tareasBaja,i);
    }
    if(tareasBaja->len(tareasBaja)==0)
    {
        printf("No hay tareas de baja prioridad por resolver\n");
    }
    if(unaTarea!=NULL)
    {
        printf("Se resolvio la siguiente tarea: \n");
        mostrarUnaTarea(unaTarea);
    }
}

void guardarTareas(ArrayList* tareasAlta, ArrayList* tareasBaja)
{
    FILE *f;
    FILE *p;
    int i;
    eTarea* unaTarea;
    f=fopen("pAlta.csv","w");
    if(f == NULL)
    {
        printf("No se pudo crear el archivo");
        exit(1);
    }
    for(i=0; i<tareasAlta->len(tareasAlta); i++)
    {
        unaTarea=tareasAlta->get(tareasAlta,i);
        fprintf(f,"%s,%d,%d\n",unaTarea->nombre,unaTarea->prioridad,unaTarea->tiempo);
    }
    fclose(f);
    p=fopen("pBaja.csv","w");
    if(p == NULL)
    {
        printf("No se pudo crear el archivo");
        exit(1);
    }
    for(i=0; i<tareasBaja->len(tareasBaja); i++)
    {
        unaTarea=tareasBaja->get(tareasBaja,i);
        fprintf(p,"%s,%d,%d\n",unaTarea->nombre,unaTarea->prioridad,unaTarea->tiempo);
    }
    printf("Se guardaron todas las listas correctamente\n");
    fclose(p);
}
