#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0

typedef struct lista{
	char info;
	struct lista *prox;
} Lista;

typedef struct pilha {
    Lista* prim;
} Pilha;

Pilha *pilha_cria(){
	Pilha *p=(Pilha *)malloc(sizeof(Pilha));
	p->prim=NULL;
	return p;
}


int pilha_vazia(Pilha *p){
	return (p->prim==NULL);
}


void pilha_push(Pilha *p, char v){
	Lista *l=(Lista *)malloc(sizeof(Lista));
	l->info=v;
	l->prox=p->prim;
	p->prim=l;
}

void pilha_pop(Pilha *p){
	Lista *l;
	if(pilha_vazia(p)){
		printf("Expressao mal formada\n");
		exit(1);
	}
	l=p->prim;
	p->prim = l->prox;
	free(l);
}

void pilha_libera(Pilha *p){
	Lista *l=p->prim;
	while(l != NULL){
		Lista *t = l->prox;
		free(l);
		l=t;
	}
	free(p);
}


int main(){
    Pilha * pil = pilha_cria(pil);
    char parenteses;



    //usuario deve digitar 0 para sair
    do{
        //pega a variavel
        scanf(" %c", &parenteses);

        //deve analisar se o caracter é um '(' ou ')'
        //se for ) deve tirar um ( da pilha
        if (parenteses == ')'){
            //se a pilha for vazia e adicionar um ) a expressão está errada
            if(pilha_vazia(pil)){
                printf("Mal formada\n");
                //sair do programa
                exit(1);
            } else {
                //se não for vazia deve tirar um ( da pilha já que formou dupla com ele
                pilha_pop(pil);
            }
        } else if (parenteses == '('){
            //se for ( deve adicionar a pilha
            pilha_push(pil, parenteses);
        }
    } while (parenteses != '0');

    //terminado o processo de tira e coloca da pilha deve analisar se sobrou algo
    if(pilha_vazia(pil)){
        printf("A expressao esta bem formada\n");
    } else {
        printf("A expressao esta mal formada\n");
    }

    //liberar a pilha ao final
    pilha_libera(pil);

    return SUCESSO;
}
