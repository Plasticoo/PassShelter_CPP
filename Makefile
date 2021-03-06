CC = clang++ 
FLAGS = -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wfloat-equal -Wconversion -Wsign-compare -Wextra-tokens  -ggdb -std=c++11 -pedantic
LIBS = -lsqlite3

FILES = main.o sqlite.o aes.o enc.o callbacks.o
EXE = passshelter

build: $(FILES)
	$(CC) $(FLAGS) $(FILES) -o $(EXE) $(LIBS)
	make clean

main.o: src/main.cpp
	$(CC) $(FLAGS) -c src/main.cpp

sqlite.o: src/sqlite.cpp
	$(CC) $(FLAGS) -c src/sqlite.cpp

aes.o: src/aes.c
	$(CC) $(FLAGS) -c src/aes.c

enc.o: src/enc.cpp
	$(CC) $(FLAGS) -c src/enc.cpp

callbacks.o: src/callbacks.c
	$(CC) $(FLAGS) -c src/callbacks.c

clean:
	rm *.o
	ctags -R .
