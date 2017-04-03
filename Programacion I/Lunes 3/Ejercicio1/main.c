#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero[5];
    int i;
    for(i=0;i<5;i++){
        printf("Ingrese un numero: ");
        scanf("%d", &numero[i]);
        system("cls");
    }
    printf("Los numeros fueron:");
    for(i=0;i<5;i++){
        printf("%d ",numero[i]);
    }
    printf("\nLos numeros fueron:");
    for(i=4;i>=0;i--){
        printf("%d ",numero[i]);
    }
    return 0;
}
