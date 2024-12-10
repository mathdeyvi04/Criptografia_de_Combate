#include "Struct_String_Formatada.h"

String construir_string_estatica(
	char* frase
){
	/*
	Descri��o:
		Fun��o respons�vel por construir uma string formatada
		a partir de um array de caracteres.
		Usando mem�ria est�tica.
		
	Par�metros:
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
	Descri��o:
		Fun��o respons�vel por criar string alocada.
		N�o possuindo, necessariamente a frase alocada.
		
	Par�metros:
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
	Descri��o:
		Fun��o respons�vel por verificar se um n�mero
		est� presente em uma lista de n�meros.
	
	Par�metros:
		Autoexplicativos.
	
	Retorno:
		1 - Se estiver presente
		0 - Se n�o.
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
	Descri��o:
		Fun��o respons�vel por receber caracteres que
		possivelmente n�o s�o ascii e transform�-los para
		ascii.
		
		Esta fun��o n�o seria necess�ria para o caso de garantirmos
		que n�o h� caracteres especiais.
	
	Par�metros:
		char char_entrada:
			Poss�vel caractere n�o ascii.
			
	Retorno:
		Caractere ascii.
	*/
	
	switch (
		char_entrada
	){
		case '�': return 'c';
		
		case '�': return 'a';
		
		case '�': case '�': return 'e';
		
		case '�': return 'i';
		
		case '�': return 'o';
		
		case '�': return 'u';
		
		default:
			return char_entrada;
	}
}

char maiusculando(
	char caract_possivelmente_minusculo
){
	/*
	Descri��o:
		Fun��o respons�vel por transformar as letras
		para maiusculo.
		
		Isso � necess�rio devido aos m�todos de substitui��o, 
		os quais utilizam fortemente meios de compara��o.
		
	Par�metros:
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
	Descri��o:
		Fun��o respons�vel por obter os indicadores de processo
		desejados pelo usu�rio e sua respectiva localiza��o.
		
	Par�metros:
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
	
	// Como s�o sempre dois
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
				printf("\nInforme o %d� indicador: ", *numero);
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
				
				printf("\nOp��o Inv�lida.");
				free(temp);				
			}
		}
		
		// Pegando Coluna do Indicador
		{
			while(1){
				printf("\nInforme a posi��o do indicador no grupo: ");
				int *temp = verificador_primario(0);
				
				if (
					(*temp >= 1) && (*temp <= 5) 
				){
					indicadores[i + 1] = *temp;
					free(temp);
					break;
				}
				
				printf("\n Inv�lido, deve estar entre 1� e 5�.");
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
				
				printf("\nInv�lido, n�o h� essa quantidade de grupos.");
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
	Descri��o:
		Fun��o respons�vel por receber entrada num�rica do 
		usu�rio. Verificando se ela foi realizada da forma
		correta.
	
	Par�metros:
		int tipo_esperado:
			0 -> int
			1 -> char
	
	Retorno:
		N�mero de entrada do usu�rio, como ponteiro alocado.
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
			printf("\nOp��o Inv�lida.");
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
	Descri��o:
		Fun��o respons�vel por verificar quantidade
		de caracteres e tomar as providencias necess�rias
		para a quantidade de grupos.
	
	Par�metros:
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
	Descri��o:
		Fun��o respons�vel por facilitar o processo de cria��o
		de strings descart�veis.
	
	Par�metros:
		Nenhum.
	
	Retorno:
		Ponteiro para string bialocada.
	*/
	
	String *nulo = (String*) calloc(1, sizeof(String));
	(*nulo).array = NULL;
	
	return nulo;
}

















