#include <stdio.h>
#include <string.h>
#include "hospital.h"


void inicializar_lista(Lista *l){
    l->ocupados = 0;

    for(int i = 0; i < TAM_LISTA; i++){
        l->leitos[i].id[0] = '\0';
    }
}


int inserir_lista(Lista *l, Paciente p){
    if(l->ocupados == TAM_LISTA){
        printf("Todos os leitos já estão ocupados!\n");

        return 0;
    }

    for(int i = 0; i < TAM_LISTA; i++){
        if(l->leitos[i].id[0] == '\0'){
            l->leitos[i] = p;
            l->ocupados++;

            return 1;
        }
    }

    return 0;
}


int remover_lista(Lista* l, Pilha* historico, char* log_str){
    for(int i = 0; i < TAM_LISTA; i++){
        if(l->leitos[i].id[0] != '\0'){
            sprintf(log_str, "ALTA      - %s (%s)", l->leitos[i].id, l->leitos[i].nome);
            inserir_pilha(historico, l->leitos[i]);
            l->leitos[i].id[0] = '\0';
            l->ocupados--;

            return 1;
        }
    }

    return 0;
}