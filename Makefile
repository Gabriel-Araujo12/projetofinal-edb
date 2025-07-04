# Nome do executável final
EXEC = hospital

# Compilador
CC = gcc

# Flags de compilação (ativar todos os warnings)
CFLAGS = -Wall -Wextra -std=c99

# Arquivos objeto
OBJS = hospital.o deque.o lista.o pilha.o tabela.o

# Regra padrão
all: $(EXEC)

# Linkagem final
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Compila cada arquivo .c individualmente
hospital.o: hospital.c hospital.h
	$(CC) $(CFLAGS) -c hospital.c

deque.o: deque.c hospital.h
	$(CC) $(CFLAGS) -c deque.c

lista.o: lista.c hospital.h
	$(CC) $(CFLAGS) -c lista.c

pilha.o: pilha.c hospital.h
	$(CC) $(CFLAGS) -c pilha.c

tabela.o: tabela.c hospital.h
	$(CC) $(CFLAGS) -c tabela.c

# Limpeza dos arquivos compilados
clean:
	rm -f *.o $(EXEC) processamento.log

# Remove tudo e recompila do zero
rebuild: clean all