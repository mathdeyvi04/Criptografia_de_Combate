#include "Struct_String_Formatada.h"

String construir_string_estatica(
	char* frase
){
	/*
	Descrição:
		Função responsável por construir uma string formatada
		a partir de um array de caracteres.
		Usando memória estática.
		
	Parâmetros:
		Autoexplicativos.
		
	Retorno:
		Objeto String de tamanho definido.
	*/
	
	int *TAMANHO_DA_STRING = (int*)calloc(1, sizeof(int));
	
	while(
		frase[*TAMANHO_DA_STRING] != '\0'
	){
		// printf("Vejo o elemento: %c\n", frase[*TAMANHO_DA_STRING]);
		(*TAMANHO_DA_STRING)++;
	}
	
	String resultado = {
		frase,
		*TAMANHO_DA_STRING
	};
	
	free(TAMANHO_DA_STRING);
	
	return resultado;
}

String* construir_string_dinamica(
	char* frase
){
	/*
	Descrição:
		Função responsável por criar string alocada dinamicamente.
		
	Parâmetros:
		Autoexplicativo.
		
	Retorno:
		Ponteiro para string formatada.
	*/
	
	int *TAMANHO_DA_STRING = (int*)calloc(1, sizeof(int));
	
	while(
		frase[*TAMANHO_DA_STRING] != '\0'
	){
		// printf("Vejo o elemento: %c\n", frase[*TAMANHO_DA_STRING]);
		(*TAMANHO_DA_STRING)++;
	}
	
	String *resultado = (String*) calloc(1, sizeof(String));
	
	(*resultado).array = frase;
	(*resultado).len = *TAMANHO_DA_STRING;
	
	free(TAMANHO_DA_STRING);
	
	return resultado;
	
}

char mudar_para_ascii(
	char char_entrada
){	
	/*
	Descrição:
		Função responsável por receber caracteres que
		possivelmente não são ascii e transformá-los para
		ascii.
		
		Esta função não seria necessária para o caso de garantirmos
		que não há caracteres especiais.
	
	Parâmetros:
		char char_entrada:
			Possível caractere não ascii.
			
	Retorno:
		Caractere ascii.
	*/
	
	switch (
		char_entrada
	){
		case 'ç': return 'c';
		
		case 'á': return 'a';
		
		case 'é': case 'ê': return 'e';
		
		case 'í': return 'i';
		
		case 'ó': return 'o';
		
		case 'ú': return 'u';
		
		default:
			return char_entrada;
	}
}


char maiusculando(
	char caract_possivelmente_minusculo
){
	/*
	Descrição:
		Função responsável por transformar as letras
		para maiusculo.
		
		Isso é necessário devido aos métodos de substituição, 
		os quais utilizam fortemente meios de comparação.
		
	Parâmetros:
		Autoexplicativos.
		
	Retorno:
		Mesmo caractere ou ele maiusculo.
	*/
	
	if (
		(caract_possivelmente_minusculo >= 97) && (caract_possivelmente_minusculo <= 122)
	){
		return caract_possivelmente_minusculo - 32;
	}
	
}


int* obtendo_indicadores(){
	/*
	Descrição:
		Função responsável por obter os indicadores de processo
		desejados pelo usuário e sua respectiva localização.
		
	Parâmetros:
		Nenhum.
		
	Retorno:
		Array = [i_1, c_1, l_1, ...]
		
		Constituindo triplas, as quais representam:
		i_1: 
			caractere indicador.
			
		c_1: 
			coluna do indicador.
			
		l_1:
			linha do indicador.
	*/
	
	// Como são sempre dois
	int *indicadores = (int*)calloc(6, sizeof(int));
	
	printf("\nIndicadores de Processo!");
	printf("\nInfo:");
	printf("\n1 -> 1° Grupo");
	printf("\n2 -> 2° Grupo");
	printf("\n...");
	printf("\n-2 -> Penúltimo Grupo");
	printf("\n-1 -> Último Grupo\n");
	
	for(
		int i = 1;
		i != 3;
		i++
	){
		// Pegando Indicador
		{
			while(1){
				printf("\nInforme o %d° indicador: ", i);
				int *temp = verificador_primario(1);
				
				if (
					(
						(*temp >= 65) && (*temp <= 90)
					) || (
						(*temp >= 97) && (*temp <= 122)
					)
				){
					indicadores[i - 1] = *temp;
					free(temp);
					break;
				}
				
				printf("\nOpção Inválida.");
				free(temp);				
			}
			
		}
		
		break;
	}
	
	
	return indicadores;
}


int* verificador_primario(
	int tipo_esperado
){
	/*
	Descrição:
		Função responsável por receber entrada numérica do 
		usuário. Verificando se ela foi realizada da forma
		correta.
	
	Parâmetros:
		int tipo_esperado:
			0 -> int
			1 -> char
	
	Retorno:
		Número de entrada do usuário.
	*/
	
	int *opcao_desejada = (int*)calloc(1, sizeof(int));
	int *se_deu_certo = (int*)calloc(1, sizeof(int));
	
	while(1){
		
		if (
			tipo_esperado
		){
			*se_deu_certo = scanf("%c", opcao_desejada);
		}else{
			*se_deu_certo = scanf("%d", opcao_desejada);
		}
		getchar();
		
		if (
			!(*se_deu_certo)
		){
			printf("\nOpção Inválida.");
			printf("\nDigite novamente: ");
		}else{
			free(se_deu_certo);
			return opcao_desejada;
		}
	}
}










