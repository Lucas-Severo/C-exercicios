#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char parenteses;
    struct Pilha* prox;
}Pilha;

Pilha* criaPilha(){
    Pilha* novaPilha = (Pilha*) malloc(sizeof(Pilha));
    novaPilha->prox = NULL;
    return novaPilha;
}

int isEmpty(Pilha* pilha){
    if(pilha->prox == NULL)
        return 1;
    return 0;
}

void empilhar(Pilha* pilha, char digito){
    Pilha* novaPilha = criaPilha();
    novaPilha->parenteses = digito;
    Pilha* ponteiro = pilha;

    if(isEmpty(pilha) == 1){
        ponteiro->prox = novaPilha;
    }else{
        while(ponteiro->prox != NULL){
            ponteiro = ponteiro->prox;
        }
        ponteiro->prox = novaPilha;
    }
}

int desempilhar(Pilha* pilha){
    Pilha* anterior = pilha;
    Pilha* ponteiro = pilha->prox;

    if(isEmpty(pilha) == 1){
        printf("Vazio");
    }else{
        while(ponteiro->prox != NULL){
            anterior = ponteiro;
            ponteiro = ponteiro->prox;
        }
        anterior->prox = NULL;
        free(ponteiro);
        return 1;
    }
}

void imprimirPilha(Pilha* pilha){
    Pilha* ponteiro = pilha->prox;
printf("\n");
    while(ponteiro != NULL){
        printf("%c", ponteiro->parenteses);
        ponteiro = ponteiro->prox;
    }
    printf("\n");
}

void limparPilha(Pilha* pilha){
    Pilha* anterior = pilha;
    Pilha* ponteiro = pilha->prox;


    while(ponteiro!=NULL){
        anterior->prox = NULL;
        anterior = ponteiro->prox;
        free(ponteiro);
        ponteiro = anterior;
    }
}

int main()
{
    Pilha* pilha = criaPilha();

    char charExpressao[10000];
	printf("Expressao(exit-sair): ");
    while(scanf("%s", charExpressao)==1  && strcmp(charExpressao, "exit") != 0){
        int i = 0;
        int valido = 1;

        while(charExpressao[i] != '\0'){
            if(charExpressao[i] == '('){
                empilhar(pilha, '(');
            }if(charExpressao[i] == ')'){
                if(isEmpty(pilha) == 1){
                    valido = 0;
                    break;
                }else{
                    desempilhar(pilha);
                }
            }
            i++;
        }

        if(valido == 1 && isEmpty(pilha) == 1)
            printf("Expressao correta\n");
        else
            printf("Expressao incorreta\n");
        limparPilha(pilha);
        Pilha* pilha = criaPilha();
        printf("\nExpressao(exit-sair): ");
    }
    return 0;
}
