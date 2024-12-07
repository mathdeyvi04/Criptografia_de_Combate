#include "Met_Grades.h"




// Funções de Cripto

String* criptando_na_grade(
	int *GRADE_EMBARALHADORA,
	String *entrada_usuario,
	char *ELEMENTO_DO_VAZIO
);


int verificando_se_estamos_em_posicao_de(
	int *index_de_indicadores,
	int *indicadores,
	int *index_da_frase_final
);


int avancando_colunas(
	int *index_frase_embaralhada
);


String* criando_string_criptografada(
	String *entrada_embaralhada_pela_grade,
	int *indicadores,
	char *ELEMENTO_DO_VAZIO
);

////////////////////////////////////////////////////////////////////////////////

// Funções de Descripto

String** descriptando_na_grade(
	int *GRADE,
	String *entrada_usuario,
	int *indicadores,
	char *ELEMENTO_DO_VAZIO
);

String *criando_strings_descriptografada(
	String** vetor_de_colunas_da_string_na_grade,
	char *ELEMENTO_DO_VAZIO
);









//////////////////////////////////////////////////////////////////////////////

// Função Principal
String* gradiando(
	int cripto_decripto,
	String* entrada,
	int *indicadores_de_processo
){
	/*
	Descrição:
		Função responsável por aplicar o método de transposição
		das grades.
	
	Parâmetros:
		Autoexplicativos.
	
	Retorno:
		String cripto ou decriptografada.
	*/
	
	// Fazendo dessa forma 'linear' poupamos muito mais.
	int GRADE[30] = {
		1, 0, 1, 1, 1, 0, 1, 1, 1, 1,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 1, 1, 0, 1, 0
	};
	char *ELEMENTO_DO_VAZIO = (char*)calloc(1, sizeof(char));
	*ELEMENTO_DO_VAZIO = '+';
	
	if(
		// Se for cripto
		// INFATQPCPENCERRADOQUATORZEZEROZEROPTXW
		cripto_decripto == 1
	){
		String *string_embaralhada_na_grade = criptando_na_grade(
			GRADE,
			entrada,
			ELEMENTO_DO_VAZIO
		);  // Vamos limpar esse ponteiro na função seguinte.
		
		String *resultado = criando_string_criptografada(
			string_embaralhada_na_grade,  // Vamos limpar isso nessa função.
			indicadores_de_processo,
			ELEMENTO_DO_VAZIO
		);
		
		return resultado;
	}
	
	// Então é descripto
	// IRPNPRFEAANDTOQCPQCEUREAOTROPOTRXZZREWZE
	// IRPNP RFEAA NDTOQ CPQCE UREAO TROPO TRXZZ REWZE
	
	String **vetor_de_colunas_da_string_na_grade = descriptando_na_grade(
		GRADE,
		entrada,
		indicadores_de_processo,
		ELEMENTO_DO_VAZIO
	);
	
	String *resultado = criando_strings_descriptografada(
		vetor_de_colunas_da_string_na_grade,
		ELEMENTO_DO_VAZIO
	);
	
	return resultado;
}


/////////////////////// Implementação das Funções de Descripto  ///////////////////////////

