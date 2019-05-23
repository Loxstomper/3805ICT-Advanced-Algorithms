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
        std::vector<int> get(int i);
        std::vector<int>* getPtr(int i);

    private:
        std::vector<int>* list;

};