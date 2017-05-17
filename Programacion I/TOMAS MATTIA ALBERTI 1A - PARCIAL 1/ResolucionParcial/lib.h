#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

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
    char descCategoria[20];
    int pagoXHora;

}eCategoria;

typedef struct
{
    int idProyecto;
    char nombreProyecto[50];

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

void inicializarTodo(eProgramador listaProgramadores[],eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[],eCategoria categorias[]);

void ordenarProgramadoresyProyectos(eProgramador listaProgramadores[],eProyecto listaProyectos[]);

void cargarProyectos(eProyecto listaProyectos[]);

void cargarCategorias(eCategoria categorias[]);

void mostrarListadoProyectos(eProyecto listaProyectos[]);

int checkearNumero(int,int,int);

void validarString(char[], int);

int buscarEspacioLibre(eProgramador listaProgramadores[]);

int buscarPorId(eProgramador listaProgramadores[],int);

void agregarProgramador(eProgramador listaProgramadores[]);

void modificarProgramador(eProgramador listaProgramadores[]);

void eliminarProgramador(eProgramador listaProgramadores[]);

void mostrarListadoProgramadores(eProgramador listaProgramadores[]);

int buscarEspacioLibreEnProyectos(eProgramadoresEnProyectos listaProgramadoresEnProyectos[]);

void cargarProgramadorEnProyecto(eProgramador listaProgramadores[],eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[]);

int buscarPorIdProyecto(eProyecto listaProyectos[],int idABuscar);

void mostrarListadoProgramadoresProyectosYSueldos(eProgramador listaProgramadores[],eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[],eCategoria categorias[]);

void mostrarProgramadoresYSusProyectos(eProgramador listaProgramadores[],eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[]);

void mostrarProyectosConProgramadores(eProgramador listaProgramadores[],eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[]);

void mostrarProgramadorYsusProyectos(eProgramador listaProgramadores[],eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[]);

void proyectoMasPopular(eProyecto listaProyectos[],eProgramadoresEnProyectos listaProgramadoresEnProyectos[]);

int checkearAsignaciones(eProgramador listaProgramadores[]);

#endif // LIB_H_INCLUDED