String** descriptando_na_grade(
	int *GRADE_EMBARALHADORA,
	String *entrada_usuario,
	int *indicadores,
	char *ELEMENTO_DO_VAZIO
){
	/*
	Descrição:
		Função responsável por colocar a string teoricamente
		criptografada na grade.	Para que seja possível a descripto.
		
		Preste bem atenção no código, pois o algoritmo é complexo.
		
	Parâmetros:
		Autoexplicativos.
	
	Retorno:
		Ponteiro para vetor que conterá as substrings que representam
		as colunas da string na grade.
		Será trialocado.
	*/
	
	/*
	Criar um array de strings que terão sempre tamanho 4.
	Sendo o último, terminador nulo, para evitar erros.
	
	Cada substring terá a responsabilidade de representar as colunas
	da string na grade.
	*/
	String **array_de_substrings = (String**) calloc(1, sizeof(String*));
	int *index_para_array_de_substrings = (int*) calloc(1, sizeof(int));
	int *index_para_substring = (int*) calloc(1, sizeof(int));
	
	// Valores para iterarmos.	
	int *index_para_frase_cripto = (int*) calloc(1, sizeof(int));
	int *index_para_grade = (int*) calloc(1, sizeof(int));
	int *index_de_indicadores = (int*) calloc(1, sizeof(int));
	
	while(
		*index_para_frase_cripto != (*entrada_usuario).len
	){
		
		// Alocamos o necessário para cada substring.
		array_de_substrings[
			*index_para_array_de_substrings
		] = (String*) calloc(1, sizeof(String));
		(
			*array_de_substrings[
				*index_para_array_de_substrings				
			]
		).array = (char*) calloc(4, sizeof(char));
		
		while(
			*index_para_substring != 3  && *index_para_frase_cripto != (*entrada_usuario).len
		){
			// Verificar se é um local válido.
			if(
				GRADE_EMBARALHADORA[
					*index_para_grade % 30
				]
			){
				
				// Verificar se é um indicador
				if(
					/*
					Em primeira mão, não precisamos dos indicadores.
					Mas precisamos saber onde eles estão para os ignorarmos.
					*/
					*index_de_indicadores = verificando_se_estamos_em_posicao_de(
						index_de_indicadores,
						indicadores,
						index_para_frase_cripto
					)
				){
					
					*index_de_indicadores = 0;
					(*index_para_frase_cripto)++;
				}
				
				(
					*array_de_substrings[
						*index_para_array_de_substrings				
					]
				).array[
					*index_para_substring
				] = (*entrada_usuario).array[
					*index_para_frase_cripto
				];
				
				(*index_para_frase_cripto)++;
			}
			else{

				(
					*array_de_substrings[
						*index_para_array_de_substrings				
					]
				).array[
					*index_para_substring
				] = *ELEMENTO_DO_VAZIO;
			}
			
			(*index_para_substring)++;
			avancando_colunas(
				index_para_grade
			);
		}
		
		(
			*array_de_substrings[
				*index_para_array_de_substrings				
			]
		).array[
			*index_para_substring
		] = '\0';
		
		(
			*array_de_substrings[
				*index_para_array_de_substrings				
			]
		).len = *index_para_substring;
		
		*index_para_substring = 0;
		
		
		printf(
			"\nVejo a substring: %s, que tem numeração %d°.",
			(
				*array_de_substrings[
					*index_para_array_de_substrings				
				]
			).array,
			*index_para_array_de_substrings
		);
		
		
		(*index_para_array_de_substrings)++;
		
		if (
			/*
			Esse if é para não alocarmos desnecessariamente mais um slot.
			*/
			*index_para_frase_cripto != (*entrada_usuario).len
		){
			// Alocamos mais espaço no array para novas substrings.
			//printf("\nAloquei para termos mais uma coluna.");
			array_de_substrings = (String**) realloc(
				array_de_substrings,
				(*index_para_array_de_substrings + 1) * sizeof(String*)
			);
		}
	}
	
	/*
	A hora de ser genial.
	
	Como a primeira substring com certeza terá 3 elementos, podemos usar o seu len
	para guardar outra informação.
	
	Como a quantidade total de substrings.
	*/
	(
		*array_de_substrings[
			0			
		]
	).len = *index_para_array_de_substrings;
	
	free(index_de_indicadores);
	free(index_para_array_de_substrings);
	free(index_para_substring);
	free(index_para_grade);
	free(index_para_frase_cripto);
	
	return array_de_substrings;
}


