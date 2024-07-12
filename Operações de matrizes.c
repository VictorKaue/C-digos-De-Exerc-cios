#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double **matriz;
    int linhas;
    int colunas;
}Matrizes;

Matrizes *alocar_matriz(int tamanho);
void desalocar_matriz(Matrizes **matrizes, int desalocar);

void soma_matrizes(Matrizes *Matrizes);

int main(){
    int operacao,quanti_matriz;
    

    printf("digite qual operação de matrizes deseja realizar\n[1] Soma\n[2] Subtração\n [3] Multiplicação\n [4] Divisão\n [5] transpor a matriz\n");
    scanf("%d", &operacao);
    printf("Digite com quantas matrizes deseja fazer a operação: ");
    scanf("%d",&quanti_matriz);
    Matrizes *matrizes = alocar_matriz(quanti_matriz);
    if(matrizes==NULL){
        printf("Erro ao alocar matrizes\n");
        return 1;
    }
    




    return 0;
}

Matrizes *alocar_matriz(int tamanho){ 
    int i,j,k,l;
    Matrizes *matrizes = (Matrizes *)calloc(tamanho, sizeof(Matrizes));
        if(matrizes == NULL){
            desalocar_matriz(&matrizes, 0);
            printf("Erro ao alocar memória para a struct!\n");
            return NULL;
        }
    for(i=0; i<tamanho; i++){
        printf("Digite a quantidade de linhas para a %dª matriz: ");
        scanf("%d", &matrizes[i].linhas);
        printf("digite a quantidade de colunas para a %dª matriz: ");
        scanf("%d", &matrizes[i].colunas); 
        matrizes[i].matriz = (double **)calloc(matrizes[i].linhas,sizeof(double *));
        if(matrizes[i].matriz == NULL){
            desalocar_matriz(&matrizes, 1);
            printf("Erro ao alocar memória para linhas da matriz %dª", i);
            return NULL;
        }
        for(j=0; j<matrizes[i].linhas; j++){
            matrizes[i].matriz[j] = (double *)calloc(matrizes[i].colunas, sizeof(double));
            if(matrizes[i].matriz[j] == NULL){
                desalocar_matriz(&matrizes, 2);
                printf("Erro ao alocar memória para as colunas da matriz %dª");
                return NULL;
            }
        }
    }
    return matrizes;
}

void desalocar_matriz(Matrizes **matrizes, int desalocar){
    int i,j;
    Matrizes *ponteiro = *matrizes;
    int tamanho = sizeof(*ponteiro)/sizeof(Matrizes);
    switch(desalocar){ //escolha para desalocar só a struct ou as linhas e colunas da matriz.
        case 1:
            for(i=0; i < tamanho; i++){
                free(ponteiro[i].matriz);
            }
            break;
        case 2:
            for(i=0; i < tamanho; i++){
                for(j=0; j < ponteiro[i].linhas; j++){
                    free(ponteiro[i].matriz[j]);
                }
                free(ponteiro[i].matriz);
            }
            break;
    }
    free(ponteiro);
    *matrizes = NULL;
    
}