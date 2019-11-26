#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


/*
	Algoritmo para resolver quadrado mágico
	com dimensões ímpares
*/

static int dimensao = 0;

int isEmpty(int matriz[dimensao][dimensao], int x, int y){
	if(matriz[y][x] != 0)
		return 0;
	return 1;
}

void preencheMatriz(int matriz[dimensao][dimensao]){
	int indice = 1;
	int x_anterior, y_anterior;
	int x = (dimensao/2); int y = 0;
	
	while(indice <= (dimensao*dimensao)){
		if(isEmpty(matriz, x, y) == 1 && x >= 0 && x < dimensao && y >= 0 && y < dimensao){
			x_anterior = x;
			y_anterior = y;
			matriz[y][x] = indice;
			indice++;
			x++;
			y--;
		}else if(x >= dimensao || x < 0){
			if(x < 0){
				x = dimensao + x;
			}else{
				x = dimensao - x;
			}
		}else if(y >= dimensao || y < 0){
			if(y < 0)
				y = dimensao + y;
			else
				y = dimensao - y;
		}else if(isEmpty(matriz, x, y) == 0){
			x = x_anterior;
			y = y_anterior;
			y++;
		}
	}
}

void imprimirMatriz(int matriz[dimensao][dimensao]){
	int i, j;
	
	
	printf("Quadrado Magico Impar\n\n");
	for(i = 0; i < dimensao; i++){
		for(j = 0; j < dimensao; j++){
			printf("%5d ", matriz[i][j]);
		}
		printf("\n");
	}
}

int main(){
	printf("Lado(impar): ");
	scanf("%d", &dimensao);
	
	if(dimensao > MAX){
		printf("MAX: %d\n", MAX);
		exit(1);
	}

	int matriz[MAX][MAX];
	memset(matriz, 0, sizeof(matriz));
	preencheMatriz(matriz);
	imprimirMatriz(matriz);
}
