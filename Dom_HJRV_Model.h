//DOM_HJRV_Model - Projeto Dominó LP2026
//18/08/2026
//Hellen Araujo da Silva, João Vitor Carvalho Magalhães Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares

#ifndef MODEL_H
#define MODEL_H

typedef enum _statusPeca{
    Disp = 'D', J1 = '1', J2 = '2', Mesa = 'M'
} statusPeca;

typedef struct stpeca {
    int esq;
    int dir;
    statusPeca sts;
} Peca;

typedef struct stpartida {
    Peca p[28];
    int qtd;
    int turno;  
    int mesaEsq;
    int mesaDir;
} Partida;

void criarPecas(Peca p[]);
void embaralharPecas(Peca p[]);
void mostrarPecas(Peca p[]);
void distribuirPecas(Peca p[]);

#endif