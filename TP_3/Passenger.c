#include "Passenger.h"

//id
int Passenger_setId(Passenger *this, int id) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		this->id = id;
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

int Passenger_getId(Passenger *this, int *id) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		*id = this->id;
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

// Nombre
int Passenger_setNombre(Passenger *this, char *nombre) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

int Passenger_getNombre(Passenger *this, char *nombre) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		strcpy(this->apellido, apellido);
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		strcpy(apellido, this->apellido);
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

// Codigo de Vuelo
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}



// Tipo de Pasajero
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}

	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

// Precio
int Passenger_setPrecio(Passenger* this,float precio) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		this->precio = precio;
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		*precio = this->precio;
		retorno = 0;

	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

// Constructores
Passenger* Passenger_new() {

	Passenger *retorno;

	retorno = (Passenger*) calloc(1, sizeof(Passenger));

	return retorno;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr) {

	Passenger *newPassenger;
	newPassenger = Passenger_new();

	if (newPassenger != NULL) {
		Passenger_setId(newPassenger, atoi(idStr));
		Passenger_setNombre(newPassenger, nombreStr);
		Passenger_setTipoPasajero(newPassenger, atoi(tipoPasajeroStr));
	} else {
		printf("Ocurrio un error\n");
	}
	return newPassenger;
}

int Passenger_print(Passenger *this) {
	int retorno;
	retorno = -1;
	int idAux;
	char nombreAux[50];
	char apellidoAux[50];
	float precioAux;
	int tipoPasajeroAux;
	char codigoVueloAux[4];
	if (this != NULL) {

		Passenger_getId(this, &idAux);
		Passenger_getNombre(this, nombreAux);
		Passenger_getApellido(this, apellidoAux);
		Passenger_getPrecio(this, &precioAux);
		Passenger_getTipoPasajero(this, &tipoPasajeroAux);
		Passenger_getCodigoVuelo(this, codigoVueloAux);
		printf("%d, %s, %s, %f.2, %d, %s\n", idAux, nombreAux, apellidoAux, precioAux,
				tipoPasajeroAux, codigoVueloAux);

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}

	return retorno;

}

// modificacion

Passenger* Passenger_modification(Passenger *this) {
	int option;
	do {
		printf("*modificacion De Pasajeros*\n"
				"1-Modificar Nombre\n"
				"2-Modificar Apellido\n"
				"3-Modificar Precio\n"
				"4-Modificar Tipo de Vuelo\n"
				"5-Modificar Codigo de Vuelo\n"
				"6-Salir\n");
		getIntWithParams("ingrese la opcion deseada\n", "opcion invalida\n",
				&option, 1, 6);
		switch (option) {

		case 1:
			Passenger_name_Modification(this);
			break;
		case 2:
			Passenger_lastName_Modification(this);
			break;
		case 3:
			Passenger_price_Modification(this);
			break;
		case 4:
			Passenger_typeOfPassenger_Modification(this);
			break;
		case 5:
			Passenger_flightCode_Modification(this);
			break;
		}

	} while (option != 4);
	return this;
}
Passenger* Passenger_name_Modification(Passenger *this) {
	char nombreAux[50];

	Passenger_print(this);
	getStringVerificado("ingrese el nuevo nombre\n",
			"ingrese el nombre correctamente\n", nombreAux);
	Passenger_setNombre(this, nombreAux);
	Passenger_print(this);
	return this;
}

Passenger* Passenger_lastName_Modification(Passenger *this) {
	char apellidoAux[50];

	Passenger_print(this);
	getStringVerificado("ingrese el nuevo apellido\n",
			"ingrese el apellido correctamente\n", apellidoAux);
	Passenger_setApellido(this, apellidoAux);
	Passenger_print(this);
	return this;
}

