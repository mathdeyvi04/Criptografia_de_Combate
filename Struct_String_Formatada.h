#ifndef STRUCT_STRING_FORMATADA_H
#define STRUCT_STRING_FORMATADA_H

#include "Variaveis_Importacoes.h"

typedef struct {
	char* array;
	int len;
}String;

String construir_string_estatica(char*);

String* construir_string_dinamica(char*);

char mudar_para_ascii(char);

char maiusculando(char);

int* obtendo_indicadores();

int* verificador_primario();

#endif
