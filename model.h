#ifndef MODEL_H
#define MODEL_H

typedef struct stpeca {
    int esq;
    int dir;
} Peca;

typedef struct ststatus {
    struct stpeca Peca;
    char status;
} Status;

void criarPecas(Peca p[]);
void embaralharPecas(Peca p[]);

#endif