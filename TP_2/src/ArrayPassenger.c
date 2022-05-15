/*
 * ArrayPassengers.c
 */
#include "ArrayPassenger.h"

int pasajerosHardcodeados(Passenger* list, int len){

	Passenger Pasajeros[5]={{1, "carlos", "rodriguez", 135254,"1542", 1, 1},
							{2, "juanito", "perez", 82547,"8854", 2, 1},
							{3, "roberto", "carlos", 15864,"4498", 2, 3},
							{4, "pedro", "perez", 78524,"6782", 1, 2},
							{5, "pablo", "marmol", 144587,"5543", 1, 1}};

	int i;
	for(i=0;i<5;i++){
		list[i]=Pasajeros[i];
	}
	return 0;
}

int initPassengers(Passenger *list, int len) {
	int retorno;
	retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = VACIO;
		}
		retorno = 0;
	}

	return retorno;
}

int requestPassenger(Passenger *list, int len, int id) {
	int retorno;
	retorno = -1;
	if (list != NULL && len > 0) {

		system("cls");
		printf("Ingreso de Pasajeros\n");
		Passenger newPassenger;
		newPassenger.id = id;

		getStringVerificado("Ingrese el nombre\n",
				"Error ingrese el nombre correctamente\n", newPassenger.name);

		getStringVerificado("Ingrese el apellido\n",
				"Error ingrese correctamente el apellido\n", newPassenger.lastName);

		getFloatWithParams("Ingrese el Precio(maximo $500.000)\n", "ERROR\n",
				&newPassenger.price, 1, 500000);

		getString("Ingrese el Codigo de vuelo\n", newPassenger.flycode);

		getValidInt("ingrese el Tipo de pasajero\n", &newPassenger.typePassenger);

		getIntWithParams("ingrese el Estado de vuelo\n 1.ACTIVO / 2.DEMORADO / 3.CANCELADO\n",
				"Error ingrese una opcion valida\n", &newPassenger.statusFlight, 1, 3);

		addPassenger(list, len, newPassenger.id, newPassenger.name, newPassenger.lastName,newPassenger.price,
				newPassenger.flycode, newPassenger.typePassenger, newPassenger.statusFlight);
		retorno = 0;

	}

	return retorno;

}

int findFreePosition(Passenger *list, int len) {
	int pos = -1;
	if (list != NULL && len > 0) {

		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == VACIO) {
				pos = i;
				break;
			}
		}

	}

	return pos;
}

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],
		float price, char flycode[],int typePassenger,int statusFlight){

	int retorno;
	retorno = -1;

	if (list != NULL && len > 0) {
		int posFree;
		posFree = findFreePosition(list, len);
		list[posFree].id = id;
		strcpy(list[posFree].name, name);
		strcpy(list[posFree].lastName, lastName);
		list[posFree].price = price;
		strcpy(list[posFree].flycode, flycode);
		list[posFree].typePassenger = typePassenger;
		list[posFree].isEmpty = CARGADO;

		retorno = 0;
	}

	return retorno;
}

int findPassengerById(Passenger *list, int len, int id) {
	int pos;
	pos = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == CARGADO && list[i].id == id) {
				pos = i;
				break;
			}
		}
	}

	if (pos == -1) {
		printf("No existe un pasajero con ese ID\n");
		system("pause");
	}

	return pos;
}
int removePassenger(Passenger *list, int len, int id) {
	int retorno, pos;
	retorno = -1;
	pos = findPassengerById(list, len, id);
	if (pos > -1) {

		list[pos].isEmpty = VACIO;
		printf("El pasajero fue dado de baja correctamente\n");
		system("pause");
		retorno = 0;
	}

	return retorno;

}

int callSortPassengers(Passenger *list, int len) {
	int retorno, option;
	retorno = -1;

	getIntWithParams("Ingrese 1 para ordenar de arriba hacia abajo\n"
			"Ingrese 0 para ordenar de abajo hacia arriba\n",
			"ERROR ingrese la opcion correctamente\n", &option, 0, 1);

	sortPassengers(list, len, option);

	return retorno;
}

