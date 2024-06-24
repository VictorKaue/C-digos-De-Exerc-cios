#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int pergaminho_verificador;
    char pergaminho_nome[15];

    int espadas_verificador;
    int espadas_valores;
    char espadas_nome[15];

    int escudos_verificador;
    int escudo_valores;
    char escudo_nome[15];
}inventario;


typedef struct{
char nome[20];
    char classe[20];
    int vida;
    int ataque;
    inventario *_inventario;
}personagem_atributos;

inventario *criar_inventario(inventario a){
    strcpy(a.escudo_nome, "");
    return ; 
}

    // strcpy(inv[0].espadas_nome, "Espada de madeira");
    // strcpy(inv[1].espadas_nome, "Espada de madeira refinada");
    // strcpy(inv[2].espadas_nome, "Espada de cobre");
    // strcpy(inv[3].espadas_nome, "Espada de ferro");

personagem_atributos* criar_personagem(){

    return ;
}

int main(){
    

    return 0;
}
