//DOM_HJRV_Model - Projeto Dominó LP2026
//22/09/2026
//Hellen Araujo da Silva, João Vitor Carvalho Magalhaes Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares
//Req09

#ifndef MODEL_H
#define MODEL_H

//Representa o status de uma peca de domino
typedef enum _statusPeca{
    Disp = 'D',
    J1 = '1',
    J2 = '2',
    Mesa = 'M'
} statusPeca;

// Estrutura que representa uma peca de domino
typedef struct stpeca {
    int esq;
    int dir;
    statusPeca sts; // status atual da peca (Disp, J1, J2 ou Mesa)
} Peca;

// Estrutura que representa o estado completo de uma partida
typedef struct stpartida {
    Peca p[28];
    Peca mesa[28];
    int qtd;       
    int turno;      // indica de quem e' a vez de jogar (1 ou 2)
    int mesaEsq;    // valor da extremidade esquerda da mesa
    int mesaDir;    // valor da extremidade direita da mesa
    int qtdMesa;    // quantidade de pecas atualmente na mesa
} Partida;

typedef struct sitjogo
{
	int qtdMesaJogo; //qtd.de pe�as na mesa
	int turnoJogo; //jogador atual
	int jogadorComp; //quantidade de jogadores da partida salva: 1 = contra o computador, 2 = 2 jogadores humanos
	Peca mesaJogo[28];
	int mesaDJogo;
	int mesaEJogo;
	Peca pecasJogo[28]; // registro completo (esq, dir e status) de cada uma das 28 pecas
}Situacao;

void criarPecas(Peca p[]);
void embaralharPecas(Peca p[]);
void distribuirPecas(Peca p[]);
int primeiroLance(Partida *partida);
int comprarPeca(Partida *partida, int jogador);
int realizarJogada(Partida *partida, int jogador, int indicePeca, char lado);
int FimDeJogo(Partida *partida);
int desempatarJogo(Partida *partida);
void salvaJogo(Partida *partida, Situacao *situacao, char TESTEX[]);
int carregaJogo(Partida *partida, Situacao *situacao, char TESTEX[]);
int jogadaPossivel(Partida *partida, int jogador);
int passarTurno(Partida *partida, int jogador);
int escolherMelhorPeca(Partida *partida, char *lado);

#endif
