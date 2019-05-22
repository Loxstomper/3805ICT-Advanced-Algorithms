#pragma once

class Node {

    public:
        int node, degree, neighbourhood_degree;

        Node(int node, int degree, int neighbourhood_degree);

        static bool compareNeighbourDegree(Node a, Node b);
        static bool compareDegree(Node a, Node b);
};