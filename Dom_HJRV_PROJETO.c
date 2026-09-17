//DOM_HJRV_PROJETO - Projeto Dominó LP2026
//02/09/2026
//Hellen Araujo da Silva, João Vitor Carvalho Magalhaes Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares

#include <stdlib.h>
#include <time.h>
#include "Dom_HJRV_Controller.h"

/*
** Funcao principal do programa: inicializa a semente de numeros aleatorios
** e chama o Controller para iniciar o jogo
** Parametros:
**      (nenhum)
*/
int main() {
    srand((unsigned int)time(NULL));
    iniciarJogo();
    return 0;
}