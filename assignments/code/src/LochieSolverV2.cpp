
#include "./headers/LochieSolverV2.hpp"
#include "./headers/LSV2ObjectWrapper.hpp"
#include "algorithm"

LochieSolverV2::LochieSolverV2(int number_nodes, int number_edges, AdjencyMatrix* adj_m, AdjencyList* adj_l)
: Solver(number_nodes, number_edges, adj_m, adj_l)
{

}

void LochieSolverV2::prepareQueue(std::queue<int>* nodeQueue)
{
    std::vector<int>* nodesVector = new std::vector<int>(this->number_nodes);

    for (int i = 0; i < this->number_nodes; i ++)
    {
        nodesVector->at(i) = i;
    }

    // shuffle vector 
    std::random_shuffle(nodesVector->begin(), nodesVector->end());

    // populate queue
    for (int i = 0; i < this->number_nodes; i ++)
    {
        // plus 1 because nodes start at 1 and a 0
        // will be present in unusedNodes vector
        nodeQueue->push(nodesVector->at(i) + 1);
    }

    // no need for unusedNodes anymore
    delete nodesVector;
}

int LochieSolverV2::solve(int target, int maxIterations, int startingSize)
{
    this->startClock();

    // just incase it gets big
    LSV2ObjectWrapper* objectWrapper = new LSV2ObjectWrapper(this->adj_l, startingSize);
    std::queue<int>* nodeQueue       = new std::queue<int>;

    this->prepareQueue(nodeQueue);

    int best = 0;
    int potential;
    int mergeTimeRange = 4;
    int mergeTime = rand() % mergeTimeRange;

    // attempt to fill startingSize objects
    // do a full pass of the queue
    std::cout << "Initial Pass" << std::endl;
    for (int i = 0; i < this->number_nodes; i ++)
    {
        potential = nodeQueue->front();
        nodeQueue->pop();

        if (!objectWrapper->attemptInsertAll(potential))
        {
            nodeQueue->push(potential);
        }

        if (objectWrapper->best > best)
        {
            best = objectWrapper->best;
            std::cout << "NEW BEST: " << best << std::endl;
        }

    }

    std::cout << "Initial Merge:" << std::endl;

    objectWrapper->mergeAll();

    if (objectWrapper->best > best) 
    {
        best = objectWrapper->best;
        std::cout << "NEW BEST: " << best  << std::endl;
    }

    int limit = 100;
    int cur = 0;


    // make another for loop to do the empty thing
    while (cur < limit)
    {
        while (!nodeQueue->empty() && best < target)
        {
            // attempt to add
            potential = nodeQueue->front();
            nodeQueue->pop();

            // inserted = objectWrapper->attemptInsertAll(potential);

            // couldnt insert so make a new object
            if (!objectWrapper->attemptInsertAll(potential))
            {
                objectWrapper->add();
                objectWrapper->insert(objectWrapper->size - 1, potential);
            }

            if (cur == mergeTime)
            {
                objectWrapper->mergeAll();

                cur = 0;
                mergeTime = rand() % mergeTimeRange;
            }

            if (objectWrapper->best > best) 
            {
                best = objectWrapper->best;
                std::cout << "NEW BEST: " << best  << std::endl;
            }

        }
        // collapse a random set
        // int index = rand() % objectWrapper->size;
        // std::unordered_set<int> collapsed = objectWrapper->collapse(index);

        // // iterate over and put into queue
        // std::cout << "COLLAPSED" << std::endl;
        // for (auto it = collapsed.begin(); it != collapsed.end(); ++it)
        // {
        //     // std::cout << *it << std::endl;
        //     nodeQueue->push(*it);
        // }



        cur ++;
    }

        // std::cout << "HERE?" << std::endl;


    this->stopClock();

    // checking they are all IS
    for (int i = 0; i < objectWrapper->size; i ++)
    {
        if (!this->isIS(objectWrapper->objects->at(i).nodes))
        {
            std::cout << "Not valid" << std::endl;
            break;
        }
    }

    return best;
}