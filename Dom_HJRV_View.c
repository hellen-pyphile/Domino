//DOM_HJRV_View - Projeto Dominó LP2026
//18/08/2026
//Hellen Araujo da Silva, João Vitor Carvalho Magalhães Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares

#include <stdio.h>
#include <stdlib.h>
#include "Dom_HJRV_View.h"

void mostrarPecas(Peca p[]) {
    int i, j, c = 0;

    printf("\n");

    for (i = 0; i <= 6; i++) {
        for (j = i; j <= 6; j++) {
            printf("[%d|%d] ", p[c].esq, p[c].dir);
            c++;
        }
        printf("\n");
    }
}

int solicitarJogador() {
    int op;
    printf("[1] - 1 jogador (CPU) \n");
    printf("[2] - 2 jogadores\n");
    printf("\nOpcao: ");
    
    if(scanf("%d", &op) != 1) {
        op = -1;
    }
    while(getchar() != '\n');

    return op;
}

void limparTela() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif defined(__linux__) || defined(__unix__)
        system("clear");
    #endif
}

void pause() {
    #if defined(_WIN32) || defined(_WIN64)
        printf("\n\n");
        system("pause");
    #elif defined(__linux__) || defined(__unix__)
        printf("\n\nPressione Enter para continuar...");
        getchar();
    #endif
}

void mostrarStatus(Peca p[]) {
    int i;
    
    for(i = 0; i <= 27; i++) {
        printf("[%d|%d] -> Status: %c\n", p[i].esq, p[i].dir, p[i].sts);
    }
}

void mostrarMensagem(const char* msg) {
    printf("%s", msg);
}

int menuAdm() {
    int op;
    printf("[1] - Visualizar Status das pecas\n");
    printf("[0] - retornar para o menu principal\n");
    printf("Opcao: \n");
    
    if(scanf("%d", &op) != 1) {
        op = -1;
    }
    while(getchar() != '\n');

    return op;
}

void limparMesa(int vetorMesa[28]) {
    int i;
    
    for(i = 0; i <= 27; i++) {
        vetorMesa[i] = '.';
    }
}

void mostrarMesa(int vetorMesa[28]) {
    int i;
    
    for(i = 0; i <= 27; i++) {
        printf("%c ", vetorMesa[i]);
    }
}

int exibirMenu() {
    int op;
    printf("[1] - Nova partida\n");
    printf("[2] - Mostrar pecas nao embaralhadas\n");
    printf("[3] - Mostrar pecas (embaralhadas)\n");
    printf("[4] - Regras\n");
    printf("[5] - Admin\n");
    printf("[0] - Sair\n");
    printf("\nOpcao: ");

    if(scanf("%d", &op) != 1) {
         op = -1;
    }
    while(getchar() != '\n');

    return op;
}

int menuRegras()
    {
        int op;
        printf("[1] - Preparacao para o jogo\n");
        printf("[2] - Inicio\n");
        printf("[3] - Turnos\n");
        printf("[4] - Compras\n");
        printf("[5] - Condicoes de vitoria\n");
        printf("[0] - Sair\n");
        printf("Opcao: \n");    

        if(scanf("%d", &op) != 1) {
            op = -1;
        }
        while (getchar() != '\n');

        return op;
    }