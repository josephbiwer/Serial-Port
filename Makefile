CC = cc

BIN = obj
SRC = src

world: $(SRC)/main.c $(BIN)/serial.o
	$(CC) $(SRC)/main.c $(BIN)/serial.o -o run

$(BIN)/serial.o: $(SRC)/serial.c $(SRC)/serial.h
	$(CC) -c $(SRC)/serial.c -o $@