#include "controller.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE *pFile;
	int retorno;
	retorno = -1;
	pFile = fopen(path, "r");
	if (pFile != NULL) {

		parser_PassengerFromText(pFile, pArrayListPassenger);

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	fclose(pFile);
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE *pFile;
	int retorno;
	retorno = -1;
	pFile = fopen(path, "rb");
	if (pFile != NULL) {

		parser_PassengerFromBinary(pFile, pArrayListPassenger);

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	fclose(pFile);
	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	Passenger *newPassenger;
	int id;
	int confirmacion;
	int retorno;

	retorno = -1;
	confirmacion =
			confirmacionDeAccion(
					"Si desea confirmar el alta de un pasajero escriba 'si', de lo contrario escriba otra cosa"
							"\n");

	if (confirmacion == 0) {
		if (pArrayListPassenger != NULL) {

			//generadorDeId(pArrayListPassenger, &id);

			get_id_Text(&id);
			id++;
			newPassenger = Passenger_add(id);
			set_id_Text(id);

			ll_add(pArrayListPassenger, newPassenger);
			printf("El pasajero fue dado de alta correctamente\n");
			retorno = 0;

		} else {
			printf("Ocurrio un error\n");
		}
	}
	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	Passenger *aux;
	int idABuscar;
	int pos;
	retorno = -1;

	if (pArrayListPassenger != NULL) {

		controller_ListPassenger(pArrayListPassenger);
		getValidInt("Ingrese el Id del pasajero que desea modificar\n",
				&idABuscar);
		pos = findPassenger_by_Id(pArrayListPassenger, idABuscar);
		if (pos != -1) {
			aux = ll_get(pArrayListPassenger, pos);
			aux = Passenger_modification(aux);
		} else {
			printf("No se encontro el pasajero\n");
		}

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}

	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	Passenger *aux;
	int idABuscar;
	int pos;
	int indice;
	int confirmacion;

	controller_ListPassenger(pArrayListPassenger);
	getValidInt("Ingrese el Id del pasajero que desea eliminar\n", &idABuscar);
	pos = findPassenger_by_Id(pArrayListPassenger, idABuscar);
	if (pos != -1) {
		aux = ll_get(pArrayListPassenger, pos);
		Passenger_print(aux);
		confirmacion =
				confirmacionDeAccion(
						"Si desea confirmar la baja de este pasajero ingrese 'si', de lo contrario escriba otra cosa\n");
		if (confirmacion == 0) {
			indice = ll_indexOf(pArrayListPassenger, aux);
			ll_remove(pArrayListPassenger, indice);
			Passenger_delete(aux);
			printf("El pasajero fue removido correctamente\n");
			Passenger_print(aux);
			printf("Removido\n");
		}

	} else {
		printf("No se encontro el pasajero\n");
	}

	return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger *aux;
	int tam;
	int retorno;
	retorno = -1;

	if (pArrayListPassenger != NULL) {
		tam = ll_len(pArrayListPassenger);
		for (int i = 0; i < tam; i++) {
			aux = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_print(aux);
			retorno = 0;
		}

	} else {
		printf("Ocurrio un error\n");
	}

	return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int option;
	int subOption;
	retorno = -1;

	if (pArrayListPassenger != NULL) {

		do {

			printf(
					"1. Listado de los Pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero\n"
					"2. Total y promedio de los Pasajes y cuantos Pasajeros superan el precio promedio.\n"
					"3. Listado de los Pasajeros ordenados por Codigo de vuelo y estados de vuelos ‘ACTIVO’\n"
					"4. Salir\n");
			getIntWithParams("Ingrese que desea ver\n ","Ingrese una opcion valida\n",
					&option, 1, 4);
			switch (option) {

			case 1:
				printf("*Ordenar por Apellido y Tipo de pasajero\n*"
						"0. Ordenar de mayor a menor\n"
						"1. Ordenar de menor a mayor\n"
						"2. Salir\n");
				getIntWithParams("Ingrese que desea ver\n ","Ingrese una opcion valida\n",
						&subOption, 0, 2);

				if (subOption != 2) {

					ll_sort(pArrayListPassenger, Passenger_compare_name,
							subOption);

				}
				break;

			case 2:
				printf("*Ordenar por Pasajes*\n"
						"0. Ordenar de mayor a menor\n"
						"1. Ordenar de menor a mayor\n"
						"2. Salir\n");
				getIntWithParams("Ingrese que desea ver\n ","Ingrese una opcion valida\n",
						&subOption, 0, 2);
				ll_sort(pArrayListPassenger, Passenger_compare_price, subOption);

				break;

			case 3:
				printf("*Ordenar por codigo de vuelo\n*"
						"0. Ordenar de mayor a menor\n"
						"1. Ordenar de menor a mayor\n"
						"2. Salir\n");
				getIntWithParams("Ingrese que desea ver\n ","Ingrese una opcion valida\n",
						&subOption, 0, 2);
				ll_sort(pArrayListPassenger, Passenger_compare_flightCode, subOption);

				break;
			}

		} while (option != 4);

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}

	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE *pFile;
	int retorno;
	retorno = -1;
	pFile = fopen(path, "w");
	if (pFile != NULL) {

		parser_textFromPassenger(pFile, pArrayListPassenger);

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	fclose(pFile);
	return retorno;

	return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE *pFile;
	int retorno;
	retorno = -1;
	pFile = fopen(path, "wb");
	if (pFile != NULL) {
		parser_binaryFromPassenger(pFile, pArrayListPassenger);
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	fclose(pFile);
	return retorno;
}

int findPassenger_by_Id(LinkedList *pArrayListPassenger, int id) {
	Passenger *aux;
	int retorno;
	int tam;
	int idABuscar;
	retorno = -1;
	if (pArrayListPassenger != NULL) {
		tam = ll_len(pArrayListPassenger);

		for (int i = 0; i < tam; i++) {
			aux = ll_get(pArrayListPassenger, i);
			Passenger_getId(aux, &idABuscar);

			if (id == idABuscar) {

				retorno = i;
			}

		}

	}

	return retorno;
}

int generadorDeId(LinkedList *pArrayListPassenger, int *id) {
	int retorno;
	int tam;
	int banderaDeEntrada;
	int idAux;
	int auxMayor;
	banderaDeEntrada = 0;
	Passenger *aux;
	retorno = -1;

	if (pArrayListPassenger != NULL) {

		tam = ll_len(pArrayListPassenger);
		for (int i = 0; i < tam; i++) {

			aux = (Passenger*) ll_get(pArrayListPassenger, (i));

			Passenger_getId(aux, &idAux);

			if (banderaDeEntrada == 0) {
				banderaDeEntrada = 1;

				auxMayor = idAux;
				if (auxMayor < idAux) {
					auxMayor = idAux;

				}
			}

			*id = idAux + 1;

			retorno = 0;
		}

	} else {
		printf("Ocurrio un error\n");
	}

	return retorno;
}
