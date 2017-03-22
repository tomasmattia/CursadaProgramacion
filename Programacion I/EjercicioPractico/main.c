#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>
#include <ctype.h>

int main()
{
    int numero;
    int numerosPares=0;
    int numerosImpares=0;
    int sumaImpares=0;
    int antecendentes;
    int sumaTotal=0;
    float promedio;
    int numeroMayor=INT_MIN;
    int imparMenor=INT_MAX;
    int entreTresYQuince=0;
    int entreDiezseisYDosNueve=0;
    int mayorATreinta=0;
    int contador=0;
    int sumatoriaAntecedentes=0;
    int respuesta='s';
    do{
        printf("Ingrese un numero positivo: ");
        scanf("%d",&numero);
        system("cls");
        while(numero<=0){
            printf("El numero tiene que ser positivo: ");
            scanf("%d",&numero);
            system("cls");
        }
        if(numero%2==0){
            numerosPares+=1;
        }
        else{
            numerosImpares+=1;
            sumaImpares+=numero;
            if(numero<imparMenor){
                imparMenor=numero;
            }
        }
        if(numero>numeroMayor){
            numeroMayor=numero;
        }
        if(numero>=3 && numero<=15){
            entreTresYQuince+=1;
        }
        else{
            if(numero>=16 && numero<=29){
                entreDiezseisYDosNueve+=1;
            }
            if(numero>=30){
                mayorATreinta+=1;
            }
        }
        sumaTotal+=numero;
        contador+=1;
        printf("Desea continuar? Presione n para detener y cualquier letra para continuar: ");
        respuesta=tolower(getche());
        system("cls");
    }while(respuesta!='n');
    antecendentes=sumaImpares-1;
    for(;antecendentes>0;antecendentes--){
        sumatoriaAntecedentes+=antecendentes;
    }
    if(numerosImpares==0){
        imparMenor=0;
    }
    promedio=(float)sumaTotal/contador;
    printf("La cantidad de numeros pares es: %d\nLa cantidad de impares: %d\nLa sumatoria de impares: %d\nEl promedio: %f\nEl numero mayor: %d\nEl numero impar menor: %d\nLos numeros entre 3 y 15: %d\nLos numeros entre 16 y 29: %d\nLos numeros mayores a 30: %d\nLa sumatoria de los antecedentes: %d\n",numerosPares,numerosImpares,sumaImpares,promedio,numeroMayor,imparMenor,entreTresYQuince,entreDiezseisYDosNueve,mayorATreinta,sumatoriaAntecedentes);
    antecendentes=sumaImpares-1;
    for(;antecendentes>0;antecendentes--){
        printf("Antecedentes de la sumatoria impar: %d\n", antecendentes);
    }
    return 0;
}
