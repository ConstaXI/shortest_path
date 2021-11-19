//
// Created by DaviB on 16/11/2021.
//

#include <algorithm>
#include "fgraph.h"

std::vector<std::vector<int>> get_graph(std::ifstream &dataset) {
    std::string s;
    std::string inner_s;

    std::vector<int> line;
    std::vector<std::vector<int>> graph;

    while(std::getline(dataset, s, '\n')) {
        std::stringstream out_s(s);
        while(std::getline(out_s, inner_s, ' ')) {
            line.push_back(std::stol(inner_s));
        }
        graph.push_back(line);
        line.clear();
    }

    return graph;
}

std::vector<int> get_path(std::vector<int> prev, const int src, const int trg) {
    std::vector<int> path;

    path.push_back(trg);

    int temp = trg;

    while (temp != src) {
        temp = prev[temp];
        path.push_back(temp);
    }

    std::reverse(path.begin(), path.end());

    return path;
}