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

int solicitarJogador()
    {
        int op;
        printf("[1] - 1 jogador\n");
        printf("[2] - 2 jogadores\n");
        //implementar na req 20
        printf("[3] - 2 jogadores (CPU)\n");
        printf("\nOpcao: ");
        //versao corrigida do scanf que evita erros de buffer em OS como linux e mac
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

void mostrarStatus(Peca p[])
    {
        int i;
        
        for(i = 0; i <= 27; i++)
            {
                printf("[%d|%d] -> Status: %c\n", p[i].esq, p[i].dir, p[i].status);
            }
    }

int exibirMenu() {
    int op;
    printf("[1] - Nova partida\n");
    printf("[2] - Mostrar pecas nao embaralhadas\n");
    printf("[3] - Mostrar pecas (embaralhadas)\n");
    printf("[4] - Admin\n");
    printf("[0] - Sair\n");
    printf("\nOpcao: ");

    if(scanf("%d", &op) != 1) {
         op = -1;
    }
    while(getchar() != '\n');

    return op;
}

void mostrarMensagem(const char* msg) {
    printf("%s", msg);
}

//menu para debug e teste de funcoes
int menuAdm()
    {
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

