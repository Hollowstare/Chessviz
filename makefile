g = g++
CFLAGS = -Wall -Werror -MP -MMD

.PHONY: clean run all

all: .bin/moveP

-include build/src/*.d

./build/main.o: ./src/main.cpp ./src/header.h
	$(g) $(CFLAGS) -o build/main.o -c src/main.cpp -lm

./build/drawBoard.o: ./src/drawBoard.cpp ./src/header.h build
	$(g) $(CFLAGS) -o ./build/drawBoard.o -c ./src/drawBoard.cpp -lm

./build/moveP.o: ./src/moveP.cpp ./src/header.h
	$(g) $(CFLAGS) -o ./build/moveP.o -c ./src/moveP.cpp -lm

.bin/moveP: ./build/main.o ./build/drawBoard.o ./build/moveP.o
	$(g) $(CFLAGS) -o ./bin/moveP ./build/main.o ./build/moveP.o ./build/drawBoard.o -lm

clean:
	rm -rf build bin

run:
	./bin/moveP
