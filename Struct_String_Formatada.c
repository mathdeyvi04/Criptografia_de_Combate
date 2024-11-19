#include "Struct_String_Formatada.h"

String construir_string_estatica(
	char* frase
){
	/*
	Descri��o:
		Fun��o respons�vel por construir uma string formatada
		a partir de um array de caracteres.
		Usando mem�ria est�tica.
		
	Par�metros:
		Autoexplicativos.
		
	Retorno:
		Objeto String de tamanho definido.
	*/
	
	int *TAMANHO_DA_STRING = (int*)calloc(1, sizeof(int));
	
	while(
		frase[*TAMANHO_DA_STRING] != '\0'
	){
		// printf("Vejo o elemento: %c\n", frase[*TAMANHO_DA_STRING]);
		(*TAMANHO_DA_STRING)++;
	}
	
	String resultado = {
		frase,
		*TAMANHO_DA_STRING
	};
	
	free(TAMANHO_DA_STRING);
	
	return resultado;
}

String* construir_string_dinamica(
	char* frase
){
	/*
	Descri��o:
		Fun��o respons�vel por criar string alocada dinamicamente.
		
	Par�metros:
		Autoexplicativo.
		
	Retorno:
		Ponteiro para string formatada.
	*/
	
	int *TAMANHO_DA_STRING = (int*)calloc(1, sizeof(int));
	
	while(
		frase[*TAMANHO_DA_STRING] != '\0'
	){
		// printf("Vejo o elemento: %c\n", frase[*TAMANHO_DA_STRING]);
		(*TAMANHO_DA_STRING)++;
	}
	
	String *resultado = (String*) calloc(1, sizeof(String));
	
	(*resultado).array = frase;
	(*resultado).len = *TAMANHO_DA_STRING;
	
	free(TAMANHO_DA_STRING);
	
	return resultado;
	
}