Passenger* Passenger_price_Modification(Passenger *this) {
	int precioAux;
	Passenger_print(this);
	getValidInt("ingrese el nuevo precio\n", &precioAux);
	Passenger_setPrecio(this, precioAux);
	Passenger_print(this);
	return this;
}

Passenger* Passenger_typeOfPassenger_Modification(Passenger *this) {
	int tipoPasajeroAux;
	Passenger_print(this);
	getValidInt("ingrese el nuevo Tipo de Pasajero\n", &tipoPasajeroAux);
	Passenger_setTipoPasajero(this, tipoPasajeroAux);
	Passenger_print(this);

	return this;
}

Passenger* Passenger_flightCode_Modification(Passenger *this) {
	int codigoVueloAux;
	Passenger_print(this);
	getValidInt("ingrese el nuevo Tipo de Pasajero\n", &codigoVueloAux);
	Passenger_setTipoPasajero(this, codigoVueloAux);
	Passenger_print(this);

	return this;
}

//agregar Pasajeros por consola.

Passenger* Passenger_add(int id) {
	Passenger *newPassenger;
	char nombreAux[50];
	char apellidoAux[50];
	float precioAux;
	int tipoPasajeroAux;
	char codigoVueloAux[4];

	newPassenger = Passenger_new();
	if (newPassenger != NULL) {

		printf("*ingreso de Pasajeros\n*");
		getStringVerificado("ingrese el nombre\n",
						"error ingrese el nombre correctamente\n", nombreAux);
		getStringVerificado("ingrese el apellido\n",
						"error ingrese el apellido correctamente\n", apellidoAux);
		getValidFloat("ingrese el precio del nuevo Pasajero.\n", &precioAux);
		getValidInt("ingrese el tipo de pasajero\n", &tipoPasajeroAux);
		getString("ingrese el codigo de vuelo\n", codigoVueloAux);

		Passenger_setTipoPasajero(newPassenger, tipoPasajeroAux);
		Passenger_setNombre(newPassenger, nombreAux);
		Passenger_setPrecio(newPassenger, precioAux);
		Passenger_setId(newPassenger, id);
	} else {
		printf("Ocurrio un error\n");
	}

	return newPassenger;

}

// ordenamiento

int Passenger_compare_name(void *uno, void *dos) {
	int retorno;
	char nombreUno[128];
	char nombreDos[128];
	Passenger *primero;
	Passenger *segundo;

	retorno = -1;
	primero = (Passenger*) uno;
	segundo = (Passenger*) dos;
	Passenger_getNombre(primero, nombreUno);
	Passenger_getNombre(segundo, nombreDos);
	retorno = stricmp(nombreUno, nombreDos);

	return retorno;

}

int Passenger_compare_price(void *uno, void *dos) {
	int retorno;
	float precioUno;
	float precioDos;
	retorno = -1;
	Passenger *primero;
	Passenger *segundo;
	primero = (Passenger*) uno;
	segundo = (Passenger*) dos;
	if (Passenger_getPrecio(primero, &precioUno) == 0
			&& Passenger_getPrecio(segundo, &precioDos) == 0) {
		retorno = 0;
		if (precioUno < precioDos) {

			retorno = 1;
		} else {

			if (precioUno > precioDos) {
				retorno = -1;

			}

		}

	}

	return retorno;

}

int Passenger_compare_flightCode(void *uno, void *dos) {
	int retorno;
	char codigoVueloUno[128];
	char codigoVueloDos[128];
	retorno = -1;
	Passenger *primero;
	Passenger *segundo;
	primero = (Passenger*) uno;
	segundo = (Passenger*) dos;

	Passenger_getNombre(primero, codigoVueloUno);
	Passenger_getNombre(segundo, codigoVueloDos);
	retorno = stricmp(codigoVueloUno, codigoVueloDos);

	return retorno;

}

int Passenger_delete(Passenger *this) {
	int retorno;

	retorno = -1;

	if (this != NULL) {

		free(this);

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}

	return retorno;
}
