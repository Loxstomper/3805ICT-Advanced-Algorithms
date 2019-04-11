#pragma once
#include <iostream>
#include <vector>

class AdjencyList 
{
    public:
        AdjencyList();
        void setup(int size);
        int getSize(int i);
        void add(int i, int a);

    private:
        std::vector<int>* list;

};