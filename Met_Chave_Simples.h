#ifndef MET_CHAVE_SIMPLES_H
#define MET_CHAVE_SIMPLES_H

#include "Struct_String_Formatada.h"

String*
obtendo_chave_do_usuario();


int*
obtendo_ordem_das_colunas(
	String*
);


String*
construindo_string_cripto(
	String*,
	int*,
	int*
);


String*
chave_simplando(int, String*, int*);

#endif
