CC = clang++ 
FLAGS = -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wfloat-equal -Wsign-compare -ggdb -std=c++11 -pedantic
LIBS = -lsqlite3

FILES = main.o
EXE = programa

build: $(FILES)
	$(CC) $(FLAGS) $(FILES) -o $(EXE) $(LIBS)
	make clean

main.o: src/main.cpp
	$(CC) $(FLAGS) -c src/main.cpp

clean:
	rm *.o
	ctags -R .
