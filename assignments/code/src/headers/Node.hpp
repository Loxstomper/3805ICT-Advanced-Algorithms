#pragma once

#define GREEDY_NEIGHBOUR 1

class Node {

    public:
        int node, degree, neighbourhood_degree;

        Node(int node, int degree, int neighbourhood_degree);

        // bool operator()(const Node& a, const Node& b);
};