#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[20];
    char auxNombre[50];
    int auxNombreLen;
    int flagAux=0;
    do
    {
        if(flagAux==1){
            printf("Error, demasiado largo. ");
        }
        printf("Ingrese su nombre: ");
        gets(auxNombre);
        auxNombreLen=strlen(auxNombre);
        flagAux=1;
    }while(auxNombreLen>19);

    strcpy(nombre,auxNombre);
    printf("%s",nombre);
    return 0;
}
