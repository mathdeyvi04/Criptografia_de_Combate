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
	printf("Não entre com acentuações ou caracteres especiais.\n");
	printf("0 - Voltar Para Menu Principal\n");
	printf("1 - Frase\n");
	printf("2 - Arquivo .txt\n");
	printf("\nEscolha sua opção: ");
	
	return verificador_primario(0);
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
	
	String *entrada = (String*)calloc(1, sizeof(String));
	
	if (tipo_de_entrada == 1){
		printf("\nEntre com a frase: ");
	}else{
		printf("\nEntre com o caminho do arquivo.txt: ");
	}
	
	char *frase_entrada = (char*)calloc(1, sizeof(char));
	char *caract_temp = (char*)calloc(1, sizeof(char));
	int *indice = (int*) calloc(1, sizeof(char));
		
	while (1){
		
		*caract_temp = getchar();
		
		if(
			tipo_de_entrada == 1
		){
			// Sabemos que será uma frase, então devemos alterar
			// para maiusculo aqui.
			
			*caract_temp = maiusculando(*caract_temp);
			
		}
		
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
	
	if (tipo_de_entrada == 1){
		(*entrada).array = frase_entrada;
		(*entrada).len = *indice;
	}else{
		// Devemos procurar o arquivo.
		FILE *arquivo = fopen(
			frase_entrada,
			"r"
		);
		
		if (arquivo == NULL){
			printf("\nNão existe nada no caminho: %s", frase_entrada);
			
			free(frase_entrada);		
		}else{
			// De posse do arquivo, devemos alterar a frase_de_entrada.
			// Para não termos vazamento de memória.
			free(frase_entrada);
			frase_entrada = (char*)calloc(1, sizeof(char));
			*indice = 0;
			
			// Vamos absorver os caracteres do arquivo e fazer uma string grande.
			while(1){
				*caract_temp = fgetc(arquivo);
				
				if (
					*caract_temp == EOF
				){
					break;
				}
				
				frase_entrada[*indice] = maiusculando(mudar_para_ascii(*caract_temp));
				(*indice)++;
				
				frase_entrada = (char*)realloc(frase_entrada, ((*indice) + 1) * sizeof(char));			
			}
			
			frase_entrada[*indice] = '\0';
			
			(*entrada).array = frase_entrada;
			(*entrada).len = *indice;
			
			fclose(arquivo);
		}

	}
	
	free(indice);
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
		Autoexplicativo.
	
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
				
				if (
					string_de_entrada == NULL
				){
					printf("\nErro na Entrada!");
					free(string_de_entrada);
				}else{
					janela_de_decisao(
						opcao_cripto_ou_decripto,
						string_de_entrada
					);
					
					free((*string_de_entrada).array);
					free(string_de_entrada);
				}
				
				break;
			}

			case -1:
			default:
				printf("Opção Inválida!\n\n");
				break;
		}
		
		free(opcao_desejada);
	}
}







