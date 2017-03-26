    #include <stdio.h>
#include <stdlib.h>

int main()
{
    char espacio=" ";
    char letra;
    int contador;
    printf("Introduzca una letra: ");
    letra=getche();
    for(contador=0;contador<5;contador++){
        printf("%c%c\n",letra);
    }
    getche();
    return 0;
}
