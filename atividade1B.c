#include<stdio.h>
#include<string.h>
#include<stdlib.h>



typedef struct celula {
int dado;
struct celula *prox;
} celula;

void insere_inicio (celula *le, int x){
celula*p = malloc (sizeof(celula));
p->dado=x;
p->prox = le->prox;
le->prox=p;
}

void insere_antes (celula *le, int x, int y){
celula* ant = le;
celula*p = le->prox;

  while (p != NULL && p->dado != y) {
        ant = p;
        p = p->prox;
    }

    if(p!=NULL){
        celula*new= malloc(sizeof(celula));
        new->dado = x;
        new->prox=p;
        ant->prox=new;
    }
    else{
        celula*new= malloc(sizeof(celula));
        new->dado=x;
        new->prox=NULL;
        ant->prox=new;
    }


}

