#include <iostream>
#include <string>
#include <map>

#include "./headers/Reader.hpp"
#include "./headers/AdjencyMatrix.hpp"
#include "./headers/AdjencyList.hpp"
#include "./headers/LochieSolver.hpp"
#include "./headers/GreedySolver.hpp"

int getTarget(char* file, bool complement, std::map<std::string, std::tuple<int, int>>& map)
{
    std::string filename(file);

    auto search = map.find(filename);
    if (search == map.end()) 
    {
        std::cout << "Target not found" << std::endl;
        return -1;
    }

    return complement ? std::get<1>(search->second) : std::get<0>(search->second);
}

void output(int target, std::string method, int mis, double time) 
{
    std::cout << method << ": "
                << mis << "\t"
                << target - mis << "\t"
                << (target / mis) * 100 << "\t"
                << time << std::endl;
}

// iterations, files?
// void test()

// try using the optimizer too - O2
int main(int argc, char** argv)
{
    Reader reader;
    AdjencyMatrix adj_m;
    AdjencyList adj_l;

    int number_nodes, number_edges;

    // add complement support in read function
    // use argv[2]
    reader.read(argv[1], &adj_m, &adj_l, &number_nodes, &number_edges);

    // filename -> [target, target complement]
    std::map<std::string, std::tuple<int, int>> targets;

    targets["./data/brock800_1.clq"] = std::tuple<int, int>(10, 23);
    targets["./data/brock800_2.clq"] = std::tuple<int, int>(10, 24);
    targets["./data/brock800_3.clq"] = std::tuple<int, int>(11, 25);
    targets["./data/brock800_4.clq"] = std::tuple<int, int>(10, 26);
    targets["./data/c2000.5.clq"   ] = std::tuple<int, int>(17, 16);
    targets["./data/c2000.9.clq"   ] = std::tuple<int, int>(6, 78);
    targets["./data/c4000.5.clq"   ] = std::tuple<int, int>(18, 18);
    targets["./data/keller6.clq"   ] = std::tuple<int, int>(63, 59);
    targets["./data/MANN_a45.clq"  ] = std::tuple<int, int>(3, 344);
    targets["./data/san1000.clq"   ] = std::tuple<int, int>(67, 15);

    int target = getTarget(argv[1], false, targets);
    int mis;
    double time;

    // complement status here too
    std::cout << "\nFile: " << argv[1] << "\tTarget: " << target << "\n\n" << std::endl;
    std::cout << "Method\tMIS\tDifference\tPercentage\tTime\n" << std::endl;

    GreedySolver greedySolver(number_nodes, number_edges, &adj_m, &adj_l);

    mis = greedySolver.solve(target, true);
    time = greedySolver.getSearchTime();

    output(target, "Greedy - node degree", mis, time);

    mis = greedySolver.solve(target, false);
    time = greedySolver.getSearchTime();

    output(target, "Greedy - neighbourhood degree", mis, time);
    std::cout << std::endl;

    exit(0);
}