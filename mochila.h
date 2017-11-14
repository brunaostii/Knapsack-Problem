#include <stdio.h>
int capMochila(int num1, int num2); int maiorvalor(int quantidade, int valor[], int peso[], int capacidade);

// Utilizando-se de programação dinamica

int capMochila(int num1, int num2){
	return (num1 > num2)? num1 : num2;
}

int maiorvalor(int quantidade, int valor[], int peso[], int capacidade){

	int i, j;
	capacidade++;
	int** mochila = (int**)malloc(sizeof(int*)*(++quantidade));
	for(i = 0; i < quantidade; i++){
        mochila[i] = (int*)malloc(sizeof(int));
        for(j = 0; j < capacidade; j++){
            mochila[i][j] = 0;
        }
	}

   for (i = 0; i < quantidade; i++){
       for (j = 0; j < capacidade; j++){
           if (peso[i-1] <= j)
                 mochila[i][j] = capMochila(valor[i-1] + mochila[i-1][capacidade-peso[i-1]],  mochila[i-1][j]);
           else
                 mochila[i][j] = mochila[i-1][j];
       }
   }

   return mochila[quantidade][j];
}
