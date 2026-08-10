#include <stdio.h>
#include "types.h"


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

                printf("[%d]|[%d] ", p[c].esq, p[c].dir);
            }
    }