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
        static void read(std::string path, bool complement, AdjencyMatrix* adj_m, AdjencyList* adj_l, int* n_n, int* n_e);


    private:

};