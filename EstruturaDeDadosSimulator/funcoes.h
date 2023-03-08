#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0

/*
Funções Lista (Fila de prioridade)
*/

//estrutura
typedef struct lista{
    int info;
    struct lista *prox;
} Lista;

//cria
Lista* lst_cria();
//insere ordenado
Lista *lst_insere_ordenado(Lista *l, int v);
//libera
void lst_libera(Lista *l);
//vazia
int lst_vazia(Lista *l);
//retira primeiro
Lista * lst_remove(Lista * l);


/*
Funções pilha
*/

//estrutura
typedef struct pilha{
	Lista *prim;
} Pilha;

//cria
Pilha *pilha_cria();
//push
void pilha_push(Pilha *p, int v);
//pop
int pilha_pop(Pilha *p);
//função para saber se é vazia
int pilha_vazia(Pilha *p);
//free
void pilha_libera(Pilha *p);


/*
Funções fila
*/

typedef struct fila{
	Lista *ini;
	Lista *fim;
} Fila;

//cria
Fila *fila_cria();
//push
void fila_insere(Fila *f, int v);
//pop
int fila_retira(Fila *f);
//fonção para saber se está vazia
int fila_vazia(Fila *f);
//libera
void fila_libera(Fila *f);


/*
Funções para saber que tipo de estrutura é
*/

//pilha
int is_Stack(int * inst, int * rest, int n);
//fila
int is_Queue(int * inst, int * rest, int n);
//fila de prioridade
int is_PriorityQueue(int * inst, int * rest, int n);