#include "./headers/LSV2Object.hpp"

LSV2Object::LSV2Object(AdjencyList* adj_list)
{
    this->adj_list = adj_list;
    this->nodes = new std::unordered_set<int>;
    this->adj_map = new std::unordered_map<int, int>;
    this->size = 0;
}

bool LSV2Object::insert(int node)
{
    // check not already in nodes
    if (this->nodes->find(node) != this->nodes->end())
    {
        return false;
    }

    // check if already in adj_map
    auto location = this->adj_map->find(node);

    // dont insert if adj_map[node] != 0
    if (location != this->adj_map->end() && location->second != 0)
    {
        return false;
    }

    // increment - set to 1
    if (location != this->adj_map->end())
    {
        location->second ++;
    }
    // add
    else
    {
        this->adj_map->insert(std::make_pair(node, 1));
    }

    // insert the node
    this->nodes->insert(node);

    // now add all of node neighbours into the list
    std::vector<int>* nodeAdj = this->adj_list->getPtr(node);

    for (int i = 0; i < nodeAdj->size(); i ++)
    {
        // search if the node is already in the adj_map
        auto location = this->adj_map->find(nodeAdj->at(i));

        // it isnt so add it
        if (location == this->adj_map->end()) 
        {
            // this->adj_map[nodeAdj[i]] = 1;
            this->adj_map->insert(std::make_pair(nodeAdj->at(i), 1));
        }
        // it is so increment
        else
        {
            location->second ++;
        }
    }


    this->size ++;

    return true;
}

// inplace merge from b -> a
// remainder is in b
void LSV2Object::merge(LSV2Object* b)
{
    // iterate through b's nodes
    for (auto it = b->nodes->begin(); it != b->nodes->end(); ++it)
    {
        // skip if node already present
        if (this->nodes->find(*it) != this->nodes->end())
        {
            continue;
        }

        // node is not in A's adjency map
        if (this->adj_map->find(*it) == this->adj_map->end())
        {
            // can add it to the IS
            this->nodes->insert(*it);

            // now insert its adj_list into A adj_map
            // change this to the wrappers adj_list so we only store one
            auto nodeAdj = this->adj_list->get(*it);
            for (int i = 0; i < nodeAdj.size(); i ++)
            {
                // search if the node is already in the adj_map
                auto location = this->adj_map->find(nodeAdj[i]);

                // it isnt so add it
                if (location == this->adj_map->end()) 
                {
                    // this->adj_map[nodeAdj[i]] = 1;
                    this->adj_map->insert(std::make_pair(nodeAdj[i], 1));
                }
                // it is so increment
                else
                {
                    location->second ++;
                }

                // same but removal for b
                location = b->adj_map->find(nodeAdj[i]);

                // no need to check because it was added on insertion

                // was the only node with an adjacent
                // remove
                if (location->second == 1)
                {
                    b->adj_map->erase(location);
                }
                // decrement
                else
                {
                    location->second --;
                }

                // remove b.node from b.nodes
                b->nodes->erase(*it);
            }
        }

    }

    this->size = this->nodes->size();
}

std::ostream &operator<<(std::ostream& stream, LSV2Object o)
{
    stream << "Nodes:\n";

    for (auto it = o.nodes->begin(); it != o.nodes->end(); ++it)
    {
        stream << *it << " ";
    }

    stream << "\n\n";

    stream << "ADJ MAP:\n";

    for (auto it = o.adj_map->begin(); it != o.adj_map->end(); ++it)
    {
        stream << it->first << ": " << it->second << "\n";
    }

    return stream;
}