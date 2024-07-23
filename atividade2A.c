#include<stdio.h>
#include<stdlib.h>

int main() {
    int *vetor = calloc(128000, sizeof(int));
    if (vetor == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    int mval = 0;
    int valor;

    while(scanf("%d", &valor) != EOF) {
        vetor[valor] += 1;
        if(vetor[mval] < vetor[valor])
            mval = valor;
    }

    printf("%d\n", mval);

    free(vetor);
    return 0;
}
