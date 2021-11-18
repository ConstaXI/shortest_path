//
// Created by DaviB on 16/11/2021.
//

#include "fgraph.h"

std::vector<long int> get_vertices_and_edges(std::ifstream &dataset) {
    std::string s;

    std::vector<long int> out;

    std::getline(dataset, s, ' ');
    out.push_back(std::stol(s));
    std::getline(dataset, s, ' ');
    out.push_back(std::stol(s));

    dataset.clear();
    dataset.seekg (0, std::ios::beg);

    return out;
}

std::vector<std::vector<long int>> get_adjacency_list_graph(std::ifstream &dataset) {
    std::string s;
    std::string inner_s;

    std::vector<long int> line;
    std::vector<std::vector<long int>> graph;

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
