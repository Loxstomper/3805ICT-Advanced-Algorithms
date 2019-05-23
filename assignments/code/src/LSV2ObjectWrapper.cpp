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

int LSV2ObjectWrapper::getSizeElement(int i)
{
    return this->objects->at(i).size;
}

void LSV2ObjectWrapper::add(LSV2Object obj)
{
    this->objects->push_back(obj);
    this->size ++;
}

void LSV2ObjectWrapper::add()
{
    this->objects->push_back(LSV2Object());
    this->size ++;

    this->objects->at(this->size - 1).setAdjList(this->adj_l);
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
    static bool success;

    success = this->objects->at(index).insert(value);
    if (success)
    {
        if (this->objects->at(index).size > this->best)
        {
            this->best = this->objects->at(index).size;
        }
    }

    return success;
}

std::ostream &operator<<(std::ostream& stream, LSV2ObjectWrapper o)
{
    return stream;
}