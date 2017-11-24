#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct lista{
	int info;
	struct lista* prox;
}Lista;

void Guloso(int peso[],int valor[], int capacidade, int qt_itens);
int compara(int num1, int num2); void mochila(int capacidade, int peso[], int valor[], int n);
Lista* inserefim(Lista* L, int valor); void imprime(Lista* L);

int main(int argc, char * argv[]){ //nome do txt passado como parametro

	FILE *valorarq, *pesoarq, *cap;
	int qt_itens = 0, i = 0, aux = 0, aux2 = 0, j = 0;
	int *valor, *peso, capacidade;

	int start = clock();
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

	printf("Quantidade de itens: %d\n", qt_itens);
	fscanf(cap, "%d", &capacidade);
	printf("Capacidade Total da Mochila: %d\n",capacidade);

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

				mochila(capacidade, peso, valor, qt_itens);

				/*Lista* V = NULL;
				Lista* P = NULL;

				for(i = 0; i < qt_itens; i++){
						V = inserefim(V, valor[i]);
						P = inserefim(P, peso[i]);
				}
*/
				printf("Arq1: %s Arq2: %s Capacidade: %s \nTempo execucao: %.f\n", argv[1], argv[2], argv[3], 1000*((double)(clock() - start))/(CLOCKS_PER_SEC));

	return 0;

}


/*Lista* inserefim(Lista* L, int valor){
	Lista* aux = L;
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = valor;
	novo->prox = NULL;

	if(L == NULL) return novo;

	while(aux->prox != NULL){
		aux = aux->prox;
	}
	aux->prox = novo;

	return L;
}

void imprime(Lista* L){
	while(L!= NULL){
		printf(" %d ", L->info);
		L = L->prox;
	}
}*/

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


//Algoritmo de programação dinâmica
int compara(int num1, int num2){
	 	return (num1 > num2)? num1 : num2;
}

void mochila(int capacidade, int peso[], int valor[], int n){
   int i, j;

	 int** tabela = (int**)malloc(sizeof(int*)*(n+1));
	 for(i = 0; i < (n+1); i++){
		 tabela[i] = (int*)malloc(sizeof(int)*(capacidade+1));
	 }

   for (i = 0; i <= n; i++){
       for (j = 0; j <= capacidade; j++){
           if (i==0 || j==0)
               tabela[i][j] = 0;
           else if(peso[i-1] <= j)
                 tabela[i][j] = compara(valor[i-1] + tabela[i-1][j-peso[i-1]], tabela[i-1][j]);
           else
                 tabela[i][j] = tabela[i-1][j];
       }
   }
   i--;
   j--;
   printf("Valor maximo: %d \n",tabela[n][capacidade]);
   printf("Dinamica: ");
	 int* resultado = (int*)malloc(sizeof(int)* n);
	 int w = 0;
   	while(tabela[i][j]){
		 	if(tabela[i][j] == tabela[i-1][j]){
				i--;
				resultado[w] = 0;
				w++;
		  }else{
				resultado[w]= 1;
				w++;
				i--;
				j = j - peso[i];
			}
	}
	for(i = (n-1); i >= 0  ; --i){
		printf(" %d ", resultado[i]);
	}
	printf("\n");
}
