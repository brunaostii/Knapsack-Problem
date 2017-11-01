#include <stdio.h>
#include <stdlib.h>

typedef struct item{		//Tipo abstrato do item - armazenar resultado
	int valor;
	float peso;
	struct item *prox;
	struct item *ant;
}Itens;


int main(int argc, char * argv[]){ //nome do txt passado como parametro
	
	FILE *valorarq, *pesoarq, *capacidade;
	Itens * item = NULL;
	int cap, qt_itens;

	if(arg != 3)
		printf("Argumentos invalidos");	

	if(!valorarq = fopen(argv[0], "r")){  //Leitura do arquivo, se não alocado retorna "NULL"
		printf("Erro ao abrir o arquivo.\n");
		system("pause");
		exit(1);
  	}

	if(!pesoarq = fopen(argv[1], "r")){

		printf("Erro ao abrir o arquivo.\n);
		system("pause");
		exit(2);
	}

	if(!capacidade = fopen(argv[2], "r")){
		printf("Erro ao abrir o arquivo.\n);
		system("pause");
		exit(3);
	}

	printf("Informe a quantidade de itens: ");
	scanf("%d", &qt_itens);

	
	int** matriz = (int**)malloc(sizeof(int*));
	 for (i = 0; i < qt_itens; i++){ 
       		matriz[i] = (int*) malloc(2 * sizeof(int)); 
       			for (j = 0; j < 2; j++){ 
           			 matriz[i][j] = 0; //Inicializa com 0.
       			}
  	}

	//Para adicionar à matriz os elementos do arquivo txt

	for(i = 0; i< qt_itens; i++){
		fscanf(valorarq, "%d", &matriz[i][0]);
		fscanf(pesoarq, "%d", &matriz[i][1]);		
	}
	
	

			
			


}


