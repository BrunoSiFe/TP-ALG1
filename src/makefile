CC=g++
CFLAGS=-Wall -Wextra -g
EXEC=./tp1
TMPOUT=tp1.testresult

$(EXEC): main.cpp 
	$(CC) $(CFLAGS) main.cpp -o $(EXEC)

test: $(EXEC)
	@bash run_test.sh $(EXEC) $(TMPOUT)