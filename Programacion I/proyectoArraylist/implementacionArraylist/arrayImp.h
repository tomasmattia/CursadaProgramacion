#include "ArrayList.h"

typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    int idCategoria;

}eProgramador;


/** \brief
 *
 * \param void
 * \return void
 *
 */
void menu(void);

void validarString(char[], int);

int checkearNumero(char*,int,int);

eProgramador* newProgramador(int,char[],char[],int);

void altaProgramador(ArrayList* listaProgramadores);

int checkearId(ArrayList* listaProgramadores,int);
