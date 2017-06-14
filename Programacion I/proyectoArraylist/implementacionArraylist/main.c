#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "arrayImp.h"

int main()
{
    int opcion;
    char respuesta='s';
    ArrayList* listaProgramadores=al_newArrayList();
    do
    {
        opcion=0;
        menu();
        fflush(stdin);
        scanf("%d",&opcion);
        fflush(stdin);
        switch(opcion)
        {
            case 1:
                altaProgramador(listaProgramadores);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 7:
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
