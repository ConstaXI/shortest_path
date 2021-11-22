//
// Created by DaviB on 16/11/2021.
//

#include "dijkstra.h"

t_distance dijkstra(std::vector<std::vector<int>> graph, const int src, const int trg) {
    auto start = std::chrono::high_resolution_clock::now();

    const int vertex = graph[0][0];
    const int edges = graph[0][1];

    graph.erase(graph.begin());

    std::vector<int> distance(vertex);
    std::vector<int> nodes(vertex);
    std::vector<int> prev(vertex);
    int iterations = 0;

    for (int i = 0; i < vertex; i++) {
        distance[i] = INT_MAX;
        nodes[i] = i;
        prev[i] = -1;
    }

    distance[src] = 0;
    int neighbor, weight;

    while (!nodes.empty()) {
        int minimum_node = nodes[0];

        for (int i : nodes) {
            if (distance[minimum_node] > distance[i]) {
                minimum_node = i;
            }
        }

        nodes.erase(std::remove(nodes.begin(), nodes.end(), minimum_node), nodes.end());

        for (int i = 0; i < edges; i++) {
            if (graph[i][0] == minimum_node) {
                neighbor = graph[i][1];
                weight = graph[i][2];

                if (distance[neighbor] > distance[minimum_node] + weight) {
                    distance[neighbor] = distance[minimum_node] + weight;

                    prev[neighbor] = minimum_node;
                }

                iterations++;
            }
        }

        if (minimum_node == trg) {
            break;
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    return {.path = get_path(prev, src, trg), .cost = distance[trg], .ms = duration, .iterations = iterations};
}
