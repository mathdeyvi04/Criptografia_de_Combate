#include "Interface.h"

int* menu_principal(){
	/*
	Descrição:
		Função responsável por obter a decisão do
		usuário quanto à cripto ou decripto.
	
	Parâmetros:
		Nenhum.
		
	Retorno:
		Decisão do usuário limpa e seca.
	*/
	
	printf("\n");
	printf("0 - Sair\n");
	printf("1 - Cripto...\n");
	printf("2 - Decripto...\n");
	printf("\nEscolha sua opção: ");
	
	return verificador_primario(0);
}

int janela_principal(){
	/*
	Descrição:
		Função responsável por gerenciar a janela principal.
		Sendo capaz de chamar as demais janelas.
		
	Parâmetros:
		Nenhum.
		
	Retorno:
		Janela Principal em condições de ser usada.
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
				// Vamos para a próxima janela
				limpa_tela();
				janela_de_entrada(
					opcao_desejada
				);
				break;
			
			default:
				printf("Opção inválida\n\n");
				break;
		}
		
		free(opcao_desejada);
	}
	
	free(TITULO_DA_JANELA_PRINCIPAL);
}


