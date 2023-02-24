//Exercício 1 e 2 / João Pedro Moreira Smolinski
//Implementações
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct arv{
	char info;
	struct arv *esq;
	struct arv *dir;
} Arv;

Arv* arv_criavazia(){return NULL;}

Arv* arv_cria(char valor,Arv* esq,Arv* dir){
	Arv *raiz = (Arv*) malloc(sizeof(Arv));
	raiz->info =valor;
	raiz->esq = esq;
	raiz->dir = dir;	
	return raiz;
}

int arv_vazia(Arv* a){
	return (a == NULL);	
}

void arv_imprime_preordem(Arv* a){
	if(!arv_vazia(a)){
		printf("%c\t",a->info);
		arv_imprime_preordem(a->esq);
		arv_imprime_preordem(a->dir);
	}
}

void arv_imprime_simetrica(Arv* a){
	if(!arv_vazia(a)){
		arv_imprime_simetrica(a->esq);
		printf("%c\t",a->info);
		arv_imprime_simetrica(a->dir);
	}
}

void arv_imprime_posordem(Arv *a){
	if(!arv_vazia(a)){
		arv_imprime_posordem(a->esq);
		arv_imprime_posordem(a->dir);
		printf("%c\t",a->info);
	}
}

Arv* arv_libera(Arv* a){
	if(!arv_vazia(a)){
		arv_libera(a->esq);
		arv_libera(a->dir);
		free(a);
	}
	return NULL;
}

Arv* arv_insere(Arv* a, char c){

    if (a == NULL) {
        a = (Arv*)malloc(sizeof(Arv));
        a->info = c;
        a->esq = a->dir = NULL;
    } else if(c < a->info){
        a->esq = arv_insere(a->esq , c);
    } else{
        a->dir = arv_insere(a-> dir, c);
    }
    return a;
}

int main(){

    Arv* tree = arv_criavazia();

    //adição de cada caracter
    tree = arv_insere(tree, 'a');
    tree = arv_insere(tree, 'b');
    tree = arv_insere(tree, 'c');
    tree = arv_insere(tree, 'a');
    tree = arv_insere(tree, '?');
    tree = arv_insere(tree, 'a');
    tree = arv_insere(tree, '?');
    tree = arv_insere(tree, 'b');

    arv_imprime_preordem(tree);
    printf("\n");
    arv_imprime_simetrica(tree);
    printf("\n");
    arv_imprime_posordem(tree);
    printf("\n");


    tree = arv_libera(tree);

    return 0;
}
