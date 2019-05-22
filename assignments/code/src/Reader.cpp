#include "./headers/Reader.hpp"

Reader::Reader()
{

}

void Reader::read(std::string path, bool complement, AdjencyMatrix* adj_m, AdjencyList* adj_l, int* n_n, int* n_e)
{
    std::ifstream file;
    file.open(path);

    std::string line;
    char tmp, temp[5];
    int number_nodes, number_edges, a, b;

    while (std::getline(file, line))
    {
        // this line is a comment
        if (line[0] == 'c') 
        {
            continue;
        }

        // this line states number of nodes and edges
        if (line[0] == 'p')
        {
            sscanf(line.c_str(), "%c %s %d %d", &tmp, temp, &number_nodes, &number_edges);

            // initialize datastructures
            // std::cout << "Nodes: " << number_nodes << "\tEdges: " << number_edges << std::endl;

            // update pointer values
            *n_n = number_nodes;
            *n_e = number_edges;

            adj_m->setup(number_nodes);

            adj_l->setup(number_nodes);
            // adj_l->setup(number_edges);
        }
        // e | a | b
        else 
        {
            sscanf(line.c_str(), "%c %d %d", &tmp, &a, &b);

            // update datastructures
            adj_m->set(adj_m->index(a, b), 1);
            adj_m->set(adj_m->index(b, a), 1);

            // no point adding if going to redo
            if (!complement)
            {
                adj_l->add(a, b);
                adj_l->add(b, a);
            }
        }
    }

    file.close();

    int index;
    if (complement) 
    {
        // invert matrix and populate adj_l
        for (int i = 1; i < number_nodes; i ++)
        {
            for (int j = 1; j < number_nodes; i ++)
            {
                index = adj_m->index(i, j);

                if (adj_m->get(index) == 0) 
                {
                    adj_m->set(index, 1);
                    // double check if needs to be done twice
                    adj_l->add(i, j);
                    adj_l->add(j, i);
                } 
                else 
                {
                    adj_m->set(index, 0);
                }
            }
        }

    }

}