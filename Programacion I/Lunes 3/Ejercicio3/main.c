#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letras[5];
    int contador;
    for(contador=0;contador<5;contador++){
        printf("Ingrese una letra: ");
        letras[contador]=getche();
        printf("\n");
    }

    for(contador=0;contador<5;contador++){
        printf("%c ",letras[contador]);
    }


    return 0;
}
