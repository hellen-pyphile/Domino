//DOM_HJRV_PROJETO - Projeto Dominó LP2026
//18/08/2026
//Hellen Araujo da Silva, João Vitor Carvalho Magalhães Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares

#include <stdlib.h>
#include <time.h>
#include "Dom_HJRV_Controller.h"

int main() {
    long long int t = time(NULL);
    srand(t);
    iniciarJogo();
    return 0;
}
