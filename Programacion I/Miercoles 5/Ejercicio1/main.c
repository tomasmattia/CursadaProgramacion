#include <stdio.h>
#include <stdlib.h>

#define MAX 3
int main()
{
    int legajo[MAX];
    float salario[MAX];
    int edad[MAX];
    float auxSueldo;
    int auxEdad;
    int contador;
    float mayor,menor;
    int legajoBuscar;
    int legajoFlag;
    int auxLegajo;
    int i;
    int j;
    for(contador=0;contador<MAX;contador++)
    {
        printf("Ingrese el legajo: ");
        scanf("%d",&legajo[contador]);
        printf("Ingrese el salario: ");
        scanf("%f",&auxSueldo);
        printf("Ingrese la edad: ");
        scanf("%d",&edad[contador]);
        salario[contador]=auxSueldo;
        system("cls");
    }
    //printf("Legajo\tSalario\tEdad\n");
    /*for(contador=0;contador<MAX;contador++)
    {
        printf("%d\t%.2f\t%d\n",legajo[contador],salario[contador],edad[contador]);
    }

    for(contador=0;contador<MAX;contador++)
    {
        if(contador==0 || salario[contador]>mayor)
        {
            mayor=salario[contador];
        }
        if(contador==0 || salario[contador]<menor)
        {
            menor=salario[contador];
        }
    }
    for(contador=0;contador<MAX;contador++)
    {
        printf("%d\t%.2f\t%d\n",legajo[contador],salario[contador],edad[contador]);
    }*/
    /*mayor=salario[0];
    menor=salario[0];
    for(contador=0;contador<MAX;contador++)
    {
        if(salario[contador]>mayor)
        {
            mayor=salario[contador];
        }
        else
        {
            if(salario[contador]<menor)
            {
                menor=salario[contador];
            }
        }
    }
    printf("El salario mayor es: %.2f y el salario menor es : %.2f",mayor, menor);
    */
    /*printf("Ingrese el legajo necesario: ");
    scanf("%d",&legajoBuscar);
    legajoFlag=0;
    for(contador=0;contador<MAX;contador++)
    {
        if(legajoBuscar==legajo[contador]){
            printf("Legajo: %d, Salario:%.2f, Edad: %d",legajo[contador],salario[contador],edad[contador]);
            legajoFlag=1;
            break;
        }
    }
    if(legajoFlag==0)
    {
        printf("No existe el legajo ingresado");
    }*/
    for(i=0;i<MAX-1;i++)
    {
        for(j=i+1;j<MAX;j++)
        {
            if(legajo[i]>legajo[j])
            {
                auxLegajo=legajo[i];
                legajo[i]=legajo[j];
                legajo[j]=auxLegajo;

                auxSueldo=salario[i];
                salario[i]=salario[j];
                salario[j]=auxSueldo;

                auxEdad=edad[i];
                edad[i]=edad[j];
                edad[j]=auxEdad;
            }
        }
    }
    for(contador=0;contador<MAX;contador++)
    {
        printf("Legajo: %d, Salario: %.2f, Edad: %d\n",legajo[contador],salario[contador],edad[contador]);
    }

    return 0;
}
