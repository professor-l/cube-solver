SRC = colors.c cube.c search/heuristic.c search/stack.c search/ida_star.c
BIN = solver

all: main.c $(SRC)
	@gcc -std=c99 $(SRC) main.c -o $(BIN)

clean:
	@rm -f $(BIN)