#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main()
{
    char nombre;
    char nacionalidad;
    char respuesta;
    int estudios;
    int antiguedad;
    int contador=0;
    int contadorExtranjeros=0;
    float porcentaje;
    do{
        contador+=1;
        printf("Ingrese el nombre del empleado: ");
        nombre=getche();

        do{
            printf("\nIngrese la nacionalidad (a-e): ");
            nacionalidad=getche();

        }while(nacionalidad!='a' && nacionalidad!='e');
        do{
            printf("\nIngrese los estudios cursados(1-2-3): ");
            scanf("%d",&estudios);

        }while(estudios<1 && estudios>3);
        do{
            printf("\nIngrese la antiguedad: ");
            scanf("%d",&antiguedad);

        }while(antiguedad<0);

        printf("\nDesea continuar? s/n: ");
        respuesta=getche();
        printf("\n");


        if(nacionalidad=='e' && estudios==3 && antiguedad>=20){
            contadorExtranjeros+=1;
            printf("\nNombre: %c\n",nombre);
        }

    }while(respuesta=='s');
        printf("La cantidad de extranjeros con estudios universitarios y antiguedad mayor a 20: %d\n",contadorExtranjeros);
        porcentaje=(float)(contadorExtranjeros*100)/contador;
        printf("El porcentaje sobre el total es de: %.2f",porcentaje);
    return 0;
}
