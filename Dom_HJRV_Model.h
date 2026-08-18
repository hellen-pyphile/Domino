//DOM_HJRV_Model - Projeto Dominó LP2026
//18/08/2026
//Hellen Araújo da Silva, João Vítor Carvalho Magalhães Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares

#ifndef MODEL_H
#define MODEL_H

typedef struct stpeca {
    int esq;
    int dir;
} Peca;

typedef struct ststatus {
    struct stpeca Peca;
    char status;
} Status;

void criarPecas(Status p[]);
void embaralharPecas(Status p[]);

#endif