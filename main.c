#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){

    int l, c, linha, coluna, jogador = 1, ganhou = 0, jogador1_vitorias = 0, jogador2_vitorias = 0, placar = 0;
    char jogo[3][3];

    for(l = 0; l <3; l++){
        for(c = 0; c < 3; c++){
            jogo[l][c] = ' ';
        }
    }

    do{
        printf("\n    0   1   2\n    V   V   V\n");
        for(l = 0; l < 3; l++){
            for(c = 0; c < 3; c++){
                if(l == 0 && c == 0)
                    printf("0 -");
                if(l == 1 && c == 0)
                    printf("1 -");
                if(l == 2 && c == 0)
                    printf("2 -");
                printf(" %c ", jogo[l][c]);
                if (c < 2)
                    printf("|");
                }
                if(l < 2){
                    printf("\n   -----------");
                printf("\n");
                }
            }
        do{
            printf("\n\nJOGADOR %d: Digite a Linha e a Coluna que deseja jogar: ", jogador);
            if(scanf("%d%d", &linha, &coluna) != 2 || (linha < 0 || linha >= 3 || coluna < 0 || coluna >= 3) ||
            isalpha(linha) || isalpha(coluna)){
                printf("Entrada invalida. Digite numeros validos.");
                while(getchar() != '\n');
                continue;
            }else if(jogo[linha][coluna] != ' '){
                printf("Espaco Ja Preenchido.");
            }
        } while ((linha < 0 || linha >= 3 || coluna < 0 || coluna >= 3) || isalpha(linha) || isalpha(coluna)|| jogo[linha][coluna] != ' ');

        if(jogador == 1){
            jogo[linha][coluna] = 'O';
            jogador++;
        } else{
            jogo[linha][coluna] = 'X';
            jogador = 1;
        }

        if(jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] =='O'||
        jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] =='O'||
        jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] =='O'){
            printf("\n    0   1   2\n    V   V   V\n");
            for(l = 0; l < 3; l++){
                for(c = 0; c < 3; c++){
                    if(l == 0 && c == 0)
                        printf("0 -");
                    if(l == 1 && c == 0)
                        printf("1 -");
                    if(l == 2 && c == 0)
                        printf("2 -");
                    printf(" %c ", jogo[l][c]);
                    if (c < 2)
                        printf("|");
                    }
                    if(l < 2){
                        printf("\n   -----------");
                    printf("\n");
                    }
            }
            ganhou = 1;
            placar = 1;
            printf("\n\nO Jogador 1 Venceu!\n");
            if(placar == 1){
                jogador1_vitorias++;
                printf("\nPlacar:\nJogador 1: %d\nJogador 2: %d\n", jogador1_vitorias, jogador2_vitorias);
            }
        }

        if(jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] =='X'||
        jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] =='X'||
        jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] =='X'){
            printf("\n    0   1   2\n    V   V   V\n");
            for(l = 0; l < 3; l++){
                for(c = 0; c < 3; c++){
                    if(l == 0 && c == 0)
                        printf("0 -");
                    if(l == 1 && c == 0)
                        printf("1 -");
                    if(l == 2 && c == 0)
                        printf("2 -");
                    printf(" %c ", jogo[l][c]);
                    if (c < 2)
                        printf("|");
                    }
                    if(l < 2){
                        printf("\n   -----------");
                    printf("\n");
                    }
            }            
            ganhou = 1;
            placar = 1;
            printf("\n\nO Jogador 2 Venceu!\n");
            if(placar == 1){
                jogador1_vitorias++;
                printf("\nPlacar:\nJogador 1: %d\nJogador 2: %d\n", jogador1_vitorias, jogador2_vitorias);
            }
        }

        if(jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] =='O'||
        jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] =='O'||
        jogo[0][2] == 'O' && jogo[1][2] == 'O' && jogo[2][2] =='O'){
            printf("\n    0   1   2\n    V   V   V\n");
            for(l = 0; l < 3; l++){
                for(c = 0; c < 3; c++){
                    if(l == 0 && c == 0)
                        printf("0 -");
                    if(l == 1 && c == 0)
                        printf("1 -");
                    if(l == 2 && c == 0)
                        printf("2 -");
                    printf(" %c ", jogo[l][c]);
                    if (c < 2)
                        printf("|");
                    }
                    if(l < 2){
                        printf("\n   -----------");
                    printf("\n");
                    }
            }            
            ganhou = 1;
            placar = 1;
            printf("\n\nO Jogador 1 Venceu!\n");
            if(placar == 1){
                jogador1_vitorias++;
                printf("\nPlacar:\nJogador 1: %d\nJogador 2: %d\n", jogador1_vitorias, jogador2_vitorias);
            }
        }

        if(jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] =='X'||
        jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] =='X'||
        jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] =='X'){
            printf("\n    0   1   2\n    V   V   V\n");
            for(l = 0; l < 3; l++){
                for(c = 0; c < 3; c++){
                    if(l == 0 && c == 0)
                        printf("0 -");
                    if(l == 1 && c == 0)
                        printf("1 -");
                    if(l == 2 && c == 0)
                        printf("2 -");
                    printf(" %c ", jogo[l][c]);
                    if (c < 2)
                        printf("|");
                    }
                    if(l < 2){
                        printf("\n   -----------");
                    printf("\n");
                    }
            }            
            ganhou = 1;
            placar = 1;
            printf("\n\nO Jogador 2 Venceu!\n");
            if(placar == 1){
                jogador1_vitorias++;
                printf("\nPlacar:\nJogador 1: %d\nJogador 2: %d\n", jogador1_vitorias, jogador2_vitorias);
            }
        }

        if(jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] =='O'){
            printf("\n    0   1   2\n    V   V   V\n");
            for(l = 0; l < 3; l++){
                for(c = 0; c < 3; c++){
                    if(l == 0 && c == 0)
                        printf("0 -");
                    if(l == 1 && c == 0)
                        printf("1 -");
                    if(l == 2 && c == 0)
                        printf("2 -");
                    printf(" %c ", jogo[l][c]);
                    if (c < 2)
                        printf("|");
                    }
                    if(l < 2){
                        printf("\n   -----------");
                    printf("\n");
                    }
            }            
            ganhou = 1;
            placar = 1;
            printf("\n\nO Jogador 1 Venceu!\n");
            if(placar == 1){
                jogador1_vitorias++;
                printf("\nPlacar:\nJogador 1: %d\nJogador 2: %d\n", jogador1_vitorias, jogador2_vitorias);
            }
        }

        if(jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] =='X'){
            printf("\n    0   1   2\n    V   V   V\n");
            for(l = 0; l < 3; l++){
                for(c = 0; c < 3; c++){
                    if(l == 0 && c == 0)
                        printf("0 -");
                    if(l == 1 && c == 0)
                        printf("1 -");
                    if(l == 2 && c == 0)
                        printf("2 -");
                    printf(" %c ", jogo[l][c]);
                    if (c < 2)
                        printf("|");
                    }
                    if(l < 2){
                        printf("\n   -----------");
                    printf("\n");
                    }
            }            
            ganhou = 1;
            placar = 1;
            printf("\n\nO Jogador 2 Venceu!\n");
            if(placar == 1){
                jogador1_vitorias++;
                printf("\nPlacar:\nJogador 1: %d\nJogador 2: %d\n", jogador1_vitorias, jogador2_vitorias);
            }
        }

        if(jogo[2][0] == 'O' && jogo[1][1] == 'O' && jogo[0][2] =='O'){
            printf("\n    0   1   2\n    V   V   V\n");
            for(l = 0; l < 3; l++){
                for(c = 0; c < 3; c++){
                    if(l == 0 && c == 0)
                        printf("0 -");
                    if(l == 1 && c == 0)
                        printf("1 -");
                    if(l == 2 && c == 0)
                        printf("2 -");
                    printf(" %c ", jogo[l][c]);
                    if (c < 2)
                        printf("|");
                    }
                    if(l < 2){
                        printf("\n   -----------");
                    printf("\n");
                    }
            }            
            ganhou = 1;
            placar = 1;
            printf("\n\nO Jogador 1 Venceu!\n");
            if(placar == 1){
                jogador1_vitorias++;
                printf("\nPlacar:\nJogador 1: %d\nJogador 2: %d\n", jogador1_vitorias, jogador2_vitorias);
            }
        }

        if(jogo[2][0] == 'X' && jogo[1][1] == 'X' && jogo[0][2] =='X'){
            printf("\n    0   1   2\n    V   V   V\n");
            for(l = 0; l < 3; l++){
                for(c = 0; c < 3; c++){
                    if(l == 0 && c == 0)
                        printf("0 -");
                    if(l == 1 && c == 0)
                        printf("1 -");
                    if(l == 2 && c == 0)
                        printf("2 -");
                    printf(" %c ", jogo[l][c]);
                    if (c < 2)
                        printf("|");
                    }
                    if(l < 2){
                        printf("\n   -----------");
                    printf("\n");
                    }
            }            
            ganhou = 1;
            placar = 1;
            printf("\n\nO Jogador 2 Venceu!\n");
            if(placar == 1){
                jogador1_vitorias++;
                printf("\nPlacar:\nJogador 1: %d\nJogador 2: %d\n", jogador1_vitorias, jogador2_vitorias);
            }
        }
    }while(ganhou == 0);
}