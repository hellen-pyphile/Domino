//DOM_HJRV_Model - Projeto Dominó LP2026
//18/08/2026
//Hellen Araujo da Silva, João Vitor Carvalho Magalhães Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares

#include <stdlib.h>
#include "Dom_HJRV_Model.h"

void criarPecas(Peca p[]) {
    int i, j;
    int c = 0;

    for(i = 0; i <= 6; i++) {
        for (j = i; j <= 6; j++) {
            p[c].esq = i;
            p[c].dir = j;
            p[c].sts = Disp;
            c++;
        }
    }
}

void embaralharPecas(Peca p[]) {
    int i, j;
    Peca temp;
    
    for (i = 27; i > 0; i--) {
        j = rand() % (i + 1);
        
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
    }
}

void distribuirPecas(Peca p[]) {
    int i, j;
    
    for (i = 0; i <= 6; i++) {
        p[i].sts = J1;
    }

    for (j = 7; j <= 13; j++) {
        p[j].sts = J2;
    }
}
