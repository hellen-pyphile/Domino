#include <stdlib.h>
#include "model.h"

void criarPecas(Peca p[]) {
    int i, j;
    int c = 0;

    for(i = 0; i <= 6; i++) {
        for (j = i; j <= 6; j++) {
            p[c].esq = i;
            p[c].dir = j;
            c++;
        }
    }
}

void embaralharPecas(Peca p[]) {
    int i, j;
    Peca temp;
    
    for(i = 0; i < 28; i++) {
        j = rand() % 28;
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
    }
}