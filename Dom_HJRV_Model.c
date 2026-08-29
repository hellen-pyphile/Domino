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

//funcao para embaralhar as pecas utilizando o algoritmo Fisher-Yates
//ref: https://github.com/JDSherbert/Fisher-Yates-Shuffle
void embaralharPecas(Peca p[])
    {
        int i, j;
        Peca temp;

        for(i = 27; i > 0; i--)
            {
                j = rand() % (i+1);

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

int primeiroLance(Partida *partida)
    {
        int i;
        int maior = -1;
        int indiceMaior = -1;
        
        for(i = 0; i <= 13; i++)
            {
                if(partida->p[i].esq == partida->p[i].dir)
                {
                    if(partida->p[i].esq > maior)
                    {
                        maior = partida->p[i].esq;
                        indiceMaior = i;
                    }
                }
            }

        if(indiceMaior == -1)
        {
            for(i = 0; i <= 13; i++)
            {
                if(partida->p[i].esq + partida->p[i].dir > maior)
                {
                    maior = partida->p[i].esq + partida->p[i].dir;
                    indiceMaior = i;
                }
            }
        }

        partida->p[indiceMaior].sts = Mesa;
        partida->mesa[0] = partida->p[indiceMaior];
        partida->mesaEsq = partida->p[indiceMaior].esq;
        partida->mesaDir = partida->p[indiceMaior].dir;
        partida->qtdMesa = 1;

        if(indiceMaior <= 6)
        {
            return 1;
        }
        else
        {
            return 2;
        }

    }