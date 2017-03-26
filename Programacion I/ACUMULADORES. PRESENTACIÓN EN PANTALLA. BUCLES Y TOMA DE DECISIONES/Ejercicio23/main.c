#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
int main()
{
    int valorHora;
    char nombre[MAX][20];
    int antiguedad;
    int horasTrabajadas;
    int sueldoBruto;
    int descuentos;
    int sueldoNeto;
    printf("Ingrese el valor de la hora: ");
    scanf("%d",&valorHora);
    system("cls");
    printf("Ingrese el nombre del empleado: ");
    scanf("%s",&nombre);
    system("cls");
    printf("Ingrese la antiguedad del empleado: ");
    scanf("%d",&antiguedad);
    system("cls");
    printf("Ingrese la cantidad de horas trabajadas: ");
    scanf("%d",&horasTrabajadas);
    system("cls");
    sueldoBruto=(valorHora*horasTrabajadas)+(antiguedad*30);
    descuentos=sueldoBruto*0.13;
    sueldoNeto=sueldoBruto-descuentos;
    printf("El empleado es: %s\n",nombre);
    printf("La antiguedad que posee es: %d ano/s\n",antiguedad);
    printf("El valor hora es de: $%d\n",valorHora);
    printf("El sueldo bruto es de: $%d\n",sueldoBruto);
    printf("La totalidad de descuentos es: $%d\n",descuentos);
    printf("El sueldo neto es de: $%d\n",sueldoNeto);
    return 0;
}
