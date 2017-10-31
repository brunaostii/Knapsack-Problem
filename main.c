#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct item{		//Tipo abstrato do item
	int valor;
	float peso;
	struct item *prox;
	struct item *ant;
}Itens;

int main(){

	FILE *valor, *peso, *capacidade;
	Itens * item = NULL;
	int cap, i = 0;

	if(!valor = fopen(" ", "r")){  //Leitura do arquivo, se não alocado retorna "NULL"
		printf("Erro ao abrir o arquivo.\n");
		system("pause");
		exit(1);
  	}

	if(!peso = fopen(" ", "r")){

		printf("Erro ao abrir o arquivo.\n);
		system("pause");
		exit(2);
	}

	if(!capacidade = fopen(" ", "r")){
		printf("Erro ao abrir o arquivo.\n);
		system("pause");
		exit(3);
	}

	while(i != cap){
	item = inserefim(item, fscanf(valor), fscanf(peso));
	++i;
	}



}
