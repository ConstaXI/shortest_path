//
// Created by DaviB on 16/11/2021.
//

#ifndef GRAFOS_FGRAPH_H
#define GRAFOS_FGRAPH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

typedef struct minimum_distance {
    std::vector<long int> distance;
    std::vector<long int> prev;
    std::vector<long int> path;
    long int cost;
    std::chrono::milliseconds ms;
} t_distance;

std::vector<long int> get_vertices_and_edges(std::ifstream &dataset);

std::vector<std::vector<long int>> get_adjacency_list_graph(std::ifstream &);

#endif //GRAFOS_FGRAPH_H
