#include "Interface_De_Apresentacao.h"


int janela_de_apresentacao(
	int *cripto_decripto,
	String *string_de_entrada,
	int *metodo_escolhido
){
	/*
	Descrição:
		Função responsável por gerenciar a apresentação
		do output e de gravação no fluxo.
		
	Parâmetros:
		int *cripto_ou_decripto:
			Ponteiro para decisão do usuário de cripto(1) ou decripto(2).
			
		String *string_de_entrada:
			Ponteiro para entrada do usuário.
			
		int *metodo_escolhido:
			Ponteiro para método escolhido de cripto ou decripto.
	
	Retorno:
		Apresentação do resultado da cripto ou decripto da
		entrada usando o método.
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
	
	printf("Vejo como saída: %s", (*resultado).array);
	
	// Devemos liberá-la aqui.
	free((*resultado).array);
	free(resultado);
	return 0;
}






