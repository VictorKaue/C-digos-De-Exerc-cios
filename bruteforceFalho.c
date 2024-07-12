#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50



int main(){
    int i,j;
    char senha[N];
    printf("Digite sua senha: ");
    fgets(senha, N, stdin);
    int tamanho = strlen(senha);
    char bruteforce[tamanho];
    for(i=0; i<tamanho; i++){
        for(j=0; j<256; j++){
            if((unsigned)j == (unsigned)senha[i]){
                bruteforce[i] = j;
                printf("char: %c || num: %d\n",j, j);
                break;
            }
        }
    }
    for (int i = 0; i < tamanho; i++)
    {
        printf("1-%c\n", senha[i]);
    }
    puts("");
    for (int i = 0; i < tamanho; i++)
    {
        printf("1-%c\n", bruteforce[i]);
    }

    return 0;
}
