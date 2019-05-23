#include "./headers/LSV2ObjectWrapper.hpp"

LSV2ObjectWrapper::LSV2ObjectWrapper(AdjencyList* adj_l, int startingSize)
{
    this->adj_l = adj_l;
    this->size = startingSize;
    this->best = 0;
    this->objects = new std::vector<LSV2Object>(this->size);

    for (int i = 0; i < this->objects->size(); i ++)
    {
        this->objects->at(i).setAdjList(adj_l);
    }
}

// LSV2Object* LSV2ObjectWrapper::get(int i)
// {
//     return &(this->objects[i]);
// }

void LSV2ObjectWrapper::add(LSV2Object obj)
{
    this->objects->push_back(obj);
    this->size ++;
}

void LSV2ObjectWrapper::merge(int a, int b)
{
    this->objects->at(a).merge(&this->objects->at(b));

    if (this->objects->at(a).size > best)
    {
        best = this->objects->at(a).size;
    }
}

bool LSV2ObjectWrapper::insert(int index, int value)
{
    // return this->objects[index].insert(value);
    return this->objects->at(index).insert(value);
}

std::ostream &operator<<(std::ostream& stream, LSV2ObjectWrapper o)
{
    return stream;
}