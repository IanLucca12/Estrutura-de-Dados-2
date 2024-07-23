#include <stdio.h>
#include <unistd.h>

typedef struct {
    int x;
    int y;
    int direcao;
} PosicaoVisitada;

typedef struct {
    int x;
    int y;
} Posicao;

int main() {
    int retorno = 0;
    char caminho[200];
    int i = 0;
    int matriz[50][50] = {{0}};
    PosicaoVisitada visitados[50 * 50];
    int visitados_count = 0;
    int loc_atualx = 25;
    int loc_atualy = 25;

    int norte = 0;
    int sul = 1;
    int leste = 2;
    int oeste = 3;

    int direcaoatual = norte;
    int objetivo_encontrado = 0;
    int limite_caminho = 200;

    Posicao fila[200];
    int front = 0;
    int rear = 0;

    while (!objetivo_encontrado && i < limite_caminho) {

        printf("m\n");
        fflush(stdout);
        scanf("%d", &retorno);

        int encontrou_caminho = 0;

        visitados[visitados_count].x = loc_atualx;
        visitados[visitados_count].y = loc_atualy;
        visitados[visitados_count].direcao = direcaoatual;
        visitados_count++;

        printf("s\n");
        fflush(stdout);
        scanf("%d", &retorno);

        int frente = (retorno >> 3) & 1;
        int direita = (retorno >> 2) & 1;
        int tras = (retorno >> 1) & 1;
        int esquerda = (retorno >> 0) & 1;

        if (frente == 0) {
            caminho[i] = 'm';
            i++;

            if (direcaoatual == norte) {
                loc_atualy--;
            } else if (direcaoatual == sul) {
                loc_atualy++;
            } else if (direcaoatual == leste) {
                loc_atualx++;
            } else if (direcaoatual == oeste) {
                loc_atualx--;
            }

            encontrou_caminho = 1;
        } else {

            front = 0;
            rear = 0;

            Posicao inicio;
            inicio.x = loc_atualx;
            inicio.y = loc_atualy;
            fila[rear] = inicio;
            rear++;

            while (front < rear) {
                Posicao atual = fila[front];
                front++;

                Posicao proximo;

                proximo.x = atual.x;
                proximo.y = atual.y - 1;
                if (proximo.x >= 0 && proximo.x < 50 && proximo.y >= 0 && proximo.y < 50 && matriz[proximo.x][proximo.y] == 0) {
                    fila[rear] = proximo;
                    rear++;
                    matriz[proximo.x][proximo.y] = 1;
                }

                proximo.x = atual.x;
                proximo.y = atual.y + 1;
                if (proximo.x >= 0 && proximo.x < 50 && proximo.y >= 0 && proximo.y < 50 && matriz[proximo.x][proximo.y] == 0) {
                    fila[rear] = proximo;
                    rear++;
                    matriz[proximo.x][proximo.y] = 1;
                }

                proximo.x = atual.x + 1;
                proximo.y = atual.y;
                if (proximo.x >= 0 && proximo.x < 50 && proximo.y >= 0 && proximo.y < 50 && matriz[proximo.x][proximo.y] == 0) {
                    fila[rear] = proximo;
                    rear++;
                    matriz[proximo.x][proximo.y] = 1;
                }

                proximo.x = atual.x - 1;
                proximo.y = atual.y;
                if (proximo.x >= 0 && proximo.x < 50 && proximo.y >= 0 && proximo.y < 50 && matriz[proximo.x][proximo.y] == 0) {
                    fila[rear] = proximo;
                    rear++;
                    matriz[proximo.x][proximo.y] = 1;
                }

                if (matriz[loc_atualx][loc_atualy] == 1) {
                    encontrou_caminho = 1;
                    break;
                }
            }
        }

        if (!encontrou_caminho) {
            visitados_count--;
            loc_atualx = visitados[visitados_count].x;
            loc_atualy = visitados[visitados_count].y;
            direcaoatual = (visitados[visitados_count].direcao - 1 + 4) % 4; // Ajuste da direção para a esquerda

            if (i > 0) {
                i--;
                if (caminho[i] == 'm') {
                    printf("r\n");
                    fflush(stdout);
                    scanf("%d", &retorno);
                    printf("r\n");
                    fflush(stdout);
                    scanf("%d", &retorno);
                } else if (caminho[i] == 'l') {
                    printf("r\n");
                    fflush(stdout);
                    scanf("%d", &retorno);
                } else if (caminho[i] == 'r') {
                    printf("l\n");
                    fflush(stdout);
                    scanf("%d", &retorno);
                }
            }
        }

        sleep(1);
        objetivo_encontrado = (retorno == 4);
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%c\n", caminho[j]);
        fflush(stdout);
        scanf("%d", &retorno);
    }

    return 0;
}
