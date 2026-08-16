#include <stdio.h>
#include <stdlib.h>
#include "view.h"

void mostrarPecas(Peca p[]) {
    int c;
    int atual = 0;

    for(c = 0; c <= 27; c++) {
        if (p[c].esq > atual) {
            printf("\n");
            atual = p[c].esq;
        }
        printf("[%d|%d] ", p[c].esq, p[c].dir);
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