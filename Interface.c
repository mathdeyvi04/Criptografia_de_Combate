#include "Interface.h"

int* menu_principal(){
	/*
	Descri��o:
		Fun��o respons�vel por obter a decis�o do
		usu�rio quanto � cripto ou decripto.
	
	Par�metros:
		Nenhum.
		
	Retorno:
		Decis�o do usu�rio limpa e seca.
	*/
	
	printf("\n");
	printf("0 - Sair\n");
	printf("1 - Cripto...\n");
	printf("2 - Decripto...\n");
	printf("\nEscolha sua op��o: ");
	
	return verificador_primario(0);
}

int janela_principal(){
	/*
	Descri��o:
		Fun��o respons�vel por gerenciar a janela principal.
		Sendo capaz de chamar as demais janelas.
		
	Par�metros:
		Nenhum.
		
	Retorno:
		Janela Principal em condi��es de ser usada.
	*/
	
	String *TITULO_DA_JANELA_PRINCIPAL = construir_string_dinamica(
		"IE COM ELT"
	);

	cor(
		1,
		32,
		-1
	);
	while (1){
		
		
		cabecalho(
			*TITULO_DA_JANELA_PRINCIPAL,
			'=',
			10
		);
		
		int *opcao_desejada = menu_principal();
		
		switch (*opcao_desejada){
			case 0:
				free(opcao_desejada);
				free(TITULO_DA_JANELA_PRINCIPAL);
				return 0;
				
			case 1: 
			case 2:
				// Vamos para a pr�xima janela
				limpa_tela();
				janela_de_entrada(
					opcao_desejada
				);
				break;
			
			default:
				printf("Op��o inv�lida\n\n");
				break;
		}
		
		free(opcao_desejada);
	}
	
	free(TITULO_DA_JANELA_PRINCIPAL);
}


