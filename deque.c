#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hospital.h"


void inicializar_deque(Deque *d){
    d->inicio = -1;
    d->final = -1;
    d->tamanho = 0;
}


int esta_cheio(Deque *d){
    return d->tamanho == TAM_DEQUE;
}


int esta_vazio(Deque *d){
    return d->tamanho == 0;
}


void insere_inicio(Deque *d, int valor){
    if(esta_cheio(d)){
        printf("Deque cheio!\n");
        return;
    }

    if(esta_vazio(d)){
        d->inicio = d->final = 0;
        d->vetor[d->inicio] = valor;
    }

    else{
        for(int i = d->tamanho; i > 0; i--){
            d->vetor[i] = d->vetor[i - 1];
        }
        
        d->inicio = 0;
        d->vetor[d->inicio] = valor;
        d->final++;
    }

    d->tamanho++;
}