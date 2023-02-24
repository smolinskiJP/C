#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0
#define MAX_TREM 26
//dupla João Pedro Moreira Smolinski; @GuilhermeoLuiz


typedef struct pilha {
	int n;
	char vet[MAX_TREM];
} Pilha;

Pilha *pilha_cria() {
	Pilha *p = (Pilha *) malloc(sizeof(Pilha));
	p->n = 0;
	return p;
}

int pilha_vazia(Pilha *p) {
	return (p->n == 0);
}

void pilha_push(Pilha *p, char v) {
	if (p->n == MAX_TREM) {
		printf("A capacidade da pilha estorou.");
		exit(1);
	}

	p->vet[p->n++] = v;
}

char pilha_pop(Pilha *p) {
	if (pilha_vazia(p)) {
		printf("Pilha vazia.");
		exit(1);
	}

	return p->vet[--p->n];
}

void pilha_libera(Pilha *p) {
	free(p);
}

int main(){
	int i;
	Pilha * pil;
	char init[MAX_TREM], mod[MAX_TREM], said[(2 * MAX_TREM)];//o vetor de saída tem 2 vezes o tamanho do normal pois nele cada char entra e sai (I e R)
	int tam, posFim, tamFim;


	//obter a primeira entrada de tamanho, se o usuario digitar 0 encerra
	scanf(" %d", &tam);
	while (tam != 0) {
        	tamFim = 0;
        	posFim = 0;
        	//pega char's o numero de vezes do inteiro digitado antes
        	for (i = 0; i < tam; i++){
            		scanf(" %c", &init[i]);
        	}
        	//pega tanto o que entra tanto o modelo que deve sair
        	for (i = 0; i < tam; i++){
            		scanf(" %c", &mod[i]);
        	}

	        //cria a pilha
        	pil = pilha_cria();


	        for (i = 0; i < tam; i++){
			pilha_push(pil, init[i]);
        	    	//para cada um novo adicionado na pilha, o final deve ter mais um I
            		said[tamFim] = 'I';
            		tamFim++;
            		//depois de adicionar um novo componente é preciso ver se é o desejado no modelo
            		while((pil->vet[pil->n-1] == mod[posFim]) && (pil->n != 0)){
      
     	           		//necessário dar pop no ultimo elemento
        	        	pil->vet[pil->n-1] = pilha_pop(pil);

		                //atualizar todas as variáveis
                		said[tamFim] = 'R';
                		tamFim++;
                		posFim++;
            		}
        	}

	        //saida com o vetor de R e I
        	for (i = 0; i < tamFim; i++){
            		printf("%c ", said[i]);
        	}
        	//o tamanho final tem que ser o mesmo que 2x o tamanho caso seja possivel, senão é impossível
        	if (tamFim != (tam *2)){
           	 	printf("IMPOSSIBLE ");
        	}
        
        	printf("\n");

        	//libera a pilha
        	pilha_libera(pil);

	        //ao final deve ver se continua ou não
        	scanf(" %d", &tam);
    	}
	return SUCESSO;
}
