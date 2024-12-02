#include "Met_Grades.h"




// Fun��es de Cripto

String* colocando_entrada_na_grade(
	int *GRADE_EMBARALHADORA,
	String *entrada_usuario,
	char *ELEMENTO_DO_VAZIO
);


int verificando_se_estamos_em_posicao_de(
	int *index_de_indicadores,
	int *indicadores,
	int *index_da_frase_final
);

String* criando_string_criptografada(
	String *entrada_embaralhada_pela_grade,
	int *indicadores,
	char *ELEMENTO_DO_VAZIO
);


// Fun��o Principal
String* gradiando(
	int cripto_decripto,
	String* entrada,
	int *indicadores_de_processo
){
	/*
	Descri��o:
		Fun��o respons�vel por aplicar o m�todo de transposi��o
		das grades.
	
	Par�metros:
		Autoexplicativos.
	
	Retorno:
		String cripto ou decriptografada.
	*/
	
	// ENTRADA TESTE -> INFATQPCPENCERRADO
	
	// Fazendo dessa forma 'linear' poupamos muito mais.
	int GRADE[30] = {
		1, 0, 1, 1, 1, 0, 1, 1, 1, 1,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 1, 1, 0, 1, 0
	};
	char *ELEMENTO_DO_VAZIO = (char*)calloc(1, sizeof(char));
	*ELEMENTO_DO_VAZIO = '+';
	
	String *string_grade = colocando_entrada_na_grade(
		GRADE,
		entrada,
		ELEMENTO_DO_VAZIO
	);  // Vamos limpar esse ponteiro na fun��o seguinte.
	
	String *resultado = criando_string_criptografada(
		string_grade,  // Vamos limpar isso nessa fun��o.
		indicadores_de_processo,
		ELEMENTO_DO_VAZIO
	);
	
	return resultado;
}

/////////////////////// Implementa��o das Fun��es de Cripto ///////////////////////////////

String* colocando_entrada_na_grade(
	int *GRADE_EMBARALHADORA,
	String *entrada_usuario,
	char *ELEMENTO_DO_VAZIO
){
	/*
	Descri��o:
		Fun��o respons�vel por inserir a string dada pelo usu�rio
		dentro da grade embaralhadora.
	
	Par�metros:
		Autoexplicativos.
	
	Retorno:
		Nova String Bialocada.
	*/
	
	char *frase_embaralhada_pela_grade = (char*) calloc(1, sizeof(char));
	int *index_para_grade_embaralhadora = (int*) calloc(1, sizeof(char));
	
	// ENTRADA TESTE -> INFATQPCPENCERRADO
	// SA�DA TESTE -> I+NFA+TQPC+P+E+N+C+ER+R+ADO
	
	int *index_para_entrada = (int*) calloc(1, sizeof(int));
	while(
		// Vamos percorrer a string de entrada at� seu final.
		*index_para_entrada != (*entrada_usuario).len
	){
		
		if(
			GRADE_EMBARALHADORA[
				/*
				Garantimos que os valores poss�veis a serem acessados
				est�o os �ndices: 0, 1, ..., 29.
				*/
				*index_para_grade_embaralhadora % 30  // � este valor pela quantidade limite de valores embaralhadores.
			]
		){
			/*
			Caso seja aceito, devemos colocar um caractere da entrada
			frase embaralhada.
			*/
			
			frase_embaralhada_pela_grade[
			
				*index_para_grade_embaralhadora
				
			] = (*entrada_usuario).array[
			
				*index_para_entrada
				
			];
			
			(*index_para_entrada)++;	
		}else{
			/*
			Caso negado, devemos preencher com o vazio.
			*/
			
			frase_embaralhada_pela_grade[
			
				*index_para_grade_embaralhadora
				
			] = *ELEMENTO_DO_VAZIO;
		}
		
		// Como colocamos algo dentro da frase embaralhada
		(*index_para_grade_embaralhadora)++;
		
		// Alocamos mais
		frase_embaralhada_pela_grade = (char*) realloc(
			frase_embaralhada_pela_grade,
			(*index_para_grade_embaralhadora + 1) * sizeof(char)
		);
	}
	free(index_para_entrada);
	
	
	// Terminador Nulo
	frase_embaralhada_pela_grade[
			
		*index_para_grade_embaralhadora
		
	] = '\0';
	
	String *string_embaralhada_pela_grade = (String*) calloc(1, sizeof(String));
	(*string_embaralhada_pela_grade).array = frase_embaralhada_pela_grade;
	(*string_embaralhada_pela_grade).len = *index_para_grade_embaralhadora;
	
	// printf("\nVejo embaralhado: %s\n", frase_embaralhada_pela_grade);
		
	free(index_para_grade_embaralhadora);
	return string_embaralhada_pela_grade;
}


