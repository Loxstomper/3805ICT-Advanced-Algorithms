#include "./headers/AdjencyList.hpp"

AdjencyList::AdjencyList()
{

}

void AdjencyList::setup(int size)
{
    // +1 for 1 -> 1 node number to indexing
    this->list = new std::vector<int>[size + 1];
}

int AdjencyList::getSize(int i)
{
    return this->list[i].size();
}

void AdjencyList::add(int i, int a)
{
    this->list[i].push_back(a);
}
