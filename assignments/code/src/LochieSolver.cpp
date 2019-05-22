#include "./headers/LochieSolver.hpp"
#include "./headers/Node.hpp"

LochieSolver::LochieSolver(int number_nodes, int number_edges, AdjencyMatrix* adj_m, AdjencyList* adj_l)
{
    this->number_nodes = number_nodes;
    this->number_edges = number_edges;
    this->adj_m = adj_m;
    this->adj_l = adj_l;
}

void LochieSolver::solve(int target)
{

}

int LochieSolver::getDegree(int i)
{
    return this->adj_l->getSize(i);
}

std::vector<int> LochieSolver::getNeighbours(int i)
{
    return this->adj_l->get(i);
}

int LochieSolver::getNeighbourhoodDegree(int i)
{
    std::vector<int> neighbours = this->getNeighbours(i);

    int sum = 0;

    // change to iterator
    for (int i = 0; i < neighbours.size(); i ++)
    {
        sum += this->getDegree(neighbours[i]);
    }

    return sum;
}


