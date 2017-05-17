#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#define TAMPRO 50
#define TAMPROY 1000
#define TAMPROXPRO 5


typedef struct
{
    int idProgramador;
    char nombre[50];
    char apellido[50];
    int idCategoria;

}eProgramador;

typedef struct
{
    int idCategoria;
    char descCategoria[30];
    int pagoXHora;

}eCategoria;

typedef struct
{
    int idProyecto;
    char nombreProyecto[30];

}eProyecto;

typedef struct
{
    int programador;
    int proyecto;
    int horasAsignadas;

}eProgramadoresEnProyectos;

typedef struct
{
    int proyecto;
    int cantProgramadores;

}eWinner;

/** \brief inicializa todas las listas de estructuras en 0
 *
 * \param listaProgramadores[] eProgramador
 * \param listaProyectos[] eProyecto
 * \param listaProgramadoresEnProyectos[] eProgramadoresEnProyectos
 * \param categorias[] eCategoria
 * \return void
 *
 */
void inicializarTodo(eProgramador listaProgramadores[],eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[],eCategoria categorias[]);

/** \brief toma la lista de programadores y proyectos y los ordena por ID
 *
 * \param listaProgramadores[] eProgramador
 * \param listaProyectos[] eProyecto
 * \return void
 *
 */
void ordenarProgramadoresyProyectos(eProgramador listaProgramadores[],eProyecto listaProyectos[]);

/** \brief carga los proyectos hardcodeados
 *
 * \param listaProyectos[] eProyecto
 * \return void
 *
 */
void cargarProyectos(eProyecto listaProyectos[]);

/** \brief carga las categorias hardcodeadas
 *
 * \param categorias[] eCategoria
 * \return void
 *
 */
void cargarCategorias(eCategoria categorias[]);

/** \brief muesta el listado de proyectos ordenados
 *
 * \param listaProyectos[] eProyecto
 * \return void
 *
 */
void mostrarListadoProyectos(eProyecto listaProyectos[]);

/** \brief chequea el numero que se pasa con el minimo y el maximo pasados
 *
 * \param int
 * \param int
 * \param int
 * \return int
 *
 */
int checkearNumero(int,int,int);

/** \brief valida un string con el tamaño pasado
 *
 * \param char[]
 * \param int
 * \return void
 *
 */
void validarString(char[], int);

/** \brief busca un espacio vacio en la lista de programadores
 *
 * \param listaProgramadores[] eProgramador
 * \return int
 *
 */
int buscarEspacioLibre(eProgramador listaProgramadores[]);

/** \brief busca un programador por ID
 *
 * \param listaProgramadores[] eProgramador
 * \param int
 * \return int
 *
 */
int buscarPorId(eProgramador listaProgramadores[],int);

/** \brief agrega un programador
 *
 * \param listaProgramadores[] eProgramador
 * \return void
 *
 */
void agregarProgramador(eProgramador listaProgramadores[]);

/** \brief busca un id y ofrece modificar partes del programador
 *
 * \param listaProgramadores[] eProgramador
 * \return void
 *
 */
void modificarProgramador(eProgramador listaProgramadores[]);

/** \brief elimina un registro de la lista de programadores
 *
 * \param listaProgramadores[] eProgramador
 * \return void
 *
 */
void eliminarProgramador(eProgramador listaProgramadores[]);

/** \brief muestra el listado de programadores
 *
 * \param listaProgramadores[] eProgramador
 * \return void
 *
 */
void mostrarListadoProgramadores(eProgramador listaProgramadores[]);

/** \brief busca un espacio libre en la lista programadores*proyectos
 *
 * \param listaProgramadoresEnProyectos[] eProgramadoresEnProyectos
 * \return int
 *
 */
int buscarEspacioLibreEnProyectos(eProgramadoresEnProyectos listaProgramadoresEnProyectos[]);

/** \brief carga un programador en un proyecto en la lista programadoresenproyectos
 *
 * \param listaProgramadores[] eProgramador
 * \param listaProyectos[] eProyecto
 * \param listaProgramadoresEnProyectos[] eProgramadoresEnProyectos
 * \return void
 *
 */
void cargarProgramadorEnProyecto(eProgramador listaProgramadores[],eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[]);

/** \brief busca un proyecto por ID
 *
 * \param listaProyectos[] eProyecto
 * \param idABuscar int
 * \return int
 *
 */
int buscarPorIdProyecto(eProyecto listaProyectos[],int idABuscar);

/** \brief muestra los programadores, los proyectos asignados y lo que cobran por cada asignacion
 *
 * \param listaProgramadores[] eProgramador
 * \param listaProyectos[] eProyecto
 * \param listaProgramadoresEnProyectos[] eProgramadoresEnProyectos
 * \param categorias[] eCategoria
 * \return void
 *
 */
void mostrarListadoProgramadoresProyectosYSueldos(eProgramador listaProgramadores[],eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[],eCategoria categorias[]);

/** \brief muestra los programadores y los proyectos donde estan asignados
 *
 * \param listaProgramadores[] eProgramador
 * \param listaProyectos[] eProyecto
 * \param listaProgramadoresEnProyectos[] eProgramadoresEnProyectos
 * \return void
 *
 */
void mostrarProgramadoresYSusProyectos(eProgramador listaProgramadores[],eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[]);

/** \brief muestra los proyectos y los programadores que estan asignados
 *
 * \param listaProgramadores[] eProgramador
 * \param listaProyectos[] eProyecto
 * \param listaProgramadoresEnProyectos[] eProgramadoresEnProyectos
 * \return void
 *
 */
void mostrarProyectosConProgramadores(eProgramador listaProgramadores[],eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[]);

void mostrarProgramadorYsusProyectos(eProgramador listaProgramadores[],eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[]);

/** \brief busca cual es el maximo de programadores en un proyecto y muestra todos los proyectos que tengan esa cantidad
 *
 * \param listaProyectos[] eProyecto
 * \param listaProgramadoresEnProyectos[] eProgramadoresEnProyectos
 * \return void
 *
 */
void proyectoMasPopular(eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[]);

/** \brief checkea si hay programadores agregados
 *
 * \param listaProgramadores[] eProgramador
 * \return int
 *
 */
int checkearAsignaciones(eProgramador listaProgramadores[]);

#endif // LIB_H_INCLUDED
