#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#endif

int getInt(char *mensaje);
float getFloat(char *mensaje);

int esNumerico(char *str);
int esNumericoFlotante(char str[]);
int esSoloLetras(char str[]);

void getString(char mensaje[], char input[]);
int getStringNumeros(char mensaje[], char input[]);
int getStringNumerosFlotantes(char mensaje[], char input[]);
int getStringLetras(char mensaje[], char input[]);

int getValidString(char requestMessage[], char errorMessage[],
		char errorMessageLenght[], char input[], int maxLenght, int attemps);
int getValidInt(char mensaje[], int *input);
int getIntWithParams(char requestMessage[], char errorMessage[], int *input,
		int lowLimit, int hiLimit);
int getValidFloat(char mensaje[], float *input);
int getFloatWithParams(char requestMessage[], char errorMessage[], float *input,
		float lowLimit, float hiLimit);

int esAlpha(char str[]);
int getStringVerificado(char mensaje[], char mensajeError[], char *input);

