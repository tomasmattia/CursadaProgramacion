#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int resta;
    printf("Ingrese el primer numero: ");
    scanf("%d",&numeroUno);
    system("cls");
    printf("Ingrese el segundo numero: ");
    scanf("%d",&numeroDos);
    system("cls");
    resta=numeroUno-numeroDos;
    if(resta==0){
        printf("Cero!");
    }
    else{
        if(resta>0){
            printf("Resultado positivo");
        }
        else{
            printf("Resultado negativo");
        }
    }

}
