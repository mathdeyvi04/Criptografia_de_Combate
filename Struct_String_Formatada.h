#ifndef STRUCT_STRING_FORMATADA_H
#define STRUCT_STRING_FORMATADA_H

#include "Variaveis_Importacoes.h"

typedef struct {
	char* array;
	int len;
}String;

String construir_string_estatica(char*);

#endif
