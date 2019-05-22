#pragma once

#define GREEDY_NEIGHBOUR 1

class Node {

    public:
        int node, degree, neighbourhood_degree;

        Node(int node, int degree, int neighbourhood_degree);

        static bool compare(Node a, Node b);
};