#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    int id;
    char nombre[50];
    int idCategoria;
    float sueldo;

}EProgramador;

typedef struct{

    int id;
    char descripcion[20];

}ECategoria;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EProgramador plantel[]);

/**
 * Busca el dni y obtiene el indice correspondiente.
 * @param lista el array se pasa como parametro.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorId(EProgramador plantel[]);

/** \brief
 *
 * \param EPersona
 * \return void
 *
 */
void agregarProgramador(EProgramador plantel[],ECategoria categorias[]);

/** \brief
 *
 * \param lista[] EPersona
 * \return void
 *
 */
void mostrarOrdenado(EProgramador plantel[],ECategoria categorias[]);

/** \brief
 *
 * \param lista[] EPersona
 * \return void
 *
 */
void eliminarProgramador(EProgramador plantel[]);

void categoriaMayor(EProgramador plantel[],ECategoria categorias[]);

void mostrarUnProgramador(EProgramador plantel[],ECategoria categorias[]);

void modificarProgramador(EProgramador plantel[],ECategoria categorias[]);
#endif // FUNCIONES_H_INCLUDED
