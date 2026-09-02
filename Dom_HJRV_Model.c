//DOM_HJRV_Model - Projeto Dominó LP2026
//02/09/2026
//Hellen Araujo da Silva, João Vitor Carvalho Magalhães Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares
//Req 08, Req 10, Req 11, Req 12, Req15, Req16

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

        //faz as atribuicoes e alteracoes dos valores apos a verificacao
        partida->p[indiceMaior].sts = Mesa;
        partida->mesa[0] = partida->p[indiceMaior];
        partida->mesaEsq = partida->p[indiceMaior].esq;
        partida->mesaDir = partida->p[indiceMaior].dir;
        partida->qtdMesa = 1;

        //valores de return para bucha ou soma
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

//funcao para validar e efetuar a jogada na mesa nas extremidades E ou D
int realizarJogada(Partida *partida, int jogador, int indicePeca, char lado) {
    int troca;
    int i;
    
    if(lado == 'e') {
        lado = 'E';
    }
    else if(lado == 'd') {
        lado = 'D';
    }

    //verifica se a peca mais recente e' do jogador 1 ou 2 para determinar o turno
    if(jogador == 1) {
        if(partida->p[indicePeca].sts != J1) {
            return 0;
        }
    }
    else if(jogador == 2) {
        if(partida->p[indicePeca].sts != J2) {
            return 0;
        }
    }

    //desloca a mesa para inserir a peca na esquerda ou adiciona na direita
    if(lado == 'E'){
        if(partida->mesaEsq == partida->p[indicePeca].esq) {
            partida->mesaEsq = partida->p[indicePeca].dir;
            
            troca = partida->p[indicePeca].esq;
            partida->p[indicePeca].esq = partida->p[indicePeca].dir;
            partida->p[indicePeca].dir = troca;
        }
        else if(partida->mesaEsq == partida->p[indicePeca].dir) {
            partida->mesaEsq = partida->p[indicePeca].esq;
        }
        else {
            return 0;
        }
    }
    else if(lado == 'D'){
        if(partida->mesaDir == partida->p[indicePeca].esq) {
            partida->mesaDir = partida->p[indicePeca].dir;
        }
        else if(partida->mesaDir == partida->p[indicePeca].dir) {
            partida->mesaDir = partida->p[indicePeca].esq;
            
            troca = partida->p[indicePeca].esq;
            partida->p[indicePeca].esq = partida->p[indicePeca].dir;
            partida->p[indicePeca].dir = troca;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }

    //atualizacao do vetor mesa a cada jogada
    partida->p[indicePeca].sts = Mesa;
    if(lado == 'E') {
        for(i = partida->qtdMesa; i > 0; i--) {
            partida->mesa[i] = partida->mesa[i - 1];
        }
        partida->mesa[0] = partida->p[indicePeca];
    }
    else {
        partida->mesa[partida->qtdMesa] = partida->p[indicePeca];
    }
    
    partida->qtdMesa++;
    return 1;
}

//funcao para verificar condicoes de vitoria por batida ou jogo trancado
int FimDeJogo(Partida *partida) {
    int i;
    int qtdJ1 = 0;
    int qtdJ2 = 0;
    int pecasDisponiveis = 0;
    int jogadaPossivelJ1 = 0;
    int jogadaPossivelJ2 = 0;

//conta quantas pecas cada jogador ainda possui em mao
    for(i = 0; i <= 27; i++) {
        if(partida->p[i].sts == J1) {
            qtdJ1++;
        }
        else if(partida->p[i].sts == J2) {
            qtdJ2++;
        }
    }

    if(qtdJ1 == 0) {
        return 1;
    }
    if(qtdJ2 == 0) {
        return 2;
    }

    for(i = 14; i <= 27; i++) {
        if(partida->p[i].sts == Disp) {
            pecasDisponiveis++;
        }
    }

    if(pecasDisponiveis > 0) {
        return 0;
    }
    
//verifica se os jogadores possuem jogadas possiveis nas extremidades
    for(i = 0; i <= 13; i++) {
        if(partida->p[i].sts == J1) {
            if(partida->p[i].esq == partida->mesaEsq || partida->p[i].dir == partida->mesaEsq ||
               partida->p[i].esq == partida->mesaDir || partida->p[i].dir == partida->mesaDir) {
                jogadaPossivelJ1 = 1;
            }
        }
        else if(partida->p[i].sts == J2) {
            if(partida->p[i].esq == partida->mesaEsq || partida->p[i].dir == partida->mesaEsq ||
               partida->p[i].esq == partida->mesaDir || partida->p[i].dir == partida->mesaDir) {
                jogadaPossivelJ2 = 1;
            }
        }
    }

    //implementar soma
    if(jogadaPossivelJ1 == 0 && jogadaPossivelJ2 == 0) {
        return 3;
    }
    return 0;
}