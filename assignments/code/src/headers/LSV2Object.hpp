#pragma once

#include <iostream>
#include <unordered_set>
#include <unordered_map>

#include "./AdjencyList.hpp"

class LSV2Object
{
    public:
        LSV2Object(AdjencyList* adj_list);
        void merge(LSV2Object* b);
        bool insert(int node);

        int size;
        std::unordered_set<int>* nodes;
        std::unordered_map<int, int>* adj_map;

        friend std::ostream &operator<<(std::ostream& stream, LSV2Object o);
    
    private:
        AdjencyList* adj_list;

};