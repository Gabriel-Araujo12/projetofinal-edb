#ifndef HOSPITAL_H
#define HOSPITAL_H


#define TAM_TABELA 51
#define TAM_DEQUE 20
#define TAM_LISTA 10
#define TAM_PILHA 200


typedef struct{
    char id[7];
    char nome[500];
    int idade;
    char sexo;
    char cpf[12];
    int prioridade;
    int atendido;
} Paciente;


typedef struct No{
    Paciente dados;
    struct No *proximo;
} No;


typedef struct{
    No *tabela[TAM_TABELA];
} Tabela_Hash;


typedef struct{
  Paciente dados[TAM_DEQUE];
  int inicio;
  int final;
  int tamanho;
} Deque;


typedef struct{
    Paciente leitos[TAM_LISTA];
    int ocupados;
} Lista;


typedef struct{
    Paciente vetor[TAM_PILHA];
    int topo;
} Pilha;


// ------------------- TABELA HASH ------------------- //
void inicializar_tabela(Tabela_Hash *tabela);
void inserir_tabela(Tabela_Hash *tabela, Paciente p);
Paciente* sortear_paciente(Tabela_Hash* h);


// ---------------------- DEQUE ---------------------- //
void inicializar_deque(Deque *d);
int esta_cheio(Deque *d);
int esta_vazio(Deque *d);
void inserir_deque(Deque *d, Paciente p);
Paciente remover_deque(Deque *d);


// ---------------------- LISTA ---------------------- //
void inicializar_lista(Lista *l);
int inserir_lista(Lista *l, Paciente p);
int remover_lista(Lista* l, Pilha* historico, char* log_str);


// ---------------------- PILHA ---------------------- //
void inserir_pilha(Pilha* p, Paciente dados);


#endif