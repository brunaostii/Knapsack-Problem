#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
	int info;
	struct lista* prox;
}Lista;

int capMochila(int num1, int num2); int valormaximo(int peso[], int valor[], int qt_itens, int capacidade, int **mochila);
void Guloso(int peso[],int valor[], int capacidade, int qt_itens);
Lista* inserefim(Lista* L, int valor); void imprime(Lista* L);

int main(int argc, char * argv[]){ //nome do txt passado como parametro

	FILE *valorarq, *pesoarq, *cap;
	int qt_itens = 0, i = 0, aux = 0, aux2 = 0, j = 0;
	int *valor, *peso, capacidade;


	if(!(valorarq = fopen(argv[1], "r"))){  //Leitura do arquivo, se não alocado retorna "NULL"
		printf("Erro ao abrir o arquivo.\n");
		exit(1);
  	}

	if(!(pesoarq = fopen(argv[2], "r"))){

		printf("Erro ao abrir o arquivo.\n");
		exit(2);
	}

	if(!(cap = fopen(argv[3], "r"))){
		printf("Erro ao abrir o arquivo.\n");
		exit(3);
	}

	while(EOF != fscanf(valorarq, "%*s")){ //conta quantidade de itens até o final do arquivo
		qt_itens++;
	}

	printf("\n%d\n\n", qt_itens);
	fscanf(cap, "%d", &capacidade);
	printf("%d\n",capacidade);

	rewind(valorarq);
	rewind(pesoarq);



		//após contagem, declaração dos vetores;
		valor = (int*)malloc(sizeof(int)* qt_itens);
		peso = (int*)malloc(sizeof(int)* qt_itens);

		for(i = 0; i < qt_itens; i++){
			fscanf(valorarq,"%d", &valor[i]);
			fscanf(pesoarq, "%d", &peso[i]);
		}

		 //Solução Aleatória
		Guloso(peso, valor, capacidade,  qt_itens);

		if(capacidade < 1000){

			int** mochila = (int**)malloc(sizeof(int*)*(qt_itens));
			for(i = 0; i < (qt_itens+1); i++){
	        		mochila[i] = (int*)malloc(sizeof(int)*(capacidade));
	        		for(j = 0; j < capacidade; j++){
	           	 	mochila[i][j] = 0;
	        		}
						}
		}else{
			Lista* V = NULL;
			Lista* P = NULL;

				for(i = 0; i < qt_itens; i++){
						V = inserefim(V, valor[i]);
						P = inserefim(P, peso[i]);
				}
	}
	return 0;

}


Lista* inserefim(Lista* L, int valor){
	Lista* aux = L;
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = valor;
	novo->prox = NULL;

	if(!L) return novo;

	while(aux->prox != NULL){
		aux = aux->prox;
	}
	aux->prox = novo;

	return L;
}

void imprime(Lista* L){
	while(L!= NULL){
		printf("%d ", L->info);
		L = L->prox;
	}
}

//Algoritmo Guloso -- Aleatório
void Guloso(int peso[],int valor[], int capacidade, int qt_itens){
	int i;
	float* itens = (float*)malloc(sizeof(float)*qt_itens);

	for(i = 0; i < qt_itens; i++){
		if(peso[i] <= capacidade){
			itens[i] = 1;
			capacidade = capacidade - peso[i];
		}else{
			itens[i] = (float)(capacidade/peso[i]);
			capacidade = 0;
		}
	}
	printf("Solução Aleatória: ");
	for(i = 0; i < qt_itens; i++){
		printf("%.f ", itens[i]);
	}
	printf("\n\n");
}
