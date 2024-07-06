#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int pergaminho_verificador;
    char pergaminho_nome[5][28];

    int espadas_verificador;
    int espadas_valores[5];
    char espadas_nome[5][28];

    int escudos_verificador;
    int escudo_valores[5];
    char escudo_nome[5][28];
}inventario;


typedef struct{
    char nome[20];
    char classe[20];
    int vida;
    int ataque;
    inventario *_inventario;
}personagem_atributos;

inventario *criar_inventario();
void imprimir_inventario(inventario *p);
personagem_atributos* criar_personagem(int op);
void desalocar_inventario(inventario **ptr);
void desalocar_personagem(personagem_atributos **ptr);

int main(){
    int op=1;

    personagem_atributos *personagem = criar_personagem(op);
    
    desalocar_personagem(&personagem);

    return 0;
}

inventario *criar_inventario(){
    inventario *a = calloc(1,sizeof(inventario));
    strcpy(a->espadas_nome[1], "Espada de madeira");
    strcpy(a->espadas_nome[2], "Espada de madeira refinada");
    strcpy(a->espadas_nome[3], "Espada de cobre");
    strcpy(a->espadas_nome[4], "Espada de ferro");

    strcpy(a->escudo_nome[1], "Escudo de madeira");
    strcpy(a->escudo_nome[2], "Escudo de madeira refinado");
    strcpy(a->escudo_nome[3], "Escudo de cobre");
    strcpy(a->escudo_nome[4], "Escudo de ferro");

    a->espadas_valores[0] = 0;
    a->espadas_valores[1] = 1;
    a->espadas_valores[2] = 3;
    a->espadas_valores[3] = 5;
    a->espadas_valores[4] = 10;

    a->escudo_valores[0] = 0;
    a->escudo_valores[1] = 1;
    a->escudo_valores[2] = 3;
    a->escudo_valores[3] = 5;
    a->escudo_valores[4] = 10;
     
    return a;
}
void imprimir_inventario(inventario *p){
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("%s\n",p->escudo_nome[i]);
    }
    for (i = 0; i < 5; i++)
    {
        printf("%s\n",p->espadas_nome[i]);
    }
}

personagem_atributos* criar_personagem(int op){
    personagem_atributos *personagem_principal = calloc(1,sizeof(personagem_atributos));
    switch (op)
    {
    case 1:
    strcpy(personagem_principal->classe, "mago");
    personagem_principal->vida = 15;
    personagem_principal->ataque = 3;
        
        break;
    case 2:
        strcpy(personagem_principal->classe, "Humano");
        personagem_principal->vida=9;
        personagem_principal->ataque=6;
        break;
    case 3:
        strcpy(personagem_principal->classe, "Elfo");
        personagem_principal->vida = 10;
        personagem_principal->ataque = 4;
        break;
        
    default:
        printf("Erro!\n");
        break;
    }
    personagem_principal->_inventario = criar_inventario();
    return personagem_principal;
}

void desalocar_inventario(inventario **ptr){
    inventario *p = *ptr;
    free(p);
    *ptr = NULL;
}

void desalocar_personagem(personagem_atributos **ptr){ 
    personagem_atributos *p = *ptr;
    desalocar_inventario(&((*ptr)->_inventario));
    free(p);
    *ptr = NULL;
}