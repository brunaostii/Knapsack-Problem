#include <stdio.h>


int tamMax(int num1, int num2){
	return (num1 > num2)? num1 : num2;
}

int maiorvalor(int capacidade, int peso[], int valor[], int qt_itens){

	int i, j;
   	int mochila[qt_itens+1][j+1];
 
   for (i = 0; i <= qt_itens; i++){
       for (j = 0; j <= capacidade; j++){
           if (i==0 || j==0)
               mochila[i][j] = 0;
           else if (peso[i-1] <= j)
                 mochila[i][j] = tamMax(valor[i-1] + mochila[i-1][capacidade-peso[i-1]],  mochila[i-1][j]);
           else
                 mochila[i][j] = mochila[i-1][j];
       }
   }
 
   return mochila[qt_itens][j];
}
