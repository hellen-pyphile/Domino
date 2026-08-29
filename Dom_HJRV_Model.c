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

//funcao para determinar qual jogador fara o primeiro lance
int primeiroLance(Partida *partida)
    {
        int i;
        int maior = -1;
        int indiceMaior = -1;
        //verifica se algum jogador possui um duplo, caso possua, o jogador com o maior duplo fara o primeiro lance
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
        //caso nenhum jogador possua um duplo, o jogador com a peca de maior valor fara o primeiro lance
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

//funcao para comprar uma peca do monte
int comprarPeca(Partida *partida, int jogador) {
    int i;
    for(i = 14; i <= 27; i++) {
        if(partida->p[i].sts == Disp) {
            if(jogador == 1) {
                partida->p[i].sts = J1;
            } else {
                partida->p[i].sts = J2;
            }
            return 1; // peca comprada com sucesso  
        }
    }
    return 0; //nenhuma peca disponivel para compra
}

int realizarJogada(Partida *partida, int jogador, int indicePeca, char lado) 
    {
        if(lado == 'E'){

            if(partida->mesaEsq == partida->p[indicePeca].esq)
            {
                partida->mesaEsq = partida->p[indicePeca].dir;
            }

            else if(partida->mesaEsq == partida->p[indicePeca].dir)
                {
                    partida->mesaEsq = partida->p[indicePeca].esq;
                }

            else
                {
                    return 0;
                }
        }

        else if (lado == 'D'){

            if(partida->mesaDir == partida->p[indicePeca].esq)
                {
                    partida->mesaDir = partida->p[indicePeca].dir;
                }

            else if(partida->mesaDir == partida->p[indicePeca].dir)
                {
                    partida->mesaDir = partida->p[indicePeca].esq;
                }

            else    
                {
                    return 0;
                }
        }

        else
        {
            return 0; //jogador digitou algo diferente de 'E' ou 'D'
        }

        partida->p[indicePeca].sts = Mesa;
        partida->mesa[partida->qtdMesa] = partida->p[indicePeca];
        partida->qtdMesa++;
        return 1;
    }   