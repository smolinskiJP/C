#include "funcoes.h"

int main(){

    //variáveis declaradas
    FILE * inFile = fopen("entrada.txt", "r");
    int i, n;
    int isStack, isQueue, isPriorityQueue;
    int *instrucao, *resultado;
    
    //enquanto não estiver no fim do arquivo
    while (!feof(inFile)){
        //le n e aloca o vetor de tamanho n
        fscanf(inFile, " %d", &n);
        instrucao = malloc(n * (sizeof(int)));
        resultado = malloc(n * (sizeof(int)));
        //le as instruções e resultado do vetor
        for (i = 0; i < n; i++){
            fscanf(inFile, " %d %d", &instrucao[i], &resultado[i]);
        }
        //zera as variáveis booleanas
        isStack = 0;
        isPriorityQueue = 0;
        isQueue = 0;
        //chama as funções de verificação
        isStack = is_Stack(instrucao, resultado, n);
        isQueue = is_Queue(instrucao, resultado, n);
        isPriorityQueue = is_PriorityQueue(instrucao, resultado, n); 


        if ((isStack + isPriorityQueue + isQueue) >= 2) { //se a soma for mais de 1, obrigatoriamente tem mais de 1 tipo
            printf("not sure\n");
        } else if ((isStack + isPriorityQueue + isQueue) == 0) { //se a soma for 0 nenhum tipo pode ser visto
            printf("impossible\n");
        } else if (isStack) {//caso pilha
            printf("stack\n");
        } else if (isQueue) {//caso fila
            printf("queue\n");
        } else if (isPriorityQueue) {//caso fila de prioridade
            printf("priority queue\n");
        }
        //libera os vetores alocados
        free(instrucao);
        free(resultado);
    }
    //fecha arquivo e retorna 0
    fclose(inFile);
    return SUCESSO;
}