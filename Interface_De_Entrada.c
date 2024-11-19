#include "Interface.h"

int* menu_de_entradas(){
	/*
	Descri��o:
		Fun��o respons�vel por exibir as possibilidades
		de entrada do usu�rio.
	
	Par�metros:
		Nenhum.
		
	Retorno:
		Disposi��o das possibilidades do usu�rio para entrar.
	*/
	
	printf("\n");
	printf("0 - Voltar Para Menu Principal\n");
	printf("1 - Frase\n");
	printf("2 - Arquivo .txt\n");
	printf("\nEscolha sua op��o: ");
	
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


String* obtendo_entrada(
	int tipo_de_entrada
){
	/*
	Descri��o:
		Fun��o respons�vel por obter a entrada correta do usu�rio.
	
	Par�metros:
		int tipo_de_entrada:
			1 -> frase
			2 -> texto
	
	Retorno:
		Ponteiro para senten�a dada pelo usu�rio.
	*/
	
	// Como n�o temos no��o do tamanho
	String *entrada = (String*)calloc(1, sizeof(String));
	
	char *frase_entrada = (char*)calloc(1, sizeof(char));
	char *caract_temp = (char*)calloc(1, sizeof(char));
	
	if (tipo_de_entrada == 1){
		
		int *indice = (int*) calloc(1, sizeof(char));
		
		while (1){
			
			*caract_temp = getchar();
			
			if(
				*caract_temp == '\n'
			){
				break;
			}
			
			frase_entrada[*indice] = *caract_temp;
			(*indice)++;
			
			frase_entrada = (char*)realloc(frase_entrada, ((*indice) + 1) * sizeof(char));			
		}
		
		frase_entrada[*indice] = '\0';
		
		(*entrada).array = frase_entrada;
		(*entrada).len = *indice;
		
		free(indice);
		
	}
	else{
		
	}

	free(caract_temp);
	return entrada;
}


int janela_de_entrada(
	int* opcao_cripto_ou_decripto
){
	/*
	Descri��o:
		Fun��o respons�vel por gerenciar a janela 
		de entrada do usu�rio.	
		
	Par�metros:
		Nenhum.
	
	Retorno:
		Nenhum.
	*/

	String *TITULO_DA_JANELA_DE_ENTRADA = construir_string_dinamica(
		"ENTRADA DO USU�RIO"
	);
	
	while(1){
		cabecalho(
			*TITULO_DA_JANELA_DE_ENTRADA,
			'+',
			10
		);
		
		int *opcao_desejada = menu_de_entradas();
		
		switch (*opcao_desejada){
			
			case 0:
				free(opcao_desejada);
				free(TITULO_DA_JANELA_DE_ENTRADA);
				limpa_tela();
				return 0;
			
			case 1:
			case 2:{
				String *string_de_entrada = obtendo_entrada(*opcao_desejada);

				printf("\nVejo como entrada: %s", (*string_de_entrada).array);
				printf("\nLen: %d\n", (*string_de_entrada).len);
				
				free((*string_de_entrada).array);
				free(string_de_entrada);
				break;
			}

			case -1:
			default:
				printf("Op��o Inv�lida!\n\n");
				break;
		}
		
		free(opcao_desejada);
	}
	
	free(TITULO_DA_JANELA_DE_ENTRADA);
}







