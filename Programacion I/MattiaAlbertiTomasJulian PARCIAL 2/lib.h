#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"

typedef struct
{
    char nombre[15];
    int prioridad;
    int tiempo;
}eTarea;

/** \brief carga en pantalla todas las opciones disponibles del menu
 *
 * \param void
 * \return void
 *
 */
void menu(void);

/** \brief Toma del csv la lista de tareas y la carga en la lista totalTareas
 *
 * \param totalTareas ArrayList*
 * \return int
 *
 */
int cargarTareas(ArrayList* totalTareas);

/** \brief ordena las tareas segun su prioridad y las carga en tareasAlta o tareasBaja segun corresponda y luego las borra de totalTareas
 *
 * \param totalTareas ArrayList*
 * \param tareasAlta ArrayList*
 * \param tareasBaja ArrayList*
 * \return void
 *
 */
void ordenarTareas(ArrayList* totalTareas,ArrayList* tareasAlta, ArrayList* tareasBaja);

/** \brief muestra en pantalla una tarea
 *
 * \param unaTarea eTarea*
 * \return void
 *
 */
void mostrarUnaTarea(eTarea* unaTarea);

/** \brief muestra el total de tareas de una lista de tareas
 *
 * \param listaTareas ArrayList*
 * \return void
 *
 */
void mostrarTareas(ArrayList* listaTareas);

/** \brief compara dos tareas por el tiempo
 *
 * \param tareaA void*
 * \param tareaB void*
 * \return int
 *
 */
int ordenarPorTiempo(void* tareaA,void* tareaB);

/** \brief toma una tarea segun el criterio mayor prioridad-menor tiempo a menor prioridad-menor tiempo, la remueve de la lista que corresponda y la muestra
 *
 * \param tareasAlta ArrayList*
 * \param tareasBaja ArrayList*
 * \return void
 *
 */
void resolverUnaTarea(ArrayList* tareasAlta, ArrayList* tareasBaja);

/** \brief guarda la lista de alta y baja prioridad en sus csv correspondientes
 *
 * \param tareasAlta ArrayList*
 * \param tareasBaja ArrayList*
 * \return void
 *
 */
void guardarTareas(ArrayList* tareasAlta, ArrayList* tareasBaja);
