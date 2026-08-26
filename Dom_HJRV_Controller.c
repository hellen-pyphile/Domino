//DOM_HJRV_Controller - Projeto Dominó LP2026
//18/08/2026
//Hellen Araujo da Silva, João Vitor Carvalho Magalhães Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares

#include "Dom_HJRV_Controller.h"
#include "Dom_HJRV_Model.h"
#include "Dom_HJRV_View.h"

void iniciarJogo() {
    Peca p[28];
    int op, opadmin;
    int qtdJogadores;

    criarPecas(p);

    do {
        limparTela();
        op = exibirMenu();

        switch(op) {
            case 1:
                limparTela();
                do {
                    qtdJogadores = solicitarJogador();
                    if (qtdJogadores != 1 && qtdJogadores != 2 && qtdJogadores != 3) {
                        mostrarMensagem("Quantidade de jogadores invalida.\n");
                        pause();
                        limparTela();
                    }
                } while(qtdJogadores != 1 && qtdJogadores != 2 && qtdJogadores != 3);
                
                criarPecas(p);
                embaralharPecas(p);
                distribuirPecas(p);
                mostrarMensagem("Pecas criadas e embaralhadas.\n");
                pause();
                break;
            
            case 2:
                limparTela();
                criarPecas(p);
                mostrarPecas(p);
                pause();
                break;

            case 3:
                limparTela();
                criarPecas(p);
                embaralharPecas(p);
                mostrarPecas(p);
                pause();
                break;
                
            case 4:
                do {
                    limparTela();
                    opadmin = menuAdm();

                    switch(opadmin) {
                        case 1:
                            limparTela();
                            mostrarStatus(p);
                            pause();
                            break;
                        
                        case 2:
                            limparTela();
                            mostrarMesa(Mesa[28]);
                            pause();
                            limparTela();
                            limparMesa(Mesa[28]);
                            mostrarMesa(Mesa[28]);
                            
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