int verificando_se_estamos_em_posicao_de(
	int *index_de_indicadores,
	int *indicadores,
	int *index_da_frase_final
){
	/*
	Descri��o:
		Fun��o respons�vel por verificar se a posi��o de
		um indicador foi atingida.
	
	Par�metros:
		int *index_de_indicadores:
			Ponteiro para fazermos as devidas verifica��es aqui,
			sem a necessidade de ficar chamando dentro do loop.
			Temos a garantia que na entrada sempre valer� 0.
	
	Retorno:
		0 - se n�o estivermos em um local apropriado.
		A - Caract indicador correspondente.
	*/
	
	while(
		*index_de_indicadores <= 3
	){
		if(
			*index_da_frase_final == (
				indicadores[
					// Posi��o no Grupo G.
					*index_de_indicadores + 1
				] + (
					// H� G - 1 grupos completos anteriormente.
					indicadores[
						*index_de_indicadores + 2
					] - 1
				) * 5 - 1
			)
		){
			// Estamos em posi��o de indicador.
			return indicadores[*index_de_indicadores];
		}
		
		*index_de_indicadores = *index_de_indicadores + 3;
	}
	
	return 0;  // N�o estamos em posi��o de indicadores.
}


String* criando_string_criptografada(
	String *entrada_embaralhada_pela_grade,
	int *indicadores,
	char *ELEMENTO_DO_VAZIO
){
	/*
	Descri��o:
		Fun��o respons�vel por, a partir da string
		embaralhada pela grade, gerar a string resultado.
		
		A qual � obtida a partir da leitura da string em-
		baralhadora por meio de suas colunas.
	
	Par�metros:
		Autoexplicativos.
	
	Retorno:
		String Bialocada representante do final da criptografia.
	*/
	
	char *frase_final_cripto = (char*) calloc(1, sizeof(char));
	int *index_para_frase_final = (int*) calloc(1, sizeof(int));
	
	int *index_para_string_embaralhada = (int*) calloc(1, sizeof(int));
	int *index_de_indicadores = (int*) calloc(1, sizeof(int));  // Apenas para fun��o de verifica��o
	printf("\nIniciando loop de preenchimento.\n");
	while(
		/*
		Ler todos os caracteres que est�o embaralhados.
		*/
		*index_para_string_embaralhada < (*entrada_embaralhada_pela_grade).len
	){
		if(
			/*
			Caso seja o local, retornar� o caractere indicador correspondente.
			O qual nunca � zero.
			*/
			*index_de_indicadores = verificando_se_estamos_em_posicao_de(
				index_de_indicadores,
				indicadores,
				index_para_frase_final
			) 
		){
			// Vamos colocar os indicadores no local.
			frase_final_cripto[
			
				*index_para_frase_final
				
			] = *index_de_indicadores;
			
			*index_de_indicadores = 0;  // Setamos de volta para zero.
			(*index_para_frase_final)++;
			
			printf("\nColoquei indicador no indice %d.", *index_para_frase_final);
			
			// Alocamos mais
			frase_final_cripto = (char*) realloc(
				frase_final_cripto,
				(*index_para_frase_final + 1) * sizeof(char)
			);
		}
		else{
			
			if(
				(*entrada_embaralhada_pela_grade).array[
					*index_para_string_embaralhada
				] != *ELEMENTO_DO_VAZIO
			){
				frase_final_cripto[
					*index_para_frase_final
				] = (*entrada_embaralhada_pela_grade).array[
					*index_para_string_embaralhada
				];
				
				(*index_para_frase_final)++;
				
				printf("\nColocando Caract: %c.", (*entrada_embaralhada_pela_grade).array[
					*index_para_string_embaralhada
				]);
				
				// Alocamos mais
				frase_final_cripto = (char*) realloc(
					frase_final_cripto,
					(*index_para_frase_final + 1) * sizeof(char)
				);
			}
			
			// Para mantermos a coluna, avan�amos 10 �ndices.
			*index_para_string_embaralhada = *index_para_string_embaralhada + 10; 
			if(
				*index_para_string_embaralhada >= (*entrada_embaralhada_pela_grade).len
			){
				*index_para_string_embaralhada = (
					*index_para_string_embaralhada % (
						(
							// Quantidade de Linhas da Entrada Embaralhada.
							(*entrada_embaralhada_pela_grade).len / 10 + 1
							
						) * 10
					)
				) + 1;
			}
		}
	}
	
	// Terminador Nulo
	frase_final_cripto[
		*index_para_frase_final
	] = '\0';
	
	String *resultado = (String*) calloc(1, sizeof(String));
	(*resultado).array = frase_final_cripto;
	(*resultado).len = *index_para_frase_final;
	
	
	// Como n�o precisamos mais da embaralhada
	free((*entrada_embaralhada_pela_grade).array);
	free(entrada_embaralhada_pela_grade);
	
	free(index_para_string_embaralhada);
	free(index_de_indicadores);
	free(index_para_frase_final);
	
	return resultado;
}



