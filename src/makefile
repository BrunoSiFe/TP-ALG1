CC=g++
CFLAGS=-Wall -Wextra -g
EXEC=./tp1
TMPOUT=tp1.testresult

$(EXEC): main.cpp pilha.o centroDistribuicao.o postoSaude.o
	$(CC) $(CFLAGS) main.cpp pilha.o centroDistribuicao.o postoSaude.o -o $(EXEC)

pilha.o: headers/pilha.cpp
	$(CC) $(CFLAGS) -c headers/pilha.cpp -o pilha.o

centroDistribuicao.o: headers/centroDistribuicao.cpp
	$(CC) $(CFLAGS) -c headers/centroDistribuicao.cpp -o centroDistribuicao.o

postoSaude.o: headers/postoSaude.cpp 
	$(CC) $(CFLAGS) -c headers/postoSaude.cpp -o postoSaude.o

test: $(EXEC)
	@bash run_test.sh $(EXEC) $(TMPOUT)

clean: 
	rm -rf pilha.o
	rm -rf postoSaude.o
	rm -rf centroDistribuicao.o