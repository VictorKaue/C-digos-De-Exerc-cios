#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX 100 
typedef struct 
{ 
    char titulo[MAX]; 
    int quanti_pag; 
    float preco;
}livro; 
 
typedef struct
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
 
livro *copy_livro(livro *_livro){ 
    return create_livro(_livro->titulo, _livro->quanti_pag, _livro->preco);
} 

void display_livro(livro *_Livro){ 
    printf("\nInformações do livro: \n");
    printf("Livro: %s\n", _Livro->titulo); 
    printf("Páginas: %d\n", _Livro->quanti_pag);
    printf("Preço: %.2f\n", _Livro->preco);
} 
 
void update_livro(livro *update1, livro *update2){
    update1->preco = 400.00;
    update2->preco = 200.00;
} 
 
void deallocate_livro(livro **livro_ref){ 
    livro *Livro = *livro_ref;
    free(Livro);
    *livro_ref = NULL;
}

aluno *createAluno(char *nome, int idade, livro *_Livro){ 
    aluno *a = calloc(1, sizeof(aluno)); 
    strcpy(a->nome, nome); 
    a->idade = idade; 
    a->livro_fav =  copy_livro(_Livro);
    return a;
}

void display_aluno(aluno *pessoa){
    printf("\nInformações do Aluno\n");
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %d\n", pessoa->idade);
    printf("Livro favorito: %s\n", pessoa->livro_fav->titulo);
}

void deallocate_aluno(aluno **aluno_ref){
    aluno *Aluno = *aluno_ref;
    free(Aluno);
    *aluno_ref = NULL;
}


int main(){ 
    livro *l = create_livro("Lord of Rings", 280, 129.00); 
    livro *l2 = create_livro("Cálice de Fogo", 300, 70.00);
    aluno *Bob = createAluno("Bob", 30, l);
    aluno *Mariana = createAluno("Mariana", 19, l2);
    display_livro(l);
    display_livro(l2);

    update_livro(l,l2);
    display_aluno(Bob);
    display_aluno(Mariana);

    deallocate_livro(&l);
    deallocate_livro(&l2);
    deallocate_aluno(&Bob);
    deallocate_aluno(&Mariana);

    return 0;
}
