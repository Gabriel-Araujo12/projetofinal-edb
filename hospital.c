#include <stdio.h>
#include "hospital.h"

void ler_csv(const char *arquivo, Paciente pacientes[], int *quantidade){
    FILE *arq = fopen(arquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    char linha[500];
    int i = 0;

    fgets(linha, 500, arquivo);

    while (fgets(linha, 500, arquivo) && i < 50) {
        char *token = strtok(linha, ";");
        strcpy(pacientes[i].id, token);

        token = strtok(NULL, ";");
        strcpy(pacientes[i].nome, token);

        token = strtok(NULL, ";");
        pacientes[i].idade = atoi(token);

        token = strtok(NULL, ";");
        pacientes[i].sexo = token[0];

        token = strtok(NULL, ";");
        strcpy(pacientes[i].cpf, token);

        token = strtok(NULL, ";");
        pacientes[i].prioridade = atoi(token);

        token = strtok(NULL, ";\n");
        pacientes[i].atendido = atoi(token);

        i++;
    }

    *quantidade = i;
    fclose(arquivo);
}

int main(){
    Tabela_Hash tabela;
    Paciente pacientes[50];
    int qtd = 0;

    inicializar_tabela(&tabela);
    ler_csv("pacientes.csv", pacientes, &qtd);

    for (int i = 0; i < qtd; i++) {
        inserir(&tabela, pacientes[i]);
    }

    return 0;
}