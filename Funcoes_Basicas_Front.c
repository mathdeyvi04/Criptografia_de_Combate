#include "Funcoes_Basicas_Front.h"

void cabecalho(
	String titulo,
	char caractere_de_apresentacao,
	int PADDING
){
	/*
	Descri��o:
		Fun��o respons�vel por estilizar t�tulos.
		Em suma, ser� utilizada nas janelas, mas poder�
		n�o se limitar a elas.
	
	Par�metros:
		String titulo:
			T�tulo que desejamos na janela.
			
		char caractere_de_apresentacao:	
			Caractere expoente que far� a separa��o.
			
		int PADDING:
			Espa�o vazio que ser� colocado de ambos lados.
			
	Retorno:
		T�tulo estilizado da forma:
		===========
		   titulo
		===========
	*/
	
	// Definindo vari�veis �teis.
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
	
	// Devemos ser capazes de colocar o t�tulo no centro
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
	Descri��o:
		Fun��o respons�vel por alterar as cores do prompt.
		Colocando 0, vamos ao padr�o.
		Colocando -1, nenhuma altera��o ser� feita.
	Par�metros:
		int estilo:
			[1, 7]
		int texto:
			[30, 37]
		int fundo:
			[40, 47]
	Retorno:
		Aplica��o da cor.
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

void limpa_tela(){
	/*
	Descri��o:
		Fun��o respons�vel por limpar a tela pulando linhas
		e posicionar o cursor no canto certo.
	
	Par�metros:
		Nenhum.
		
	Retorno:
		Tela de Console em condi��es.
	*/
	
	printf("\033[2J\033[H");
}


















