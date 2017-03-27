#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


int main()
{
    char apellido[MAX][20];
    char nombre[MAX][20];
    float altura;
    int flagAltura=0;
    int mayorAltura;
    char apellidoMayor[MAX][20];
    char nombreMayor[MAX][20];
    char respuesta;
    do{
        printf("Ingrese el apellido del alumno :");
        scanf("%s",&apellido);
        printf("Ingrese el nombre: ");
        scanf("%s",&nombre);
        printf("Ingrese la altura: ");
        scanf("%f",&altura);
        if(flagAltura==0 || altura>mayorAltura){
            mayorAltura=altura;
            nombreMayor=nombre;
            apellidoMayor=apellido;
        }
        system("cls");
        printf("Desea continuar? s/n: ");
        respuesta=tolower(getche());
        system("cls");
    }while(respuesta!='n');
    printf("Mayor altura: %.2f\nNombre: %s\nApellido: %s",mayorAltura, nombreMayor,apellidoMayor);
    return 0;
}
