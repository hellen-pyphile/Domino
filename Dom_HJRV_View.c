//DOM_HJRV_View - Projeto Dominó LP2026
//18/08/2026
//Hellen Araújo da Silva, João Vítor Carvalho Magalhães Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares

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

int exibirMenu() {
    int op;
    printf("[1] - Nova partida\n");
    printf("[2] - Mostrar pecas nao embaralhadas\n");
    printf("[3] - Mostrar pecas (embaralhadas)\n");
    printf("[0] - Sair\n");
    printf("\nOpcao: ");
    scanf("%d", &op);
    return op;
}

void mostrarMensagem(const char* msg) {
    printf("%s", msg);
}