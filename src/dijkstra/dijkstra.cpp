//
// Created by DaviB on 16/11/2021.
//

#include <algorithm>
#include "dijkstra.h"

t_distance_1d dijkstra(std::vector<std::vector<long int>> graph, const int src, const int trg) {
    auto start = std::chrono::high_resolution_clock::now();

    const long int vertex = graph[0][0];
    const long int edges = graph[0][1];

    graph.erase(graph.begin());

    std::vector<long int> distance(vertex);
    std::vector<long int> nodes(vertex);
    std::vector<long int> prev(vertex);

    for (int i = 0; i < vertex; i++) {
        distance[i] = INT_MAX;
        nodes[i] = i;
        prev[i] = -1;
    }

    distance[src] = 0;

    while (!nodes.empty()) {
        int minimum_node = nodes[0];

        for(int i : nodes) {
            if (distance[minimum_node] > distance[i]) {
                minimum_node = i;
            }
        }

        nodes.erase(std::remove(nodes.begin(), nodes.end(), minimum_node), nodes.end());

        for (int i = 0; i < edges; i++) {
            if (graph[i][0] == minimum_node) {
                long int alt = distance[minimum_node] + graph[i][2];
                if (distance[graph[i][1]] > alt) {
                    distance[graph[i][1]] = alt;

                    prev[graph[i][1]] = minimum_node;
                }
            }
        }

        if (minimum_node == trg) {
            break;
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    return {.distance = distance, .prev = prev, .path = get_path(prev, src, trg), .cost = distance[trg], .ms = duration};
}
