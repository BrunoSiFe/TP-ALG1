CC=g++
CFLAGS=-Wall -Wextra -g
EXEC=./tp01
TMPOUT=tp01.testresult

$(EXEC): main.cpp centroDistribuicao.o postoSaude.o
	$(CC) $(CFLAGS) main.cpp centroDistribuicao.o postoSaude.o -o $(EXEC)

centroDistribuicao.o: headers/centroDistribuicao.cpp
	$(CC) $(CFLAGS) -c headers/centroDistribuicao.cpp -o centroDistribuicao.o

postoSaude.o: headers/postoSaude.cpp 
	$(CC) $(CFLAGS) -c headers/postoSaude.cpp -o postoSaude.o

test: $(EXEC)
	@bash run_test.sh $(EXEC) $(TMPOUT)

clean: 
	rm -rf postoSaude.o
	rm -rf centroDistribuicao.o