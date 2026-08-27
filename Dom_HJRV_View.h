//DOM_HJRV_View - Projeto Dominó LP2026
//18/08/2026
//Hellen Araujo da Silva, João Vitor Carvalho Magalhães Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares

#ifndef VIEW_H
#define VIEW_H

#include "Dom_HJRV_Model.h"

void mostrarPecas(Peca p[]);
int solicitarJogador();
void limparTela();
void pause();
int exibirMenu();
int solicitarJogador();
void mostrarStatus(Peca p[]);
void mostrarMensagem(const char* msg);
void limparMesa(int vetorMesa[28]);
void mostrarMesa(int vetorMesa[28]);
int menuAdm();
int menuRegras()

#endif