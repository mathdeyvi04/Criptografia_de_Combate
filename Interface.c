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
	printf("1 - Cripto...\n");
	printf("2 - Decripto...\n");
	
	int *opcao_desejada = (int*)calloc(1, sizeof(int));
	int *se_deu_certo = (int*)calloc(1, sizeof(int));
	
	*se_deu_certo = scanf("%d", opcao_desejada);
	getchar();
	
	if (
		!(*se_deu_certo)
	){
		*opcao_desejada = -1;
	}
	
	free(se_deu_certo);
	return opcao_desejada;
}

void janela_principal(){
	/*
	Descrição:
		Função responsável por gerenciar a janela principal.
		Sendo capaz de chamar as demais janelas.
		
	Parâmetros:
		Nenhum.
		
	Retorno:
		Janela Principal em condições de ser usada.
	*/
	
	String TITULO_DA_JANELA_PRINCIPAL = construir_string_estatica(
		"IE COM ELT"
	);

	cor(
		1,
		32,
		-1
	);
	while (1){ 
		
		cabecalho(
			TITULO_DA_JANELA_PRINCIPAL,
			'=',
			10
		);
		
		int *opcao_desejada = menu_principal();
		
		switch (*opcao_desejada){
			case 1: 
				// Cripto
				break;
			case 2:
				// Decripto
				break;
				
			default:
				printf("Opção inválida");
				break;
		}
		
		free(opcao_desejada);
	}
}