String* criando_strings_descriptografada(
	String **vetor_de_colunas_da_string_na_grade,
	char *ELEMENTO_DO_VAZIO
){
	/*
	Descrição:
		Função responsável por juntar as colunas da strings cripto
		na grade e lê-la de forma a termos a string descriptografada.
	
	Parâmetros:
		String **vetor_de_colunas_da_string_na_grade:
			Vetor de colunas da grade.
		
	Retorno:
		Ponteiro para String descripto.
	*/
	
	// Limpando tudo por enquanto
	int *quant_de_substrings = (int*) calloc(1, sizeof(int));
	*quant_de_substrings = (
		*vetor_de_colunas_da_string_na_grade[
			0
		]
	).len;
	
	// IRPNPRFEAANDTOQCPQCEUREAOTROPOTRXZZREWZE
	
	char *frase = (char*) calloc(1, sizeof(char));
	int *index_para_frase = (int*) calloc(1, sizeof(int));
	
	int *index_para_vetor_de_substrings = (int*) calloc(1, sizeof(int));
	int *index_para_linha = (int*) calloc(1, sizeof(int));
	while(
		(	
			// Se estamos na última coluna acessível.
			*index_para_vetor_de_substrings == (*quant_de_substrings - 1)
		)  && (
			// Se estamos na linha inacessível.
			*index_para_linha == (
				*vetor_de_colunas_da_string_na_grade[
					*index_para_vetor_de_substrings
				]
			).len
		)
	){
		
		/*
		printf(
			"\nVejo: %c na coluna %d e linha %d.",
			(
				*vetor_de_colunas_da_string_na_grade[
					*index_para_vetor_de_substrings
				]
			).array[
				*index_para_linha
			],
			*index_para_vetor_de_substrings,
			*index_para_linha
		);
		*/
		
		
		(*index_para_vetor_de_substrings)++;
		if(
			/*
			Algoritmo para:
				- Verificação se estamos na última coluna do grupo.
			*/
			*index_para_vetor_de_substrings % 10 == 0
		){
			
			if(
				// Estaremos na 3° linha
				*index_para_linha == 2
			){

				*index_para_linha = 0;
			}
			else{
				(*index_para_linha)++;
				*index_para_vetor_de_substrings = *index_para_vetor_de_substrings - 10;
			}
			
		}
		
		if(
			*index_para_vetor_de_substrings == *quant_de_substrings
		){
			/*
			Estamos na coluna que é INACESSÍVEL.
			*/
			
			*index_para_vetor_de_substrings = (*index_para_vetor_de_substrings / 10) * 10;
			(*index_para_linha)++;
		}

	}
	
	
	free(index_para_vetor_de_substrings);
	free(index_para_linha);
	free(index_para_frase);
	free(frase);
	
	for(
		int i = 0;
		i < *quant_de_substrings;
		i++ 
	){	
		// Limpamos os array de caracteres dentro de cada slot.
		free(
			(
				*vetor_de_colunas_da_string_na_grade[
					i			
				]
			).array
		);
		
		// Limpamos dentro de cada slot.
		free(
			vetor_de_colunas_da_string_na_grade[
				i
			]
		);
		// printf("\nLimpei a %d°.", i);
	}
	// Limpamos o vetor de slots.
	free(vetor_de_colunas_da_string_na_grade);
	free(quant_de_substrings);
	
	return criar_nulo();
}








/////////////////////// Implementação das Funções de Cripto ///////////////////////////////

