//Exercício 2 / João Pedro Moreira Smolinski
//imprime os graus de um grafo não orientado com lista de adj
#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct lista *prox;
}Lista;

Lista* lst_cria(){
	return NULL;
}

Lista* lst_insere(Lista *l, int i){
	Lista *novo=(Lista *)malloc(sizeof(Lista));
	novo->info=i;
	novo->prox=l;
	return novo;
}

void lst_imprime(Lista *l){
	Lista *p;
	for(p=l;p!=NULL;p=p->prox){
		printf(" %d ", p->info+1);
	}
}

int lst_vazia(Lista *l){
	if(l==NULL)
		return 1;

	else
		return 0;
}

int lst_busca(Lista *l, int v){
	Lista *p;
	for(p=l;p!=NULL;p=p->prox){
		if(p->info==v){
			return 1;
		}
	}
	return 0;
}

Lista *lst_retira(Lista *l, int v){
	Lista *p=l;
	Lista *ant=NULL;
	while(p!=NULL && p->info!=v){
		ant=p;
		p=p->prox;
	}
	if(p==NULL){
		printf("Elemento não encontrado\n");
		return l;
	}
	if(ant==NULL){
		l=p->prox;
	}
	else{
		ant->prox=p->prox;
	}
	free(p);
	return l;
}

void lst_libera(Lista *l){
	Lista *p=l;
	while(p!=NULL){
		Lista *t=p->prox;
		free(p);
		p=t;
	}
}

Lista ** criaLista (Lista ** lst, int tam){
    int i, j, temAresta;

    lst = (Lista**)malloc(tam * sizeof(Lista*));
    for (i = 0; i < tam; i++){
        lst[i] = lst_cria();
    }
    for (i = 0; i < tam; i++){
        for (j = i; j < tam; j++){
            printf("\nTem ligacao entre %d e %d?(0 ou 1): ", i+1, j+1);
            scanf(" %d", &temAresta);
            if (temAresta) {
                lst[i] = lst_insere(lst[i], j);
                if (j != i){
                    lst[j] = lst_insere(lst[j], i);
                }
            }
        }
    }
    return lst;
}

void calcNo(Lista** lst, int tam){
    int i, graus;
    Lista * p;
    for (i = 0; i < tam; i++){
        graus = 0;
        for(p=lst[i];p!=NULL;p=p->prox){
		    graus++;
    	}
        printf("\n %d tem %d graus", i+1, graus);
    }
    printf("\n");
}

int main(){

    Lista ** list_adj;
    int tamGrafo, i;

    printf("Digite quantos nos tera o grafo: \n");
    scanf(" %d", &tamGrafo);

    list_adj = criaLista(list_adj, tamGrafo);

    printf("\n");
    for (i = 0; i < tamGrafo; i++){
        printf(" %d : ", i+1);
        lst_imprime(list_adj[i]);
        printf("\n");
    }

    calcNo(list_adj, tamGrafo);

    for (i = 0; i < tamGrafo; i++){
        lst_libera(list_adj[i]);
    }
    free(list_adj);

    return 0;
}