int sortDownPassengers(Passenger *list, int tam) {
	Passenger temp;
	int retorno;
	retorno = 0;

	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (strcmp(list[i].lastName, list[j].lastName)
					< 0&& list[i].isEmpty == CARGADO && list[j].isEmpty == CARGADO) {
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			} else {
				if (strcmp(list[i].lastName, list[j].lastName) == 0) {

					if (list[i].typePassenger
							> list[j].typePassenger&& list[i].isEmpty == CARGADO && list[j].isEmpty == CARGADO) {
						temp = list[i];
						list[i] = list[j];
						list[j] = temp;
					}
				}
			}
		}
	}

	return retorno;
}

int sortUpPassengers(Passenger *list, int tam) {

	Passenger temp;
	int retorno;
	retorno = 0;
	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (strcmp(list[i].lastName, list[j].lastName)
					> 0&& list[i].isEmpty == CARGADO && list[j].isEmpty == CARGADO) {
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			} else {
				if (strcmp(list[i].lastName, list[j].lastName) == 0) {

					if (list[i].typePassenger
							> list[j].typePassenger&& list[i].isEmpty == CARGADO && list[j].isEmpty == CARGADO) {
						temp = list[i];
						list[i] = list[j];
						list[j] = temp;
					}
				}
			}
		}
	}
	return retorno;
}

int sortPassengers(Passenger *list, int len, int option) {
	int retorno;
	retorno = -1;

	if (list != NULL && len > 0) {
		if (option == 1) {
			sortUpPassengers(list, len);

		} else {
			sortDownPassengers(list, len);

		}
		retorno = 0;
	}

	return retorno;
}

int callSortPassengersCode(Passenger *list, int len) {
	int retorno, option;
	retorno = -1;

	getIntWithParams("Ingrese 1 para ordenar de arriba hacia abajo\n"
			"Ingrese 0 para ordenar de abajo hacia arriba\n",
			"ERROR ingrese la opcion correctamente\n", &option, 0, 1);

	sortPassengersByCode(list, len, option);

	return retorno;
}

int sortPassengersByCode(Passenger* list, int tam, int order){
	Passenger temp;
	int retorno;
	retorno = 0;
		for (int i = 0; i < tam - 1; i++) {
				for (int j = i + 1; j < tam; j++) {
					if (list[i].flycode
							> list[j].flycode && list[i].isEmpty == CARGADO && list[j].isEmpty == CARGADO) {
						temp = list[i];
						list[i] = list[j];
						list[j] = temp;
					} else {
						if (list[i].flycode == list[i].flycode) {
							if (strcmp(list[i].lastName, list[j].lastName)
									> 0&& list[i].isEmpty == CARGADO && list[j].isEmpty == CARGADO) {
								temp = list[i];
								list[i] = list[j];
								list[j] = temp;
							}
						}
					}
				}
			}
	return retorno;
}

int modifyName(Passenger *Pasajero, int pos) {
	int retorno;
	retorno = 0;
	system("cls");
	getStringVerificado("Ingrese el nuevo nombre\n",
			"Ingrese correctamente el nuevo nombre", Pasajero[pos].name);

	return retorno;
}

int modifyLastName(Passenger *Pasajero, int pos) {
	int retorno;
	retorno = 0;
	system("cls");
	getStringVerificado("Ingrese el nuevo apellido\n",
			"Ingrese correctamente el nuevo apellido\n", Pasajero[pos].lastName);

	return retorno;

}

int modifyflycode(Passenger *Pasajero, int pos) {
	system("cls");
	getString("Ingrese el nuevo Codigo de vuelo\n", Pasajero[pos].flycode);

	return 0;
}
int modifyprice(Passenger *Pasajero, int pos) {
	system("cls");
	getValidFloat("Ingrese el nuevo salario\n", &Pasajero[pos].price);

	return 0;
}

