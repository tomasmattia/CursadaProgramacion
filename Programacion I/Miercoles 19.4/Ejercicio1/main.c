#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct //definido asi para no repetir "struct alumno", se define una unica vez
{
    int legajo;
    char nombre[20];
    char apellido[30];
    float promedio;
    eFecha fnac;
}eAlumno;

void mostrarAlumno(eAlumno);
void mostrarCurso(eAlumno[],int);

int main()
{
    int j;
    //int idModificar;
    int i;
    //int flag=0;
    //char nuevoNombre[20];
    //int alumnoModif;
    eAlumno unAlumno[5]={{827,"Juan","Perez",8,{9,9,1990}},{555,"Jorge","Perez",5,{9,9,1990}},{999,"Raul","Perez",2,{8,8,1990}},{777,"Ruben","Perez",3,{8,7,1990}},{666,"Roman","Perez",7,{6,5,1990}}};
    eAlumno aux={};
    /*printf("Ingrese el legajo: ");
    scanf("%d",&unAlumno.legajo);
    printf("Ingrese el apellido: ");
    fflush(stdin);
    gets(unAlumno.apellido);
    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(unAlumno.nombre);
    printf("Ingrese el promedio: ");
    scanf("%f",&unAlumno.promedio);
    printf("Ingrese el dia de nacimiento: ");
    scanf("%d",&unAlumno.fnac.dia);
    printf("Ingrese el mes de nacimiento: ");
    scanf("%d",&unAlumno.fnac.mes);
    printf("Ingrese el anio de nacimiento: ");
    scanf("%d",&unAlumno.fnac.anio);*/
    /*printf("Legajo a modificar: ");
    scanf("%d",&idModificar);
    for(i=0;i<5;i++)
    {
        if(unAlumno[i].legajo==idModificar)
        {
            alumnoModif=i;
            printf("%d %s %s %f %d/%d/%d",unAlumno[i].legajo,unAlumno[i].nombre,unAlumno[i].apellido,unAlumno[i].promedio,unAlumno[i].fnac.dia,unAlumno[i].fnac.mes,unAlumno[i].fnac.anio);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("El legajo no existe");
    }
    printf("\nIngrese el nuevo nombre: ");
    fflush(stdin);
    gets(nuevoNombre);
    strcpy(unAlumno[alumnoModif].nombre,nuevoNombre);
    */
    for(i=0;i<5-1;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(strcmp(unAlumno[i].nombre,unAlumno[j].nombre)>0)
            {
                aux=unAlumno[i];
                unAlumno[i]=unAlumno[j];
                unAlumno[j]=aux;
            }
        }
    }

    mostrarCurso(unAlumno,5);

    return 0;
}

void mostrarAlumno(eAlumno alumno)
{
    printf("Datos del alumno: \n\n");
    printf("Legajo: %d \n",alumno.legajo);
    printf("Nombre: %s \n",alumno.nombre);
    printf("Apellido: %s \n",alumno.apellido);
    printf("Promedio: %.2f \n",alumno.promedio);
    printf("Fecha de nacimiento: %d/%d/%d\n",alumno.fnac.dia,alumno.fnac.mes,alumno.fnac.anio);
};

void mostrarCurso(eAlumno alumno[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        mostrarAlumno(alumno[i]);
    }
};
