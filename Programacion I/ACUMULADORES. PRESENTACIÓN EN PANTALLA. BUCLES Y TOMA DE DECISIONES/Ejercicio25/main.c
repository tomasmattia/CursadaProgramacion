#include <stdio.h>
#include <stdlib.h>

int main()
{
    float mozo1=0;
    float mozo2=0;
    int mozo;
    do{
        printf("Ingrese el numero de mozo: ");
        scanf("%d",&mozo);
        switch(mozo){
            case 1:
                printf("Ingrese la facturacion: ");
                scanf("%f",&mozo1);
                mozo1=(mozo1/3);
                system("cls");
                break;
            case 2:
                printf("Ingrese la facturacion: ");
                scanf("%f",&mozo2);
                mozo2=(mozo2/3);
                system("cls");
                break;
            case 0:
                break;
            default:
                printf("Solo hay 2 mozos\n");

        }
    }while(mozo!=0);

    if(mozo1>mozo2){
        printf("El bono es para el mozo 1 y es de %.2f",mozo1);
    }
    else{
        printf("El bono es para el mozo 2 y es de %.2f",mozo2);
    }

    return 0;
}
