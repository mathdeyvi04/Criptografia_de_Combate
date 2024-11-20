#include "Met_Inversao.h"

String* inversao(
	int cripto_decripto,
	String *entrada
){
	/*
	Descri��o:
		Fun��o respons�vel por aplicar o m�todo da invers�o.
		
	Par�metros:
		Autoexplicativos.
	
	Retorno:
		String resultado.
	*/
	
	String *resultado = (String*) calloc(1, sizeof(String));
	
	// Neste case simples, temos a certeza que teremos a 
	// mesma quantidade de caracteres, sendo assim:
	char *frase = (char*)calloc(
		// Afinal, ter� a mesma quantidade de caracteres e o terminador nulo.
		(*entrada).len + 1,
		sizeof(char)
	);	
	
	// L�gica para Inversao

	(*resultado).array = frase;
	return resultado;
}







