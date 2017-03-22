#include <stdio.h>
#include <stdlib.h>

int main()

{
    char letra;
    int acumuladorA=0;
    int acumuladorE=0;
    int acumuladorI=0;
    int acumuladorO=0;
    int acumuladorU=0;
    int contador;
    for(contador=0;contador<20;contador++){
        printf("Ingrese una letra: ");
        scanf(" %c",&letra);
        switch(letra){
        case 'a':
            acumuladorA+=1;
            break;
        case 'e':
            acumuladorE+=1;
            break;
        case 'i':
            acumuladorI+=1;
            break;
        case 'o':
            acumuladorO+=1;
            break;
        case 'u':
            acumuladorU+=1;
        }
        system("cls");
    }
    printf("La cantidad de letras A fue de %d , de letras E %d , de letras I %d, de letras O %d, y de letras U %d",acumuladorA,acumuladorE,acumuladorI,acumuladorO,acumuladorU);
}
