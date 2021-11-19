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
    std::string file_path;

    std::cout << R"(Digite o caminho absoluto para o arquivo com o dataset: (exemplo: C:\Users\DaviB\OneDrive\Desktop\shortest_path\src\datasets\rg300_4730.txt))" << std::endl;

    std::cin >> file_path;

    std::ifstream dataset(file_path);

    if (!dataset) {
        throw std::invalid_argument("file path");
    }

    std::vector<std::vector<int>> graph = get_graph(dataset);

    const int src = 0;
    const int trg = 100;

    std::cout << file_path << std::endl;

    std::cout << "1. Dijkstra" << std::endl;
    std::cout << "2. Bellman-Ford" << std::endl;
    std::cout << "3. Floyd-Warshall" << std::endl;

    int option;
    std::cin >> option;

    switch (option) {
        case 1: {
            system("cls");
            t_distance_1d result_d = dijkstra(graph, src, trg);
            print_result_1d("Dijkstra", result_d);
            break;
        }
        case 2: {
            system("cls");
            t_distance_1d result_b = bellmanford(graph, src, trg);
            print_result_1d("Bellman-Ford", result_b);
            break;
        }
        case 3: {
            system("cls");
            t_distance_2d result_f = floyd_warshall(graph, src, trg);
            print_result_2d("Floyd-Warshall", result_f);
            break;
        }
        default: {
            system("cls");
            throw std::invalid_argument("option");
        }
    }

    dataset.close();
    std::getchar();

    return 0;
}
