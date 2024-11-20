#include "Interface_De_Apresentacao.h"


int janela_de_apresentacao(
	int *cripto_decripto,
	String *string_de_entrada,
	int *metodo_escolhido
){
	/*
	Descri��o:
		Fun��o respons�vel por gerenciar a apresenta��o
		do output e de grava��o no fluxo.
		
	Par�metros:
		int *cripto_ou_decripto:
			Ponteiro para decis�o do usu�rio de cripto(1) ou decripto(2).
			
		String *string_de_entrada:
			Ponteiro para entrada do usu�rio.
			
		int *metodo_escolhido:
			Ponteiro para m�todo escolhido de cripto ou decripto.
	
	Retorno:
		Apresenta��o do resultado da cripto ou decripto da
		entrada usando o m�todo.
	*/
	
	String* (*vetor_de_metodos_possiveis[1])(int, String*) = {
		inversao
	};
	
	
	String *resultado = vetor_de_metodos_possiveis[
		*metodo_escolhido - 1
	](
		*cripto_decripto,
		string_de_entrada
	);
	
	printf("Vejo como sa�da: %s", (*resultado).array);
	
	// Devemos liber�-la aqui.
	free((*resultado).array);
	free(resultado);
	return 0;
}






