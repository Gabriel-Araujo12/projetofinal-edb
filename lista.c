#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hospital.h"


void inicializar_lista(Lista *l){
    l->ocupados = 0;

    for(int i = 0; i < TAM_LISTA; i++){
        l->leitos[i].id[0] = '\0';
    }
}


void inserir(Lista *l, Paciente p){
    if(l->ocupados == 0){
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