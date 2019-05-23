#include "./headers/Solver.hpp"

Solver::Solver(int number_nodes, int number_edges, AdjencyMatrix* adj_m, AdjencyList* adj_l)
{
    this->number_nodes = number_nodes;
    this->number_edges = number_edges;
    this->adj_m = adj_m;
    this->adj_l = adj_l;
}

int Solver::solve(int target)
{
    std::cout << "Solve function" << std::endl;
    return -1;
}

int Solver::getDegree(int i)
{
    return this->adj_l->getSize(i);
}

std::vector<int>* Solver::getNeighbours(int i)
{
    return this->adj_l->getPtr(i);
}

int Solver::getNeighbourhoodDegree(int i)
{
    std::vector<int>* neighbours = this->getNeighbours(i);

    int sum = 0;

    // change to iterator
    for (int i = 0; i < neighbours->size(); i ++)
    {
        sum += this->getDegree(neighbours->at(i));
    }

    return sum;
}

void Solver::startClock()
{
    this->startTime = std::chrono::high_resolution_clock::now();
}

void Solver::stopClock()
{
    this->endTime = std::chrono::high_resolution_clock::now();
}

double Solver::getSearchTime()
{
    std::chrono::duration<double> elapsed_time = this->endTime - this->startTime;

    return elapsed_time.count();
}

bool Solver::isIS(std::unordered_set<int>* is)
{
    // iterate over is, check that no other nodes in its adj_l is in the unordered_set
    static int node;
    static std::vector<int> neighbours;

    for (auto it = is->begin(); it != is->end(); ++it) 
    {
        node = *it;
        neighbours = this->adj_l->get(node);

        for (int i = 0; i < neighbours.size(); i ++)
        {
            if (is->find(neighbours[i]) != is->end())
            {
                return false;
            }
        }
    }

    return true;
}


