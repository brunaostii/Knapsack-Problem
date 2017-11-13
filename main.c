#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct lista* prox;
}Lista;

int main(int argc, char * argv[]){ //nome do txt passado como parametro
	
	FILE *valorarq, *pesoarq, *cap;
	int qt_itens = 0, i = 0, aux = 0, aux2 = 0;
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
	}cap

	while(EOF != fscanf(valorarq, "%*s")){
	
		qt_itens++;
	}
	
	printf("\n%d\n", qt_itens);
	fscanf(cap, "%d", &capacidade);

	rewind(valorarq);
 
	if(cap < 1000){
	
		//após contagem, declaração dos vetores;
		valor = (int*)malloc(sizeof(int)* qt_itens);
		peso = (int*)malloc(sizeof(int)* qt_itens);		
	

		for(i = 0; i < qt_itens; i++){
			fscanf(valorarq,"%d", &valor[i]);
			fscanf(pesoarq, "%d", &peso[i]);
		}
	

		for(i = 0; i < qt_itens; i++){
			printf("%d -", valor[i]);
			printf("%d\n", peso[i]);
		}
	}else{
		Lista* valor = NULL;
		Lista* peso = NULL;
		
		
		for(i = 0; i< qt_itens; i++){
			fscanf(valorarq, "%d", &aux);
			fscanf(pesoarq, "%d", &aux2);
			valor = inserefim(valor, aux);
			peso = inserefim(peso, aux2);
			
		} 
	}

}

Lista* inserefim(Lista* L, int num){
	Lista* aux = L;
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->prox= NULL;
	novo->info = num;

	if(L == NULL) return novo;

	while(L->prox != NULL){
		aux=aux->prox;
	}
	aux->prox = novo;

	return L;
}

void imprimelista(Lista* L, int num){
	while(L != NULL){
		printf("%d\n", L->info);
		L=L->prox;
	}
}
