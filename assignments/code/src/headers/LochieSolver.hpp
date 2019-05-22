#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

#include "./AdjencyMatrix.hpp"
#include "./AdjencyList.hpp"

class LochieSolver
{
    public:
        LochieSolver(int number_nodes, int number_edges, AdjencyMatrix* adj_m, AdjencyList* adj_l);
        void solve(int target);

    private:
        int number_nodes, number_edges;
        AdjencyMatrix* adj_m;
        AdjencyList* adj_l;

        int getDegree(int i);
        std::vector<int> getNeighbours(int i);
        int getNeighbourhoodDegree(int i);
};