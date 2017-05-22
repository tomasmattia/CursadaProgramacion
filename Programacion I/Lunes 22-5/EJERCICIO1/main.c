#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* num;
    int* aux;
    int i;
    num=(int*)malloc(sizeof(int)*5);
    if(num==NULL)
    {
        printf("No se consiguio memoria");
        exit(1);
    }
    for(i=0;i<5;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",num+i);
    }
    for(i=0;i<5;i++)
    {
        printf("%d ",*(num+i));
    }
    printf("\n");
    aux=(int*)realloc(num,10*sizeof(int));
    if(aux==NULL)
    {
        printf("No se consiguio memoria");
        exit(1);
    }
    num=aux;
    for(i=5;i<10;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",num+i);
    }
    for(i=0;i<10;i++)
    {
        printf("%d ",*(num+i));
    }
    free(num);
    return 0;
}
