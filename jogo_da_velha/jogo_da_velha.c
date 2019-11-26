#include <stdio.h>
#include <stdlib.h>

void iniciarJogo(char jogo[3][3]){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            jogo[i][j] = ' ';
        }
    }
}

void jogar(char jogo[3][3]){
    int i, j;
    printf("\n");
    for(i = 0; i < 3; i++){
        printf("\t   ");
        for(j = 0; j < 3; j++){
            if(j < 2)
                printf("%c  |  ", jogo[i][j]);
            else
                printf("%c", jogo[i][j]);
        }
        if(i < 2)
            printf("\n\t  _______________\n");
        else
            printf("\n");
    }
}

int verificarVencedor(char jogo[3][3], int jogadorAtual){
    int i, j, vencedor = 0;
    char jogada = ' ';

    if(jogadorAtual == 1)
        jogada = 'X';
    else
        jogada = 'O';

    if(jogo[0][0] == jogada && jogo[0][1] == jogada && jogo[0][2] == jogada)
        vencedor = jogadorAtual;
    else if(jogo[1][0] == jogada && jogo[1][1] == jogada && jogo[1][2] == jogada)
        vencedor = jogadorAtual;
    else if(jogo[2][0] == jogada && jogo[2][1] == jogada && jogo[2][2] == jogada)
        vencedor = jogadorAtual;

    else if(jogo[0][0] == jogada && jogo[1][0] == jogada && jogo[2][0] == jogada)
        vencedor = jogadorAtual;
    else if(jogo[0][1] == jogada && jogo[1][1] == jogada && jogo[2][1] == jogada)
        vencedor = jogadorAtual;
    else if(jogo[0][2] == jogada && jogo[1][2] == jogada && jogo[2][2] == jogada)
        vencedor = jogadorAtual;

    else if(jogo[0][0] == jogada && jogo[1][1] == jogada && jogo[2][2] == jogada)
        vencedor = jogadorAtual;
    else if(jogo[0][2] == jogada && jogo[1][1] == jogada && jogo[2][0] == jogada)
        vencedor = jogadorAtual;

    return vencedor;
}

void capturarJogada(char jogo[3][3], int jogadorAtual){
    int x, y;
    char jogada = ' ';
    if(jogadorAtual == 1){
        jogada = 'X';
    }else{
        jogada = 'O';
    }

    do{
        printf("Jogador %d(linha coluna): ", jogadorAtual);
        scanf("%d %d", &x, &y);
        x = x - 1;
        y = y - 1;

        if(x < 0 || x >= 3 || y < 0 || y >= 3){
            printf("Jogada invalida!\n\n");
        }
        if(jogo[x][y] != ' ')
            printf("Jogada ja jogada!\n\n");

    }while(x < 0 || x >= 3 || y < 0 || y >= 3 || jogo[x][y] != ' ');
    jogo[x][y] = jogada;
}

void limpar(){
    // identificar o sistema operacional
    #if defined(_WIN32)
    system("cls");
    #endif // defined

    #if defined(__linux__)
    system("clear");
    #endif // defined
}

int main(){
    int i, j, jogadas = 0, jogadorAtual = 1, x, y, vencedor = 0;
    char jogo[3][3] = {};

    limpar();
    iniciarJogo(jogo);
    jogar(jogo);

    while(jogadas < 9 && vencedor == 0){
        if(jogadorAtual == 1){
            capturarJogada(jogo, jogadorAtual);
        }else if(jogadorAtual == 2){
            capturarJogada(jogo, jogadorAtual);
        }

        vencedor = verificarVencedor(jogo, jogadorAtual);

        limpar();
        jogar(jogo);

        if(vencedor != 0)
            printf("Fim! jogador %d venceu!", vencedor);

        jogadas += 1;

        if(jogadas == 9 && vencedor == 0)
            printf("Empate!");

        jogadorAtual += 1;
        if(jogadorAtual > 2)
            jogadorAtual = 1;
        printf("\n");
    }

    return 0;
}
