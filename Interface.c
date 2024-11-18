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
	
	while (1){
		String arroz = {"MATH", 12};
		cabecalho(arroz, '=');
		
		int res = 0;
		printf("Digite 0 para fechar: ");
		scanf("%d", &res);
		
		if (res == 0){
			break;
		}
	}
}


