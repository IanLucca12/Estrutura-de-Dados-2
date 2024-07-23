#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p) {
    if (p->prox == NULL) {
        return 0;
    }

    celula *depois = p->prox;
    p->prox = depois->prox;
    int dado = depois->dado;
    free(depois);
    return dado;
}

void remove_elemento(celula *le, int x) {
    celula *p = le;
    while (p->prox != NULL) {
        if (p->prox->dado == x) {
            celula *temp = p->prox;
            p->prox = temp->prox;
            free(temp);
        } else {
            p = p->prox;
        }
    }
}

void remove_todos_elementos(celula *le, int x) {
    celula *p = le;
    while (p != NULL && p->prox != NULL) {
        if (p->prox->dado == x) {
            celula *temp = p->prox;
            p->prox = temp->prox;
            free(temp);
        } else {
            p = p->prox;
        }
    }
}


