#include <iostream>
#include <time.h>
#include <chrono>

#include "./headers/Reader.hpp"
#include "./headers/AdjencyMatrix.hpp"
#include "./headers/AdjencyList.hpp"
#include "./headers/Solver.hpp"
#include "./headers/LochieSolver.hpp"


int main(int argc, char** argv)
{
    Reader reader;
    AdjencyMatrix adj_m;
    AdjencyList adj_l;

    int number_nodes, number_edges;

    reader.read(argv[1], &adj_m, &adj_l, &number_nodes, &number_edges);

    Solver solver(number_nodes, number_edges, &adj_m, &adj_l);

    int target = 10;


    auto start_time = std::chrono::high_resolution_clock::now();

    solver.solve(target);

    auto search_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = search_time - start_time;
    std::cout << "DURATION: " << elapsed_time.count() << std::endl;

    exit(0);
}