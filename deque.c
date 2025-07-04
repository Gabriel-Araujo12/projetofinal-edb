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


void insere_inicio(Deque *d, Paciente p){
    if(esta_cheio(d)){
        printf("Deque cheio!\n");

        return;
    }

    d->inicio = (d->inicio - 1 + TAM_DEQUE) % TAM_DEQUE;
    d->dados[d->inicio] = p;
    d->tamanho++;
}


void insere_final(Deque *d, Paciente p){
    if(esta_cheio(d)){
        printf("Deque cheio!\n");

        return;
    }

    d->final = (d->final + 1) % TAM_DEQUE;
    d->dados[d->final] = p;
    d->tamanho++;
}


Paciente remove_inicio(Deque *d){
    Paciente removido = {0};

    if (esta_vazio(d)) return removido;

    removido = d->dados[d->inicio];
    d->inicio = (d->inicio + 1) % TAM_DEQUE;
    d->tamanho--;

    return removido;
}


Paciente remove_final(Deque *d){
    Paciente removido = {0};

    if (esta_vazio(d)) return removido;

    removido = d->dados[d->final];
    d->final = (d->final - 1 + TAM_DEQUE) % TAM_DEQUE;
    d->tamanho--;

    return removido;
}


//------------------Prioridade------------------//


void inserir_deque(Deque *d, Paciente p){
    if(p.prioridade >= 4){
        insere_inicio(d, p);
    } 
    
    else{
        insere_fim(d, p);
    }
}


Paciente remover_deque(Deque *d){
    Paciente frente = d->dados[d->inicio];
    Paciente tras = d->dados[d->final];

    if(frente.prioridade > tras.prioridade){
        return remove_inicio(d);
    } 
    
    else if(tras.prioridade > frente.prioridade){
        return remove_final(d);
    } 
    
    else{
        return remove_inicio(d);
    }
}