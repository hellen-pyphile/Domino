//DOM_HJRV_View - Projeto Dominó LP2026
//22/09/2026
//Hellen Araujo da Silva, João Vitor Carvalho Magalhães Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares

#ifndef VIEW_H
#define VIEW_H

#include "Dom_HJRV_Model.h"

void mostrarPecas(Peca p[]);
void limparTela();
void pause();
void mostrarStatus(Peca p[]);
void mostrarMensagem(const char* msg);
void limparMesa(int vetorMesa[28]);
void mostrarMesa(int vetorMesa[28]);
void mostrarJogo(Partida *partida, int qtdJogadores);
int mostrarMenu(int id);
void mostrarTurno(int jogador, int contraComputador);
int solicitarIndicePeca(void);
char solicitarLado(void);
void mostrarJogadaComputador(int esq, int dir, char lado);
void mostrarCompraComputador(void);
void mostrarPasseComputador(void);

#endif
