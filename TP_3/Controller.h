#include "input.h"
#include "LinkedList.h"
#include "parser.h"
#include "Passenger.h"

/// @fn int controller_loadFromText(char*, LinkedList*)
/// @brief carga los datos de texto en la memoria
/// @param path archivo a leer y cargar
/// @param pArrayListPassenger lista donde cargar
/// @return retorna 0 si salio bien -1 si salio mal.
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
/// @fn int controller_loadFromBinary(char*, LinkedList*)
/// @brief carga los datos de binario en la memoria
/// @param path archivo a leer y cargar
/// @param pArrayListPassenger lista donde cargar
/// @return retorna 0 si salio bien -1 si salio mal.
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
/// @fn int controller_addPassenger(LinkedList*)
/// @brief añade un nuevo Pasajero
/// @param pArrayListPassenger lsita
/// @return retorna 0 si salio bien -1 si salio mal
int controller_addPassenger(LinkedList* pArrayListPassenger);

int controller_editPassenger(LinkedList* pArrayListPassenger);
/// @fn int controller_removePassenger(LinkedList*)
/// @brief elimina un Pasajero de la lista.
/// @param pArrayListPassenger
/// @return
int controller_removePassenger(LinkedList* pArrayListPassenger);
/// @fn int controller_ListPassenger(LinkedList*)
/// @brief lista los Pasajeros.
/// @param pArrayListPassenger
/// @return retorna 0 si salio bien -1 si salio mal
int controller_ListPassenger(LinkedList* pArrayListPassenger);
/// @fn int controller_sortPassenger(LinkedList*)
/// @brief ordena la lista segun lo que se reciba dentro
/// @param pArrayListPassenger
/// @return retorna 0 si salio bien -1 si salio mal
int controller_sortPassenger(LinkedList* pArrayListPassenger);
/// @fn int controller_saveAsText(char*, LinkedList*)
/// @brief guarda en en texto el nuevo archivo.
/// @param path
/// @param pArrayListPassenger
/// @return  retorna 0 si salio bien -1 si salio mal
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
/// @fn int controller_saveAsBinary(char*, LinkedList*)
/// @brief guarda en binario el archivo.
/// @param path
/// @param pArrayListPassenger
/// @return retorna 0 si salio bien -1 si salio mal
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
/// @fn int findPassenger_by_Id(LinkedList*, int)
/// @brief  recibe una lista y un id y busca que elemento tiene ese id
/// @param pArrayListPassenger
/// @param id id a buscar
/// @return -1 si no encontro o salio algo mal y si no la posicion del elemento
int findPassenger_by_Id(LinkedList *pArrayListPassenger, int id);
/// @fn int generadorDeId(LinkedList*, int*)
/// @param pArrayListPassenger lista
/// @param id
/// @return retorna 0 si salio bien -1 si salio mal
int generadorDeId(LinkedList *pArrayListPassenger, int *id);

