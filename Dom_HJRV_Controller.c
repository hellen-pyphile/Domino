//DOM_HJRV_Controller - Projeto Dominó LP2026
//18/08/2026
//Hellen Araujo da Silva, João Vitor Carvalho Magalhães Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares

#include "Dom_HJRV_Controller.h"
#include "Dom_HJRV_Model.h"
#include "Dom_HJRV_View.h"

void iniciarJogo() {
    Partida partida;       
    int mesaVisual[28];    
    int op, opadmin, opregras;
    int qtdJogadores;

    criarPecas(partida.p); 

    do {
        limparTela();
        op = exibirMenu();

        switch(op) {
            case 1:
                limparTela();
                do {
                    qtdJogadores = solicitarJogador();
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
                    opregras = menuRegras();

                    switch(opregras) {
                        case 1:
                            limparTela();
                            mostrarMensagem("Exibicao das regras.\n");
                            pause();
                            break;
                        case 2:
                            limparTela();
                            pause();
                            break;
                        case 3:
                            limparTela();
                            pause();
                            break;
                        case 4:
                            limparTela();
                            pause();
                            break;
                        case 5:
                            limparTela();
                            pause();
                            break;
                        case 0:
                            break;
                    }
                } while(opregras != 0);
                break;

            case 5:
                do {
                    limparTela();
                    opadmin = menuAdm();

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