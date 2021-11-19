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
    std::vector<long int> distance;
    std::vector<long int> prev;
    std::vector<long int> path;
    long int cost;
    std::chrono::milliseconds ms;
    long int iterations;
} t_distance_1d;

typedef struct minimum_distance_2d {
    std::vector<std::vector<long int>> distance;
    std::vector<std::vector<long int>> next;
    std::vector<long int> path;
    long int cost;
    std::chrono::milliseconds ms;
    long int iterations;
} t_distance_2d;

/* Get the vertices and edges as an array of size 2
 *
 * @param std::ifstream &file
*/
std::vector<long int> get_vertices_and_edges(std::ifstream &);

/* Get the adjacency list of a graph in a .txt file
 *
 * @param std::ifstream &file
*/
std::vector<std::vector<long int>> get_adjacency_list_graph(std::ifstream &);

std::vector<long int> get_path(std::vector<long int>, long int src, long int trg);

#endif //GRAFOS_FGRAPH_H
