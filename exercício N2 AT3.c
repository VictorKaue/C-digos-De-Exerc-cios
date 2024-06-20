// Crie as funções de criação, delete e de impressão para a structs Aluno e Livro 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX 100 
typedef struct _Livro 
{ 
    char titulo[MAX]; 
    int quanti_pag; 
    float preco; 
}livro; 
 
typedef struct _Aluno 
{ 
    char nome[MAX]; 
    int idade; 
    livro *livro_fav; 
}aluno; 
 
livro *create_livro(char *nome, int quanti, float preco){ 
     
    livro *l = calloc(1, sizeof(livro)); 
    strcpy(l->titulo, nome); 
    l->quanti_pag = quanti; 
    l->preco = preco; 
    return l; 
} 
 
livro *copy_livro(livro){ 
 
} 
 
void display_livro(livro *_Livro){ 
     
    printf("Livro preferido: %s\n", _Livro->titulo); 
 
} 
 
void update_livro(){ //Atualiza o preço de um livro 
     
} 
 
void desaloca_livro(){ 
 
} 
 
aluno *createAluno(char *nome, int idade, livro *Livro){ 
 
    aluno *a = calloc(1, sizeof(aluno)); 
    strcpy(a->nome, nome); 
    a->idade = idade; 
    a->livro_fav =  
} 

int main(){ 
    livro *l = create_livro("Lord of Rings", 280, 129.00); 
    aluno *Bob = createAluno("Bob", 30, l); 
    display_livro(l); 
    return 0; 
} 