int modifytypePassenger(Passenger *Pasajero, int pos) {
	system("cls");
	getValidInt("Ingrese el nuevo tipo de pasajero\n", &Pasajero[pos].typePassenger);

	return 0;
}

int modifystatusFlight(Passenger *Pasajero, int pos) {
	system("cls");
	getValidInt("Ingrese el nuevo estado\n", &Pasajero[pos].statusFlight);

	return 0;
}

int modifyPassengers(Passenger *list, int len, int id) {
	int pos, option;
	pos = findPassengerById(list, len, id);
	system("cls");
	if (pos != -1) {

		do {
			system("cls");
			printf("1. Modificar el nombre\n");
			printf("2. Modificar el apellido\n");
			printf("3. Modificar el precio\n");
			printf("4. Modificar el codigo de vuelo\n");
			printf("5. Modificar el tipo de pasajero\n");
			printf("6. Modificar el estado de vuelo\n");
			printf("7. Atras\n");
			getIntWithParams("ingrese una opcion\n",
					"ingrese correctamente la opcion\n", &option, 1, 7);
			switch (option) {
			case 1:
				modifyName(list, pos);
				break;

			case 2:
				modifyLastName(list, pos);
				break;

			case 3:
				modifyprice(list, pos);
				break;

			case 4:
				modifyflycode(list, pos);
				break;

			case 5:
				modifytypePassenger(list, pos);
				break;

			case 6:
				modifystatusFlight(list, pos);
				break;

			}

		} while (option != 7);

	}

	return 0;
}

int getAvarageOfprice(Passenger *list, int len, float *promedio,
		int *acumuladorDePasajes) {
	int contadorDePasajeros, auxDeAcumuladorDePasajes;

	contadorDePasajeros = 0;
	auxDeAcumuladorDePasajes = 0;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {

			if (list[i].isEmpty == CARGADO) {
				auxDeAcumuladorDePasajes = auxDeAcumuladorDePasajes
						+ list[i].price;
				++contadorDePasajeros;

			}
		}

	}

	*promedio = auxDeAcumuladorDePasajes / (float) contadorDePasajeros;
	*acumuladorDePasajes = auxDeAcumuladorDePasajes;
	return 0;
}

int PassengersAboveprice(Passenger *list, int len) {
	int contadorDePasajerosSuperadoresDePromedio, acumuladorDePasajes;
	float promedio;
	contadorDePasajerosSuperadoresDePromedio = 0;
	getAvarageOfprice(list, len, &promedio, &acumuladorDePasajes);

	for (int i = 0; i < len; i++) {

		if (list[i].price > promedio && list[i].isEmpty == CARGADO) {
			contadorDePasajerosSuperadoresDePromedio++;
		}

	}

	printf("El promedio de los Pasajes es:%.2f \n"
			"La cantidad de Pasajeros que superan el promedio son %d\n",
			promedio, contadorDePasajerosSuperadoresDePromedio);
	return 1;
}

int printPassenger(Passenger nombre) {

	printf("\t\t\t|%5d|%9s|%10s|", nombre.id, nombre.name, nombre.lastName);
	printf("%8s|%8d|%10.2f|%8d|\n", nombre.flycode, nombre.typePassenger,nombre.price,nombre.statusFlight);

	return 0;
}

int printPassengers(Passenger *list, int len) {
	int retorno;
	retorno = -1;
	system("cls");
	printf("\t\t\t ________________________________________________________________ \n");
	printf("\t\t\t|     |         |          |Codigo  |Tipo de |          |        |\n");
	printf("\t\t\t| Id  | Nombre  | Apellido |de vuelo|Pasajero|  Precio  | Estado |\n");
	printf("\t\t\t|_____|_________|__________|________|________|__________|________|\n");
	for (int i = 0; i < len; i++) {

		if (list != NULL && len > 0) {

			if (list[i].isEmpty == CARGADO) {
				printPassenger(list[i]);
			}
			retorno = 0;
		}

	}

	return retorno;
}
