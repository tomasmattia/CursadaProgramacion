#include <stdio.h>
#include <stdlib.h>

int main()
{
    float peso;
    int masOchenta=0;
    int menosOchenta=0;
    int contador;
    char respuesta;
    do{
        printf("Ingrese el peso del empleado: ");
        scanf("%f",&peso);
        if(peso<=80){
            menosOchenta+=1;
        }
        else{
            masOchenta+=1;
        }
        system("cls");
        printf("Desea continuar? s/n :");
        respuesta=tolower(getche());
        system("cls");
    }while(respuesta=='s');
    printf("Cantidad de empleados que pesan hasta 80kg: %d\nCantidad de empleados que pesan mas de 80kg: %d",menosOchenta,masOchenta);
    return 0;
}
