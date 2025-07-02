#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hospital.h"


void inserir(Pilha* p, Paciente dados){
    p->vetor[++p->topo] = dados;
}