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

typedef struct minimum_distance_1d {
    std::vector<int> distance;
    std::vector<int> prev;
    std::vector<int> path;
    int cost;
    std::chrono::milliseconds ms;
    int iterations;
} t_distance_1d;

typedef struct minimum_distance_2d {
    std::vector<std::vector<int>> distance;
    std::vector<std::vector<int>> next;
    std::vector<int> path;
    int cost;
    std::chrono::milliseconds ms;
    int iterations;
} t_distance_2d;

/* Get the adjacency list of a graph in a .txt file
 *
 * @param std::ifstream &file
*/
std::vector<std::vector<int>> get_graph(std::ifstream &);

std::vector<int> get_path(std::vector<int>, int src, int trg);

#endif //GRAFOS_FGRAPH_H
