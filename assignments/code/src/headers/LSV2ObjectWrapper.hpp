#pragma once

#include <iostream>

#include "./LSV2Object.hpp"
#include "./AdjencyList.hpp"

class LSV2ObjectWrapper
{
    public:
        LSV2ObjectWrapper(AdjencyList* adj_l, int startingSize);

        // LSV2Object* get(int i);
        void add(LSV2Object obj);
        int getSize();
        int getBest();

        void merge(int a, int b);
        bool insert(int index, int value);


        int size;
        int best;

        friend std::ostream &operator<<(std::ostream& stream, LSV2ObjectWrapper o);
    private:
        AdjencyList* adj_l;
        std::vector<LSV2Object>* objects;
};