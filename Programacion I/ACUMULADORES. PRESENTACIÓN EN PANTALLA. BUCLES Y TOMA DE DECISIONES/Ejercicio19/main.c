#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int lado1;
    int lado2;
    int lado3;
    int ladoMayor;
    int sumaMenores;

    printf("Ingrese un lado: ");
    scanf("%d",&lado1);
    system("cls");
    printf("Ingrese un lado: ");
    scanf("%d",&lado2);
    system("cls");
    printf("Ingrese un lado: ");
    scanf("%d",&lado3);
    system("cls");

    if(lado1>=lado2 && lado1>=lado3){
        ladoMayor=lado1;
        sumaMenores=lado2+lado3;
    }
    else{
        if(lado2>=lado3){
            ladoMayor=lado2;
            sumaMenores=lado1+lado3;
        }
        else{
            ladoMayor=lado3;
            sumaMenores=lado1+lado2;
        }
    }
    if(sumaMenores>ladoMayor){
        if(lado1==lado2 && lado1==lado3){
            printf("Es un triangulo equilatero");
        }
        else{
            if(lado1==lado2 || lado1==lado3 || lado2==lado3){
                printf("Es un triangulo isosceles");
            }
            else{
                printf("Es un triangulo escaleno");
            }
        }

    }
    else{
        printf("No es un triangulo");
    }


    //printf("Lado mayor: %d\n",ladoMayor);
    //printf("Suma menores: %d\n",sumaMenores);
    return 0;
}
