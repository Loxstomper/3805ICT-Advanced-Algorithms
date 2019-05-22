#include "./headers/Node.hpp"

Node::Node(int node, int degree, int neighbourhood_degree)
{
    this->node = node;
    this->degree = degree;
    this->neighbourhood_degree = neighbourhood_degree;
}

// bool Node::operator()(const Node& a, const Node& b)
// {
//     if (GREEDY_NEIGHBOUR) 
//     {
//         return a.neighbourhood_degree > b.neighbourhood_degree;
//     }
//     else
//     {
//         return a.degree > b.degree;
//     }
// }

// bool operator<(const Node& a, const Node& b) 
// {
//     return a.neighbourhood_degree > b.neighbourhood_degree;
// }