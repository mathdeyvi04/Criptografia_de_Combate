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
	
	int *TAMANHO_DA_STRING = (int*)calloc(1, sizeof(int));  // 33 
	
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
	
	free(TAMANHO_DA_STRING);  // 19
	
	return resultado;
}

String* construir_string_dinamica(
	char* frase
){
	/*
	Descrição:
		Função responsável por criar string alocada.
		Não possuindo, necessariamente a frase alocada.
		
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


int verificando_presenca(
	int *lista_de_numeros,
	int *temp_para_varrer,
	int quant_total,
	int valor_a_ser_verificado
){
	/*
	Descrição:
		Função responsável por verificar se um número
		está presente em uma lista de números.
	
	Parâmetros:
		Autoexplicativos.
	
	Retorno:
		1 - Se estiver presente
		0 - Se não.
	*/
	
	*temp_para_varrer = 0;
	
	while(
		*temp_para_varrer != quant_total
	){
		if(
			lista_de_numeros[
				*temp_para_varrer
			] == valor_a_ser_verificado
		){
			return 1;
		}
		
		(*temp_para_varrer)++;
	}
	
	return 0;
	
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

int* obtendo_indicadores(
	int quantidade_de_grupos
){
	/*
	Descrição:
		Função responsável por obter os indicadores de processo
		desejados pelo usuário e sua respectiva localização.
		
	Parâmetros:
		Nenhum.
		
	Retorno:
		Array = [i_1, c_1, g_1, ...]
		
		Constituindo triplas, as quais representam:
		i_1: 
			caractere indicador.
			
		c_1: 
			coluna do indicador.
			
		g_1:
			grupo do indicador.
	*/
	
	// Como são sempre dois
	int *indicadores = (int*)calloc(6, sizeof(int));
	
	printf("\nIndicadores de Processo!");
	
	int *numero = (int*)calloc(1, sizeof(int));
	*numero = 1;
	for(
		int i = 0;
		i <= 3;
		i = i + 3
	){
		// Pegando Indicador
		{
			while(1){
				printf("\nInforme o %d° indicador: ", *numero);
				int *temp = verificador_primario(1);
				
				if (
					(
						(*temp >= 65) && (*temp <= 90)
					) || (
						(*temp >= 97) && (*temp <= 122)
					)
				){
					indicadores[i] = *temp;
					free(temp);
					break;
				}
				
				printf("\nOpção Inválida.");
				free(temp);				
			}
		}
		
		// Pegando Coluna do Indicador
		{
			while(1){
				printf("\nInforme a posição do indicador no grupo: ");
				int *temp = verificador_primario(0);
				
				if (
					(*temp >= 1) && (*temp <= 5) 
				){
					indicadores[i + 1] = *temp;
					free(temp);
					break;
				}
				
				printf("\n Inválido, deve estar entre 1° e 5°.");
				free(temp);				
			}
		}
		
		// Pegando o Grupo do Indicador
		{
			while(1){
				printf("\nInforme o grupo do indicador(Total = %d): ", quantidade_de_grupos);
				int *temp = verificador_primario(0);
				
				if (
					(*temp >= 1) && (*temp <= quantidade_de_grupos) 
				){
					indicadores[i + 2] = *temp;
					free(temp);
					break;
				}
				
				printf("\nInválido, não há essa quantidade de grupos.");
				free(temp);				
			}
		}
		(*numero)++;
	}
	
	free(numero);
	
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
		Número de entrada do usuário, como ponteiro alocado.
	*/
	
	int *opcao_desejada = (int*)calloc(1, sizeof(int));
	int *se_deu_certo = (int*)calloc(1, sizeof(int));  // 284
	
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
			free(se_deu_certo);  // 265
			return opcao_desejada;
		}
	}
}


int verificando_letras_mortas(
	String *entrada
){
	/*
	Descrição:
		Função responsável por verificar quantidade
		de caracteres e tomar as providencias necessárias
		para a quantidade de grupos.
	
	Parâmetros:
		Entrada a ser verificada.
		
	Retorno:
		Quantidade de Grupos Final.
	*/
	
	
	while (
		(*entrada).len % 5 != 3
	){
		// Vamos preencher com letras mortas
		
		(*entrada).array = (char*)realloc(
			(*entrada).array,
			((*entrada).len + 1) * sizeof(char)	
		);
		
		(*entrada).array[(*entrada).len] = 'X';
		
		(*entrada).len = (*entrada).len + 1;
		
	}
	(*entrada).array = (char*)realloc(
		(*entrada).array,
		((*entrada).len + 1) * sizeof(char)	
	);
	
	(*entrada).array[(*entrada).len] = '\0';
	
	
	return ((*entrada).len + 2) / 5;
}


String* criar_nulo(){
	/*
	Descrição:
		Função responsável por facilitar o processo de criação
		de strings descartáveis.
	
	Parâmetros:
		Nenhum.
	
	Retorno:
		Ponteiro para string bialocada.
	*/
	
	String *nulo = (String*) calloc(1, sizeof(String));
	(*nulo).array = NULL;
	
	return nulo;
}

















