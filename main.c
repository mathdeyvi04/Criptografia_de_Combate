/*
Descri��o:
	C�digo respons�vel por puxar a aplica��o,
	como um precursor. 
*/
#include "Interface.h"

int main(){
	setlocale(LC_ALL, "");
	
	// Garantir exist�ncia do hist�rico
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