String* criptando_na_grade(
	int *GRADE_EMBARALHADORA,
	String *entrada_usuario,
	char *ELEMENTO_DO_VAZIO
){
	/*
	Descrição:
		Função responsável por inserir a string dada pelo usuário
		dentro da grade embaralhadora.
	
	Parâmetros:
		Autoexplicativos.
	
	Retorno:
		Nova String Bialocada.
	*/
	
	char *frase_embaralhada_pela_grade = (char*) calloc(1, sizeof(char));
	int *index_para_grade_embaralhadora = (int*) calloc(1, sizeof(char));
	
	// ENTRADA TESTE -> INFATQPCPENCERRADO
	// SAÍDA TESTE -> I+NFA+TQPC+P+E+N+C+ER+R+ADO
	
	int *index_para_entrada = (int*) calloc(1, sizeof(int));
	while(
		// Vamos percorrer a string de entrada até seu final.
		*index_para_entrada != (*entrada_usuario).len
	){
		
		if(
			GRADE_EMBARALHADORA[
				/*
				Garantimos que os valores possíveis a serem acessados
				estão os índices: 0, 1, ..., 29.
				*/
				*index_para_grade_embaralhadora % 30  // É este valor pela quantidade limite de valores embaralhadores.
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
	Descrição:
		Função responsável por verificar se a posição de
		um indicador foi atingida.
	
	Parâmetros:
		int *index_de_indicadores:
			Ponteiro para fazermos as devidas verificações aqui,
			sem a necessidade de ficar chamando dentro do loop.
			Temos a garantia que na entrada sempre valerá 0.
	
	Retorno:
		0 - se não estivermos em um local apropriado.
		A - Caract indicador correspondente.
	*/
	
	while(
		*index_de_indicadores <= 3
	){
		if(
			*index_da_frase_final == (
				indicadores[
					// Posição no Grupo G.
					*index_de_indicadores + 1
				] + (
					// Há G - 1 grupos completos anteriormente.
					indicadores[
						*index_de_indicadores + 2
					] - 1
				) * 5 - 1
			)
		){
			// Estamos em posição de indicador.
			return indicadores[*index_de_indicadores];
		}
		
		*index_de_indicadores = *index_de_indicadores + 3;
	}
	
	return 0;  // Não estamos em posição de indicadores.
}


int avancando_colunas(
	int *index_frase_embaralhada
){
	/*
	Descrição:
		Função responsável por aplicar a lógica de avanço
		do index para vermos as colunas da string embaralhada
		da forma correta.
	
	Parãmetros:
		Autoexplicativos.
	
	Retorno:
		Ponteiro para index setado para novo local.
	*/
	
	// Avançamos para a próxima linha.
	*index_frase_embaralhada = *index_frase_embaralhada + 10;

	if (
		(
		
			// Obter índice que estamos.
			*index_frase_embaralhada
			
		) >= 30 * ( 1 + 
			/*
			 Obter informação de que grupo estamos.
			 0...29 -> 1° g
			 30...59 -> 2° g
			*/
			(*index_frase_embaralhada - 10) / 30
			
		)
	){
		/*
		Devemos ir para a próxima coluna.
		Note que essa divisão por 30 é importante, pois como são
		ambos inteiros, o resultado sempre também será.
		
		Ou seja, 29 / 30 = 0, por exemplo.
		*/
		*index_frase_embaralhada = 1 + (
			*index_frase_embaralhada % (30 * (  1 + (*index_frase_embaralhada - 10) / 30))
		) + 30 * ((*index_frase_embaralhada - 10) / 30);
		
		/*
		Existe a chance de estarmos em uma coluna que não existe
		fato que indica que devemos ir ao prox grupo.
		*/
		if(
			*index_frase_embaralhada == (10 + 30 * ((*index_frase_embaralhada - 10) / 30))
		){
			*index_frase_embaralhada = *index_frase_embaralhada + 20;
		}
	}
	
	return 0;
}


String* criando_string_criptografada(
	String *entrada_embaralhada_pela_grade,
	int *indicadores,
	char *ELEMENTO_DO_VAZIO
){
	/*
	Descrição:
		Função responsável por, a partir da string
		embaralhada pela grade, gerar a string resultado.
		
		A qual é obtida a partir da leitura da string em-
		baralhadora por meio de suas colunas.
	
	Parâmetros:
		Autoexplicativos.
	
	Retorno:
		String Bialocada representante do final da criptografia.
	*/
	
	char *frase_final_cripto = (char*) calloc(1, sizeof(char));
	int *index_para_frase_final = (int*) calloc(1, sizeof(int));
	
	int *index_para_string_embaralhada = (int*) calloc(1, sizeof(int));
	int *index_de_indicadores = (int*) calloc(1, sizeof(int));  // Apenas para função de verificação
	while(
		/*
		Ler todos os caracteres que estão embaralhados.
		*/
		*index_para_string_embaralhada < (*entrada_embaralhada_pela_grade).len
	){
		if(
			/*
			Caso seja o local, retornará o caractere indicador correspondente.
			O qual nunca é zero.
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
			
			// printf("\nColoquei indicador no indice %d.", *index_para_frase_final);
			
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
				
				// Alocamos mais
				frase_final_cripto = (char*) realloc(
					frase_final_cripto,
					(*index_para_frase_final + 1) * sizeof(char)
				);
			}
			
			/*
			Lógica insana para avançarmos as colunas da maneira correta.
			*/
			avancando_colunas(index_para_string_embaralhada);
		}
	}
	
	// Terminador Nulo
	frase_final_cripto[
		*index_para_frase_final
	] = '\0';
	
	String *resultado = (String*) calloc(1, sizeof(String));
	(*resultado).array = frase_final_cripto;
	(*resultado).len = *index_para_frase_final;
	
	
	// Como não precisamos mais da embaralhada
	free((*entrada_embaralhada_pela_grade).array);
	free(entrada_embaralhada_pela_grade);
	
	free(index_para_string_embaralhada);
	free(index_de_indicadores);
	free(index_para_frase_final);
	
	return resultado;
}

