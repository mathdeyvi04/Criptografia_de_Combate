#include "Met_Grades.h"


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
	
	// L�gica de quantidade de caracteres.
	
	String* colocando_na_grade(
		int *GRADE,
		String *entrada,
		char *ELEMENTO_DO_VAZIO
	){
		/*
		Descri��o:
			Fun��o( CRIPTO ) respons�vel por inserir a string de entrada dentro
			da grade linear.
		*/	
		
		char *grade_linear = (char*)calloc(1, sizeof(char));
		int *index_linear = (int*)calloc(1, sizeof(int));  // para percorrer as grades
		
		/*
		Precisamos percorrer a string, de modo a encerrar 
		quando n�o houver mais caracteres a serem lidos.
		
		// INFATQPCPENCERRADO
		// I+NFA+TQPC+P+E+N+C+ER+R+ADO
		
		*/
		int *index = (int*)calloc(1, sizeof(int));  // para percorrer a string
		while(
			*index != (*entrada).len
		){
			
			if (
				GRADE[*index_linear]
			){
				
				grade_linear[*index_linear] = (*entrada).array[*index];
				(*index)++;
				
			}else{
				// Algum caractere para ser o vazio.
				grade_linear[*index_linear] = *ELEMENTO_DO_VAZIO;
					
			}
			(*index_linear)++;
			
			// Vamos alocar mais mem�ria.
			grade_linear = (char*)realloc(grade_linear, (*index_linear + 1) * sizeof(char));
			
		}
		free(index);
		
		String* entrada_na_grade = (String*)calloc(1, sizeof(String));
		(*entrada_na_grade).array = grade_linear;
		(*entrada_na_grade).len = *index_linear;		
		free(index_linear);
		
		// N�o devemos limpar grade_linear j� que estamos usando-a.
		return entrada_na_grade;
	}
	
	String* criando_string_final(
		String *string_grade,
		int *indicadores,
		char *ELEMENTO_DO_VAZIO
	){
		/*
		Descri��o:
			Fun��o( CRIPTO ) respons�vel por, a partir da string na grade,
			ser capazes de fazer as verifica��es necess�rias para pegar 
			a string final.
		*/
		
		String *resultado = (String*)calloc(1, sizeof(String));
		// I+NFA+TQPC+P+E+N+C+ER+R+ADO
		
		char *frase = (char*)calloc((*entrada).len + 2, sizeof(char));  // J� sabemos que a quantidade total de caracteres.
		int *index_resultado = (int*)calloc(1, sizeof(int)); // Para percorrer string final.
		int *index_grade = (int*)calloc(1,sizeof(int));  // Para percorrer string que est� grade.
		
		/*
		Desenvolvimento de l�gica de preenchimento dos grupos
		N�o esquecer indicadores de processo.
		
		- Vamos precisar varrer a string da grade pelas colunas.
		Suponhndo que tenha 3 linhas e 10 colunas, o index no vetor
		da string deve seguir: 0, 10, 20, 1, 11, 21, ... .
		
			- Para o limite, devemos pensar na quantidade de caracteres
			que ser�o lidos, pois em teoria deve ir somente at� onde h�
			caracteres. 
			
			- Note que, como n�o h� uma l�gica na grade, por seguran�a, 
			ent�o n�o temos escolha a n�o ser varrer por todos.
		
		- Al�m disso, devemos verificar se o elemento na string grade
		� v�lido, isto �, diferente do elemento vazio.
		
		- Al�m disso, devemos verificar se as posi��es n�o s�o dos 
		indicadores de processo. 
		
			- Basta que fa�amos index_indicador = 0, 3. Acessamos
			os outros elementos apenas somando 1 e 2.
			
			- Podemos contar qual o grupo que estamos a partir de:
			
		*/
		
		int *index_indicador = (int*)calloc(1, sizeof(int));
		while(
			*index_grade <= (*string_grade).len
		){
			
			if(
				// Caso seja um local dos indicadores.
				(
					// Verificamos se est� no mesmo grupo do indicador.
					(
						*index_resultado >= (5 * (indicadores[*index_indicador + 2] - 1))
					) && (
						*index_resultado <= ((5 * indicadores[*index_indicador + 2] - 1))
					)
									
				) && (
					// Verificamos se est� na mesma coluna do indicador.
					((*index_resultado % 5) + 1) == indicadores[*index_indicador + 1]					
				)
				
			){
				// Colocar indicador na frase.
				
				(*index_indicador)++;
			}else{
				// Caso n�o seja indicador, podemos prosseguir.
				if(
					(*string_grade).array[*index_grade] != *ELEMENTO_DO_VAZIO
				){
					
					frase[*index_resultado] = (*string_grade).array[*index_grade];
					(*index_resultado)++;			
				}
				
				(*index_grade) = (*index_grade) + 10;
				if(
					*index_grade >= 30
				){
					*index_grade = (*index_grade % 30) + 1;
				}
			}
		}
		
		
		
		
		
		
		
		// Como ela se tornou inutil
		free((*string_grade).array);
		free(string_grade);
		free(frase);  // Devemos retirar.
		free(index_resultado);
		free(index_grade);
		free(index_indicador);
		return resultado;
	}
	
	// Fazendo dessa forma 'linear' poupamos muito mais.
	int GRADE[30] = {
		1, 0, 1, 1, 1, 0, 1, 1, 1, 1,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 1, 1, 0, 1, 0
	};
	char *ELEMENTO_DO_VAZIO = (char*)calloc(1, sizeof(char));
	*ELEMENTO_DO_VAZIO = '+';
	
	String *string_grade = colocando_na_grade(
		GRADE,
		entrada,
		ELEMENTO_DO_VAZIO
	);  // Vamos limpar esse ponteiro na fun��o seguinte.
	
	String *resultado = criando_string_final(
		string_grade,  // Vamos limpar isso nessa fun��o.
		indicadores_de_processo,
		ELEMENTO_DO_VAZIO
	);
	
	return resultado;
}

