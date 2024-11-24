#include "Met_Grades.h"


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
	
	// Lógica de quantidade de caracteres.
	
	String* colocando_na_grade(
		int *grade,
		String *entrada
	){
		/*
		Descrição:
			Função( CRIPTO ) responsável por inserir a string de entrada dentro
			da grade linear.
		*/	
		
		char *grade_linear = (char*)calloc(1, sizeof(char));
		int *index_linear = (int*)calloc(1, sizeof(int));  // para percorrer as grades
		
		/*
		Precisamos percorrer a string, de modo a encerrar 
		quando não houver mais caracteres a serem lidos.
		
		// INFATQPCPENCERRADO
		// I+NFA+TQPC+P+E+N+C+ER+R+ADO
		
		*/
		int *index = (int*)calloc(1, sizeof(int));  // para percorrer a string
		while(
			*index != (*entrada).len
		){
			
			if (
				grade[*index_linear]
			){
				
				grade_linear[*index_linear] = (*entrada).array[*index];
				(*index)++;
				
			}else{
				// Algum caractere para ser o vazio.
				grade_linear[*index_linear] = '+';
					
			}
			(*index_linear)++;
			
			// Vamos alocar mais memória.
			grade_linear = (char*)realloc(grade_linear, (*index_linear + 1) * sizeof(char));
			
		}
		free(index);
		
		String* entrada_na_grade = (String*)calloc(1, sizeof(String));
		(*entrada_na_grade).array = grade_linear;
		(*entrada_na_grade).len = *index_linear;		
		free(index_linear);
		
		// Não devemos limpar grade_linear já que estamos usando-a.
		return entrada_na_grade;
	}
	
	String* criando_string_final(
		int *grade,
		String *string_grade,
		int *indicadores
	){
		/*
		Descrição:
			Função( CRIPTO ) responsável por, a partir da string na grade,
			ser capazes de fazer as verificações necessárias para pegar 
			a string final.
		*/
		
		String *resultado = (String*)calloc(1, sizeof(String));
		// I+NFA+TQPC+P+E+N+C+ER+R+ADO
		
		char *frase = (char*)calloc((*entrada).len + 2, sizeof(char));
		int *index_resultado = (int*)calloc(1, sizeof(int)); // Para percorrer string final.
		int *index_grade = (int*)calloc(1,sizeof(int));  // Para percorrer string que está grade.
		
		/*
		Desenvolvimento de lógica de preenchimento dos grupos
		Não esquecer indicadores de processo.
		*/
		
		
		
		// Como ela se tornou inutil
		free((*string_grade).array);
		free(string_grade);
		free(index_resultado);
		free(index_grade);
		return resultado;
	}
	
	// Fazendo dessa forma 'linear' poupamos muito mais.
	int grade[30] = {
		1, 0, 1, 1, 1, 0, 1, 1, 1, 1,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 1, 1, 0, 1, 0
	};
	
	String *string_grade = colocando_na_grade(
		grade,
		entrada
	);  // Vamos limpar esse na string seguinte.
	
	String *resultado = criando_string_final(
		grade,
		string_grade,  // Vamos limpar isso nessa função.
		indicadores_de_processo
	);
	
	return resultado;
}

