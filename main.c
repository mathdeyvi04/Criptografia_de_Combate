/*
Descrição:
	Código responsável por puxar a aplicação,
	como um precursor. 
*/
#include "Interface.h"

int main(){
	setlocale(LC_ALL, "");
	
	// Garantir existência do histórico
	{
		FILE *historico = fopen("historico.txt", "r");
		
		if (
			historico == NULL
		){
			FILE *historico = fopen("historico.txt", "w");
		}
		
		fclose(historico);
	}
	
	janela_principal();
	
	return 0;
}



