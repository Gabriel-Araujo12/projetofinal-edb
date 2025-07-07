#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "hospital.h"


void carregar_pacientes(Tabela_Hash *tabela, const char *arquivo){
    FILE* f = fopen(arquivo, "r");

    if(!f){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    char cabecalho[200];
    fgets(cabecalho, sizeof(cabecalho), f);

    Paciente p;

    while(fscanf(f, "%[^;];%[^;];%d;%c;%[^;];%d;%d\n", p.id, p.nome, &p.idade, &p.sexo, p.cpf, &p.prioridade, &p.atendido) == 7){
        inserir_tabela(tabela, p);
    }

    fclose(f);
}


void registrar(const char *mensagem){
    FILE* f = fopen("Histórico/processamento.log", "a");

    if(f){
        fprintf(f, "%s\n", mensagem);

        fclose(f);
    }

    printf("%s\n", mensagem);
}


int main(){
    Tabela_Hash tabela;
    inicializar_tabela(&tabela);

    Deque fila;
    inicializar_deque(&fila);

    Lista leitos;
    inicializar_lista(&leitos);

    Pilha historico;
    historico.topo = -1;

    char mensagem[200];
    int ciclo = 1;
    srand(time(NULL));

    carregar_pacientes(&tabela, "Pacientes/pacientes.csv");

    while(1){
        sprintf(mensagem, "\n[CICLO %02d]", ciclo);
        registrar(mensagem);
        ciclo++;

        if(leitos.ocupados > 0){
            if(remover_lista(&leitos, &historico, mensagem)){
                registrar(mensagem);
            }
        }

        if(!esta_vazio(&fila) && leitos.ocupados < TAM_LISTA){
            Paciente p = remover_deque(&fila);

            if(inserir_lista(&leitos, p)){
                sprintf(mensagem, "INTERNADO - %s (Prioridade %d)", p.id, p.prioridade);
                registrar(mensagem);
            }
        }

        if(!esta_cheio(&fila)){
            Paciente* p = sortear_paciente(&tabela);

            if(p){
                inserir_deque(&fila, *p);
                sprintf(mensagem, "ESPERA    - %s (Prioridade %d)", p->id, p->prioridade);
                registrar(mensagem);
            }
        }

        if((esta_vazio(&fila)) && leitos.ocupados == 0){
            registrar("\nO fluxo de internação foi encerrado.");
            break;
        }

        sleep(2);
    }

    return 0;
}