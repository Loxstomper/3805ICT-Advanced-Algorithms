#pragma once

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_set>
#include <queue>

#include "./AdjencyMatrix.hpp"
#include "./AdjencyList.hpp"
#include "./Node.hpp"

class Solver
{
    public:
        Solver(int number_nodes, int number_edges, AdjencyMatrix* adj_m, AdjencyList* adj_l);
        int solve(int target);
        double getSearchTime();
        bool isIS(std::unordered_set<int>* is);

    protected:
        int number_nodes, number_edges;
        AdjencyMatrix* adj_m;
        AdjencyList* adj_l;
        std::chrono::high_resolution_clock::time_point startTime;
        std::chrono::high_resolution_clock::time_point endTime;

        int getDegree(int i);
        std::vector<int>* getNeighbours(int i);
        int getNeighbourhoodDegree(int i);

        void startClock();
        void stopClock();

};