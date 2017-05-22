#include <stdio.h>
#include <stdlib.h>

// fopen ("NOMBRE DEL ARCHIVO","FORMATO") = r, w, a, rb, wb, ab; read, write, append;

int main()
{
    char cadena[50];
    //char x;
    FILE* f;
    //f=fopen("prueba.txt","r");
    f=fopen("pruebaEscritura.txt","w");
    if(f==NULL)
    {
        printf("No se pudo abrir el fichero");
        exit(1);
    }
    /*
    while(x!=EOF)
    {
        x=fgetc(f);
        printf("%c",x);
    }
    fclose(f);
    */
    /*
    while(!feof(f))
    {
        fgets(cadena,50,f);
        printf("%s",cadena);
    }
    fclose(f);
    */
    fprintf(f,"PanchoBDM= Boludo de Mierda");
    fclose(f);
    f=fopen("pruebaEscritura.txt","r");
    while(!feof(f))
    {
        fgets(cadena,50,f);
        printf("%s",cadena);
    }
    fclose(f);
    return 0;
}
