#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger *aux;
	int retorno;
	char id[128];
	char nombre[128];
	char apellido[128];
	char precio[128];
	char tipoPasajero[128];
	char codigoVuelo[128];

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n ", id, nombre, apellido, precio,
			tipoPasajero, codigoVuelo);
	do {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n ", id, nombre, apellido, precio,
				tipoPasajero, codigoVuelo);
		aux = Passenger_newParametros(id, nombre, apellido, precio, tipoPasajero, codigoVuelo);
		ll_add(pArrayListPassenger, aux);
		retorno = 0;

	} while (!feof(pFile));

	return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger *aux;
	int retorno;
	retorno = -1;
	if (pArrayListPassenger != NULL && pFile != NULL) {

		do {
			aux = Passenger_new();
			if (aux != NULL) {

				fread(aux, sizeof(Passenger), 1, pFile);

				if (feof(pFile)) {
					break;
				} else {

					ll_add(pArrayListPassenger, aux);
				}
				retorno = 0;
			} else {
				printf("Ocurrio un error\n");
			}

		} while (!feof(pFile));
	}
	return retorno;
}

int parser_textFromPassenger(FILE *pFile, LinkedList *pArrayListPassenger)
{
	int retorno;
	int tam;
	int idAux;
	char nombreAux[50];
	char apellidoAux[50];
	float precioAux;
	int tipoPasajeroAux;
	char codigoVueloAux[4];
	Passenger *aux;
	retorno = -1;

	if (pArrayListPassenger != NULL && pFile != NULL) {

		tam = ll_len(pArrayListPassenger);
		fprintf(pFile, "id,nombre,apellido,precio,tipo de pasajero,codigo de vuelo\n");
		for (int i = 0; i < tam; i++) {
			aux = ll_get(pArrayListPassenger, i);
			Passenger_getId(aux, &idAux);
			Passenger_getNombre(aux, nombreAux);
			Passenger_getApellido(aux, apellidoAux);
			Passenger_getPrecio(aux, &precioAux);
			Passenger_getTipoPasajero(aux, &tipoPasajeroAux);
			Passenger_getCodigoVuelo(aux, codigoVueloAux);
			fprintf(pFile, "%d,%s,%s,"
					"%f,%d,%s\n ", idAux, nombreAux, apellidoAux, precioAux,
					tipoPasajeroAux, codigoVueloAux);

		}

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

int parser_binaryFromPassenger(FILE *pFile, LinkedList *pArrayListPassenger)
{
	int tam;
	int retorno;
	Passenger *aux;
	retorno = -1;

	if (pArrayListPassenger != NULL && pFile != NULL) {

		tam = ll_len(pArrayListPassenger);
		for (int i = 0; i < tam; i++) {
			aux = (Passenger*) ll_get(pArrayListPassenger, i);
			fwrite(aux, sizeof(Passenger), 1, pFile);

			retorno = 0;
		}

	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

int get_id_Text(int *id)
{
	char idStr[128];
	FILE *pFile;
	int retorno;
	retorno = -1;
	pFile = fopen("id.csv", "r");

	if (pFile != NULL) {
		fscanf(pFile, "%[^\n]", idStr);
		*id = atoi(idStr);
	} else {
		printf("Ocurrio un error\n");
	}
	fclose(pFile);
	return retorno;
}

int set_id_Text(int id)
{
	int retorno;
	FILE *pFile;
	retorno = -1;
	pFile = fopen("id.csv", "w");
	if (pFile != NULL) {

		fprintf(pFile, "%d\n ", id);

		retorno = 0;
		fclose(pFile);
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}
