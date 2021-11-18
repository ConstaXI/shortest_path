#include <stdexcept>

#include "fgraph/fgraph.h"
#include "dijkstra/dijkstra.h"
#include "bellmanford/bellmanford.h"

int main() {
    std::ifstream dataset(R"(C:\Users\DaviB\OneDrive\Desktop\grafos\src\datasets\USA-road-dt.DC.txt)");

    if (!dataset) {
        throw std::invalid_argument("file path");
    }

    std::vector<long int> vertices_and_edges_vector = get_vertices_and_edges(dataset);
    std::vector<std::vector<long int>> graph = get_adjacency_list_graph(dataset);
    t_distance result_b = bellmanford(graph, 0, 100);
    t_distance result_d = dijkstra(graph, 0, 100);

    std::cout << "Dijkstra: " << std::endl << std::endl;
    std::cout << "Time: " << result_d.ms.count() << "ms" << std::endl;
    std::cout << "Path: " << std::endl;
    for(const auto &i : result_d.path) {
        std::cout << i << " ";
    }
    std::cout << std::endl << "Cost: " << result_d.cost << std::endl;

    std::cout << "Bellman: " << std::endl << std::endl;
    std::cout << "Time: " << result_b.ms.count() << "ms" << std::endl;
    std::cout << "Path: " << std::endl;
    for(const auto &i : result_b.path) {
        std::cout << i << " ";
    }
    std::cout << std::endl << "Cost: " << result_b.cost << std::endl;

    return 0;
}
