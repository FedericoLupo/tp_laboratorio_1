#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
// isEmpty
#define CARGADO 0
#define VACIO 1

struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}typedef Passenger;

int pasajerosHardcodeados(Passenger* list, int len);

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len);

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],
		float price, char flycode[],int typePassenger,int statusFlight);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger *list, int len, int option);

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassengers(Passenger* list, int len);

/**
 * @fn int requestPassenger(Passenger*, int, int)
 * @brief pide y registra un nuevo Pasajero
 * @param list
 * @param len
 * @param id
 * @return -1 si no se logro  si se logro
 */
int requestPassenger(Passenger *list, int len, int id);

/// @fn int findFreePosition(Passenger*, int)
/// @brief encuentra una posicion libre
/// @param list
/// @param len
/// @return devuelve la posicion libre
int findFreePosition(Passenger *list, int len);

/// @fn int modifyName(Passenger*, int)
/// @brief recibe el vector de Pasajeros y su posicion y  modifica el nombre segun lo que el ususario decida
/// @param Pasajero
/// @param pos
/// @return -1 si no se logro 0 si se logro
int modifyName(Passenger *Pasajero, int pos);

/// @fn int modifyLastName(Passenger*, int)
/// @brief recibe el vector de Pasajeros y su posicion y modifica el apellido segun lo que el ususario decida
/// @param Pasajero
/// @param pos
/// @return-1 si no se logro  0 si se logro
int modifyLastName(Passenger *Pasajero, int pos);

/// @fn int modifyflycode(Passenger*, int)
/// @brief recibe el vector de Pasajeros y su posicion y  modifica el flycode segun lo que el ususario decida
/// @param Pasajero
/// @param pos
/// @return -1 si no se logro  0 si se logro
int modifyflycode(Passenger *Pasajero, int pos);

/// @fn int modifyprice(Passenger*, int)
/// @brief recibe el vector de Pasajeros y su posicion y modifica el precio segun lo que el usuario decida
/// @param Pasajero
/// @param pos
/// @return -1 si no se logro  0 si se logro
int modifyprice(Passenger *Pasajero, int pos);

/// @fn int modifytypePassenger(Passenger *Pasajero, int pos)
/// @param Pasajero
/// @param pos
/// @return -1 si no se logro  0 si se logro
int modifytypePassenger(Passenger *Pasajero, int pos);

/// @fn int modifystatusFlight(Passenger *Pasajero, int pos)
/// @param Pasajero
/// @param pos
/// @return -1 si no se logro  0 si se logro
int modifystatusFlight(Passenger *Pasajero, int pos);

/// @fn int modifyPassengers(Passenger*, int, int)
/// @brief  recibe el vector el tamaño y la id para luego mostrar un menu para selecccionar que se desea moficiar
/// @param list
/// @param len
/// @param id
/// @return-1 si no se logro  0 si se logro
int modifyPassengers(Passenger *list, int len, int id);

/// @fn int getAvarageOfprice(Passenger*, int, float*, int*)
/// @brief esta funcion calcula el promedio de los Pasajes y devuelve por referencia el promedio y el acumulado de los Pasajes
/// @param list
/// @param len
/// @param promedio
/// @param acumuladorDePasajes
/// @return
int getAvarageOfprice(Passenger *list, int len, float *promedio,
		int *acumuladorDePasajes);

/// @fn int PassengersAboveprice(Passenger*, int)
/// @brief muestra cual es el promedio de los Pasajes y cuantos Pasajeros superan el mismo
/// @param list
/// @param len
/// @return
int PassengersAboveprice(Passenger *list, int len);

/// @fn int sortForLastName(Passenger*, int)
/// @brief ordena el vector por apellido
/// @param list
/// @param len
/// @return
int sortForLastName(Passenger *list, int len);

/// @fn int sortUpPassengers(Passenger *list, int len)
/// @brief ordena el vector de manera ascendente
/// @param list
/// @param len
/// @return
int sortUpPassengers(Passenger *list, int len);

/// @fn int sortDownPassengers(Passenger *list, int len)
/// @brief ordena el vector de manera descendente
/// @param list
/// @param len
/// @return
int sortDownPassengers(Passenger *list, int len);

/// @fn int callSortPassengers(Passenger *list, int len)
/// @brief llama al ordenamiento
/// @param list
/// @param len
/// @return
int callSortPassengers(Passenger *list, int len);


/// @fn int callSortPassengersCode(Passenger *list, int len)
/// @brief llama al ordenamiento
/// @param list
/// @param len
/// @return
int callSortPassengersCode(Passenger *list, int len);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(Passenger* list, int tam, int order);
#endif /* ARRAYPASSENGER_H_ */
