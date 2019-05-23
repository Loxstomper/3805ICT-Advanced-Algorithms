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
        void add();
        int getSizeElement(int i);
        int getBest();

        void merge(int a, int b);
        void mergeAll();
        bool insert(int index, int value);
        bool attemptInsertAll(int value);


        int size;
        int best;
        std::vector<LSV2Object>* objects;

        friend std::ostream &operator<<(std::ostream& stream, LSV2ObjectWrapper o);
    private:
        AdjencyList* adj_l;
};