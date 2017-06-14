#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "arrayImp.h"
#include "ArrayList.h"


void menu(void)
{
    printf("1- Dar de alta un programador\n");
    printf("2- Editar un programador\n");
    printf("3- Dar de baja un programador\n");
    printf("4- Mostrar lista de programadores\n");
    printf("5-\n");
    printf("6-\n");
    printf("7- Salir\n");
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

int checkearNumero(char* numero,int minimo,int maximo)
{
    int i;
    int largo=strlen(numero);
    int flag;
    int numCheck;
    do
    {
        do
        {
            flag=0;
            for(i=0; i<largo; i++)
            {
                if(!isdigit(numero[i]))
                {
                    flag=1;
                    break;
                }
            }
            if(flag!=0)
            {
                printf("Por Favor reingrese: ");
                fflush(stdin);
                gets(numero);
            }
        }while(flag!=0);
        numCheck=atoi(numero);
        if(numCheck<minimo || numCheck>maximo)
        {
            printf("Por Favor reingrese: ");
            fflush(stdin);
            gets(numero);
        }
    }while(numCheck<minimo || numCheck>maximo);
    return numCheck;
}

eProgramador* newProgramador(int id,char nombre[],char apellido[],int categoria)
{
    eProgramador* returnAux=NULL;
    eProgramador* nuevoProgramador=(eProgramador*)malloc(sizeof(eProgramador));
    if(nuevoProgramador!=NULL)
    {
        nuevoProgramador->id=id;
        strcpy(nuevoProgramador->nombre,nombre);
        strcpy(nuevoProgramador->apellido,apellido);
        nuevoProgramador->idCategoria=categoria;
        returnAux=nuevoProgramador;
    }
    return returnAux;
}

int checkearId(ArrayList* listaProgramadores,int id)
{
    int i;
    int returnAux=0;
    eProgramador* programadorAux;
    if(id!=0)
    {
        for(i=0; i<listaProgramadores->size; i++)
        {
            programadorAux=listaProgramadores->get(listaProgramadores,i);
            if(programadorAux->id==id)
            {
                returnAux=1;
            }
        }
    }
    return returnAux;
}

void altaProgramador(ArrayList* listaProgramadores)
{
    eProgramador* nuevoProgramador;
    int max=INT_MAX;
    char* id=(char*)malloc(sizeof(char)*10);
    char* categoria=(char*)malloc(sizeof(char)*10);;
    char nombre[100];
    char apellido[100];
    int idNum;
    int catNum;
    printf("Ingrese el ID: ");
    fflush(stdin);
    gets(id);
    idNum=checkearNumero(id,1,max);
    while(checkearId(listaProgramadores,idNum))
    {
        printf("Error 'ID en uso' reingrese: ");
        fflush(stdin);
        gets(id);
        idNum=checkearNumero(id,1,max);
    }
    printf("Ingrese el nombre: ");
    fflush(stdin);
    scanf("%100s",nombre);
    validarString(nombre,50);
    printf("Ingrese el apellido: ");
    fflush(stdin);
    scanf("%100s",apellido);
    validarString(apellido,50);
    printf("Ingrese la categoria");
    printf("1-Junior / 2- Semi-Senior / 3- Senior: ");
    fflush(stdin);
    gets(categoria);
    catNum=checkearNumero(categoria,1,3);
    nuevoProgramador=newProgramador(idNum,nombre,apellido,catNum);
    if(nuevoProgramador!=NULL)
    {
        listaProgramadores->add(listaProgramadores,nuevoProgramador);
    }
    else
    {
        printf("Hubo un error");
    }
    id++;
}

