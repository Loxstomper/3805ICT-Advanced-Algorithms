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

void LSV2ObjectWrapper::mergeAll()
{
    static int i, j;

    for (int i = 0; i < this->size; i ++)
    {
        for (int j = i; j < this->size; j ++)
        {
            // try merge the smallest
            if (this->getSizeElement(i) > this->getSizeElement(j))
            {
                this->merge(i, j);
            }
            else
            {
                this->merge(j, i);
            }
        }
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

bool LSV2ObjectWrapper::attemptInsertAll(int value)
{

    for (int i = 0; i < this->size; i ++)
    {
        if (this->insert(i, value))
        {
            if (this->objects->at(i).size > this->best)
            {
                this->best = this->objects->at(i).size;
            }

            return true;
        }
    }

    return false;
}

std::unordered_set<int> LSV2ObjectWrapper::collapse(int index)
{
    std::unordered_set<int> nodes = *this->objects->at(index).nodes;

    this->objects->erase(this->objects->begin() + index);
    this->size --;

    return nodes;
}

std::ostream &operator<<(std::ostream& stream, LSV2ObjectWrapper o)
{
    return stream;
}