#include "./headers/Node.hpp"

Node::Node(int node, int degree, int neighbourhood_degree)
{
    this->node = node;
    this->degree = degree;
    this->neighbourhood_degree = neighbourhood_degree;
}

bool Node::compareNeighbourDegree(Node a, Node b)
{
    return a.neighbourhood_degree > b.neighbourhood_degree;
}

bool Node::compareDegree(Node a, Node b)
{
    return a.degree > b.degree;
}