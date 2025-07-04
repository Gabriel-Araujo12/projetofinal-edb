#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "hospital.h"


void carregar_pacientes(Tabela_Hash* tabela, const char* nome_arquivo) {
    FILE* f = fopen(nome_arquivo, "r");
    if (!f) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    Paciente p;
    while (fscanf(f, "%[^;];%[^;];%d;%c;%[^;];%d;%d\n", 
        p.id, p.nome, &p.idade, &p.sexo, p.cpf, &p.prioridade, &p.atendido) == 7) {
        inserir_tabela(tabela, p);
    }

    fclose(f);
}


void registrar_log(const char* msg) {
    FILE* f = fopen("processamento.log", "a");
    if (f) {
        fprintf(f, "%s\n", msg);
        fclose(f);
    }
    printf("%s\n", msg);
}


int main() {
    Tabela_Hash tabela;
    Deque fila;
    Lista leitos;
    Pilha historico;
    char log_str[200];
    int ciclo = 1;

    srand(time(NULL));

    inicializar_tabela(&tabela);
    inicializar_deque(&fila);
    inicializar_lista(&leitos);
    historico.topo = -1;

    remove("processamento.log");
    carregar_pacientes(&tabela, "pacientes.csv");

    while (1) {
        sprintf(log_str, "[CICLO %02d]", ciclo++);
        registrar_log(log_str);

        // Tenta internar
        if (!esta_vazio(&fila) && leitos.ocupados < TAM_LISTA) {
            Paciente p = remover_deque(&fila);
            if (inserir_lista(&leitos, p)) {
                sprintf(log_str, "INTERNADO - %s (prioridade %d)", p.id, p.prioridade);
                registrar_log(log_str);
            }
        }

        // Tenta dar alta se estiver cheio
        if (leitos.ocupados == TAM_LISTA) {
            if (remover_lista(&leitos, &historico, log_str)) {
                registrar_log(log_str);
            }
        }

        // Tenta inserir novo paciente na fila
        if (!esta_cheio(&fila)) {
            Paciente* p = sortear_paciente(&tabela);
            if (p) {
                inserir_deque(&fila, *p);
                sprintf(log_str, "ESPERA - %s (prioridade %d)", p->id, p->prioridade);
                registrar_log(log_str);
            }
        }

        // Verifica encerramento da simulação
        if (esta_vazio(&fila) && leitos.ocupados == 0) {
            registrar_log("Simulação finalizada.");
            break;
        }

        sleep(2);
    }

    return 0;
}