#include "./headers/AdjencyMatrix.hpp"

AdjencyMatrix::AdjencyMatrix()
{

}

void AdjencyMatrix::setup(int n_nodes)
{
    // nodes start a 1 not 0 - makes it easier to index
    this->size = n_nodes + 1;
    // this zeroes out the memory region
    this->matrix = new int[this->size * this->size]();
}

int AdjencyMatrix::getSize()
{
    return this->size;
}

int AdjencyMatrix::index(int x, int y)
{
    return x + size * y;
}

void AdjencyMatrix::set(int i, int v)
{
    this->matrix[i] = v;
}

int AdjencyMatrix::get(int i)
{
    return this->matrix[i];
}

int AdjencyMatrix::isConnected(int a, int b)
{
    return this->matrix[this->index(a, b)] == 1;
}

void AdjencyMatrix::print()
{
    for (int i = 0; i < this->size * this->size; i ++)
    {
        std::cout << this->matrix[i] << " ";

        if (i != 0 && i % this->size == 0)
        {
            std::cout << "\n";
        }
    }
}