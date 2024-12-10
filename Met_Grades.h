#ifndef MET_GRADES_H
#define MET_GRADES_H

#include "Met_Chave_Simples.h"

String* criptando_na_grade(
	int*,
	String*,
	char*
);

int verificando_se_estamos_em_posicao_de(
	int*,
	int*,
	int*
);

int avancando_colunas(
	int*
);

String* criando_string_criptografada(
	int,
	String*,
	int*,
	char*
);

String** descriptando_na_grade(
	int*,
	String*,
	int*,
	char*
);

String *criando_strings_descriptografada(
	String**,
	char*
);


String* gradiando(int, String*,int*);

#endif
