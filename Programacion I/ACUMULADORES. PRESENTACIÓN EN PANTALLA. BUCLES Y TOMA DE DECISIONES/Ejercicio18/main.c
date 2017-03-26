#include <stdio.h>
#include <stdlib.h>

int main()
{
    int importe;
    int vendedor;
    int vendedor1=0;
    int vendedor2=0;
    int vendedor3=0;
    char respuesta;
    do{
    printf("Ingrese el importe de la venta: ");
    scanf("%d",&importe);
    system("cls");
    printf("Ingrese el numero de vendedor: ");
    scanf("%d",&vendedor);
    while(vendedor<1 || vendedor>3){
        printf("Ingrese un numero de vendedor valido: ");
        scanf("%d",&vendedor);
        system("cls");
    }
    switch(vendedor){
    case 1:
        vendedor1+=(importe*0.05);
        break;
    case 2:
        vendedor2+=(importe*0.05);
        break;
    case 3:
        vendedor3+=(importe*0.05);
        break;
    }
    system("cls");
    do{
        printf("Desea continuar? s/n: ");
        respuesta=tolower(getche());
        system("cls");
    }while(respuesta!='s' && respuesta!='n');
    }while(respuesta!='n');
    printf("El vendedor 1 gano: $%d\n",vendedor1);
    printf("El vendedor 2 gano: $%d\n",vendedor2);
    printf("El vendedor 3 gano: $%d\n",vendedor3);

    return 0;
}
