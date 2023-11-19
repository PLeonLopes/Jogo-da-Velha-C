#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct modelo {
    char **jogo;  // criação da matriz 3x3 com ponteiro de ponteiro
    int l, c; 
} t_modelo;

typedef struct jogar{
    int linha;
    int coluna;
    int jogador;
    int empate;
    char continuar;
}t_jogar;

typedef struct vencedor{
    int ganhou;
    int jogador1_vitorias;
    int jogador2_vitorias;
}t_vencedor;

// Função VOID para inicialização do jogo
void inicializarjogo(t_modelo *design){
    design->jogo = (char **)malloc(3 * sizeof(char *));  // Alocação de linhas
    for (design->l = 0; design->l < 3; design->l++) {
        design->jogo[design->l] = (char *)malloc(3 * sizeof(char));  // Alocação de colunas
        for (design->c = 0; design->c < 3; design->c++) {
            design->jogo[design->l][design->c] = ' ';
        }
    }
}

// Função VOID para liberação de memória alocada
void liberarMemoria(t_modelo *design) {
    for (design->l = 0; design->l < 3; design->l++) {
        free(design->jogo[design->l]);
    }
    free(design->jogo);
}

int main () {
    t_jogar jogadas;
    t_modelo design;
    t_vencedor vencer;

    jogadas.jogador = 1;
    jogadas.continuar = 's';
    vencer.ganhou = 0;
    vencer.jogador1_vitorias = 0;
    vencer.jogador2_vitorias = 0;

    do {
        inicializarjogo(&design);
        do{
            printf("\n    0   1   2\n    V   V   V\n");
            for(design.l = 0; design.l < 3; design.l++){
                for(design.c = 0; design.c < 3; design.c++){
                    if(design.l == 0 && design.c == 0)
                        printf("0 -");
                    if(design.l == 1 && design.c == 0)
                        printf("1 -");
                    if(design.l == 2 && design.c == 0)
                        printf("2 -");
                    printf(" %c ", design.jogo[design.l][design.c]);
                    if (design.c < 2)
                        printf("|");
                    }
                    if(design.l < 2){
                        printf("\n   -----------");
                    printf("\n");
                    }
                }
            do{
                printf("\n\nJOGADOR %d: Digite a Linha e a Coluna que deseja jogar: ", jogadas.jogador);
                if(scanf("%d%d", &jogadas.linha, &jogadas.coluna) != 2 || (jogadas.linha < 0 || jogadas.linha >= 3 || jogadas.coluna < 0 || jogadas.coluna >= 3) ||
                isalpha(jogadas.linha) || isalpha(jogadas.coluna)){
                    printf("Entrada invalida. Digite numeros validos.");
                    while(getchar() != '\n');
                    continue;
                }else if(design.jogo[jogadas.linha][jogadas.coluna] != ' '){
                    printf("Espaco Ja Preenchido.");
                }
            } while ((jogadas.linha < 0 || jogadas.linha >= 3 || jogadas.coluna < 0 || jogadas.coluna >= 3) || isalpha(jogadas.linha) || isalpha(jogadas.coluna)|| design.jogo[jogadas.linha][jogadas.coluna] != ' ');

            if(jogadas.jogador == 1){
                design.jogo[jogadas.linha][jogadas.coluna] = 'O';
                jogadas.jogador++;
            } else{
                design.jogo[jogadas.linha][jogadas.coluna] = 'X';
                jogadas.jogador = 1;
            }
            jogadas.empate++;

            if(design.jogo[0][0] == 'O' && design.jogo[0][1] == 'O' && design.jogo[0][2] =='O'||
            design.jogo[1][0] == 'O' && design.jogo[1][1] == 'O' && design.jogo[1][2] =='O'||
            design.jogo[2][0] == 'O' && design.jogo[2][1] == 'O' && design.jogo[2][2] =='O'){
                printf("\n    0   1   2\n    V   V   V\n");
                for(design.l = 0; design.l < 3; design.l++){
                    for(design.c = 0; design.c < 3; design.c++){
                        if(design.l == 0 && design.c == 0)
                            printf("0 -");
                        if(design.l == 1 && design.c == 0)
                            printf("1 -");
                        if(design.l == 2 && design.c == 0)
                            printf("2 -");
                        printf(" %c ", design.jogo[design.l][design.c]);
                        if (design.c < 2)
                            printf("|");
                        }
                        if(design.l < 2){
                            printf("\n   -----------");
                        printf("\n");
                        }
                }
                jogadas.empate = 0;
                vencer.ganhou = 1;
                printf("\n\nO Jogador 1 Venceu!\n");
                if(vencer.ganhou == 1){
                    vencer.jogador1_vitorias++;
                    jogadas.jogador = 1;
                    printf("\nPlacar:\nVitorias do Jogador 1: %d\nVitorias do Jogador 2: %d\n", vencer.jogador1_vitorias, vencer.jogador2_vitorias);
                }
            }

            if(design.jogo[0][0] == 'X' && design.jogo[0][1] == 'X' && design.jogo[0][2] =='X'||
            design.jogo[1][0] == 'X' && design.jogo[1][1] == 'X' && design.jogo[1][2] =='X'||
            design.jogo[2][0] == 'X' && design.jogo[2][1] == 'X' && design.jogo[2][2] =='X'){
                printf("\n    0   1   2\n    V   V   V\n");
                for(design.l = 0; design.l < 3; design.l++){
                    for(design.c = 0; design.c < 3; design.c++){
                        if(design.l == 0 && design.c == 0)
                            printf("0 -");
                        if(design.l == 1 && design.c == 0)
                            printf("1 -");
                        if(design.l == 2 && design.c == 0)
                            printf("2 -");
                        printf(" %c ", design.jogo[design.l][design.c]);
                        if (design.c < 2)
                            printf("|");
                    }
                    if(design.l < 2){
                        printf("\n   -----------");
                    printf("\n");
                    }
                }
                jogadas.empate = 0;   
                vencer.ganhou = 1;
                printf("\n\nO Jogador 2 Venceu!\n");
                if(vencer.ganhou == 1){
                    vencer.jogador2_vitorias++;
                    printf("\nPlacar:\nVitorias do Jogador 1: %d\nVitorias do Jogador 2: %d\n", vencer.jogador1_vitorias, vencer.jogador2_vitorias);
                }
            }

            if(design.jogo[0][0] == 'O' && design.jogo[1][0] == 'O' && design.jogo[2][0] =='O'||
            design.jogo[0][1] == 'O' && design.jogo[1][1] == 'O' && design.jogo[2][1] =='O'||
            design.jogo[0][2] == 'O' && design.jogo[1][2] == 'O' && design.jogo[2][2] =='O'){
                printf("\n    0   1   2\n    V   V   V\n");
                for(design.l = 0; design.l < 3; design.l++){
                    for(design.c = 0; design.c < 3; design.c++){
                        if(design.l == 0 && design.c == 0)
                            printf("0 -");
                        if(design.l == 1 && design.c == 0)
                            printf("1 -");
                        if(design.l == 2 && design.c == 0)
                            printf("2 -");
                        printf(" %c ", design.jogo[design.l][design.c]);
                        if (design.c < 2)
                            printf("|");
                    }
                    if(design.l < 2){
                        printf("\n   -----------");
                    printf("\n");
                    }
                }
                jogadas.empate = 0;
                vencer.ganhou = 1;
                printf("\n\nO Jogador 1 Venceu!\n");
                if(vencer.ganhou == 1){
                    vencer.jogador1_vitorias++;
                    jogadas.jogador = 1;
                    printf("\nPlacar:\nVitorias do Jogador 1: %d\nVitorias do Jogador 2: %d\n", vencer.jogador1_vitorias, vencer.jogador2_vitorias);
                }
            }

            if(design.jogo[0][0] == 'X' && design.jogo[1][0] == 'X' && design.jogo[2][0] =='X'||
            design.jogo[0][1] == 'X' && design.jogo[1][1] == 'X' && design.jogo[2][1] =='X'||
            design.jogo[0][2] == 'X' && design.jogo[1][2] == 'X' && design.jogo[2][2] =='X'){
            printf("\n    0   1   2\n    V   V   V\n");
                for(design.l = 0; design.l < 3; design.l++){
                    for(design.c = 0; design.c < 3; design.c++){
                        if(design.l == 0 && design.c == 0)
                            printf("0 -");
                        if(design.l == 1 && design.c == 0)
                            printf("1 -");
                        if(design.l == 2 && design.c == 0)
                            printf("2 -");
                        printf(" %c ", design.jogo[design.l][design.c]);
                        if (design.c < 2)
                            printf("|");
                    }
                    if(design.l < 2){
                        printf("\n   -----------");
                    printf("\n");
                    }
                }
                jogadas.empate = 0;
                vencer.ganhou = 1;
                printf("\n\nO Jogador 2 Venceu!\n");
                if(vencer.ganhou == 1){
                    vencer.jogador2_vitorias++;
                    printf("\nPlacar:\nVitorias do Jogador 1: %d\nVitorias do Jogador 2: %d\n", vencer.jogador1_vitorias, vencer.jogador2_vitorias);
                }
            }

            if(design.jogo[0][0] == 'O' && design.jogo[1][1] == 'O' && design.jogo[2][2] =='O'){
                printf("\n    0   1   2\n    V   V   V\n");
                for(design.l = 0; design.l < 3; design.l++){
                    for(design.c = 0; design.c < 3; design.c++){
                        if(design.l == 0 && design.c == 0)
                            printf("0 -");
                        if(design.l == 1 && design.c == 0)
                            printf("1 -");
                        if(design.l == 2 && design.c == 0)
                            printf("2 -");
                        printf(" %c ", design.jogo[design.l][design.c]);
                        if (design.c < 2)
                            printf("|");
                    }
                    if(design.l < 2){
                        printf("\n   -----------");
                    printf("\n");
                    }
                }
                jogadas.empate = 0;
                vencer.ganhou = 1;
                printf("\n\nO Jogador 1 Venceu!\n");
                if(vencer.ganhou == 1){
                    vencer.jogador1_vitorias++;
                    jogadas.jogador = 1;
                    printf("\nPlacar:\nVitorias do Jogador 1: %d\nVitorias do Jogador 2: %d\n", vencer.jogador1_vitorias, vencer.jogador2_vitorias);
                }
            }

            if(design.jogo[0][0] == 'X' && design.jogo[1][1] == 'X' && design.jogo[2][2] =='X'){
                printf("\n    0   1   2\n    V   V   V\n");
                for(design.l = 0; design.l < 3; design.l++){
                    for(design.c = 0; design.c < 3; design.c++){
                        if(design.l == 0 && design.c == 0)
                            printf("0 -");
                        if(design.l == 1 && design.c == 0)
                            printf("1 -");
                        if(design.l == 2 && design.c == 0)
                            printf("2 -");
                        printf(" %c ", design.jogo[design.l][design.c]);
                        if (design.c < 2)
                            printf("|");
                    }
                    if(design.l < 2){
                        printf("\n   -----------");
                    printf("\n");
                    }
                }
                jogadas.empate = 0;            
                vencer.ganhou = 1;
                printf("\n\nO Jogador 2 Venceu!\n");
                if(vencer.ganhou == 1){
                    vencer.jogador2_vitorias++;
                    printf("\nPlacar:\nVitorias do Jogador 1: %d\nVitorias do Jogador 2: %d\n", vencer.jogador1_vitorias, vencer.jogador2_vitorias);
                }
            }

            if(design.jogo[2][0] == 'O' && design.jogo[1][1] == 'O' && design.jogo[0][2] =='O'){
                printf("\n    0   1   2\n    V   V   V\n");
                for(design.l = 0; design.l < 3; design.l++){
                    for(design.c = 0; design.c < 3; design.c++){
                        if(design.l == 0 && design.c == 0)
                            printf("0 -");
                        if(design.l == 1 && design.c == 0)
                            printf("1 -");
                        if(design.l == 2 && design.c == 0)
                            printf("2 -");
                        printf(" %c ", design.jogo[design.l][design.c]);
                        if (design.c < 2)
                            printf("|");
                    }
                    if(design.l < 2){
                        printf("\n   -----------");
                    printf("\n");
                    }
                }
                jogadas.empate = 0;
                vencer.ganhou = 1;
                printf("\n\nO Jogador 1 Venceu!\n");
                if(vencer.ganhou == 1){
                    vencer.jogador1_vitorias++;
                    jogadas.jogador = 1;
                    printf("\nPlacar:\nVitorias do Jogador 1: %d\nVitorias do Jogador 2: %d\n", vencer.jogador1_vitorias, vencer.jogador2_vitorias);
                }
            }

            if(design.jogo[2][0] == 'X' && design.jogo[1][1] == 'X' && design.jogo[0][2] =='X'){
                printf("\n    0   1   2\n    V   V   V\n");
                for(design.l = 0; design.l < 3; design.l++){
                    for(design.c = 0; design.c < 3; design.c++){
                        if(design.l == 0 && design.c == 0)
                            printf("0 -");
                        if(design.l == 1 && design.c == 0)
                            printf("1 -");
                        if(design.l == 2 && design.c == 0)
                            printf("2 -");
                        printf(" %c ", design.jogo[design.l][design.c]);
                        if (design.c < 2)
                            printf("|");
                    }
                    if(design.l < 2){
                        printf("\n   -----------");
                    printf("\n");
                    }
                }
                jogadas.empate = 0;
                vencer.ganhou = 1;
                printf("\n\nO Jogador 2 Venceu!\n");
                if(vencer.ganhou == 1){
                    vencer.jogador2_vitorias++;
                    printf("\nPlacar:\nVitorias do Jogador 1: %d\nVitorias do Jogador 2: %d\n", vencer.jogador1_vitorias, vencer.jogador2_vitorias);
                }
            }
        }while(vencer.ganhou == 0 && jogadas.empate < 9);

        vencer.ganhou = 1;

        if(jogadas.empate > 8){
            printf("\n    0   1   2\n    V   V   V\n");
            for(design.l = 0; design.l < 3; design.l++){
                for(design.c = 0; design.c < 3; design.c++){
                    if(design.l == 0 && design.c == 0)
                        printf("0 -");
                    if(design.l == 1 && design.c == 0)
                        printf("1 -");
                    if(design.l == 2 && design.c == 0)
                        printf("2 -");
                    printf(" %c ", design.jogo[design.l][design.c]);
                    if (design.c < 2)
                        printf("|");
                }
                if(design.l < 2){
                    printf("\n   -----------");
                printf("\n");
                }
            }
            printf("\n\nEmpate.\n");
            jogadas.empate = 0;
            jogadas.jogador = 1;
        }
        
        printf("\nDeseja continuar jogando? ('S' para SIM, qualquer tecla para NAO): ");
        scanf(" %c", &jogadas.continuar);
        vencer.ganhou = 0;      

        // Liberação de memória alocada ao final de cada jogo
        liberarMemoria(&design);

    } while (jogadas.continuar == 's' || jogadas.continuar == 'S');

    printf("Fim de Jogo.\n");
    return 0;
}