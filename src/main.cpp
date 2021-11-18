#include <stdexcept>

#include "fgraph/fgraph.h"
#include "dijkstra/dijkstra.h"
#include "bellman_ford/bellman_ford.h"
#include "floyd_warshall/floyd_warshall.h"

int main() {
    std::string file_path = R"(C:\Users\DaviB\OneDrive\Desktop\shortest_path\src\datasets\rome99c.txt)";

    std::ifstream dataset(file_path);

    if (!dataset) {
        throw std::invalid_argument("file path");
    }

    std::vector<long int> vertices_and_edges_vector = get_vertices_and_edges(dataset);
    std::vector<std::vector<long int>> graph = get_adjacency_list_graph(dataset);

    t_distance_1d result_d = dijkstra(graph, 0, 100);

    std::cout << file_path << std::endl << std::endl;

    std::cout << "Dijkstra: " << std::endl << std::endl;
    std::cout << "Time: " << result_d.ms.count() << "ms" << std::endl;
    std::cout << "Path: " << std::endl;
    for(const auto &i : result_d.path) {
        std::cout << i << " ";
    }
    std::cout << std::endl << "Cost: " << result_d.cost << std::endl;

    t_distance_1d result_b = bellmanford(graph, 0, 100);

    std::cout << std::endl;

    std::cout << "Bellman Ford: " << std::endl << std::endl;
    std::cout << "Time: " << result_b.ms.count() << "ms" << std::endl;
    std::cout << "Path: " << std::endl;
    for(const auto &i : result_b.path) {
        std::cout << i << " ";
    }
    std::cout << std::endl << "Cost: " << result_b.cost << std::endl;

    t_distance_2d result_f = floyd_warshall(graph, 0, 100);

    std::cout << std::endl;

    std::cout << "Floyd-Warshall: " << std::endl << std::endl;
    std::cout << "Time: " << result_f.ms.count() << "ms" << std::endl;
    std::cout << "Path: " << std::endl;
    for(const auto &i : result_f.path) {
        std::cout << i << " ";
    }
    std::cout << std::endl << "Cost: " << result_f.cost << std::endl;

    dataset.close();

    return 0;
}
