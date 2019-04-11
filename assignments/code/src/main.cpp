#include <iostream>

#include "./headers/Reader.hpp"
#include "./headers/AdjencyMatrix.hpp"
#include "./headers/AdjencyList.hpp"
#include "./headers/Solver.hpp"


int main(int argc, char** argv)
{
    Reader reader;
    AdjencyMatrix adj_m;
    AdjencyList adj_l;

    int number_nodes, number_edges;

    reader.read(argv[1], &adj_m, &adj_l, &number_nodes, &number_edges);

    Solver solver(number_nodes, number_edges, &adj_m, &adj_l);

    int target = 10;

    solver.solve(target);

    exit(0);
}