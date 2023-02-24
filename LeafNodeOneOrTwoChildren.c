//Exercício 3 / João Pedro Moreira Smolinski
//contém funções que contam 1/2 filhos ou se é folha
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

void arv_imprime_simetrica(Arv* a){
	if(!arv_vazia(a)){
		arv_imprime_simetrica(a->esq);
		printf("%c\t",a->info);
		arv_imprime_simetrica(a->dir);
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

int arv_conta_doisfilho(Arv *a){

    int total = 0;
    if(!arv_vazia(a->esq)){
        total += arv_conta_doisfilho(a->esq);
    }if (!arv_vazia(a->dir)){
        total += arv_conta_doisfilho(a->dir);
    }
    if ((!arv_vazia(a->esq)) && (!arv_vazia(a->dir))){
        return (total + 1);
    } else {
        return total;
    }
}

int arv_conta_umfilho(Arv *a){

    int total = 0;
    if(!arv_vazia(a->esq)){
        total += arv_conta_umfilho(a->esq);
    }if (!arv_vazia(a->dir)){
        total += arv_conta_umfilho(a->dir);
    }
    if (((arv_vazia(a->esq)) && (!arv_vazia(a->dir))) || ((!arv_vazia(a->esq)) && (arv_vazia(a->dir)))){
        return (total + 1);
    } else {
        return total;
    }
}

int arv_conta_folha(Arv * a){

    int total = 0;
    if (arv_vazia(a)){
        return total;
    } else if (arv_vazia(a->esq) && (arv_vazia(a->dir))){
        return (total + 1);
    } else {
        total += arv_conta_folha(a->esq);
        total += arv_conta_folha(a->dir);
        return total;
    }


}

int main(){

    Arv* tree = arv_criavazia();
    int folhas, umfilho, doisfilhos;

    tree = arv_insere(tree, 'a');
    tree = arv_insere(tree, 'b');
    tree = arv_insere(tree, 'c');
    tree = arv_insere(tree, 'd');
    tree = arv_insere(tree, 'e');
    tree = arv_insere(tree, 'f');
    tree = arv_insere(tree, 'g');
    

    arv_imprime_simetrica(tree);

    folhas = arv_conta_folha(tree);
    printf("\nFolhas = %d", folhas);
    umfilho = arv_conta_umfilho(tree);
    printf("\nUm filho = %d", umfilho);
    doisfilhos = arv_conta_doisfilho(tree);
    printf("\nDois filhos = %d\n", doisfilhos);

    tree = arv_libera(tree);

    return 0;
}
