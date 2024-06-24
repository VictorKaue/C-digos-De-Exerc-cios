#include <stdio.h>
#include <stdlib.h>

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

inventario *criar_inventario();

personagem_atributos* criar_personagem();


int main(){
    

    return 0;
}

inventario *criar_inventario();

personagem_atributos* criar_personagem();