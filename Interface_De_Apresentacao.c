#include "Interface_De_Apresentacao.h"


int atualizar_historico(
	String *entrada,
	String *resultado
){
	/*
	Descri��o:	
		Fun��o respons�vel por atualizar o fluxo
		de entrada e sa�da do software.
		
	Par�metros:
		Autoexplicativo.
	
	Retorno:
		Atualiza��o.
	*/
	FILE *historico = fopen("historico.txt", "a");
	
	// Obtendo informa��es de tempo.
	time_t tempo_atual;
    struct tm *data_hora;

    time(&tempo_atual);
    data_hora = localtime(&tempo_atual);
    
    fprintf(
		historico,
		"Data: %02d/%02d/%d\n",
		(*data_hora).tm_mday, (*data_hora).tm_mon + 1, (*data_hora).tm_year + 1900
	);
	fprintf(
		historico,
		"Hora: %02d:%02d:%02d\n",
		(*data_hora).tm_hour, (*data_hora).tm_min, (*data_hora).tm_sec
	);
	fprintf(historico, "Entrada:\n");
	fprintf(historico, (*entrada).array);
	fprintf(historico, "\nFinal:\n");
	fprintf(historico, (*resultado).array);
	fprintf(historico, "\n\n");

	fclose(historico);
}


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
	
	printf("\n\nVejo como sa�da: %s\n", (*resultado).array);
	
	// Devemos atualizar no hist�rico.
	atualizar_historico(
		string_de_entrada,
		resultado
	);
	
	// Devemos liber�-la aqui.
	free((*resultado).array);
	free(resultado);
	return 0;
}






