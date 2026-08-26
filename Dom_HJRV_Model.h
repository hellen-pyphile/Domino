//DOM_HJRV_Model - Projeto Dominó LP2026
//18/08/2026
//Hellen Araujo da Silva, João Vitor Carvalho Magalhães Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares

#ifndef MODEL_H
#define MODEL_H

typedef struct stpeca {
    int esq;
    int dir;
    char status;
} Peca;

void criarPecas(Peca p[]);
void embaralharPecas(Peca p[]);
void mostrarPecas(Peca p[]);

#endif