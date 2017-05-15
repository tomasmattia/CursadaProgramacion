#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    // int matriz[FILAS][COLUMNAS];
    int matriz[4][5];
    int i;
    int j;
    int filas=1;
    int columnas=1;
    int max=INT_MIN;
    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
        {
            matriz[i][j]=max;
        }
    }
    for(i=0;i<5;i++)
    {
        columnas=i+1;
        for(j=0;j<4;j++)
        {
            filas=j+1;
            if(matriz[j][i]==max)
            {
                printf("Ingrese un numero [%d][%d]: ",filas,columnas);
                scanf("%d",&matriz[j][i]);
            }
        }
    }
    filas=1;
    printf("\nMATRIZ\n");
    for(i=0;i<4;i++)
    {
        printf("FILA %d: ",filas);
        for(j=0;j<5;j++)
        {
            printf("%d\t",matriz[i][j]);
        }
        printf("\n");
        filas+=1;
    }
    return 0;
}
