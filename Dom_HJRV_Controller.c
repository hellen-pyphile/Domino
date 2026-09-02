//DOM_HJRV_Controller - Projeto Dominó LP2026
//02/09/2026
//Hellen Araujo da Silva, João Vitor Carvalho Magalhães Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares
//Req07, Req14, Req17

#include "Dom_HJRV_Controller.h"
#include "Dom_HJRV_Model.h"
#include "Dom_HJRV_View.h"
#include <stdio.h>

void iniciarJogo() {
    Partida partida;       
    int mesaVisual[28];    
    int op, opadmin, opregras;
    int qtdJogadores;
    int jogo;
    int escolha;
    int indicePeca;
    char lado;

    criarPecas(partida.p); 

    do {
        limparTela();
        
        op = mostrarMenu(1);

        switch(op) {
            case 1:
                limparTela();
                do {
                    qtdJogadores = mostrarMenu(4);
                    
                    if (qtdJogadores != 1 && qtdJogadores != 2) {
                        mostrarMensagem("Quantidade de jogadores invalida.\n");
                        pause();
                        limparTela();
                    }
                } while(qtdJogadores != 1 && qtdJogadores != 2);
                
                criarPecas(partida.p);
                embaralharPecas(partida.p);
                distribuirPecas(partida.p);
                
                partida.mesaEsq = -1;
                partida.mesaDir = -1;
                partida.qtdMesa = 0;

                mostrarMensagem("Pecas criadas, embaralhadas e distribuidas.\n");
                pause();
                partida.turno = primeiroLance(&partida);
                
                jogo = 1;
                
                while(jogo == 1) {
                    limparTela();
                    
                    printf("Jogador: %d\n", partida.turno);
                    mostrarJogo(&partida);
                    escolha = mostrarMenu(5);
                    
                    if(escolha == 0) {
                        jogo = 0;
                    }
                    else if(escolha == 2) {
                        if(comprarPeca(&partida, partida.turno) == 1) {
                            mostrarMensagem("Comprada\n");
                        }
                        else {
                            mostrarMensagem("Vazia\n");
                        }
                        pause();
                    }
                    else if(escolha == 1) {
                        printf("\nIndice da peca: ");
                        if(scanf("%d", &indicePeca) != 1) {
                            indicePeca = -1;
                        }
                        while(getchar() != '\n');
                        
                        printf("\nLado (E ou D): ");
                        if(scanf(" %c", &lado) != 1) {
                            lado = 'X';
                        }
                        while(getchar() != '\n');
                        
                        if(realizarJogada(&partida, partida.turno, indicePeca, lado) == 1) {
                            
                            if(FimDeJogo(&partida) == 1) {
                                mostrarMensagem("\nJogador 1 Venceu!\n");
                                jogo = 0;
                                pause();
                            }
                            else if(FimDeJogo(&partida) == 2) {
                                mostrarMensagem("\nJogador 2 Venceu!\n");
                                jogo = 0;
                                pause();
                            }
                            else {
                                if(partida.turno == 1) {
                                    partida.turno = 2;
                                }
                                else if(partida.turno == 2) {
                                    partida.turno = 1;
                                }
                            }
                        }
                        else {
                            mostrarMensagem("Invalida\n");
                            pause();
                        }
                    }
                }
                break;
                
            case 2:
                limparTela();
                criarPecas(partida.p);
                mostrarPecas(partida.p);
                pause();
                break;

            case 3:
                limparTela();
                criarPecas(partida.p);
                embaralharPecas(partida.p);
                mostrarPecas(partida.p);
                pause();
                break;

            case 4:
                do {
                    limparTela();
                    opregras = mostrarMenu(6);

                    switch(opregras) {
                        case 1:
                            limparTela();
                            mostrarMensagem("- O jogo pode ser jogado entre 2 jogadores ou contra o computador\n");
                            mostrarMensagem("- Cada jogador deve comprar 7 pecas\n");
                            pause();
                            break;
                        
                        case 2:
                            limparTela();
                            mostrarMensagem("- O jogador com a carroca/bucha de 6 deve iniciar o jogo\n");
                            mostrarMensagem("- Caso nenhum jogador tenha a carroca/bucha de 6, sera priorizada a maior carroca/bucha\n");
                            mostrarMensagem("- No caso de nenhum jogador possuir uma carroca/bucha, sera considerada a maior soma (Ex: [6|5] -> 6 + 5 = 11) \n");
                            pause();
                            break;
                        
                        case 3:
                            limparTela();
                            mostrarMensagem("- Os turnos devem ser alternados\n");
                            // ????
                            pause();
                            break;
                            
                        case 4:
                            limparTela();
                            mostrarMensagem("- Ganha o jogador que jogar esvaziar sua mao primeiro\n");
                            mostrarMensagem("- Em caso de jogo fechado \n");
                            mostrarMensagem("\t - Ganha o jogador com menos pecas\n");
                            mostrarMensagem("\t - Em caso de empate no numero de pecas, considera a mao com a menor soma (Ex: [1|0] -> 1 + 0 = 1)\n"); //verificar regra
                            mostrarMensagem("- O empate ocorre caso nenhum dos criterios acima sejam cumpridos");
                            pause();
                            break;
                        
                        case 5:
                            limparTela();
                            mostrarMensagem("- Caso nao possa fazer uma jogada, o jogador deve comprar ate ter uma peca que possibilite que ele continue o jogo\n");
                            mostrarMensagem("- O jogador pode optar por comprar uma peca como blefe\n");
                            mostrarMensagem("- Caso as pecas do monte acabem, o jogador que nao puder fazer uma jogada deve passar a vez\n");
                            pause();
                            break;
                    }
                } while(opregras != 0);
                break;

            case 5:
                do {
                    limparTela();
                    opadmin = mostrarMenu(2);

                    switch(opadmin) {
                        case 1:
                            limparTela();
                            mostrarStatus(partida.p);
                            pause();
                            break;
                        
                        case 2:
                            limparTela();
                            limparMesa(mesaVisual); 
                            mostrarMesa(mesaVisual);
                            pause();
                            break;
                            
                        case 0:
                            break;
                            
                        default:
                            mostrarMensagem("\nOpcao invalida.\n");
                            pause();
                    }
                } while(opadmin != 0);
                break;

            case 0:
                mostrarMensagem("\nSaindo.\n");
                break;

            default:
                mostrarMensagem("\nOpcao invalida.\n");
                pause();
        }

    } while(op != 0);
}