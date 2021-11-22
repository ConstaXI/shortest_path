#include <stdexcept>
#include <filesystem>
#include <clocale>

#include "fgraph/fgraph.h"
#include "dijkstra/dijkstra.h"
#include "bellman_ford/bellman_ford.h"
#include "floyd_warshall/floyd_warshall.h"

void print_result(const std::string &algorithm, const t_distance &result) {
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
    std::setlocale(LC_ALL, "pt-br");
    std::string file_path;

    std::cout << "Escolha o arquivo: " << std::endl;
    std::cout << "1. toy.txt" << std::endl;
    std::cout << "2. rg300_4730.txt" << std::endl;
    std::cout << "3. rome99c.txt" << std::endl;
    std::cout << "4. facebook_combined.txt" << std::endl;
    std::cout << "5. USA-road-dt.DC.txt" << std::endl;

    int file;
    std::cin >> file;

    switch (file) {
        case 1:
            file_path = "../src/datasets/toy.txt";
            break;
        case 2:
            file_path = "../src/datasets/rg300_4730.txt";
            break;
        case 3:
            file_path = "../src/datasets/rome99c.txt";
            break;
        case 4:
            file_path = "../src/datasets/facebook_combined.txt";
            break;
        case 5:
            file_path = "../src/datasets/USA-road-dt.DC.txt";
            break;
        default:
            throw std::invalid_argument("file");
    }

    std::ifstream dataset(file_path);

    if (!dataset) {
        throw std::invalid_argument("file path");
    }

    std::vector<std::vector<int>> graph = get_graph(dataset);

    std::cout << "Digite o v�rtice de origem." << std::endl;
    int src;
    std::cin >> src;

    std::cout << "Digite o v�rtice de destino." << std::endl;
    int trg;
    std::cin >> trg;

    std::cout << "1. Dijkstra" << std::endl;
    std::cout << "2. Bellman-Ford" << std::endl;
    std::cout << "3. Floyd-Warshall" << std::endl;

    int option;
    std::cin >> option;

    switch (option) {
        case 1: {
            system("cls");
            t_distance result_d = dijkstra(graph, src, trg);
            print_result("Dijkstra", result_d);
            break;
        }
        case 2: {
            system("cls");
            t_distance result_b = bellmanford(graph, src, trg);
            print_result("Bellman-Ford", result_b);
            break;
        }
        case 3: {
            system("cls");
            t_distance result_f = floyd_warshall(graph, src, trg);
            print_result("Floyd-Warshall", result_f);
            break;
        }
        default: {
            system("cls");
            throw std::invalid_argument("option");
        }
    }

    dataset.close();
    std::fflush(stdin);
    std::system("pause");

    return 0;
}
