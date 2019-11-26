#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	float valor;
	struct Pilha* prox;
}Pilha;

int vazia(Pilha* pilha){
	if(pilha->prox == NULL){
		return 1;
	}
	return 0;
}

Pilha* criaPilha(){
	Pilha* novaPilha = (Pilha*)malloc(sizeof(Pilha));
	novaPilha->prox = NULL;
	return novaPilha;
}

void empilharValor(Pilha* pilha, float valor){
	Pilha* ponteiro = pilha;
	
	Pilha* novoPonteiro = (Pilha*)malloc(sizeof(Pilha));
	novoPonteiro->valor = valor;
	novoPonteiro->prox = NULL;
	
	if(vazia(pilha) == 1){
		ponteiro->prox = novoPonteiro;
	}else{
		while(ponteiro->prox != NULL){
			ponteiro = ponteiro->prox;
		}
		ponteiro->prox = novoPonteiro;
	}
}

void limparPilha(Pilha* pilha){
	if(vazia(pilha) == 1){
		printf("\nPilha vazia\n");
	}else{
		Pilha* anterior = pilha;
		Pilha* ponteiro = pilha->prox;
		while(ponteiro != NULL){
			anterior->prox = NULL;
			anterior = ponteiro->prox;
			free(ponteiro);
			ponteiro = anterior;
		}
	}
}

void imprimirValores(Pilha* pilha){
	Pilha* ponteiro = pilha->prox;
	
	if(vazia(pilha) == 1){
		printf("Pilha vazia\n");
	}else{
		printf("\nValores\n");
		while(ponteiro != NULL){
			printf("| %.2f |", ponteiro->valor);
			ponteiro = ponteiro->prox;
		}
		printf("\n");
	}
}

float desempilharValor(Pilha* pilha){
	float valor;
	
	if(vazia(pilha) == 1){
		printf("\nPilha Vazia\n");
		exit(1);
	}else{
		Pilha* anterior = pilha;
		Pilha* fim = pilha->prox;
		
		while(fim->prox != NULL){
			anterior = fim;
			fim = fim->prox;
		}
		
		valor = fim->valor;
		
		anterior->prox = NULL;
		free(fim);
		return valor;
	}
}

int juntar(int numero, char digito){
	numero = numero * 10;
	numero += (digito-48);
	return numero;
}

int isNumber(char *expressao){
	int i = 0;
	float numero = 0;
	while(expressao[i] != '\0'){
		if(i == 0 && expressao[0] == '-'){
			i++;
			continue;
		}
		if(expressao[i] < 48 || expressao[i] > 57){
			break;
		}
		
		if(expressao[i] >= 48 && expressao[i] <= 57){
			numero = juntar(numero, expressao[i]);
		}
		
		i++;
	}
	
	if(numero != 0 && expressao[0] == '-'){
		numero = numero*-1;
	}
	
	return numero;
}

int main(){
	Pilha* pilha = criaPilha();
	char expressao[255] = {};
	int numero;
	float valor1 = 0;
	float valor2 = 0;
	
	printf("\nDigite 'fim' para parar, 'listar' para ver a pilha, 'limpar' para limpar a pilha\n");
	do{
		printf("> ");
		scanf("%s", expressao);
		if(strcmp(expressao, "listar") == 0){
			imprimirValores(pilha);
			continue;
		}
		if(strcmp(expressao, "limpar") == 0){
			limparPilha(pilha);
			continue;
		}
		numero = isNumber(expressao);
		if(numero != 0){
			empilharValor(pilha, numero);
		}else{
			if(strcmp(expressao, "+") == 0){
				valor1 = desempilharValor(pilha);
				valor2 = desempilharValor(pilha);
				empilharValor(pilha, valor1+valor2);
				printf("%.2f\n", valor1+valor2); 
			}
			if(strcmp(expressao, "-") == 0){
				valor1 = desempilharValor(pilha);
				valor2 = desempilharValor(pilha);
				empilharValor(pilha, valor1-valor2);
				printf("%.2f\n", valor1-valor2); 
			}
			if(strcmp(expressao, "*") == 0){
				valor1 = desempilharValor(pilha);
				valor2 = desempilharValor(pilha);
				empilharValor(pilha, valor1*valor2);
				printf("%.2f\n", valor1*valor2); 
			}
			if(strcmp(expressao, "/") == 0){
				valor1 = desempilharValor(pilha);
				valor2 = desempilharValor(pilha);
				empilharValor(pilha, valor2/valor1);
				printf("%.2f\n", valor2/valor1); 
			}
		}
	}while(strcmp(expressao, "fim") != 0);
	return 0;
}
