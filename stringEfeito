#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	struct timespec ts;
	ts.tv_sec = 0;          
    ts.tv_nsec = 200000000;
    char nome[50];
    printf("Digite um nome:");
    scanf("%50[^\n]", nome);
    int contagem = strlen(nome);
    int contagem2= contagem;
    int i, j;
    for(i = contagem; i >= 0; i--){ 
        for(j = 0; j < contagem2-i; j++){
            printf("%c", nome[j]);
            nanosleep(&ts, NULL);
        }
        puts("");
    }
    contagem2--;
    for(i = 0; i < contagem; i++){ 
        for(j = 0; j < contagem2; j++){
            printf("%c", nome[j]);
            nanosleep(&ts, NULL);
		}
        contagem2--;
        puts("");
    }
    return 0;
}
