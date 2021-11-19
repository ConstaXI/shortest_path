#include <stdexcept>

#include "fgraph/fgraph.h"
#include "dijkstra/dijkstra.h"
#include "bellman_ford/bellman_ford.h"
#include "floyd_warshall/floyd_warshall.h"

void print_result_1d(const std::string &algorithm, const t_distance_1d &result) {
    std::cout << algorithm << std::endl;
    std::cout << "Time: " << result.ms.count() << "ms" << std::endl;
    std::cout << "Path: ";
    for (const auto &i : result.path) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "Cost: " << result.cost << std::endl;
    std::cout << "Iterations: " << result.iterations << std::endl << std::endl;
}

void print_result_2d(const std::string &algorithm, const t_distance_2d &result) {
    std::cout << algorithm << std::endl;
    std::cout << "Time: " << result.ms.count() << "ms" << std::endl;
    std::cout << "Path: ";
    for (const auto &i : result.path) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "Cost: " << result.cost << std::endl;
    std::cout << "Iterations: " << result.iterations << std::endl << std::endl;
}

int main() {
    std::string file_path = R"(C:\Users\DaviB\OneDrive\Desktop\shortest_path\src\datasets\rome99c.txt)";

    std::ifstream dataset(file_path);

    if (!dataset) {
        throw std::invalid_argument("file path");
    }

    std::vector<long int> vertices_and_edges_vector = get_vertices_and_edges(dataset);
    std::vector<std::vector<long int>> graph = get_adjacency_list_graph(dataset);

    const int src = 0;
    const int trg = 100;

    std::cout << file_path << std::endl;

    t_distance_1d result_d = dijkstra(graph, src, trg);
    print_result_1d("Dijkstra", result_d);

    t_distance_1d result_b = bellmanford(graph, src, trg);
    print_result_1d("Bellman-Ford", result_b);

//    t_distance_2d result_f = floyd_warshall(graph, src, trg);
//    print_result_2d("Floyd-Warshall", result_f);

    dataset.close();

    return 0;
}
