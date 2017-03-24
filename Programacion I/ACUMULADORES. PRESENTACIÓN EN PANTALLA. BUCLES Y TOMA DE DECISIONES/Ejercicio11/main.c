#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int sumAntecedente=0;
    int contador;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    for(contador=0;contador<numero;contador++){
        sumAntecedente+=contador;
    }
    printf("La suma de todos los antecedentes da %d", sumAntecedente);
    return 0;
}
