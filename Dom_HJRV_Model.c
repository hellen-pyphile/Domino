//DOM_HJRV_Model - Projeto Domino LP2026
//22/09/2026
//Hellen Araujo da Silva, Joao Vitor Carvalho Magalhaes Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares
//Req 08, Req 10, Req 11, Req 12, Req15, Req16

#include <stdlib.h>
#include <stdio.h>
#include "Dom_HJRV_Model.h"

/*
** Cria as 28 pecas do domino, preenchendo os valores esquerdo e direito
** de cada uma e marcando-as como disponiveis
** Parametros:
**      p[] - (Peca) array com todas as pecas do jogo
*/
void criarPecas(Peca p[]) {
    int i, j;
    int c = 0;  // indice da peca atual dentro do array p[]

    // percorre todas as combinacoes possiveis de lado esquerdo e direito
    for(i = 0; i <= 6; i++) {
        for (j = i; j <= 6; j++) {
            p[c].esq = i;
            p[c].dir = j;
            p[c].sts = Disp;
            c++;
        }
    }
}

/*
** Embaralha o array de pecas utilizando o algoritmo Fisher-Yates
** Parametros:
**      p[] - (Peca) array com todas as pecas do jogo (por referencia)
*/
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

/*
** Distribui as 14 primeiras pecas do array entre os jogadores 1 e 2
** (7 pecas para cada um), alterando o status de cada peca
** Parametros:
**      p[] - (Peca) array com todas as pecas do jogo (por referencia)
*/
void distribuirPecas(Peca p[]) {
    int i, j;
    
    for (i = 0; i <= 6; i++) {
        p[i].sts = J1;
    }

    for (j = 7; j <= 13; j++) {
        p[j].sts = J2;
    }
}

