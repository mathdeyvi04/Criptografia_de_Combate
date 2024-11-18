#include "Interface.h"

void janela_principal(){
	/*
	Descri��o:
		Fun��o respons�vel por gerenciar a janela principal.
		Sendo capaz de chamar as demais janelas.
		
	Par�metros:
		Nenhum.
		
	Retorno:
		Janela Principal em condi��es de ser usada.
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


