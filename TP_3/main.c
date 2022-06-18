#include "Controller.h"
#define ARCHIVOTEXTO "data.csv"
#define ARCHIVOBINARIO "data.bin"
#define ARCHIVOID "id.csv"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main() {
	setbuf(stdout, NULL);
	int option = 0;
	int id;
	int banderaDeLectura;
	int banderaDeAgregado;
	int banderaDeCambios;
	banderaDeCambios = -1;
	banderaDeLectura = 0;
	banderaDeAgregado = 0;
	LinkedList *listaPasajeros = ll_newLinkedList();

	do {
		printf(
				"Menu:\n"
						"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
						"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
						"3. Alta de pasajero\n"
						"4. Modificar datos de pasajero\n"
						"5. Baja de pasajero\n"
						"6. Listar pasajeros\n"
						"7. Ordenar pasajeros\n"
						"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
						"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
						"10. Salir\n");
		getIntWithParams("Ingrese la opcion deseada: \n", "Opcion invalida\n",
				&option, 1, 10);
		switch (option) {
		case 1:
			if (banderaDeLectura == 0) {
				get_id_Text(&id);
				controller_loadFromText(ARCHIVOTEXTO, listaPasajeros);
				//	set_id_Text(2);
				banderaDeLectura = 1;
			} else {
				printf("Ya fueron cargados los datos\n");
			}

			break;
		case 2:
			if (banderaDeLectura == 0) {
				controller_loadFromBinary(ARCHIVOBINARIO, listaPasajeros);
				banderaDeLectura = 1;
			} else {

				printf("Ya fueron cargados los datos\n");
			}

			break;
		case 3:
			banderaDeAgregado = 1;
			banderaDeCambios = 0;
			controller_addPassenger(listaPasajeros);

			break;
		case 4:
			if (banderaDeLectura == 0 && banderaDeAgregado == 0) {

				printf("Es necesario cargar algun pasajero.\n");

			} else {
				controller_editPassenger(listaPasajeros);
				banderaDeCambios = 0;
			}
			break;
		case 5:
			if (banderaDeLectura == 0 && banderaDeAgregado == 0) {

				printf("Es necesario cargar algun pasajero.\n");

			} else {
				controller_removePassenger(listaPasajeros);
				banderaDeCambios = 0;
			}
			break;

		case 6:
			if (banderaDeLectura == 0 && banderaDeAgregado == 0) {

				printf("Es necesario cargar algun pasajero.\n");

			} else {
				controller_ListPassenger(listaPasajeros);

			}

			break;
		case 7:
			if (banderaDeLectura == 0 && banderaDeAgregado == 0) {

				printf("Es necesario cargar algun pasajero.\n");

			} else {
				controller_sortPassenger(listaPasajeros);

			}

			break;

		case 8:
			if (banderaDeLectura == 0 || banderaDeAgregado == 0) {

				printf("Es necesario cargar algun pasajero.\n");

			} else {
				banderaDeCambios = 1;
				banderaDeAgregado = 0;
				controller_saveAsText(ARCHIVOTEXTO, listaPasajeros);
			}

			break;
		case 9:
			if (banderaDeLectura == 0 && banderaDeAgregado == 0) {

				printf("Es necesario cargar algun pasajero.\n");

			} else {
				banderaDeAgregado = 0;
				banderaDeCambios = 1;
				controller_saveAsBinary(ARCHIVOBINARIO, listaPasajeros);
			}

			break;
		case 10:
			if (banderaDeLectura == 0) {
				printf(
						"Antes de salir se solicita guardar los datos.\n");
				printf("1-Cargar en texto\n"
						"2-Cargar en binario\n");
				getIntWithParams("Ingrese la opcion que desee: ",
						"Opcion invalida", &option, 1, 2);
				switch (option) {
				case 1:

					controller_loadFromText
					(ARCHIVOTEXTO, listaPasajeros);
					banderaDeLectura = 1;
					break;
				case 2:
					controller_loadFromBinary(ARCHIVOBINARIO, listaPasajeros);

					banderaDeLectura = 1;
					break;
				}

			}

		}

	} while (option != 10);
	return 0;
}

