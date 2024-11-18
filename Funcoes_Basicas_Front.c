#include "Funcoes_Basicas_Front.h"

void cabecalho(
	String titulo,
	char caractere_de_apresentacao,
	int PADDING
){
	/*
	Descrição:
		Função responsável por estilizar títulos.
		Em suma, será utilizada nas janelas, mas poderá
		não se limitar a elas.
	
	Parâmetros:
		String titulo:
			Título que desejamos na janela.
			
		char caractere_de_apresentacao:	
			Caractere expoente que fará a separação.
			
		int PADDING:
			Espaço vazio que será colocado de ambos lados.
			
	Retorno:
		Título estilizado da forma:
		===========
		   titulo
		===========
	*/
	
	// Definindo variáveis úteis.
	int *contador = (int*)calloc(1, sizeof(int));
	
	int *QUANTIDADE_TOTAL_DE_CARACTERES_DE_APRESENTACAO = (int*) calloc(1, sizeof(int));
	*QUANTIDADE_TOTAL_DE_CARACTERES_DE_APRESENTACAO = 2 * (PADDING) + titulo.len;
	
	for(
		*contador = 0;
		*contador < *QUANTIDADE_TOTAL_DE_CARACTERES_DE_APRESENTACAO;
		(*contador)++
	){
		printf("%c", caractere_de_apresentacao);
	}
	
	// Devemos ser capazes de colocar o título no centro
	printf("\n");
	for(
		*contador = 0;
		*contador < PADDING;
		(*contador)++
	){
		printf(" ");
	}
	
	for(
		*contador = 0;
		*contador < titulo.len;
		(*contador)++
	){
		printf("%c", titulo.array[*contador]);
	}
	
	for(
		*contador = 0;
		*contador < PADDING;
		(*contador)++
	){
		printf(" ");
	}
	
	// Finalizando
	printf("\n");
	for(
		*contador = 0;
		*contador < *QUANTIDADE_TOTAL_DE_CARACTERES_DE_APRESENTACAO;
		(*contador)++
	){
		printf("%c", caractere_de_apresentacao);
	}
	printf("\n");
	
	free(contador);
	free(QUANTIDADE_TOTAL_DE_CARACTERES_DE_APRESENTACAO);
}

void cor(
	int estilo,
	int texto,
	int fundo
){
	/*
	Descrição:
		Função responsável por alterar as cores do prompt.
	
	Parâmetros:
		Autoexplicativos.
		Colocando -1, nada acontece.
		
	Retorno:
		Aplicação da cor.
	*/
	
	if (estilo != -1){
		printf("\033[%dm", estilo);
	}
	
	if (texto != -1){
		printf("\033[%dm", texto);
	}
	
	if (fundo != -1){
		printf("\033[%dm", fundo);
	}	
	
}
