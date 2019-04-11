maximum-independent-set: build/main.o build/Reader.o build/AdjencyMatrix.o build/AdjencyList.o
	g++ -o maximum-independent-set ./build/*.o

build/main.o: ./src/main.cpp 
	g++ -c ./src/main.cpp -o ./build/main.o

build/Reader.o: ./src/Reader.cpp
	g++ -c ./src/Reader.cpp -o ./build/Reader.o

build/AdjencyMatrix.o: ./src/AdjencyMatrix.cpp
	g++ -c ./src/AdjencyMatrix.cpp -o ./build/AdjencyMatrix.o

build/AdjencyList.o: ./src/AdjencyList.cpp
	g++ -c ./src/AdjencyList.cpp -o ./build/AdjencyList.o

clean:
	rm maximum-independent-set ./build/*.o 