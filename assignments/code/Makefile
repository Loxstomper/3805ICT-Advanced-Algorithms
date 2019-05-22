debug = -g
optimize = -O2

maximum-independent-set: build/main.o build/Reader.o build/AdjencyMatrix.o build/AdjencyList.o build/Solver.o build/GreedySolver.o build/LochieSolver.o build/Node.o
# maximum-independent-set: build/main.o build/Reader.o build/AdjencyMatrix.o build/AdjencyList.o build/Solver.o build/Node.o
	g++ ${debug} ${optimize} -o maximum-independent-set ./build/*.o

build/main.o: ./src/main.cpp 
	g++ ${debug} ${optimize} -c ./src/main.cpp -o ./build/main.o

build/Reader.o: ./src/Reader.cpp
	g++ ${debug} ${optimize} -c ./src/Reader.cpp -o ./build/Reader.o

build/AdjencyMatrix.o: ./src/AdjencyMatrix.cpp
	g++ ${debug} ${optimize} -c ./src/AdjencyMatrix.cpp -o ./build/AdjencyMatrix.o

build/AdjencyList.o: ./src/AdjencyList.cpp
	g++ ${debug} ${optimize} -c ./src/AdjencyList.cpp -o ./build/AdjencyList.o

build/Solver.o: ./src/Solver.cpp build/Node.o
	g++ ${debug} ${optimize} -c ./src/Solver.cpp -o ./build/Solver.o

build/GreedySolver.o: ./src/GreedySolver.cpp
	g++ ${debug} ${optimize} -c ./src/GreedySolver.cpp -o ./build/GreedySolver.o

build/LochieSolver.o: ./src/LochieSolver.cpp
	g++ ${debug} ${optimize} -c ./src/LochieSolver.cpp -o ./build/LochieSolver.o

build/Node.o: ./src/Node.cpp
	g++ ${debug} ${optimize} -c ./src/Node.cpp -o ./build/Node.o

clean:
	rm maximum-independent-set ./build/*.o 