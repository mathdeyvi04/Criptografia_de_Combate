#include "Met_Chave_Simples.h"




String* chave_simplando(
	int cripto_decripto,
	String *entrada_usuario,
	int *indicadores_de_processo
){
	/*
	Função responsável por gerenciar o procedimento
	de cripto ou decripto de chave simples.
	*/
	
	String *chave_digitada = obtendo_chave_do_usuario();  // Já fazemos a limpeza completa deste posteriormente.
	int *quant_de_elementos_chave = (int*) calloc(1, sizeof(int));
	*quant_de_elementos_chave = (*chave_digitada).len;  
	
	int *ordem_dos_indexs_das_colunas_a_serem_lidas = obtendo_ordem_das_colunas(
		chave_digitada
	);
	
	String *resultado = construindo_string_cripto(
		entrada_usuario,
		ordem_dos_indexs_das_colunas_a_serem_lidas,
		quant_de_elementos_chave
	);
	
	
	
	return resultado;
}


//////////////// Funções de Entrada de Chave /////////////////////////
String*
obtendo_chave_do_usuario(){
	/*
	Descrição:
		Função responsável por obter a chave correta
		do usuário.
		
		Não deve haver limitação mínima ou máxima de caracteres de entrada.
		
	Parâmetros:
		Nenhum.
	
	Retorno:
		String da Chave digitada.
		
		Neste caso especifico, a quantidade .len representará a quantidade 
		de slots que foram alocados para tal string.
	*/
	
	printf("\nInsira a chave: ");
	
	/*
		Declarando as variáveis que serão necessárias.
	*/
	
	int *quant_total_1 = (int*) calloc(1, sizeof(int));
	char *frase_chave_digitada = (char*) calloc(1, sizeof(char));
	char *temp_para_receber_caract = (char*) calloc(1, sizeof(char));
	
	/*
		Obtendo a chave dada pelo usuário.
	*/
	while(
		1
	){
		*temp_para_receber_caract = getchar();
		
		if(
			*temp_para_receber_caract == '\n'
		){
			
			frase_chave_digitada[
				*quant_total_1
			] = '\0';
			
			//printf("Vejo como chave digitada: %s", frase_chave_digitada);
			break;
		}
		
		if(
			(
				// Algarismos
				(*temp_para_receber_caract >= 48) && (*temp_para_receber_caract <= 57)
			) || (
				// Alfabeto maiúsculo
				(*temp_para_receber_caract >= 65) && (*temp_para_receber_caract <= 90)
			) || (
				// Alfabeto minúsculo
				(*temp_para_receber_caract >= 97) && (*temp_para_receber_caract <= 122)
			)
		){
			
			frase_chave_digitada[
				*quant_total_1
			] = *temp_para_receber_caract;
			
			(*quant_total_1)++;
			
			frase_chave_digitada = (char*) realloc(
				frase_chave_digitada,
				(*quant_total_1 + 1) * sizeof(char)
			);
		}
		else{
			
			printf("\nCaractere Inválido Digitado.\nContinue: ");
		}
	}
	
	String *chave_digitada = (String*) calloc(1, sizeof(String));
	(*chave_digitada).array = frase_chave_digitada;
	(*chave_digitada).len = *quant_total_1;
	
	free(quant_total_1);
	free(temp_para_receber_caract);
	
	return chave_digitada;
}


int*
obtendo_ordem_das_colunas(
	String *chave_digitada
){
	/*
	Descrição:
		Função responsável por varrer a chave digitada,
		de forma a construir uma ordem dos index que representa
		uma ordem crescente dos valores da chave.
		
	Parâmetros:
		-> String *chave_digitada:
			Neste caso especifico, a quantidade .len representará a quantidade 
			de slots que foram alocados para tal string.
	
	Retorno:
		Ordem dos index representando a ordem crescente.
	*/
	
	// Vamos renomear ponteiros, sem alocar mais memória.
	char *menor_elemento_na_configuracao_atual = (char*) calloc(1, sizeof(char));
	int *quant_total_2 = (int*) calloc(1, sizeof(int));
	
	int *ordem_das_colunas = (int*) calloc((*chave_digitada).len, sizeof(int));
	int *temp_para_acessar_ordem = (int*) calloc(1, sizeof(int));
	int *para_verificarmos_presenca = (int*) calloc(1, sizeof(int));
	
	char *frase_chave_digitada = (*chave_digitada).array;  // Sem acréscimo de memória.
	
	/*
	Partimos para o algoritmo.
	*/
	
	while(
		/*
		Sabemos que '\0' terá a menor hierárquia, logo terá seu index, que é o último 
		da frase_chave_digitada, no último lugar da ordem das colunas.
		
		Deveremos trocar para que não guarde seu index, mas sim o terminador nulo -1.
		*/
		*quant_total_2 != (*chave_digitada).len
	){
		// Setamos.
		*menor_elemento_na_configuracao_atual = 123;
		*temp_para_acessar_ordem = 0;
		
		while(
			*temp_para_acessar_ordem != (*chave_digitada).len
		){
			if(
				frase_chave_digitada[
					*temp_para_acessar_ordem
				] <= *menor_elemento_na_configuracao_atual
			){
				if(
					!verificando_presenca(
						ordem_das_colunas,
						para_verificarmos_presenca,
						*quant_total_2,
						*temp_para_acessar_ordem
					)
				){
					// Vamos colocar o index na ordem e salvar o novo maior.
					*menor_elemento_na_configuracao_atual = frase_chave_digitada[
						*temp_para_acessar_ordem
					];
					
					/*
					printf(
						"\nO novo maior é: %c",
						*maior_elemento_na_configuracao_atual
					);
					*/
					
					ordem_das_colunas[
						*quant_total_2
					] = *temp_para_acessar_ordem;
				}
				
			}
			(*temp_para_acessar_ordem)++;
		}
		
		(*quant_total_2)++;
		/*
		printf("\nA ordem das colunas possui tamanho %d.", *quant_total_2);
		printf("\n");
		*/
	}
	
	free(para_verificarmos_presenca);
	free(frase_chave_digitada);
	free(chave_digitada);
	free(menor_elemento_na_configuracao_atual);
	free(temp_para_acessar_ordem);
	free(quant_total_2);
	
	return ordem_das_colunas;
}


String*
construindo_string_cripto(
	String *entrada_usuario,
	int *ordem_dos_indexs_das_colunas_a_serem_acessadas,
	int *quant_de_elementos_chave
){
	/*
	Descrição:
		Função responsável por produzir a string cripto
		a partir da grade.
		
	Parâmetros:
		Autoexplicativos.
	
	Retorno:
		String Cripto.
	*/
	
	
	
	
	
	
	free(ordem_dos_indexs_das_colunas_a_serem_acessadas);
	free(quant_de_elementos_chave);
	
	return criar_nulo();	
}












