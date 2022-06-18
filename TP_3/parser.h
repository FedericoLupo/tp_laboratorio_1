#include "input.h"
#include "LinkedList.h"
#include "Passenger.h"
#ifndef PARSER_H_
#define PARSER_H_
#endif /* PARSER_H_ */

int parser_PassengerFromText(FILE *pFile, LinkedList *pArrayListPassenger);
int parser_PassengerFromBinary(FILE *pFile, LinkedList *pArrayListPassenger);
int parser_textFromPassenger(FILE *pFile, LinkedList *pArrayListPassenger);
int parser_binaryFromPassenger(FILE *pFile, LinkedList *pArrayListPassenger);
int parser_idFromText(FILE *pFile, LinkedList *pArrayListPassenger);
int parser_textFromId(FILE *pFile, LinkedList *pArrayListPassenger);
int get_id_Text(int *id);
int set_id_Text( int id);
