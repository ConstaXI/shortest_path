//
// Created by DaviB on 16/11/2021.
//

#include <algorithm>
#include "bellmanford.h"

t_distance bellmanford(std::vector<std::vector<long int>> graph, const int src, const int trg) {
    auto start = std::chrono::high_resolution_clock::now();

    const long int vertex = graph[0][0];
    const long int edges = graph[0][1];

    graph.erase(graph.begin());

    std::vector<long int> distance(vertex);
    std::vector<long int> nodes(vertex);
    std::vector<long int> prev(vertex);
    std::vector<long int> path;
    long int cost = 0;

    for (int i = 0; i < vertex; i++) {
        distance[i] = INT_MAX;
        nodes[i] = i;
        prev[i] = -1;
    }

    distance[src] = 0;

    for (int i = 0; i < vertex - 1; i++) {
        bool has_changed = false;
        for (int j = 0; j < edges; j++) {
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                prev[v] = u;
                has_changed = true;
            }
        }

        if (!has_changed) {
            break;
        }
    }

    path.push_back(trg);

    long int temp = trg;
    while (temp != src) {
        temp = prev[temp];
        path.push_back(temp);
    }

    std::reverse(path.begin(), path.end());

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    return {.distance = distance, .prev = prev, .path = path, .cost = distance[trg], .ms = duration};
}
