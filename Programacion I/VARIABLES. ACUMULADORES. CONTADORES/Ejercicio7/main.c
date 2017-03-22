#include <stdio.h>
#include <stdlib.h>

int main()
{
    int radio;
    float longitudCirc;
    float areaCirc;
    float pi=3.14;
    printf("Ingrese el radio del circulo: ");
    scanf("%d",&radio);
    longitudCirc=2*pi*radio;
    areaCirc=pi*(radio*radio);
    printf("La longitud de la circunferencia es de %.2f y el area del circulo es de %.2f",longitudCirc,areaCirc);
}
