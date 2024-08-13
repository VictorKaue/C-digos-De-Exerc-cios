#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double **matriz;
    int linhas;
    int colunas;
} Matrizes;

Matrizes *alocar_matriz(int operacao, int tamanho);
Matrizes *alocar_matriz_multiplicacao(int *quanti_matrizes);
void desalocar_matriz(Matrizes **matrizes, int desalocar, int quanti_matrizes);
void atribuir_valores(Matrizes *matrizes, int quanti_matrizes); 
void imprimir_matrizes(Matrizes *matrizes, int quanti_matrizes);
void soma(Matrizes *matrizes, int quanti_matrizes);
void subtracao(Matrizes *matrizes, int quanti_matrizes);
void multiplicacao(Matrizes *matrizes, int quanti_matrizes);

int main() {
    int operacao, quanti_matriz;
    Matrizes *matrizes;
    
    printf("Digite qual operação de matrizes deseja realizar\n[1] Soma\n[2] Subtração\n[3] Multiplicação\n[4] Divisão\n[5] Transpor a matriz\n");
    scanf("%d", &operacao);
    printf("Digite com quantas matrizes deseja fazer a operação: ");
    scanf("%d", &quanti_matriz);
    quanti_matriz++;

    if (operacao == 3) {
        matrizes = alocar_matriz_multiplicacao(&quanti_matriz);
    } else {
        matrizes = alocar_matriz(operacao, quanti_matriz);
    }
    
    if (matrizes == NULL) {
        printf("Erro ao alocar matrizes\n");
        return 1;
    }

    atribuir_valores(matrizes, quanti_matriz);

    switch (operacao) {
        case 1:
            soma(matrizes, quanti_matriz);
            imprimir_matrizes(matrizes, quanti_matriz);
            break;
        case 2:
            subtracao(matrizes, quanti_matriz);
            imprimir_matrizes(matrizes, quanti_matriz);
            break;
        case 3:
            multiplicacao(matrizes, quanti_matriz);
            imprimir_matrizes(matrizes, quanti_matriz);
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
    
    desalocar_matriz(&matrizes, 2, quanti_matriz);

    return 0;
}

Matrizes *alocar_matriz(int operacao, int tamanho) { 
    int i, j;
    int linha, coluna;
    Matrizes *matrizes = (Matrizes *)calloc(tamanho, sizeof(Matrizes));
    if (matrizes == NULL) {
        printf("Erro ao alocar memória para a struct!\n");
        return NULL;
    }

    for (i = 0; i < tamanho; i++) {
        switch (operacao) {
            case 1:
            case 2:
                if (i == 0) {
                    printf("Digite quantas linhas e quantas colunas para cada matriz: ");
                    scanf("%d %d", &linha, &coluna);
                }
                matrizes[i].linhas = linha;
                matrizes[i].colunas = coluna;
                break;
            default:
                printf("Digite a quantidade de linhas para a %dª matriz: ", i + 1);
                scanf("%d", &matrizes[i].linhas);
                printf("Digite a quantidade de colunas para a %dª matriz: ", i + 1);
                scanf("%d", &matrizes[i].colunas);
                break;
        }

        matrizes[i].matriz = (double **)calloc(matrizes[i].linhas, sizeof(double *));
        if (matrizes[i].matriz == NULL) {
            desalocar_matriz(&matrizes, 0, tamanho);
            printf("Erro ao alocar memória para linhas da matriz %dª", i + 1);
            return NULL;
        }

        for (j = 0; j < matrizes[i].linhas; j++) {
            matrizes[i].matriz[j] = (double *)calloc(matrizes[i].colunas, sizeof(double));
            if (matrizes[i].matriz[j] == NULL) {
                desalocar_matriz(&matrizes, 1, tamanho);
                printf("Erro ao alocar memória para as colunas da matriz %dª", i + 1);
                return NULL;
            }
        }
    }
    return matrizes;
}

Matrizes *alocar_matriz_multiplicacao(int *quanti_matrizes) {
    int i, j;

    Matrizes *matrizes = (Matrizes *)calloc(*quanti_matrizes, sizeof(Matrizes));
    if (matrizes == NULL) {
        printf("Erro ao alocar memória para a struct!\n");
        return NULL;
    }

    for (i = 0; i < *quanti_matrizes; i++) {
        if (i == 0) {
            printf("Digite a quantidade de linhas para a %dª matriz: ", i + 1);
            scanf("%d", &matrizes[i].linhas);
            printf("Digite a quantidade de colunas para a %dª matriz: ", i + 1);
            scanf("%d", &matrizes[i].colunas);
        } else if (i >= 2) {
            matrizes[i].linhas = matrizes[i - 2].linhas;
            matrizes[i].colunas = matrizes[i - 1].colunas;
        } else {
            printf("Digite a quantidade de colunas para a %dª matriz: ", i + 1);
            scanf("%d", &matrizes[i].colunas);
        }

        matrizes[i].matriz = (double **)calloc(matrizes[i].linhas, sizeof(double *));
        if (matrizes[i].matriz == NULL) {
            desalocar_matriz(&matrizes, 0, *quanti_matrizes);
            printf("Erro ao alocar memória para linhas da matriz %dª", i + 1);
            return NULL;
        }

        for (j = 0; j < matrizes[i].linhas; j++) {
            matrizes[i].matriz[j] = (double *)calloc(matrizes[i].colunas, sizeof(double));
            if (matrizes[i].matriz[j] == NULL) {
                desalocar_matriz(&matrizes, 1, *quanti_matrizes);
                printf("Erro ao alocar memória para as colunas da matriz %dª", i + 1);
                return NULL;
            }
        }
    }
    return matrizes;
}

void desalocar_matriz(Matrizes **matrizes, int desalocar, int quanti_matrizes) {
    int i, j;
    Matrizes *ponteiro = *matrizes;

    switch (desalocar) {
        case 1:
            for (i = 0; i < quanti_matrizes; i++) {
                if (ponteiro[i].matriz != NULL) {
                    free(ponteiro[i].matriz);
                }
            }
            break;
        case 2:
            for (i = 0; i < quanti_matrizes; i++) {
                if (ponteiro[i].matriz != NULL) {
                    for (j = 0; j < ponteiro[i].linhas; j++) {
                        free(ponteiro[i].matriz[j]);
                    }
                    free(ponteiro[i].matriz);
                }
            }
            break;
    }
    free(ponteiro);
    *matrizes = NULL;
}

void atribuir_valores(Matrizes *matrizes, int quanti_matrizes) {
    int i, j, k, op;
    srand(time(NULL));
    
    do {
        printf("\nDigite [1] para atribuir os valores manualmente\nDigite [2] para atribuir valores aleatoriamente\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                for (k = 0; k < quanti_matrizes; k++) {
                    for (i = 0; i < matrizes[k].linhas; i++) {
                        for (j = 0; j < matrizes[k].colunas; j++) {
                            printf("%dª matriz | %dª linha | %dª coluna\n", k + 1, i + 1, j + 1);
                            scanf("%lf", &matrizes[k].matriz[i][j]);
                        }
                    }
                }
                break;
            case 2:
                for (k = 0; k < quanti_matrizes; k++) {
                    for (i = 0; i < matrizes[k].linhas; i++) {
                        for (j = 0; j < matrizes[k].colunas; j++) {
                            matrizes[k].matriz[i][j] = rand() % 100 + 1;
                        }
                    }
                }
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (op != 1 && op != 2);
}

void imprimir_matrizes(Matrizes *matrizes, int quanti_matrizes) {
    int k, i, j;
    for (k = 0; k < quanti_matrizes; k++) {
        printf("%dª matriz:\n", k + 1);
        for (i = 0; i < matrizes[k].linhas; i++) {
            for (j = 0; j < matrizes[k].colunas; j++) {
                printf("%4.2lf ", matrizes[k].matriz[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void soma(Matrizes *matrizes, int quanti_matrizes) {
    int i, j, k;
    for (i = 0; i < matrizes[0].linhas; i++) {
        for (j = 0; j < matrizes[0].colunas; j++) {
            matrizes[quanti_matrizes - 1].matriz[i][j] = 0;
            for (k = 0; k < quanti_matrizes - 1; k++) {
                matrizes[quanti_matrizes - 1].matriz[i][j] += matrizes[k].matriz[i][j];
            }
        }
    }
}

void subtracao(Matrizes *matrizes, int quanti_matrizes) {
    int i, j, k;
    for (i = 0; i < matrizes[0].linhas; i++) {
        for (j = 0; j < matrizes[0].colunas; j++) {
            if (quanti_matrizes > 1) {
                matrizes[quanti_matrizes - 1].matriz[i][j] = matrizes[0].matriz[i][j];
                for (k = 1; k < quanti_matrizes - 1; k++) {
                    matrizes[quanti_matrizes - 1].matriz[i][j] -= matrizes[k].matriz[i][j];
                }
            }
        }
    }
}

void multiplicacao(Matrizes *matrizes, int quanti_matrizes) {
    int i, j, k, l;
    if (quanti_matrizes < 2) {
        printf("Número insuficiente de matrizes para multiplicação.\n");
        return;
    }

    for (k = 0; k < quanti_matrizes - 1; k += 2) {
        for (i = 0; i < matrizes[k].linhas; i++) {
            for (j = 0; j < matrizes[k + 1].colunas; j++) {
                matrizes[k + 2].matriz[i][j] = 0;
                for (l = 0; l < matrizes[k].colunas; l++) {
                    matrizes[k + 2].matriz[i][j] += matrizes[k].matriz[i][l] * matrizes[k + 1].matriz[l][j];
                }
            }
        }
    }
}