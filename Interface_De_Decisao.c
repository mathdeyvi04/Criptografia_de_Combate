#include "Interface_De_Decisao.h"


int* menu_de_decisao(){
	/*
	Descri��o:	
		Fun��o respons�vel por prover os m�todos poss�veis 
		de cripto ou decripto para o usu�rio.
		
	Par�metros:
		Nenhum.
	
	Retorno:
		Decis�o do usu�rio.
	*/
	
	printf("\n");
	printf("0 - Voltar para Menu de Entrada\n");
	printf("1 - Invers�o\n");
	printf("2 - Grades\n");
	printf("3 - Quadros");
	
	printf("\nEscolha o m�todo desejado: ");
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


int janela_de_decisao(
	int *cripto_ou_decripto,
	String *string_de_entrada
){
	/*
	Descri��o:
		Fun��o respons�vel por gerenciar a decis�o do m�todo 
		escolhido pelo usu�rio.
	
	Par�metros:
		Autoexplicativos.
		
	Retorno:
		Se eu te contar...
	*/
	
	String *TITULO_DA_JANELA_DE_DECISAO = construir_string_dinamica(
		"Escolha do M�todo"	
	);
	
	int *TOTAL_DE_METODOS_ATE_AGORA = (int*)calloc(1, sizeof(int));
	*TOTAL_DE_METODOS_ATE_AGORA = 3;
	
	while(1){
		cabecalho(
			*TITULO_DA_JANELA_DE_DECISAO,
			'-',
			10
		);
		
		int *opcao_desejada = menu_de_decisao();
		
		if(
			*opcao_desejada == 0
		){
			free(TITULO_DA_JANELA_DE_DECISAO);
			free(opcao_desejada);
			limpa_tela();
			return 0;
		}else{
			
			if (
				(*opcao_desejada >= 1) && (*opcao_desejada <= *TOTAL_DE_METODOS_ATE_AGORA)
			){
				
				// Devemos chamar uma nova interface de apresenta��o!
				janela_de_apresentacao(
					cripto_ou_decripto,
					string_de_entrada,
					opcao_desejada
				);
				
			}else{
				
				printf("\nOp��o Inv�lida!");
			}
		}

		free(opcao_desejada);
	}
}


