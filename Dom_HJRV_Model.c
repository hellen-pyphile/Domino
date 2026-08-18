//DOM_HJRV_Model - Projeto Dominó LP2026
//18/08/2026
//Hellen Araújo da Silva, João Vítor Carvalho Magalhães Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares

#include <stdlib.h>
#include "Dom_HJRV_Model.h"

void criarPecas(Status p[]) {
    int i, j;
    int c = 0;

    for(i = 0; i <= 6; i++) {
        for (j = i; j <= 6; j++) {
            p[c].Peca.esq = i;
            p[c].Peca.dir = j;
            p[c].status = 'D';
            c++;
        }
    }
}

void embaralharPecas(Status p[]) {
    int i, j;
    Status temp;
    
    for(i = 0; i < 28; i++) {
        j = rand() % 28;
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
    }
}