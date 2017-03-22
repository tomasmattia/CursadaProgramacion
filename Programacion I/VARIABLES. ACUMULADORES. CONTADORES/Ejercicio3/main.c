#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int producto;
    int cuadradoUno;
    printf("Ingrese el primer numero: ");
    scanf("%d",&numeroUno);
    system("cls");
    printf("Ingrese el segundo numero: ");
    scanf("%d",&numeroDos);
    system("cls");
    producto=numeroUno*numeroDos;
    printf("El producto de ambos es %d\n",producto);
    system("pause");
    system("cls");
    cuadradoUno=numeroUno*numeroUno;
    printf("El cuadrado del primero es %d",cuadradoUno);

}
