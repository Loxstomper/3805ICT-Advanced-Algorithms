#pragma once

#include <string>
#include <iostream>
#include <fstream>

#include "AdjencyMatrix.hpp"
#include "AdjencyList.hpp"

class Reader
{
    public:
        Reader();
        void read(std::string path, AdjencyMatrix* adj_m, AdjencyList* adj_l, int* n_n, int* n_e);


    private:

};