#include <stdio.h>
#include <unistd.h>

typedef struct {
    int x;
    int y;
    int direcao;
} PosicaoVisitada;

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
            int proxima_direcao = (direcaoatual + 1) % 4;
            for (int k = 0; k < 4; k++) {
                int nova_direcao = (proxima_direcao + k) % 4;
                int obstaculo = 0;

                if (nova_direcao == norte) {
                    obstaculo = matriz[loc_atualx][loc_atualy - 1];
                } else if (nova_direcao == sul) {
                    obstaculo = matriz[loc_atualx][loc_atualy + 1];
                } else if (nova_direcao == leste) {
                    obstaculo = matriz[loc_atualx + 1][loc_atualy];
                } else if (nova_direcao == oeste) {
                    obstaculo = matriz[loc_atualx - 1][loc_atualy];
                }

                if (obstaculo == 0) {
                    direcaoatual = nova_direcao;
                    encontrou_caminho = 1;
                    break;
                }
            }
        }

        if (!encontrou_caminho) {
            visitados_count--;
            loc_atualx = visitados[visitados_count].x;
            loc_atualy = visitados[visitados_count].y;
            direcaoatual = (visitados[visitados_count].direcao + 1) % 4;

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
