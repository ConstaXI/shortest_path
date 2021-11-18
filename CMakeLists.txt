cmake_minimum_required(VERSION 3.17)
project(shortest_path)

set(CMAKE_CXX_STANDARD 20)

add_executable(shortest_path src/main.cpp src/fgraph/fgraph.cpp src/fgraph/fgraph.h src/dijkstra/dijkstra.cpp src/dijkstra/dijkstra.h src/bellman_ford/bellman_ford.cpp src/bellman_ford/bellman_ford.h src/floyd_warshall/floyd_warshall.cpp src/floyd_warshall/floyd_warshall.h)
