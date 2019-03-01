maximum-independent-set: main.o Reader.o
	g++ -o maximum-independent-set ./build/*.o

main.o: ./src/main.cpp Reader.o
	g++ -c ./src/main.cpp -o ./build/main.o

Reader.o: ./src/Reader.cpp
	g++ -c ./src/Reader.cpp -o ./build/Reader.o

clean:
	rm maximum-independent-set ./build/*.o 