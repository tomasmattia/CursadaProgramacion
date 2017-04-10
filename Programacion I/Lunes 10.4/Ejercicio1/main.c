#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char nombre[20];
    int i;
    printf("Ingrese su nombre: ");
    gets(nombre);
    strlwr(nombre);
    nombre[0]=toupper(nombre[0]);
    for(i=0;i<20;i++)
    {
        if(isspace(nombre[i]))
        {
            nombre[i+1]=toupper(nombre[i+1]);
        }
    }
    printf("Usted se llama %s",nombre);
    return 0;
}
