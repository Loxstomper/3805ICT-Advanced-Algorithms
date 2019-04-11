#include "./headers/Reader.hpp"

Reader::Reader()
{

}

void Reader::read(std::string path, AdjencyMatrix* adj_m, AdjencyList* adj_l)
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
            std::cout << "Nodes: " << number_nodes << "\tEdges: " << number_edges << std::endl;

            adj_m->setup(number_nodes);
            adj_l->setup(number_edges);
        }
        // e | a | b
        else 
        {
            sscanf(line.c_str(), "%c %d %d", &tmp, &a, &b);

            // update datastructures
            adj_m->set(adj_m->index(a, b));
            adj_m->set(adj_m->index(b, a));

            adj_l->add(a, b);
            adj_l->add(b, a);
        }
    }

    file.close();
}