#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"
#define tamanho 28

void criarPecas(Peca p[])
    {
        int i, j;
        int c = 0;

        for(i = 0; i <= 6; i++)
            {
                for (j = i; j <= 6; j++)
                {
                    p[c].esq = i;
                    p[c].dir = j;
                    c++;
                }
            }

    }

void mostrarPecas(Peca p[])
    {
        int c;
        int atual = 0;

        for(c = 0; c <= 27; c++)
            {
                if (p[c].esq > atual)
                    {
                        printf("\n");
                        atual = p[c].esq;
                    }

                printf("[%d|%d] ", p[c].esq, p[c].dir);
            }
    }

//Function to shuffle the pieces
void embaralharPecas(Peca p[])
    {
        int i,j;
        Peca temp;
        srand((unsigned int)time(NULL));
        for(i = 0; i < tamanho; i++) {
            j = rand() % 28;
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
        }
        mostrarPecas(p);
    }

void limparTela()
    {
        #if defined(_WIN32) || defined(_WIN64)
            system("cls");
        #elif defined(__linux__) || defined(__unix__)
            system("clear");
        #endif
    }

void pause()
    {
        #if defined(_WIN32) || defined(_WIN64)
            system("pause");
        #elif defined(__linux__) || defined(__unix__)
            printf("\n\nPressione Enter para continuar...");
            getchar();
        #endif
    }
 
 