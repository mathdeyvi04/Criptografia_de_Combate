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
	Descri��o:
		Fun��o respons�vel por criar string alocada dinamicamente.
		
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


int* obtendo_indicadores(){
	/*
	Descri��o:
		Fun��o respons�vel por obter os indicadores de processo
		desejados pelo usu�rio e sua respectiva localiza��o.
		
	Par�metros:
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
	
	// Como s�o sempre dois
	int *indicadores = (int*)calloc(6, sizeof(int));
	
	printf("\nIndicadores de Processo!");
	printf("\nInfo:");
	printf("\n1 -> 1� Grupo");
	printf("\n2 -> 2� Grupo");
	printf("\n...");
	printf("\n-2 -> Pen�ltimo Grupo");
	printf("\n-1 -> �ltimo Grupo\n");
	
	for(
		int i = 1;
		i != 3;
		i++
	){
		// Pegando Indicador
		{
			while(1){
				printf("\nInforme o %d� indicador: ", i);
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
				
				printf("\nOp��o Inv�lida.");
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
	Descri��o:
		Fun��o respons�vel por receber entrada num�rica do 
		usu�rio. Verificando se ela foi realizada da forma
		correta.
	
	Par�metros:
		int tipo_esperado:
			0 -> int
			1 -> char
	
	Retorno:
		N�mero de entrada do usu�rio.
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
			printf("\nOp��o Inv�lida.");
			printf("\nDigite novamente: ");
		}else{
			free(se_deu_certo);
			return opcao_desejada;
		}
	}
}










