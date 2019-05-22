
#include "./headers/LochieSolver.hpp"
#include "algorithm"

LochieSolver::LochieSolver(int number_nodes, int number_edges, AdjencyMatrix* adj_m, AdjencyList* adj_l)
: Solver(number_nodes, number_edges, adj_m, adj_l)
{

}

void LochieSolver::updatePotential(int inserted, std::unordered_set<int>* potential)
{
    for (int i = 0; i < this->adj_l->getSize(inserted); i ++)
    {
        potential->erase(this->adj_l->get(inserted)[i]);
    }
}

int LochieSolver::solve(int target, int maxIterations)
{
    this->startClock();

    int best = 0;
    int attempts = 0;

    std::unordered_set<int> mis;
    std::unordered_set<int> allNodes;
    std::unordered_set<int> potential;

    for (int i = 0; i < this->number_nodes; i ++)
    {
        allNodes.insert(i + 1);
    }

    while (best < target && attempts < maxIterations)
    {
        // clear the mis
        mis.clear();

        // copy all nodes
        potential = allNodes;

        while (!potential.empty())
        {
            // first element in set
            auto it = (potential.begin());

            // traverse - for randomization otherwise determistic
            std::advance(it, rand() % potential.size());

            int node = *it;

            // remove from potential and add to mis
            potential.erase(it);
            mis.insert(node);

            // update potential
            updatePotential(node, &potential);
        }


        if (mis.size() > best)
        {
            best = mis.size();
        }


        attempts ++;

    }

    this->stopClock();

    // std::cout << "Size: " << best << "IS? " << this->isIS(&mis) << std::endl;

    return best;
}