#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0
#define NUM_PRIS 41
#define PASSO 3

typedef struct lista{
	int info;
    	struct lista *prox;
} Lista;

Lista* lst_cria(){
	return NULL;
}

Lista* lst_insere(Lista *l, int i){
	Lista *novo=(Lista *)malloc(sizeof(Lista));
   	novo->info=i;
   	novo->prox=l;
	return novo;
}

Lista *lcirc_transforma(Lista *l){
	Lista *p=l;
   	while(p->prox!=NULL){
		p=p->prox;
    	}
    	if(p == NULL){
        	return l;
    	}
    	else{
        	p->prox=l;
        	return l;
    	}
}

void lcirc_libera(Lista *l){
    	Lista *p = l;
    	do{
        	Lista *t = p->prox;
        	free(p);
        	p=t;
    	} while(p != l);
}

Lista * Jojo(Lista* l){
    
    	Lista* p, *ant;
    	//enquanto l não tiver um unico elemento deve continuar eliminando
    	while (l->prox != l){
        	//passa uma posição para a frente o numero de vezes igual ao passo (3)
        	for (int i = 1; i < PASSO; i++){
            		ant = l;
            		l = l->prox;
        	}
        	printf("%d morreu \n", l->info);
        	ant->prox = l->prox;
        	p = l;
        	free(p);
        	l = ant->prox;
    	}
    	return l;
}


int main(int argc, char ** argv){

    	//declaração de variável
    	Lista *l1;

    	//cria a lista e adiciona as 41 casas
    	l1 = lst_cria();
    	for (int i = NUM_PRIS; i > 0; i--){
        	l1 = lst_insere(l1, i);
    	}

    	//transforma a lista encadeada em circular
    	l1 = lcirc_transforma(l1);

    	l1 = Jojo(l1);

    	printf("O soldado %d sobreviveu", l1->info);

    	//libera a lista
    	lcirc_libera(l1);


    	return SUCESSO;
}
