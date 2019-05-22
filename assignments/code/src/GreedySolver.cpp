#include "./headers/GreedySolver.hpp"

class NodeCompare {
    public:
        bool neighbourDegree;

        NodeCompare(bool n) : neighbourDegree(n) {}

        bool operator()(const Node& a, const Node& b)
        {
            return (this->neighbourDegree) ? a.neighbourhood_degree > b.neighbourhood_degree :
                                             a.degree > b.degree;
        }
};

GreedySolver::GreedySolver(int number_nodes, int number_edges, AdjencyMatrix* adj_m, AdjencyList* adj_l)
: Solver(number_nodes, number_edges, adj_m, adj_l)
{
    this->compareNeighbourDegree = false;
}

bool GreedySolver::compareNodes(Node a, Node b) 
{
    return (this->compareNeighbourDegree == true) ? a.neighbourhood_degree > b.neighbourhood_degree :
                                                    a.degree > b.degree;
}

int GreedySolver::solve(bool neighbourDegreeCompare, int target)
{
    this->compareNeighbourDegree = neighbourDegreeCompare;
    this->startClock();

    // set intersection?
    std::unordered_set<int> is;
    // std::priority_queue<Node, std::vector<Node>, bool(*)(Node, Node)> q(Node::compareNeighbourDegree);
    // std::priority_queue<Node, std::vector<Node>, bool(*)(Node, Node)> q(GreedySolver::compareNodes);
    std::priority_queue<Node, std::vector<Node>, NodeCompare> q((NodeCompare(neighbourDegreeCompare)));


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

    this->stopClock();

    return is.size();
}