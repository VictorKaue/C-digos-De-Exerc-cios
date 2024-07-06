#include <stdio.h>
#include <stdlib.h>


void imprimir_representacao();
void imprimir_matriz(char matriz[][3]);
void escolher_posicao(char matriz[][3], int posicao, char letra, int *i);
int verificacao_de_vitoria(char matriz[][3],char letra);
void limpar_tela();

int main(){
    char matriz[3][3], letra;
    int posicao;
    int i,j;
    for(i=0; i < 3; i++)
    {
        for(j=0; j < 3; j++){
            matriz[i][j] = ' '; //atribuindo caractere de espaço para retirar lixo de memória
        }
    }
    
    printf("Digite a posição de acordo com a tabela mostrada abaixo\n");
    imprimir_representacao();
    i = 0;
    while(i < 9){
        if(i%2==0){
            puts("Vez do jogador X");
            printf("Digite a posição onde queira colocar o X: ");
            scanf("%d",&posicao);
            letra = 'X';
        }else{
            puts("Vez do jogardor O");
            printf("Digite a posição onde queira colocar o 0: ");
            scanf("%d",&posicao);
            letra = 'O';
        }
        limpar_tela();
        escolher_posicao(matriz, posicao, letra, &i);
        imprimir_matriz(matriz);
        if(verificacao_de_vitoria(matriz, letra)){
            printf("O %c ganhou!\n", letra);
            break;
        }
        if(i > 8){
            puts("Deu velha!");
        }

    }

    return 0;
}

void imprimir_representacao(){
    puts("");
    puts("1 | 2 | 3");
    puts("----------");
    puts("4 | 5 | 6");
    puts("----------");
    puts("7 | 8 | 9");
}

void imprimir_matriz(char matriz[][3]){
    printf("\n");
    printf("%c | %c | %c\n", matriz[0][0],matriz[0][1],matriz[0][2]);
    printf("----------\n");
    printf("%c | %c | %c\n", matriz[1][0],matriz[1][1],matriz[1][2]);
    printf("----------\n");
    printf("%c | %c | %c\n", matriz[2][0],matriz[2][1],matriz[2][2]);
    printf("----------\n");

}

void escolher_posicao(char matriz[][3], int posicao, char letra, int *i){
    int linha=0, coluna;
    coluna = posicao - 1;
    if(posicao > 3){
        while(coluna > 2){
            coluna -= 3;
            linha++;
        }
    }
    if(matriz[linha][coluna] == ' '){
        matriz[linha][coluna] = letra;
        (*i)++;
    } else{
        puts("Posição já preenchida. Digite outra posição!");
    }
    
}

int verificacao_de_vitoria(char matriz[][3], char letra){
    int linha;
    int coluna;
    for(linha = 0; linha < 3; linha++){
        if(matriz[linha][0] == letra && matriz[linha][1] == letra && matriz[linha][2] == letra){
            return 1;
        }
    }

    for(coluna = 0; coluna < 3; coluna++){
        if(matriz[0][coluna] == letra && matriz[1][coluna] == letra && matriz[2][coluna] == letra){
            return 1;
        }
    }

    if(matriz[0][0] == letra && matriz[1][1] == letra && matriz[2][2] == letra){
        return 1;
    }

    if(matriz[2][0] == letra && matriz[1][1] == letra && matriz[0][2] == letra){
        return 1;
    }
    return 0;
}

void limpar_tela(){
    #ifdef _WIN32_
        system("cls");
    #elif __ANDROID__
        clrscr();
    #else
        system("clear");
    #endif
}