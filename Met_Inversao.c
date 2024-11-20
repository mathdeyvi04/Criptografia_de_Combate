#include "Met_Inversao.h"

String* inversao(
	int cripto_decripto,
	String *entrada
){
	/*
	Descrição:
		Função responsável por aplicar o método da inversão.
		
	Parâmetros:
		Autoexplicativos.
	
	Retorno:
		String resultado.
	*/
	
	String *resultado = (String*) calloc(1, sizeof(String));
	
	// Neste case simples, temos a certeza que teremos a 
	// mesma quantidade de caracteres, sendo assim:
	char *frase = (char*)calloc(
		// Afinal, terá a mesma quantidade de caracteres e o terminador nulo.
		(*entrada).len + 1,
		sizeof(char)
	);	
	
	// Lógica para Inversao

	(*resultado).array = frase;
	return resultado;
}







