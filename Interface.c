#include "Interface.h"

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
	
	cor(-1, 30, 42);
	while (1){
		
		cabecalho(
			TITULO_DA_JANELA_PRINCIPAL,
			'=',
			8
		);
		
		int res = 0;
		printf("Digite 0 para fechar: ");
		scanf("%d", &res);
		
		if (res == 0){
			break;
		}
	}
	
}


