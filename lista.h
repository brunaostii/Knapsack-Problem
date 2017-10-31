#include <stdio.h>
#include <mystring.h>

Itens* inserefim(Itens* L, int valor, float peso){  //adicionar itens na mochila

	Itens* novo = (Itens*)malloc(sizeof(Itens));
	Itens* aux = L;
	novo->valor = valor;
	novo->peso = peso;
	novo->prox = NULL;
	novo->ant = NULL;

	if(L == NULL) return novo;

	while(aux->prox != NULL){
		aux= aux->prox;
	}
	aux->prox = novo;
	novo->ant = aux;

}

void imprimelista(Itens* L){
	while(L != NULL){
		printf(" %d %.2f", L->valor, L->peso);
		L=L->prox;
	}
}

