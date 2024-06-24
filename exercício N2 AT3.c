#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int pergaminho_verificador;
    char pergaminho_nome[4][28];

    int espadas_verificador;
    int espadas_valores[4];
    char espadas_nome[4][28];

    int escudos_verificador;
    int escudo_valores[4];
    char escudo_nome[4][28];
}inventario;


typedef struct{
    char nome[20];
    char classe[20];
    int vida;
    int ataque;
    inventario *_inventario;
}personagem_atributos;

inventario *criar_inventario(){
    inventario *a = calloc(1,sizeof(inventario));
    strcpy(a->escudo_nome, "Espada de madeira");
    strcpy(a->escudo_nome, "Espada de madeira refinada");
    strcpy(a->escudo_nome, "Espada de cobre");
    strcpy(a->escudo_nome, "Espada de ferro");

    strcpy(a->escudo_nome[0][28], "Espada de madeira");
    strcpy(a->escudo_nome[1][28], "Espada de madeira refinada");
    strcpy(a->escudo_nome[2][28], "Espada de cobre");
    strcpy(a->escudo_nome[3][28], "Espada de ferro");

    return a;
}

void desalloc(){

    
}

personagem_atributos* criar_personagem(){

    return ;
}

int main(){
    inventario *a = criar_inventario();


    return 0;
}
