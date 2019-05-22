#pragma once
#include <iostream>

class AdjencyMatrix 
{
    public:
        AdjencyMatrix();
        void setup(int size);
        int getSize();
        int index(int x, int y);
        void set(int i, int v);
        int get(int i);
        int isConnected(int a, int b);
        void print();


    private:
        int size;
        int* matrix;

};