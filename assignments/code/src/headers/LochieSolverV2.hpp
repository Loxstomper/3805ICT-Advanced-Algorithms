#pragma once

#include "./Solver.hpp"
#include "./LSV2Object.hpp"

class LochieSolverV2: public Solver
{
    public:
        LochieSolverV2(int number_nodes, int number_edges, AdjencyMatrix* adj_m, AdjencyList* adj_l);
        int solve(int target, int maxIterations, int startingSize);

    private:
};