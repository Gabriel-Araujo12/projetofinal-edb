#include <stdlib.h>
#include "hospital.h"


int funcao_hash(int prioridade){
    return prioridade % TAM_TABELA;
}


No *criar_no(Paciente paciente){
    No *novo_no = (No *)malloc(sizeof(No));

    if(novo_no){
        novo_no->dados = paciente;
        novo_no->proximo = NULL;
    }
    
    return novo_no;
}


void inicializar_tabela(Tabela_Hash *tabela){
    for(int i = 0; i < TAM_TABELA; i++){
        tabela->tabela[i] = NULL;
    }
}


void inserir_tabela(Tabela_Hash *tabela, Paciente p){
    int indice = funcao_hash(p.prioridade);
    No* novo_no = criar_no(p);

    if(tabela->tabela[indice] == NULL){
        tabela->tabela[indice] = novo_no;
    }
    
    else{
        novo_no->proximo = tabela->tabela[indice];
        tabela->tabela[indice] = novo_no;
    }
}


Paciente* sortear_paciente(Tabela_Hash* h){
    int total = 0;
    No* pacientes[100];

    for (int i = 0; i < TAM_TABELA; i++) {
        No* atual = h->tabela[i];
        while (atual != NULL) {
            if (atual->dados.atendido == 0) {
                pacientes[total++] = atual;
            }

            atual = atual->proximo;
        }
    }

    if (total == 0){
        return NULL;
    }

    int indice = rand() % total;

    pacientes[indice]->dados.atendido = 1;

    return &pacientes[indice]->dados;
}