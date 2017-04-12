#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nom[25];
    char ape[25];
    char nomApe[51]={};
    int i;
    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(nom);
    printf("Ingrese su apellido: ");
    fflush(stdin);
    gets(ape);
    strcat(nomApe,ape);
    strcat(nomApe,", ");
    strcat(nomApe,nom);
    strlwr(nomApe);
    nomApe[0]=toupper(nomApe[0]);
    for(i=0;nomApe[i]!='\0';i++)
    {
        if(isspace(nomApe[i]))
        {
            nomApe[i+1]=toupper(nomApe[i+1]);
        }
    }
    printf("Su nombre es %s",nomApe);
    return 0;
}
