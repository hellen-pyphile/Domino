#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "model.h"
#include "view.h"

int main() {
    Peca p[28];
    int op;

    srand(time(NULL));

    do {
        limparTela();

        printf("1 - Nova partida\n");
        printf("2 - Mostrar pecas nao embaralhadas\n");
        printf("3 - Mostras pecas (embaralhadas)\n");
        printf("0 - Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                limparTela();
                criarPecas(p);
                embaralharPecas(p);
                printf("Pecas criadas e embaralhadas.\n");
                pause();
                break;
            
            case 2:
                limparTela();
                criarPecas(p);
                mostrarPecas(p);
                pause();
                break;

            case 3:
                limparTela();
                criarPecas(p);
                embaralharPecas(p);
                mostrarPecas(p);
                pause();
                break;

            case 0:
                printf("\nSaindo.\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
                pause();
        }

    } while(op != 0);

    return 0;
}