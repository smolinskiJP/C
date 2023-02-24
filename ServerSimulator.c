// Exercício 3 / João Pedro Moreira Smolinski
// Detectar se há uma falta de conexão entre dois nós de grafo
// Há um rand() para ver se há ou não erro, necessário executar várias vezes para ver vários casos
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM_GRAFO 10
#define NUM_MAQ 8

int ** CriaMatriz(int ** matriz){
    int i;

    matriz = (int**)malloc(TAM_GRAFO * sizeof(int*));
    for (i = 0; i < TAM_GRAFO; i++){
        matriz[i] = (int*)malloc(TAM_GRAFO * sizeof(int));
    }
    return matriz;
}

void LiberaMatriz(int ** matriz){
    int i;

    for (i = 0; i < TAM_GRAFO; i++){
        free(matriz[i]);
    }
    free(matriz);
}

int ** GravaMatriz(int ** matriz){

    int i, j;

    for (i = 0; i < TAM_GRAFO; i++){
        for (j = 0; j < TAM_GRAFO; j++){
            if (i == j){
                matriz[i][j] = 8;
            } else {
                matriz[i][j] = matriz[j][i] = 1;
            }
        }
    }
    return matriz;
}

void PrintMatriz(int ** matriz){
    int i, j;
    printf("\nMatriz de Adjacencias:\n");
    for(i = 0; i < TAM_GRAFO; i ++){
        printf("\t|");
        for (j = 0; j < TAM_GRAFO; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("|\n");
    }
}

int ** AleatorioErro(int ** matriz){

    srand(time(NULL));
    int RandomL = (rand()%10), RandomC = (rand()%10);

    matriz[RandomL][RandomC]--;
    if (RandomC != RandomL){
        matriz[RandomC][RandomL]--;
    }
    return matriz;
}

void ComparaMatriz(int ** modelo, int ** compara){
    int i, j;
    for (i = 0; i < TAM_GRAFO; i++){
        for (j = 0; j < TAM_GRAFO; j++){
            if (compara[i][j] != modelo[i][j]){
                if (i == j){
                    printf("\nERRO NAS MAQUINAS DE %d\n", (i+1));
                } else {
                    printf("\nERRO NA COMUNICACAO ENTRE %d E %d\n", (i+1), (j+1));
                }
                return;
            }
        }
    }
    printf("\nSEM ERRO\n");
}

int main(){

    srand(time(NULL));
    int erro = (rand()%7);
    int ** grafico, **modelo;

    grafico = CriaMatriz(grafico);
    grafico = GravaMatriz(grafico);
    modelo = CriaMatriz(modelo);
    modelo = GravaMatriz(modelo);
    
    if (erro != 0){
        grafico = AleatorioErro(grafico);
    }
    PrintMatriz(grafico);
    ComparaMatriz(modelo, grafico);

    LiberaMatriz(grafico);
    LiberaMatriz(modelo);
    return 0;
}
