#ifndef Passenger_H_INCLUDED
#define Passenger_H_INCLUDED
#include  "input.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int isEmpty;

}Passenger;

// leer y cargar los archivos.
//
// despues de modificar y demas otra carga de archivos.

/// @fn Passenger Passenger_new*()
/// @return el Pasajero creado y vacio
Passenger* Passenger_new(); // construcs
/// @fn Passenger Passenger_newParametros*(char*, char*, char*)
/// @brief crea un Pasajero y le carga dentro de los campos correspondientes los parametros recibidos.
/// @param idStr id a cargar
/// @param nombreStr nombre a cargar
/// @param tipoPasajeroStr tipo de pasajero a cargar
/// @return retorna el Pasajero con los campos cargados
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr);
/// @fn int Passenger_delete(Passenger*)
/// @brief recibe un Pasajero y lo elimina de la memoria interna del programa.
/// @param this
/// @return retorna 0 si se pudo o -1 si el puntero es null.
int Passenger_delete(Passenger *this);
// agregar por cada set funciones que pidan por consola los datos que sean necesarios.
// funcion de comparacion x cada campo de Pasajero.

// Id
/// @fn int Passenger_setId(Passenger*, int)
/// @brief  recibe un id y lo ingresa en el campo correspondinete de la estructura
/// @param this puntero a Pasajero
/// @param id
/// @return retorna 0 si se pudo o -1 si el puntero es null
int Passenger_setId(Passenger *this, int id); // aca flechita
/// @fn int Passenger_getId(Passenger*, int*)
/// @brief recibe el Pasajero y una variablde donde cargar el id del Pasajero
/// @param this puntero a Pasajero
/// @param id
/// @return retorna 0 si se pudo o -1 si el puntero es null
int Passenger_getId(Passenger *this, int *id); //aca flechita

// Nombre
/// @fn int Passenger_setNombre(Passenger*, char*)
/// @brief recibe nombre, un puntero e ingresa el nombre en el campo correspondiente de la estrucura.
/// @param this puntero a Pasajero
/// @param nombre nombre a setear
/// @return retorna 0 si se pudo o -1 si el puntero es null
int Passenger_setNombre(Passenger *this, char *nombre); //aca flechita
/// @fn int Passenger_getNombre(Passenger*, char*)
/// @brief recibe el Pasajero y una variablde donde cargar el nombre del Pasajero
/// @param this puntero a Pasajero
/// @param nombre
/// @return retorna 0 si se pudo o -1 si el puntero null
int Passenger_getNombre(Passenger *this, char *nombre); //aca flechita
/// @fn int Passenger_setApellido(Passenger*, char*)
/// @brief recibe apellido, un puntero e ingresa el apellido en el campo correspondiente de la estrucura.
/// @param this puntero a Pasajero
/// @param apellido apellido a setear
/// @return retorna 0 si se pudo o -1 si el puntero es null
int Passenger_setApellido(Passenger* this,char* apellido);
/// @fn int Passenger_getApellido(Passenger*, char*)
/// @brief recibe el Pasajero y una variablde donde cargar el apellido del Pasajero
/// @param this puntero a Pasajero
/// @param apellido
/// @return retorna 0 si se pudo o -1 si el puntero null
int Passenger_getApellido(Passenger* this,char* apellido);

// Codigo de Vuelo
/// @fn int Passenger_setCodigoVuelo(Passenger*, char)
/// @brief recibe codigoVuelo, un puntero e ingresa el codigo de Vuelo en el campo correspondiente de la estrucura.
/// @param this untero a Pasajero
/// @param codigoVuelo codigoVuelo a setear
/// @return retorna 0 si se pudo o -1 si el puntero es null
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
/// @fn int Passenger_getCodigoVuelo(Passenger*, char*)
/// @brief  recibe el Pasajero y una variablde donde cargar el codigo de Vuelo del Pasajero
/// @param this puntero a Pasajero
/// @param codigoVuelo
/// @return retorna 0 si se pudo o -1 si el puntero es null
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

// Tipo de Pasajero
/// @fn int Passenger_setTipoPasajero(Passenger*, int)
/// @brief recibe un tipo de Pasajero, un puntero e ingresa el tipo de Pasajero en el campo correspondiente de la estrucura.
/// @param this puntero a Pasajero
/// @param tipo de Pasajero el tipo de Pasajero a setear
/// @return retorna 0 si se pudo o -1 si el puntero es null
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
/// @fn int Passenger_getTipoPasajero(Passenger*, int*)
/// @brief recibe el Pasajero y una variablde donde cargar el tipo de Pasajero
/// @param this puntero a Pasajero
/// @param tipo de Pasajero  variable donde se va recibir el tipo de Pasajero del Pasajero
/// @return retorna 0 si se pudo o -1 si el puntero es null
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

