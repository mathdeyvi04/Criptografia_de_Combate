#include "Interface.h"

int* menu_de_entradas(){
	/*
	Descrição:
		Função responsável por exibir as possibilidades
		de entrada do usuário.
	
	Parâmetros:
		Nenhum.
		
	Retorno:
		Disposição das possibilidades do usuário para entrar.
	*/
	
	printf("\n");
	printf("0 - Voltar Para Menu Principal\n");
	printf("1 - Frase\n");
	printf("2 - Arquivo .txt\n");
	printf("\nEscolha sua opção: ");
	
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
	Descrição:
		Função responsável por obter a entrada correta do usuário.
	
	Parâmetros:
		int tipo_de_entrada:
			1 -> frase
			2 -> texto
	
	Retorno:
		Ponteiro para sentença dada pelo usuário.
	*/
	
	// Como não temos noção do tamanho
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
	Descrição:
		Função responsável por gerenciar a janela 
		de entrada do usuário.	
		
	Parâmetros:
		Nenhum.
	
	Retorno:
		Nenhum.
	*/

	String *TITULO_DA_JANELA_DE_ENTRADA = construir_string_dinamica(
		"ENTRADA DO USUÁRIO"
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
				printf("Opção Inválida!\n\n");
				break;
		}
		
		free(opcao_desejada);
	}
	
	free(TITULO_DA_JANELA_DE_ENTRADA);
}







