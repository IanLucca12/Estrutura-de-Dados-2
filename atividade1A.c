#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct celula {
int dado;
struct celula *prox;
} celula;

void imprime (celula *le){
celula*p;
for(p=le->prox; p!=NULL; p = p->prox){
    printf("%d -> ",p->dado);
}
printf("NULL\n");
}
void imprime_rec (celula *le){

    if (le->prox == NULL){
        printf("NULL\n");}
    else{
        printf("%d -> ",le->prox->dado);
    imprime_rec(le->prox);}
}


