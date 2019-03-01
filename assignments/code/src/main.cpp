#include <iostream>

#include "./headers/Reader.hpp"


int main(int argc, char** argv)
{
    Reader reader;

    reader.read(argv[1]);

    exit(0);
}