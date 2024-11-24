#include "Met_Inversao.h"

String* inversao(
	int cripto_decripto,
	String *entrada,
	int *indicadores
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
	
	int *i = (int*) calloc(1, sizeof(int));
	
	while(
		// Case fosse igual à 0, ele não pegaria o último elemento 
		// da entrada, no caso o do index 0.
		((*entrada).len - 1 - *i) != -1
	){
		frase[*i] = (*entrada).array[(*entrada).len - 1 - *i];
		(*i)++;
	}
	
	frase[*i + 1] = '\0';
	
	free(i);
	(*resultado).array = frase;
	return resultado;
}

