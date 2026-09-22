//DOM_HJRV_View - Projeto Dominó LP2026
//22/09/2026
//Hellen Araujo da Silva, João Vitor Carvalho Magalhaes Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares
//Req07, Req09, Req13, Req14, Req17

#include <stdio.h>
#include <stdlib.h>
#include "Dom_HJRV_View.h"

/*
** Exibe na tela todas as pecas do domino organizadas por linha
** Parametros:
**      p[] - (Peca) array com todas as pecas do jogo
*/
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

/*
** Limpa a tela do console, de acordo com o sistema operacional
** Parametros:
**      (nenhum)
*/
void limparTela() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif defined(__linux__) || defined(__unix__)
        system("clear");
    #endif
}

/*
** Pausa a execucao do programa ate que o usuario pressione uma tecla
** Parametros:
**      (nenhum)
*/
void pause() {
    #if defined(_WIN32) || defined(_WIN64)
        printf("\n\n");
        system("pause");
    #elif defined(__linux__) || defined(__unix__)
        printf("\n\nPressione Enter para continuar...");
        getchar();
    #endif
}

/*
** Exibe o status atual (Disp, J1, J2 ou Mesa) de cada peca do jogo
** Parametros:
**      p[] - (Peca) array com todas as pecas do jogo
*/
void mostrarStatus(Peca p[]) {
    int i;
    
    for(i = 0; i <= 27; i++) {
        printf("[%d|%d] -> Status: %c\n", p[i].esq, p[i].dir, p[i].sts);
    }
}

/*
** Exibe uma mensagem de texto na tela
** Parametros:
**      msg - (const char*) mensagem a ser exibida
*/
void mostrarMensagem(const char* msg) {
    printf("%s", msg);
}


/*
** Inicializa/limpa o vetor visual da mesa, preenchendo-o com '.'
** Parametros:
**      vetorMesa[] - (int) vetor que representa visualmente a mesa (por referencia)
*/
void limparMesa(int vetorMesa[28]) {
    int i;
    
    for(i = 0; i <= 27; i++) {
        vetorMesa[i] = '.';
    }
}

/*
** Exibe o vetor visual da mesa na tela
** Parametros:
**      vetorMesa[] - (int) vetor que representa visualmente a mesa
*/
void mostrarMesa(int vetorMesa[28]) {
    int i;
    
    for(i = 0; i <= 27; i++) {
        printf("%c ", vetorMesa[i]);
    }
}


/*
** Exibe o estado atual do jogo: pecas na mesa, extremidades e
** as pecas na mao do jogador da vez
** Parametros:
**      *partida - (Partida) dados da partida atual
*/
void mostrarJogo(Partida *partida) {
    int i;
    
    printf("\n");
    
    for(i = 0; i < partida->qtdMesa; i++) {
        printf("[%d|%d] ", partida->mesa[i].esq, partida->mesa[i].dir);
    }
    
    printf("\n\n[%d] e [%d]\n\n", partida->mesaEsq, partida->mesaDir);
    
    for(i = 0; i <= 27; i++) {
        if(partida->turno == 1) {
            if(partida->p[i].sts == J1) {
                printf("%d:[%d|%d]  ", i, partida->p[i].esq, partida->p[i].dir);
            }
        }
        else if(partida->turno == 2) {
            if(partida->p[i].sts == J2) {
                printf("%d:[%d|%d]  ", i, partida->p[i].esq, partida->p[i].dir);
            }
        }
    }
    printf("\n");
}

/*
** Exibe um menu de acordo com o id informado e le a opcao escolhida pelo usuario
** Parametros:
**      id - (int) identificador do menu a ser exibido
*/
int mostrarMenu(int id) {
    int op;

    switch(id) {
        case 1:
            printf("\n[1] - Nova partida\n");
            printf("[2] - Continuar partida\n");
            printf("[3] - Mostrar pecas nao embaralhadas\n");
            printf("[4] - Mostrar pecas (embaralhadas)\n");
            printf("[5] - Regras\n");
            printf("[6] - Admin\n");
            printf("[0] - Sair\n");
            break;
        case 2:
            printf("\n[1] - Visualizar Status das pecas\n");
            printf("[0] - Retornar\n");
            break;
        case 3:
            printf("\n[1] - Preparacao para o jogo\n");
            printf("[2] - Inicio\n");
            printf("[3] - Turnos\n");
            printf("[4] - Compras\n");
            printf("[5] - Condicoes de vitoria\n");
            printf("[0] - Sair\n");
            break;
        case 4:
            printf("\n[1] - 1 jogador (CPU)\n");
            printf("[2] - 2 jogadores\n");
            break;
        case 5:
            printf("\n[1] - Jogar\n");
            printf("[2] - Comprar\n");
            printf("[3] - Salvar\n");
            printf("[0] - Sair\n");
            break;
        case 6:
            printf("\n[1] - Preparar jogo\n");
            printf("[2] - Inicio do jogo\n");
            printf("[3] - Turnos\n");
            printf("[4] - Como ganhar\n");
            printf("[5] - Compra/Passar turno\n");
            printf("[0] - Sair\n");
            break;
    }

    printf("\nOpcao: ");
    
    if(scanf("%d", &op) != 1) {
        op = -1;
    }
    while(getchar() != '\n');

    return op;
}
