#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 10

int main()
{
    char seguir='s';
    int opcion=0;
    int i;
    EProgramador plantel[MAX];
    ECategoria categorias[]={{1,"Junior"},{2,"SemiSenior"},{3,"Senior"}};
    for(i=0;i<MAX;i++)
    {
        plantel[i].id=0;
    }
    while(seguir=='s')
    {
        printf("\n1- Agregar programador\n");
        printf("2- Borrar programador\n");
        printf("3- Imprimir lista de programadores\n");
        printf("4- Mostrar un programador\n");
        printf("5- Mostrar la categoria con mas programadores\n");
        printf("6- Modificar los datos de un programador\n");
        printf("7- Salir\n\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarProgramador(plantel,categorias);
                break;
            case 2:
                eliminarProgramador(plantel);
                break;
            case 3:
                mostrarOrdenado(plantel,categorias);
                break;
            case 4:
                mostrarUnProgramador(plantel,categorias);
                break;
            case 5:
                categoriaMayor(plantel,categorias);
                break;
            case 6:
                modificarProgramador(plantel,categorias);
                break;
            case 7:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