// Precio
/// @fn int Passenger_setPrecio(Passenger*, float)
/// @brief recibe un precio, un puntero e ingresa el precio en el campo correspondiente de la estrucura.
/// @param this puntero a Pasajero
/// @param precio el precio a setear
/// @return retorna 0 si se pudo o -1 si el puntero es null
int Passenger_setPrecio(Passenger* this,float precio);
/// @fn int Passenger_getPrecio(Passenger*, float*)
/// @brief recibe el Pasajero y una variablde donde cargar el tipo de Pasajero
/// @param this puntero a Pasajero
/// @param precio variable donde se va recibir el precio
/// @return retorna 0 si se pudo o -1 si el puntero es null
int Passenger_getPrecio(Passenger* this,float* precio);

// Print
int Passenger_print(Passenger *this);

// Modificacion
/// @fn Passenger Passenger_modification*(Passenger*)
/// @brief recibe una Pasajero y modifica el Pasajero donde se pida
/// @param this Pasajero.
/// @return retorna el Pasajero modificado.
Passenger* Passenger_modification(Passenger *this);
/// @fn Passenger Passenger_name_Modification*(Passenger*)
/// @brief  recibe un Pasajero y modifica el nombre con los datos que el usuario ponga.
/// @param this
/// @return retorna el Pasajero modificado.
Passenger* Passenger_name_Modification(Passenger *this);/// @fn Passenger Passenger_name_Modification*(Passenger*)
/// @fn Passenger Passenger_lastName_Modification*(Passenger*)
/// @brief  recibe un Pasajero y modifica el apellido con los datos que el usuario ponga.
/// @param this
/// @return retorna el Pasajero modificado.
Passenger* Passenger_lastName_Modification(Passenger *this);
/// @fn Passenger Passenger_price_Modification*(Passenger*)
/// @brief recibe un Pasajero y modifica el precio con los datos que el usuario ponga.
/// @param this
/// @return retorna el Pasajero modificado.
Passenger* Passenger_price_Modification(Passenger *this);
/// @fn Passenger Passenger_flightCode_Modification*(Passenger*)
/// @brief recibe un Pasajero y modifica el codigo de vuelo con los datos que el usuario ponga.
/// @param this
/// @return retorna el Pasajero modificado.
Passenger* Passenger_flightCode_Modification(Passenger *this);/// @fn Passenger Passenger_flightCode_Modification*(Passenger*)
/// @fn Passenger Passenger_typeOfPassenger_Modification*(Passenger*)
/// @brief recibe un Pasajero y modifica el tipo de pasajero con los datos que el usuario ponga.
/// @param this
/// @return retorna el Pasajero modificado.
Passenger* Passenger_typeOfPassenger_Modification(Passenger *this);
/// @fn Passenger Passenger_add*()
/// @brief añade un Pasajero por teclado
/// @return retorna el Pasajero ingresado.
Passenger* Passenger_add();

// Sort
/// @fn int Passenger_compare_name(void*, void*)
/// @brief compara dos nombre que se reciben por parametro
/// @param uno primer nombre
/// @param dos segundo nombre
/// @return retorna el resultado de la comparacion.
int Passenger_compare_name(void *uno, void *dos);
/// @fn int Passenger_compare_hours(void*, void*)
/// @brief compara las codigoVuelo
/// @param uno primer Pasajero
/// @param dos segundo Pasajero
/// @return retorna 0 si las codigoVuelo son iguales, uno si el primero es menor que el segundo
/// y -1 si las codigoVuelo del primero es mayor que el segundo
int Passenger_compare_flightCode(void *uno, void *dos);
/// @fn int Passenger_compare_price(void*, void*)
/// @brieg compara los precios.
/// @param uno  primer Pasajero
/// @param dos segundo Pasajero
/// @return retorna 0 si las codigoVuelo son iguales, uno si el sueldo del primero  es menor que el segundo
/// y -1 si el sueldo del primero es mayor  que el segundo
int Passenger_compare_price(void *uno, void *dos);

#endif // Passenger_H_INCLUDED
