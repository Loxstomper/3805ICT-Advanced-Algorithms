#include <iostream>

#include "./headers/Reader.hpp"
#include "./headers/AdjencyMatrix.hpp"
#include "./headers/AdjencyList.hpp"


int main(int argc, char** argv)
{
    Reader reader;
    AdjencyMatrix adj_m;
    AdjencyList adj_l;

    reader.read(argv[1], &adj_m, &adj_l);

    exit(0);
}