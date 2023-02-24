//Busca em profundidade / Lista de ADJ
//João Pedro Moreira Smolinski
#include <stdio.h>
#include <stdlib.h>

//estrutura da lista
typedef struct lst{
    int info;
    struct lst* prox;
} Lista;

//estrutura do grafo
typedef struct graph{
    int * visitados;
    int n;
    Lista ** lstAdj;
} Grafo;

//funcao cria lista
Lista* criaLista(){
    return NULL;
}

//funcao insere lista
Lista* insereLista(int v){
    Lista* lst = (Lista*)malloc(sizeof(Lista));
    lst->info = v;
    lst->prox = NULL;
    return lst;
}

//funcao de criar o grafo
Grafo * criaGrafo(int tam){
    int i;
    //aloca espaço para tudo
    Grafo * grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->n = tam;
    grafo->lstAdj = (Lista**)malloc(tam * sizeof(Lista*));
    grafo->visitados = (int*)malloc(tam * sizeof(int));

    //loop para criar cada lista
    for(i = 0; i < tam; i++){
        grafo->lstAdj[i] = criaLista();
        grafo->visitados[i] = 0;
    }
    //retorna o grafo
    return grafo;
}

//funcao de inserir arestas no grafo(orientado)
void insereGrafo(Grafo * grafo, int remetente, int destinatario){
    //adiciona destinatario no remetente
    Lista * lst = insereLista(destinatario);
    //adiciona o node na lista de adj
    lst->prox = grafo->lstAdj[remetente];
    grafo->lstAdj[remetente] = lst;

}

//funcao de free de lista
void liberaLista(Lista* lst){
    Lista * p = lst;
    while (p != NULL){
        Lista * t = p->prox;
        free(p);
        p = t;
    }
}

//funcao de free do grafo
void liberaGrafo(Grafo * grafo){
    int i;
    for (i = 0; i < grafo->n; i++){
        liberaLista(grafo->lstAdj[i]);
    }
    free(grafo);
}

//funcao de print do grafo
void printaGrafo(Grafo* grafo){
    int i;
    for (i = 0; i < grafo->n; i++){
        printf("%d: ", i);
        Lista* tmp = grafo->lstAdj[i];
        while (tmp != NULL){
            printf("%d ", tmp->info);
            tmp = tmp->prox;
        }
        printf("\n");
    }
}

//funcao de busca de profundidade
void DFS(Grafo * grafo, int vertice){
    Lista* listaAdj = grafo->lstAdj[vertice];
    Lista* tmp = listaAdj;

    grafo->visitados[vertice] = 1;
    printf("%d visitado \n", vertice);

    while (tmp != NULL){
        if (grafo->visitados[tmp->info] == 0) {
            DFS(grafo, tmp->info);
        }
        tmp = tmp->prox;
    }
}

int main(){
    Grafo * grafo;
    
    grafo = criaGrafo(6);

    insereGrafo(grafo, 0, 2);
    insereGrafo(grafo, 0, 4);
    insereGrafo(grafo, 0, 1);
    insereGrafo(grafo, 1, 0);
    insereGrafo(grafo, 4, 0);
    insereGrafo(grafo, 2, 0);
    insereGrafo(grafo, 5, 1);
    insereGrafo(grafo, 1, 5);
    insereGrafo(grafo, 5, 3);
    insereGrafo(grafo, 3, 5);
    insereGrafo(grafo, 4, 2);
    insereGrafo(grafo, 2, 4);

    printaGrafo(grafo);

    DFS(grafo, 0);

    liberaGrafo(grafo);

    return 0;
}
