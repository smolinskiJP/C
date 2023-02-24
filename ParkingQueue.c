#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SUCESSO 0
#define TAM_PLACA 7

typedef struct lista{
	char info[TAM_PLACA]; //informacao na celula (placa do carro)
	struct lista *prox; //prox celula
} Lista;

typedef struct fila{
    Lista *ini; //celula da lista que representa o inicio
    Lista *fim; //celula da lista que representa o fim
} Fila;

Fila *fila_cria(){
	Fila *f = (Fila *) malloc(sizeof(Fila)); //alocar espaço para a fila
	f->ini = f->fim = NULL; //em uma nova fila, seu inicio e final serão nulos
	return f;
}

int fila_vazia(Fila * f){
    return (f->ini == NULL);
}

//funcao para adicionar elemento
void fila_push(Fila *f, char * placa){
    Lista *n = (Lista *) malloc(sizeof(Lista)); //alocar nova celula de lista
    strcpy(n->info, placa); //escreve a placa na info da nova celula
    n->prox = NULL; //deixa a nova apontado pra null (é a ultima)
    if (f->fim != NULL) { //se não for vazia
        f->fim->prox = n; //o proximo do fim sera a nova lista
    } else {
        f->ini = n; //senão o inicio também sera a nova
    }
    f->fim = n; //o ultimo passa a ser a nova lista
}

//funcao para tirar o primeiro elemento
void fila_pop(Fila *f, char * placa){
    //cria lista temporaria
    Lista * t;
    char excl[TAM_PLACA];
    while (strcmp(placa, f->ini->info)) { //caso não seja a placa requisitada
        if (fila_vazia(f)){
            printf("Fila vazia");
            exit(1);
        }
       t = f->ini; //a celula do inicio é guardada no temp
       strcpy(excl, t->info); //copia a placa do que sera excluido
       f->ini = t->prox; //o inicio passa a ser o segundo
       if (f->ini == NULL) f->fim = NULL; //se tiver só um elemento o inicio e fim vao ser nulos
       free(t); //liberar o temporario
       fila_push(f, excl); //adiciona no final
    }
   t = f->ini;
   f->ini = t->prox;
   if (f->ini == NULL) f->fim = NULL;
   free(t);
}

//funcao para liberar fila
void fila_free(Fila * f){
    Lista * q = f->ini;
    while (q != NULL){
        Lista *t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}

//funcao para imprimir fila
void fila_print(Fila * f){
    Lista * q;
    for (q=f->ini; q != NULL; q=q->prox) printf("\t%s\n", q->info);
}

int main(){

    Fila *filaCarros;
    int Ordem, i;
    char placaCarro[TAM_PLACA];

    filaCarros = fila_cria(); //criar a fila

    printf("Voce deseja tirar ou colocar um carro? (2 para tirar, 1 para colocar e 0 para sair do programa): ");
    scanf(" %d", &Ordem);
    while (Ordem){
        if (Ordem == 1){
            //pegar a placa do carro e inserir na fila
            printf("Digite a placa do carro que sera adicionado (ex. ABC0123): ");
            for (i = 0; i < TAM_PLACA; i++) scanf(" %c", &placaCarro[i]);
            fila_push(filaCarros, placaCarro);
            fila_print(filaCarros);
        } else if (Ordem == 2){
            //pegar a placa do carro e tirar da fila
            printf("Digite a placa do carro que sera removido (ex. ABC0123): ");
            for (i = 0; i < TAM_PLACA; i++) scanf(" %c", &placaCarro[i]);
            fila_pop(filaCarros, placaCarro);
            fila_print(filaCarros);
        } else printf("Codigo invalido");
        printf("Voce deseja tirar ou colocar um carro? (2 para tirar, 1 para colocar e 0 para sair do programa): ");
        scanf(" %d", &Ordem); 
    }

    //liberar a fila
    fila_free(filaCarros);

    return SUCESSO;
}
