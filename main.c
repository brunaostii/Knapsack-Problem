#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[]){ //nome do txt passado como parametro
	
	FILE *valorarq, *pesoarq, *capacidade;
	int qt_itens = 0, i = 0;
	int *valor, *peso;


	if(!(valorarq = fopen(argv[1], "r"))){  //Leitura do arquivo, se não alocado retorna "NULL"
		printf("Erro ao abrir o arquivo.\n");
		exit(1);
  	}

	if(!(pesoarq = fopen(argv[2], "r"))){

		printf("Erro ao abrir o arquivo.\n");
		exit(2);
	}

	if(!(capacidade = fopen(argv[3], "r"))){
		printf("Erro ao abrir o arquivo.\n");
		exit(3);
	}

	while(EOF != fscanf(valorarq, "%*s")){
	
		qt_itens++;
	}

	//após contagem, declaração dos vetores;
	valor = (int*)malloc(sizeof(int)* qt_itens);
	peso = (int*)malloc(sizeof(int)* qt_itens);		
	
	rewind(valorarq);  //VOLTA INICIO DO ARQUIVO

	for(i = 0; i < qt_itens; i++){
		fscanf(valorarq,"%d", &valor[i]);
		fscanf(pesoarq, "%d", &peso[i]);
	} 

	for(i = 0; i < qt_itens; i++){
		printf("%d -", valor[i]);
		printf("%d\n", peso[i]);
	}
	
}


