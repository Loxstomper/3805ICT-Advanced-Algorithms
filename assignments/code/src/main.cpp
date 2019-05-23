#include <iostream>
#include <string>
#include <map>
#include <cstring>

#include "./headers/Reader.hpp"
#include "./headers/AdjencyMatrix.hpp"
#include "./headers/AdjencyList.hpp"
#include "./headers/GreedySolver.hpp"
#include "./headers/LochieSolver.hpp"
#include "./headers/LochieSolverV2.hpp"


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
                << std::abs(double(mis - target) / target) * 100.0f << "\t"
                << time << std::endl;
}

int main(int argc, char** argv)
{
    AdjencyMatrix adj_m;
    AdjencyList adj_l;

    int number_nodes, number_edges;

    srand(time(NULL));

    bool complement = (argc > 2 && (strcmp(argv[2], "c") == 0)) ? true : false;

    // std::cout << "COMPLEMENT? : " << complement << std::endl;

    Reader::read(argv[1], complement, &adj_m, &adj_l, &number_nodes, &number_edges);

    // filename -> [target, target complement]
    std::map<std::string, std::tuple<int, int>> targets;

    targets["./data/brock800_1.clq"] = std::tuple<int, int>(10, 23);
    targets["./data/brock800_2.clq"] = std::tuple<int, int>(10, 24);
    targets["./data/brock800_3.clq"] = std::tuple<int, int>(11, 25);
    targets["./data/brock800_4.clq"] = std::tuple<int, int>(10, 26);
    targets["./data/C2000.5.clq"   ] = std::tuple<int, int>(17, 16);
    targets["./data/C2000.9.clq"   ] = std::tuple<int, int>(6, 78);
    targets["./data/C4000.5.clq"   ] = std::tuple<int, int>(18, 18);
    targets["./data/keller6.clq"   ] = std::tuple<int, int>(63, 59);
    targets["./data/MANN_a45.clq"  ] = std::tuple<int, int>(3, 344);
    targets["./data/san1000.clq"   ] = std::tuple<int, int>(67, 15);

    int target = getTarget(argv[1], complement, targets);
    int mis;
    double time;

    // complement status here too
    std::cout << "\nFile: " << argv[1] << "\tTarget: " << target <<  std::endl;
    // std::cout << "Method\tMIS\tError\tPercentage\tTime\n" << std::endl;

    GreedySolver greedySolver(number_nodes, number_edges, &adj_m, &adj_l);
    LochieSolver lochieSolver(number_nodes, number_edges, &adj_m, &adj_l);
    LochieSolverV2 lochieSolverV2(number_nodes, number_edges, &adj_m, &adj_l);

    // mis  = lochieSolverV2.solve(target, 100, 4);
    // time = lochieSolverV2.getSearchTime();

    // output(target, "LochieV2", mis, time);

    double counts[4] = {0, 0, 0, 0};
    double times[4] = {0, 0, 0, 0};

    for (int i = 0; i < 1; i ++)
    {
        mis  = lochieSolver.solve(target, 5000);
        time = lochieSolver.getSearchTime();

        counts[0] += mis;
        times[0] += time;
        // output(target, "LochieV1", mis, time);

        mis  = lochieSolverV2.solve(target, 100, 4);
        time = lochieSolverV2.getSearchTime();

        counts[1] += mis;
        times[1] += time;

        // output(target, "LochieV2", mis, time);

        mis  = greedySolver.solve(true, target);
        time = greedySolver.getSearchTime();

        counts[2] += mis;
        times[2] += time;

        // output(target, "GreedyDegree", mis, time);

        mis  = greedySolver.solve(false, target);
        time = greedySolver.getSearchTime();

        counts[3] += mis;
        times[3] += time;

        // output(target, "GreedyNeighbourhoodDegree", mis, time);
    }

    for (int i = 0; i < 4; i ++)
    {
        // counts[i] /= 10.0;
        // times[i] /= 10.0;

        std::cout << counts[i] << "\t" << times[i] << std::endl;
    }

    std::cout << std::endl;

    exit(0);
}
