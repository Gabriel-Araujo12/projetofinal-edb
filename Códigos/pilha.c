#include "hospital.h"


void inserir_pilha(Pilha* p, Paciente dados){
    p->vetor[++p->topo] = dados;
}