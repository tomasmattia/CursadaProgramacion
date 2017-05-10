#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED

typedef struct {
    int idProgramador;
    char apellido[50];
    char nombre[50];
    int idCategoria;

}eProgramador;

typedef struct
{
    int idProyecto;
    char nombre[20];

}eProyecto;

typedef struct
{
    int programador;
    int proyecto;
    int horasAsignadas;

}eProgramadoresXProyecto;

typedef struct
{
    int categoria;
    char desCategoria[20];
    int pagoXHora;

}eCategorias;

typedef struct//Para el punto 5
{
    int idProyect;
    int cont;
} ePopular;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(eProgramador lista[]);

/** \brief Se ejecuta obtenerEspacioLibre, si hay espacio toma los datos y los guarda, caso contrario avisa falta de espacio
 *
 * \param recibe la estructura "lista"
 * \return void guarda un registro o avisa falta de espacio
 *
 */
void agregarCliente(eProgramador lista[]);

/**
 * Busca el dni y obtiene el indice correspondiente.
 * @param lista el array se pasa como parametro.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorId(eProgramador lista[]);

/** \brief Recibe la estructura, ejecuta buscarPorId, si el dni existe se muestra y pregunta si se quiere eliminar o no, caso afirmativo el estado pasa a 0, si no existe dni sale una advertencia,
 *
 * \param recibe la estructura "lista"
 * \return void uestra el dni buscado para eliminar y lo elimina si el usuario asi lo decide
 *
 */
void eliminarCliente(eProgramador lista[]);

/** \brief Recibe la estructura, la ordena alfabeticamente y la muestra en pantalla.
 *
 * \param recibe la estructura "lista"
 * \return void muestra y guarda la estructura ordenada alfabeticamente
 *
 */
void mostrarOrdenado(eProgramador lista[]);

/** \brief Recibe la estructura, el id y el indice, para validar que no se repita el ID y modificar el indice.
 *
 * \param lista[] ECliente
 * \param int id
 * \param int indice
 * \return void
 *
 */
void validarId(eProgramador lista[],int,int);

void modificarDatos(eProgramador lista[]);

void cargarProgramadores(eProgramador lista[]);

void cargarProyectos(eProyecto proyectos[]);

void cargar_ProgramadoresXProyecto(eProgramadoresXProyecto programadoresProyectos[]);

int obtenerProyectoXProgramador(eProgramadoresXProyecto programadoresProyectos[],eProyecto proyectos[]);

void asignarProgramador(eProgramador lista[],eProyecto proyectos[],eProgramadoresXProyecto programadoresProyectos[]);

void mostrarProgramadoresYSusProyectos(eProgramador lista[],eProyecto proyectos[],eProgramadoresXProyecto programadoresProyectos[],int,int,int);

void mostrarProyectosConClientes(eProgramador lista[],eProyecto proyectos[],eProgramadoresXProyecto programadoresProyectos[],int,int,int );

void mostrarProgramadorYsusProyectos(eProgramador lista[],eProyecto proyectos[],eProgramadoresXProyecto programadoresProyectos[],int tamprog, int tamproyect, int tampxp);

void proyectoMasPopular(eProgramador lista[],eProyecto proyectos[],eProgramadoresXProyecto programadoresProyectos[],int, int, int);
#endif // FUNCIONES_H_INCLUDED

