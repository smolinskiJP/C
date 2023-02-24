#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#define SUCESSO 0


int comparaLista (Lista* l1, Lista* l2){
    Lista * ll1;
    Lista * ll2;
    int comp1 = 0;
    int comp2 = 0;

    //o primeiro fator que se deve comparar é o tamanho da lista, caso seja diferente ja deve retornar negativo
    for (ll1 = l1; ll1 != NULL; ll1 = ll1->prox){
        comp1++;
    }
    for (ll2 = l2; ll2 != NULL; ll2 = ll2->prox){
        comp2++;
    }
    if (comp2 != comp1){
        return 0; //caso diferente retorne negativo
    }

    ll1 = l1;
    ll2 = l2;

    while (ll1 != NULL){
        //se esse nivel for igual, deve passar ao prox, senão retorna negativo
        if (ll1->info == ll2->info){
            ll1 = ll1->prox;
            ll2 = ll2->prox;
        } else {
            return 0;
        }

    }
    //ao fim, analisou o tamanho e o componente de cada celula da lista, se não caiu em nenhum dos casos de lista diferente são iguais e deve retornar positivo
    return 1;
}


int main(int argc, char ** argv){

    Lista* l1;
    Lista* l2;
    int igual;

    l1 = lst_cria();
    l1 = lst_insere(l1, 1);
    l1 = lst_insere(l1, 3);
    l2 = lst_cria();
    l2 = lst_insere(l2, 1);
    l2 = lst_insere(l2, 3);

    //chamar função comparação
    igual = comparaLista(l1, l2);

    if (igual){
        printf("Listas iguais");
    } else {
        printf("Listas diferentes");
    }

    lst_libera(l1);
    lst_libera(l2);


    return SUCESSO;
}
