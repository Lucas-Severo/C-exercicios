#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char caractere;
	struct Pilha *prox;
}Pilha;

Pilha* criaPilha(){
	Pilha* novaPilha = (Pilha*) malloc(sizeof(Pilha));
	novaPilha->prox = NULL;
	return novaPilha;
}

int vazia(Pilha* pilha){
	if(pilha->prox == NULL)
		return 1;
	return 0;
}

void empilharValor(Pilha* pilha, char string[100]){
	int i = 0;
	
	if(vazia(pilha) == 1){
		Pilha* ponteiro = pilha;
		while(string[i] != '\0'){
			Pilha* novaPilha = criaPilha();
			novaPilha->caractere = string[i];
			ponteiro->prox = novaPilha;
			ponteiro = ponteiro->prox;
			i++;
		}
	}
}

char desempilharValor(Pilha* pilha){
	if(vazia(pilha) == 1){
		printf("Pilha vazia\n");
		exit(1);
	}else{
		char valor;
		Pilha* anterior = pilha;
		Pilha* ponteiro = pilha;
		while(ponteiro->prox != NULL){
			anterior = ponteiro;
			ponteiro = ponteiro->prox;
		}
		anterior->prox = NULL;
		valor = ponteiro->caractere;
		free(ponteiro);
		return valor;
	}
}

void imprimirPilha(Pilha* pilha){
	Pilha* ponteiro = pilha;
	while(ponteiro != NULL){
		printf("%c\n", ponteiro->caractere);
		ponteiro = ponteiro->prox;
	}
}

int main(){
	Pilha* pilha = criaPilha();
	
	char palavra[100] = {};
	printf("Palavra: ");
	scanf("%s", &palavra);
	
	empilharValor(pilha, palavra);
	
	char palavraInvertida[100] = {};
	int i = 0;
	
	
	while(vazia(pilha) != 1){
		palavraInvertida[i] = desempilharValor(pilha);
		i++;
	}
	printf("\nPalavra: %s\n", palavra);
	printf("Palavra Invertida: %s\n\n", palavraInvertida);
	
	if(strcmp(palavra, palavraInvertida) == 0){
		printf("Eh palindromo\n");
	}else{
		printf("Nao eh palindromo\n");
	}
}
