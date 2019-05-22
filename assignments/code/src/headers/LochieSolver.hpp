#include "./Solver.hpp"

class LochieSolver: public Solver
{
    public:
        LochieSolver(int number_nodes, int number_edges, AdjencyMatrix* adj_m, AdjencyList* adj_l);
        int solve(int target, int maxIterations);

    private:
        void updatePotential(int inserted, std::unordered_set<int>* potential);
};