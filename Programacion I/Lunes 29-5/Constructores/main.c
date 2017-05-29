#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct
{
    int id;
    char marca[20];
    char modelo[15];
    float precio;
}eNotebook;

eNotebook* new_notebook();
void printNotebook(eNotebook* n);
eNotebook* new_notebookParam(int,char[],char[],float);

int main()
{
    eNotebook *unaNotebook;
    eNotebook *otraNotebook;
    unaNotebook=new_notebook();
    otraNotebook=new_notebookParam(120,"HP","ENVY 460",35000);
    if(unaNotebook==NULL || otraNotebook==NULL)
    {
        printf("No se pudo asignar memoria");
        exit(1);
    }
    /*unaNotebook->id=8;
    strcpy(unaNotebook->marca,"HP");
    strcpy(unaNotebook->modelo,"Envy");
    unaNotebook->precio=30000;*/
    printNotebook(unaNotebook);
    printf("\n");
    printNotebook(otraNotebook);
    free(unaNotebook);
    free(otraNotebook);
    return 0;
}

eNotebook* new_notebook()
{
    eNotebook* x=(eNotebook*)malloc(sizeof(eNotebook));
    if(x!=NULL)
    {
        x->id=0;
        strcpy(x->marca,"");
        strcpy(x->modelo,"");
        x->precio=0;
    }
    return x;
}

eNotebook* new_notebookParam(int id,char marca[],char modelo[],float precio)
{
    //eNotebook* x=(eNotebook*)malloc(sizeof(eNotebook));
    eNotebook* x=new_notebook();
    if(x!=NULL)
    {
        x->id=id;
        strcpy(x->marca,marca);
        strcpy(x->modelo,modelo);
        x->precio=precio;
    }
    return x;
}

void printNotebook(eNotebook* n)
{
    printf("ID: %d MARCA: %s MODELO: %s PRECIO: %2.f",n->id,n->marca,n->modelo,n->precio);
}
