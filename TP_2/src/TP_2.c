/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "ArrayPassenger.h"
#include "input.h"
#define TAM 2000

int main(void) {
	setbuf(stdout, NULL);
	int option, banderaPrimeraIinicializacion, contador, id, optionOfMainFour,
			confirmacion;
	contador = 0;
	banderaPrimeraIinicializacion = 0;
	Passenger Pasajeros[TAM];


	do {
		pasajerosHardcodeados(Pasajeros, TAM);
		printf("1.Alta de un Pasajero\n");
		printf("2.Modificar la informacion de un Pasajero\n");
		printf("3.Dar de baja a un Pasajero\n");
		printf("4.Informar\n");
		printf("5.Salir\n\n");
		getIntWithParams("Ingrese una opcion: \n",
				"Ingrese correctamente la opcion: \n", &option, 1, 5);
		switch (option) {
		case 1:
			if (banderaPrimeraIinicializacion == 0) {
				banderaPrimeraIinicializacion = 1;
				initPassengers(Pasajeros, TAM);
			}

			getValidInt("Ingrese 1 para confirmar el alta de un nuevo Pasajero"
					" o presione otra tecla para volver: ", &confirmacion);
			if (confirmacion == 1) {
				contador++;
				requestPassenger(Pasajeros, TAM, contador);

			}

			break;
		case 2:
			system("cls");
			if (banderaPrimeraIinicializacion == 1) {
				getIntWithParams("Ingrese el ID: \n", "El ID es invalido: \n", &id,
						1, 1000);
				modifyPassengers(Pasajeros, TAM, id);

			} else {
				printf("No hay ningun Pasajero cargado\n");
			}

			break;
		case 3:
			system("cls");
			if (banderaPrimeraIinicializacion == 1) {
				getValidInt("Ingrese el ID: \n", &id);
				removePassenger(Pasajeros, TAM, id);
			} else {
				printf("No hay ningun Pasajero cargado\n");
			}

			break;
		case 4:
			system("cls");
			if (banderaPrimeraIinicializacion == 1) {
				printf(
						"1. Listado de los Pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero\n"
						"2. Total y promedio de los Pasajes y cuantos Pasajeros superan el precio promedio.\n"
						"3. Listado de los Pasajeros ordenados por Codigo de vuelo y estados de vuelos ‘ACTIVO’\n");
				getIntWithParams("Ingrese que desea ver\n ",
						"Ingrese una opcion valida\n", &optionOfMainFour, 1, 3);
				switch (optionOfMainFour) {

				case 1:
					system("cls");
					callSortPassengers(Pasajeros, option);
					printPassengers(Pasajeros, TAM);
					break;

				case 2:
					system("cls");
					PassengersAboveprice(Pasajeros, TAM);
					break;

				case 3:
					system("cls");
					callSortPassengersCode(Pasajeros, option);
					printPassengers(Pasajeros, TAM);
					break;
				}

			} else {
				printf("No hay ningun Pasajero cargado\n");
			}

			break;

		}
	} while (option != 5);

}
