#include "./Solver.hpp"

class GreedySolver: public Solver
{
    public:
        GreedySolver(int number_nodes, int number_edges, AdjencyMatrix* adj_m, AdjencyList* adj_l);
        int solve(bool neighbourDegreeCompare, int target);
        bool compareNodes(Node a, Node b);
    
    private:
        bool compareNeighbourDegree;
};