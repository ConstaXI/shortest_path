//
// Created by DaviB on 18/11/2021.
//

#include "floyd_warshall.h"

std::vector<int> get_path(std::vector<std::vector<int>> next, int src, int trg) {
    std::vector<int> path;

    path.push_back(src);

    while (src != trg) {
        src = next[src][trg];
        path.push_back(src);
    }

    return path;
}

t_distance_2d floyd_warshall(std::vector<std::vector<int>> graph, const int src, const int trg) {
    auto start = std::chrono::high_resolution_clock::now();

    const int vertex = graph[0][0];
    const int edges = graph[0][1];

    graph.erase(graph.begin());

    std::vector<std::vector<int>> distance(vertex, std::vector<int>(vertex, INT_MAX));
    std::vector<std::vector<int>> next(vertex, std::vector<int>(vertex, INT_MAX));
    int iterations = 0;

    for (auto &i : graph) {
        distance[i[0]][i[1]] = i[2];
        next[i[0]][i[1]] = i[1];
    }

    for (int i = 0; i < vertex; i++) {
        distance[i][i] = 0;
        next[i][i] = i;
    }

    for (int k = 0; k < vertex; k++) {
        for (int i = 0; i < vertex; i++) {
            for (int j = 0; j < vertex; j++) {
                if (distance[i][j] > distance[i][k] + distance[k][j] &&
                    (distance[k][j] != INT_MAX && distance[i][k] != INT_MAX)) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    next[i][j] = next[i][k];
                }

                iterations++;
            }
        }
    }

    std::vector<int> path = get_path(next, src, trg);

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    return {.distance = distance, .next = next, .path = path, .cost = distance[src][trg], .ms = duration, .iterations = iterations};
}
