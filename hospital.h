#ifndef HOSPITAL_H
#define HOSPITAL_H


#define TAM_TABELA 51
#define TAM_LISTA 10
#define TAM_DEQUE 20


typedef struct{
    char id[6];
    char nome[500];
    int idade;
    char sexo;
    char cpf[12];
    int prioridade;
    int atendido;
}Paciente;


typedef struct{
    Paciente dados;
    struct No *proximo;
}No;


typedef struct{
    No *tabela[TAM_TABELA];
}Tabela_Hash;


typedef struct{
  Paciente dados[TAM_DEQUE];
  int inicio;
  int final;
  int tamanho;
}Deque;


typedef struct{
    Paciente dados[TAM_LISTA];
    int ocupados;
}Lista;


typedef struct{
    Paciente dados;
    int topo;
}Pilha;


int funcao_hash(int prioridade);
No *criar_no(Paciente paciente);
void inicializar_tabela(Tabela_Hash *tabela);
void inserir_tabela(Tabela_Hash *tabela, Paciente p);
Paciente* sortear_paciente(Tabela_Hash* h);


void inicializar_deque(Deque *d);



#endif