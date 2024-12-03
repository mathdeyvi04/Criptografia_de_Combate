#include "Interface_De_Apresentacao.h"


int atualizar_historico(
	String *entrada,
	String *resultado
){
	/*
	Descrição:	
		Função responsável por atualizar o fluxo
		de entrada e saída do software.
		
	Parâmetros:
		Autoexplicativo.
	
	Retorno:
		Atualização.
	*/
	FILE *historico = fopen("historico.txt", "a");
	
	// Obtendo informações de tempo.
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
	String* (*vetor_de_metodos_possiveis[2])(int, String*, int*) = {
		inversao,
		gradiando
	};
	
	// Vamos pegar indicadores de processo
	int *indicadores_de_processo = (int*)calloc(1, sizeof(int));
	indicadores_de_processo = NULL;
	if (
		*metodo_escolhido != 1
	){
		indicadores_de_processo = obtendo_indicadores(verificando_letras_mortas(string_de_entrada));
	}

	String *resultado = vetor_de_metodos_possiveis[
		*metodo_escolhido - 1
	](
		*cripto_decripto,
		string_de_entrada,
		indicadores_de_processo
	);
	
	printf("\n\nVejo como saída: %s\n", (*resultado).array);
	
	// Devemos atualizar no histórico.
	atualizar_historico(
		string_de_entrada,
		resultado
	);
	
	// Devemos liberá-los aqui.
	free(indicadores_de_processo);
	free((*resultado).array);
	free(resultado);	
	return 0;
}






