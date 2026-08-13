#include <stdio.h>

typedef struct stpeca {
    int esq;
    int dir;
} Peca;

typedef struct ststatus {
    struct stpeca Peca;
    char status;
} Status;