/*
** Determina qual jogador fara o primeiro lance da partida e realiza
** essa primeira jogada, atualizando a mesa
** Parametros:
**      *partida - (Partida) dados da partida atual (por referencia)
*/
int primeiroLance(Partida *partida)
    {
        int i;
        int maior = -1;       // guarda o maior valor encontrado (duplo ou soma)
        int indiceMaior = -1; // indice da peca com o maior valor encontrado
        
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

		if(partida->p[indiceMaior].sts == J1)
        {
        	partida->turno = 2;
		}
		else if(partida->p[indiceMaior].sts == J2)
		{
        	partida->turno = 1;
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

/*
** Compra uma peca do monte (pecas ainda disponiveis) para o jogador informado
** Parametros:
**      *partida - (Partida) dados da partida atual (por referencia)
**       jogador -    (int) numero do jogador que esta comprando (1 ou 2)
*/
int comprarPeca(Partida *partida, int jogador) {
    int i; 
    for(i = 14; i <= 27; i++) {
        if(partida->p[i].sts == Disp) {
            if(jogador == 1) {
                partida->p[i].sts = J1;
            } else {
                partida->p[i].sts = J2;
            }
            return 1; 
        }
    }
    return 0;
}

/*
** Valida e efetua a jogada de uma peca em uma das extremidades da mesa
** Parametros:
**      *partida    - (Partida) dados da partida atual (por referencia)
**       jogador    -    (int) numero do jogador que esta jogando (1 ou 2)
**       indicePeca -    (int) indice da peca no array de pecas
**       lado       -   (char) lado da mesa em que a peca sera jogada ('E' ou 'D')
*/
int realizarJogada(Partida *partida, int jogador, int indicePeca, char lado) {
    int troca; // variavel auxiliar usada para inverter os lados da peca quando necessario
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

/*
** Verifica as condicoes de fim de jogo (vitoria por batida ou jogo trancado)
** Parametros:
**      *partida - (Partida) dados da partida atual (por referencia)
*/
int FimDeJogo(Partida *partida) {
    int i;
    int qtdJ1 = 0;             // quantidade de pecas restantes na mao do jogador 1
    int qtdJ2 = 0;             // quantidade de pecas restantes na mao do jogador 2
    int pecasDisponiveis = 0;  // quantidade de pecas ainda disponiveis no monte
    int jogadaPossivelJ1 = 0;  // indica se o jogador 1 possui alguma jogada possivel
    int jogadaPossivelJ2 = 0;  // indica se o jogador 2 possui alguma jogada possivel

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

    if(jogadaPossivelJ1 == 0 && jogadaPossivelJ2 == 0) {
        return 3;
    }
    return 0;
}

/*
** Determina o vencedor quando o jogo termina trancado (FimDeJogo retorna 3):
** nenhum dos dois jogadores consegue jogar e o monte esta vazio.
** Criterios, em ordem, conforme as regras do jogo:
**   1) Vence quem tiver menos pecas na mao
**   2) Em caso de empate na quantidade de pecas, vence quem tiver a menor soma dos pontos na mao
**   3) Se nenhum dos criterios acima decidir, o jogo termina empatado
** Parametros:
**      *partida - (Partida) dados da partida atual
** Retorno:
**      1 se o jogador 1 vencer, 2 se o jogador 2 vencer, 0 em caso de empate
*/
int desempatarJogo(Partida *partida) {
    int i;
    int qtdJ1 = 0, qtdJ2 = 0;
    int somaJ1 = 0, somaJ2 = 0;

    for(i = 0; i <= 27; i++) {
        if(partida->p[i].sts == J1) {
            qtdJ1++;
            somaJ1 += partida->p[i].esq + partida->p[i].dir;
        }
        else if(partida->p[i].sts == J2) {
            qtdJ2++;
            somaJ2 += partida->p[i].esq + partida->p[i].dir;
        }
    }

    if(qtdJ1 < qtdJ2) {
        return 1;
    }
    if(qtdJ2 < qtdJ1) {
        return 2;
    }

    if(somaJ1 < somaJ2) {
        return 1;
    }
    if(somaJ2 < somaJ1) {
        return 2;
    }

    return 0;
}

void salvaJogo(Partida *partida, Situacao *situacao, char TESTEX[])
{
	int i;
	
	for(i = 0; i <= 27; i++)
	{
		situacao->pecasJogo[i] = partida->p[i];
		situacao->mesaJogo[i] = partida->mesa[i];
	}
	situacao->turnoJogo = partida->turno;
	situacao->qtdMesaJogo = partida->qtdMesa;
	situacao->mesaDJogo = partida->mesaDir;
	situacao->mesaEJogo = partida->mesaEsq;

	FILE *fp = fopen(TESTEX, "wb"); //grava em modo binario, pois estamos gravando a struct inteira (fwrite), nao texto
	if(fp == NULL)
	{
		printf("Arquivo nao pode ser aberto");
		return;
	}
	
	if(fwrite(situacao, sizeof(Situacao), 1, fp) != 1) 
    {
        printf("Erro na gravacao do arquivo\n");
    }
	fclose(fp);
}

/*
** Le o arquivo gravado por salvaJogo() e reconstroi o estado da partida
** (pecas, mesa, turno e extremidades) a partir dele
** Parametros:
**      *partida - (Partida)  onde o estado recuperado sera restaurado (por referencia)
**      *situacao - (Situacao) estrutura auxiliar usada para ler o arquivo (por referencia)
**       TESTEX[] -   (char)  nome do arquivo a ser lido
** Retorno:
**      1 se o jogo foi carregado com sucesso, 0 caso o arquivo nao exista/nao possa ser lido
*/
int carregaJogo(Partida *partida, Situacao *situacao, char TESTEX[])
{
	int i;

	FILE *fp = fopen(TESTEX, "rb"); //le em modo binario, simetrico ao "wb" usado na gravacao
	if(fp == NULL)
	{
		return 0;
	}

	if(fread(situacao, sizeof(Situacao), 1, fp) != 1)
	{
		fclose(fp);
		return 0;
	}
	fclose(fp);

	/* 
	** restaura cada uma das 28 pecas exatamente como estavam (valores e status),
	** sem depender da ordem em que criarPecas() as gera, pois o embaralhamento
	** ja havia alterado essa ordem antes da gravacao
	*/
	for(i = 0; i <= 27; i++)
	{
		partida->p[i] = situacao->pecasJogo[i];
	}

	partida->qtdMesa = situacao->qtdMesaJogo;
	for(i = 0; i < partida->qtdMesa; i++)
	{
		partida->mesa[i] = situacao->mesaJogo[i];
	}

	partida->turno = situacao->turnoJogo;
	partida->mesaEsq = situacao->mesaEJogo;
	partida->mesaDir = situacao->mesaDJogo;

	return 1;
}

/*
** Verifica se o jogador possui alguma peca que possa ser jogada
** em uma das extremidades atuais da mesa
** Parametros:
**      *partida - (Partida) dados da partida atual
**       jogador -    (int) numero do jogador que sera verificado (1 ou 2)
** Retorno:
**      1 se o jogador possuir alguma jogada possivel, 0 caso contrario
*/
int jogadaPossivel(Partida *partida, int jogador)

    {
        int i;
        statusPeca statusJogador;

        if(jogador == 1)
        {
            statusJogador = J1;
        }
        else
        {
            statusJogador = J2;
        }

        for(i = 0; i <= 27; i++)
        {
            if(partida->p[i].sts == statusJogador)
            {
                if(partida->p[i].esq == partida->mesaEsq || partida->p[i].dir == partida->mesaEsq || partida->p[i].esq == partida->mesaDir || partida->p[i].dir == partida->mesaDir)
                {
                    return 1;
                }
            }
        }

        return 0;
    }