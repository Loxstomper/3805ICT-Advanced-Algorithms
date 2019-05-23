
#include "./headers/LochieSolverV2.hpp"
#include "./headers/LSV2ObjectWrapper.hpp"
#include "algorithm"

LochieSolverV2::LochieSolverV2(int number_nodes, int number_edges, AdjencyMatrix* adj_m, AdjencyList* adj_l)
: Solver(number_nodes, number_edges, adj_m, adj_l)
{

}

int LochieSolverV2::solve(int target, int maxIterations, int startingSize)
{
    this->startClock();

    // just incase it gets big
    LSV2ObjectWrapper* objectWrapper = new LSV2ObjectWrapper(this->adj_l, startingSize);

    // maybe do a queue and randomize it?
    // maybe just do a set?
    std::vector<int>* unusedNodes = new std::vector<int>(this->number_nodes);

    for (int i = 0; i < this->number_nodes; i ++)
    {
        unusedNodes->at(i) = i;
    }


    // shuffle this then insert into queue
    std::random_shuffle(unusedNodes->begin(), unusedNodes->end());
    std::queue<int>* nodeQueue = new std::queue<int>;

    int tmp;

    for (int i = 0; i < this->number_nodes; i ++)
    {
        // plus 1 because nodes start at 0 and a 0
        // will be present in unusedNodes vector
        // std::cout << unusedNodes->at(i) + 1 << std::endl;
        nodeQueue->push(unusedNodes->at(i) + 1);
    }

    delete unusedNodes;

    int best = 0;
    int attempts = 0;
    int potential;
    bool inserted = false;

    // attempt to fill startingSize objects
    // do a full pass of the queue
    std::cout << "Initial Pass" << std::endl;
    for (int i = 0; i < this->number_nodes; i ++)
    {
        inserted = false;
        potential = nodeQueue->front();
        nodeQueue->pop();

        // try see if it will fit in any
        for (int i = 0; i < startingSize; i ++)
        {
            if (objectWrapper->insert(i, potential))
            {
                // std::cout << "INSERTED Node: " << potential << " Into: " << i << " Size Now: " << objectWrapper->getSizeElement(i) << std::endl;
                inserted = true;
                break;
            }
            else
            {
                // std::cout << "Failed to add Node: " << potential << " To Set: " << i << std::endl;
            }
            
        }

        if (!inserted) 
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
    // start the merging
    // just testing
    for (int i = 0; i < startingSize; i ++)
    {
        for (int j = i; j < startingSize; j ++)
        {
            // try merge the smallest
            if (objectWrapper->getSizeElement(i) > objectWrapper->getSizeElement(j))
            {
                objectWrapper->merge(i, j);
            }
            else
            {
                objectWrapper->merge(j, i);
            }
            

            if (objectWrapper->best > best) 
            {
                best = objectWrapper->best;
                std::cout << "NEW BEST: " << best  << std::endl;
            }
        }
    }

    int limit = 100;
    int cur = 0;
    int mergeTimeRange = 4;
    int mergeTime = rand() % mergeTimeRange;



    // while (cur < limit)
    while (!nodeQueue->empty() && best < target)
    {
        inserted = false;
        // attempt to add
        potential = nodeQueue->front();
        nodeQueue->pop();

        // std::cout << "POTENTIAL: " << potential << std::endl;

        for (int i = 0; i < objectWrapper->size; i ++)
        {
            if (objectWrapper->insert(i, potential))
            {
                // std::cout << "INSERTED: " << i << "Node: " << potential << " Size: " << std::endl;
                inserted = true;
                break;
            }
        }

        // couldnt insert so make a new object
        if (!inserted) 
        {
            objectWrapper->add();
            objectWrapper->insert(objectWrapper->size - 1, potential);
        }

        if (cur == mergeTime)
        {
            // now merge
            for (int i = 0; i < startingSize; i ++)
            {
                for (int j = i; j < startingSize; j ++)
                {
                    // try merge the smallest
                    if (objectWrapper->getSizeElement(i) > objectWrapper->getSizeElement(j))
                    {
                        objectWrapper->merge(i, j);
                    }
                    else
                    {
                        objectWrapper->merge(j, i);
                    }
                }
            }

            cur = 0;
            mergeTime = rand() % mergeTimeRange;
        }

        if (objectWrapper->best > best) 
        {
            best = objectWrapper->best;
            std::cout << "NEW BEST: " << best  << std::endl;
        }

        cur ++;
    }

    this->stopClock();

    return best;
}