#include "./headers/Node.hpp"

Node::Node(int node, int degree, int neighbourhood_degree)
{
    this->node = node;
    this->degree = degree;
    this->neighbourhood_degree = neighbourhood_degree;
}

bool Node::compare(Node a, Node b)
{
    if (GREEDY_NEIGHBOUR) 
    {
        return a.neighbourhood_degree > b.neighbourhood_degree;
    }
    else 
    {
        return a.degree > b.degree;
    }
}