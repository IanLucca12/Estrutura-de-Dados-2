#include<stdio.h>
#include<string.h>
#include<stdlib.h>



typedef struct celula {
int dado;
struct celula *prox;
} celula;


 celula *busca (celula *le, int x){
celula *p = le;
    while (p->prox != NULL && p->prox->dado != x) {
         p = p->prox;
}
return p->prox ;
}


 celula *busca_rec(celula *le, int x) {
    celula *p = le->prox;
    if (p == NULL) {
        return NULL;
    } else if (p->dado == x) {
        return p;
    } else {
        return busca_rec(p, x);
    }
}

