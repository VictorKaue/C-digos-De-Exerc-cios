#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char nome[50];
    int idade;
}pessoa;

int main(){
    pessoa pessoa1[2][2];
    int j;
    for (int i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("Digite o seu nome: ");
            scanf("%50[^\n]", pessoa1[i][j].nome);
            printf("Digite sua idade: ");
            scanf("%d", &pessoa1[i][j].idade);
            fflush(stdin);
        }
        
    }
    for (int i = 0; i < 2; i++)
    {        
        for (j = 0; j < 2; j++)
        {
            printf("Pessoa[%d][%d]:\n",i,j);
            printf("Nome: %s\n", pessoa1[i][j].nome);
            printf("Idade: %d\n", pessoa1[i][j].idade);
        }
        
    }

    return 0;
}
