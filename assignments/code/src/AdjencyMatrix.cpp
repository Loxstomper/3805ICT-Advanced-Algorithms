#include "./headers/AdjencyMatrix.hpp"

AdjencyMatrix::AdjencyMatrix()
{

}

void AdjencyMatrix::setup(int n_edges)
{
    this->size = n_edges;
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

void AdjencyMatrix::set(int i)
{
    this->matrix[i] = 1;
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