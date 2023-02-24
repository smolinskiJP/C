//Exercício 4 / João Pedro Moreira Smolinski
//Função que faz histograma de ocorrencias
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct arv{
	char info;
    int ocorrencias;
	struct arv *esq;
	struct arv *dir;
} Arv;

Arv* arv_criavazia(){return NULL;}

Arv* arv_cria(char valor,Arv* esq,Arv* dir){
	Arv *raiz = (Arv*) malloc(sizeof(Arv));
	raiz->info =valor;
    raiz->ocorrencias = 1;
	raiz->esq = esq;
	raiz->dir = dir;	
	return raiz;
}

int arv_vazia(Arv* a){
	return (a == NULL);	
}

void arv_imprime_simetrica(Arv* a){
    int i;
	if(!arv_vazia(a)){
		arv_imprime_simetrica(a->esq);
        for (i = 0; i < a->ocorrencias; i++){
		    printf("%c   ",a->info);
        }
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
        a->ocorrencias = 1;
    } else if(c < a->info){
        a->esq = arv_insere(a->esq , c);
    } else if (c > a->info){
        a->dir = arv_insere(a-> dir, c);
    } else {
        a->ocorrencias++;
    }
    return a;
}

void arv_histH(Arv* a){
    int i;
	if(!arv_vazia(a)){
		arv_histH(a->esq);
		printf("%c   ",a->info);
        for (i = 0; i < a->ocorrencias; i++){
            printf("▀");
        }
        printf("%i\n", a->ocorrencias);
		arv_histH(a->dir);
	}
}

int arv_moda(Arv * a, int moda){
    if(a==NULL) return 0;
    moda = arv_moda(a->esq, moda);
    moda = arv_moda(a->dir, moda);
    if(moda<a->ocorrencias) return a->ocorrencias;
    return moda;
}

void arv_histV(Arv* a, int maior){
    int i = maior;
    if (!arv_vazia(a)){
        arv_histV(a->esq, i);
        if (a->ocorrencias > i) printf("▀ "); //se for  maior imprime uma unidade
        if (a->ocorrencias <= i) printf("  "); //se for menor imprime espaço
        arv_histV(a->dir, i);
    }
}

void arv_elementos(Arv* a){
    if(!arv_vazia(a)){
		arv_elementos(a->esq);
		printf("%c ",a->info);
		arv_elementos(a->dir);
	}
}

int main(){

    Arv* tree = arv_criavazia();
    int moda = 0, i;

    //adição de cada caracter
    tree = arv_insere(tree, 'a');
    tree = arv_insere(tree, 'b');
    tree = arv_insere(tree, 'c');
    tree = arv_insere(tree, 'a');
    tree = arv_insere(tree, 'a');
    tree = arv_insere(tree, 'a');
    tree = arv_insere(tree, '?');
    tree = arv_insere(tree, 'b');
    tree = arv_insere(tree, 'a');
    tree = arv_insere(tree, 'b');
    tree = arv_insere(tree, 'a');
    tree = arv_insere(tree, 'a');
    tree = arv_insere(tree, 'a');
    tree = arv_insere(tree, 'a');
    tree = arv_insere(tree, '?');
    tree = arv_insere(tree, 'a');

    arv_imprime_simetrica(tree);//Impressão com todos elementos simétricos

    printf("\n");
    printf("\n| - - - - - - - - |\n");
    arv_histH(tree);//histograma horizontal
    printf("\n| - - - - - - - - |\n");

    moda = arv_moda(tree, moda);

    for (i = 0; i <=moda; i++){
        arv_histV(tree, (moda - i));
        printf("\n");
    }
    arv_elementos(tree);
    printf("\n");

    tree = arv_libera(tree);

    return 0;
}
