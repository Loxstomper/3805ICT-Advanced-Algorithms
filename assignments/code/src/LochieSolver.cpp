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
    // set intersection?
    std::unordered_set<int> is;
    std::priority_queue<Node, std::vector<Node>, bool(*)(Node, Node)> q(Node::compare);

    for (int i = 1; i <= this->number_nodes; i ++)
    {
        // std::cout << "Node: " << i << "\tDegree: " << this->getDegree(i) << "\tNeighbourhoodDegree: " << this->getNeighbourhoodDegree(i) << std::endl;

        q.push(Node(i, this->getDegree(i), this->getNeighbourhoodDegree(i)));
    }

    // priority que of tuple (node_number, nighbourhooddegree)
    // pop see if it can be added to set, if not forget about it
    // when add do a set inersection between IS and popped node - cant add if is greater than length 1

    int collision;

    while (!q.empty())
    {
        collision = 0;
        Node potential = q.top();
        q.pop();

        // check potential node wont cause an edge
        for (int i = 0; i < this->adj_l->get(potential.node).size(); i ++)
        {
            if (is.find(this->adj_l->get(potential.node)[i]) != is.end())
            {
                collision = 1;
                break;
            }
        }

        if (!collision)
        {
            is.insert(potential.node);
        }


        // std::cout << q.top().neighbourhood_degree << std::endl;
        // q.pop();
    }

    std::cout << "SIZE: " << is.size() << std::endl;

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


