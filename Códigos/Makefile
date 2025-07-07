EXEC = hospital
CC = gcc
CFLAGS = -Wall -g
OBJS = hospital.o tabela.o deque.o lista.o pilha.o

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

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

clean:
	rm -f *.o $(EXEC) ../Histórico/processamento.log