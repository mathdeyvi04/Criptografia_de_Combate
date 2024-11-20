#include "Struct_String_Formatada.h"

String construir_string_estatica(
	char* frase
){
	/*
	Descrição:
		Função responsável por construir uma string formatada
		a partir de um array de caracteres.
		Usando memória estática.
		
	Parâmetros:
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
	Descrição:
		Função responsável por criar string alocada dinamicamente.
		
	Parâmetros:
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

char mudar_para_ascii(
	char char_entrada
){	
	/*
	Descrição:
		Função responsável por receber caracteres que
		possivelmente não são ascii e transformá-los para
		ascii.
		
		Esta função não seria necessária para o caso de garantirmos
		que não há caracteres especiais.
	
	Parâmetros:
		char char_entrada:
			Possível caractere não ascii.
			
	Retorno:
		Caractere ascii.
	*/
	
	switch (
		char_entrada
	){
		case 'ç': return 'c';
		
		case 'á': return 'a';
		
		case 'é': case 'ê': return 'e';
		
		case 'í': return 'i';
		
		case 'ó': return 'o';
		
		case 'ú': return 'u';
		
		default:
			return char_entrada;
	}
}

















