#include <stdio.h>
#include <stdlib.h>

int main()
{
    int primero;
    int numero;
    int ultimo;
    printf("Ingrese el primer numero del intervalo: ");
    scanf("%d",&primero);
    system("cls");
    printf("Ingrese un numero: ");
    scanf("%d",&numero);
    system("cls");
    printf("Ingrese el ultimo numero del intervalo: ");
    scanf("%d",&ultimo);
    system("cls");
    if(numero>=primero && numero<=ultimo){
        printf("El numero %d pertenece al intervalo [%d;%d]",numero,primero,ultimo);
    }
    else{
        printf("El numero %d no pertenece al intervalo [%d;%d]",numero,primero,ultimo);
    }

    return 0;
}
