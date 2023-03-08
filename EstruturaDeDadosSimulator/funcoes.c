#include "funcoes.h"

/*
Funções de lista/fila de prioridade
*/

//cria
Lista* lst_cria(){
    return NULL;
}

//insere ordenado
Lista *lst_insere_ordenado(Lista *l, int v){
    Lista *novo;
    novo=(Lista *)malloc(sizeof(Lista));
    novo->info=v;
    Lista *ant=NULL;
    Lista *p=l;
    while(p!=NULL && p->info>v){
        ant=p;
        p=p->prox;
    }
    if(ant==NULL){
        novo->prox=l;
        return novo;
    }
    else{
        ant->prox=novo;
        novo->prox=p;
        return l;
    }
}

//libera
void lst_libera(Lista *l){
    Lista *p=l;
    while(p!=NULL){
        Lista *t=p->prox;
        free(p);
        p=t;
    }
}

//vazia
int lst_vazia(Lista *l){
    if(l==NULL)
        return 1;

    else
        return 0;
}

//retira primeiro
Lista * lst_remove(Lista * l){
    Lista * p = l;
    l = l->prox;
    free(p);
    return l;
}

/*
Funções de pilha
*/

//cria
Pilha *pilha_cria(){
	Pilha *p=(Pilha *)malloc(sizeof(Pilha));
	p->prim=NULL;
	return p;
}

//push
void pilha_push(Pilha *p, int v){
	Lista *l=(Lista *)malloc(sizeof(Lista));
	l->info=v;
	l->prox=p->prim;
	p->prim=l;
}

//pop
int pilha_pop(Pilha *p){
	Lista *l;
	int c;
	if(pilha_vazia(p)){
		printf("Pilha vazia\n");
		exit(1);
	}
	l=p->prim;
	c = l->info;
	p->prim = l->prox;
	free(l);
	return c;
}

//vazia
int pilha_vazia(Pilha *p){
	return (p->prim==NULL);
}

//libera
void pilha_libera(Pilha *p){
	Lista *l=p->prim;
	while(l != NULL){
		Lista *t = l->prox;
		free(l);
		l=t;
	}
	free(p);
}

/*
Funções de Fila
*/

//cria
Fila *fila_cria(){
	Fila *f = (Fila *) malloc(sizeof(Fila));
	f->ini = f->fim = NULL;
	return f;
}

//inserir
void fila_insere(Fila *f,int v){
	Lista *n = (Lista *) malloc(sizeof(Lista));
	int i;
	n->info = v;
	n->prox = NULL;
	if(f->fim != NULL) f->fim->prox = n;
	else f->ini = n;
	f->fim = n;
}

//retirar
int fila_retira(Fila *f){
	Lista *t;
	int v;
	if(fila_vazia(f)){
		printf("Fila vazia!");
		exit(1);
	}
	t = f->ini;
	v = t->info;
	f->ini = t->prox;
	if(f->ini==NULL) f->fim = NULL;
	free(t);
	return v;
}

//vazia
int fila_vazia(Fila *f){
	return (f->ini == NULL);
}

//libera
void fila_libera(Fila *f){
	Lista *q = f->ini;
	while(q!=NULL){
		Lista *t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}

/*
Funções para saber que tipo de estrutura é
*/

//pilha
int is_Stack(int * inst, int * rest, int n){
    Pilha * pil;
    int i, removed;

    pil = pilha_cria();

    for (i = 0; i < n; i++){
        if (inst[i] == 1) {
            pilha_push(pil, rest[i]); //se a instrução for 1, deve dar push na pilha
        } else if (inst[i] == 2) {
            removed = pilha_pop(pil); //se for 2 deve dar pop
            if (removed != rest[i]) {
                pilha_libera(pil);
                return 0; // o numero "popado" tem que ser o desejado
            }
        }
    }

    pilha_libera(pil);
    
    return 1; //ao final, se não deu nenhum erro, deve ser pilha
}

//fila
int is_Queue(int * inst, int * rest, int n){
    Fila * fil;
    int i, removed;

    fil = fila_cria();

    for (i = 0; i < n; i++){
        if (inst[i] == 1) {
            fila_insere(fil, rest[i]); //se a instrução for 1, deve dar push na fila
        } else if (inst[i] == 2) {
            removed = fila_retira(fil); //se a instrução for 2, vai tirar
            if (removed != rest[i]){
                fila_libera(fil);
                return 0; //o numero popado tem que ser igual ao esperado
            }
        }
    }

    fila_libera(fil);

    return 1;
}

//fila de prioridade
int is_PriorityQueue(int * inst, int * rest, int n){
    Lista * pfil;
    int i, removed;

    pfil = lst_cria();

    for (i = 0; i < n; i++) {
        if (inst[i] == 1) {
            pfil = lst_insere_ordenado(pfil, rest[i]);
        } else if (inst[i] == 2) {
            removed = pfil->info;
            pfil = lst_remove(pfil);
            if (removed != rest[i]){
                lst_libera(pfil);
                return 0;
            }
        }
    }

    lst_libera(pfil);

    return 1;
}