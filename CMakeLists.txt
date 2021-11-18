cmake_minimum_required(VERSION 3.17)
project(grafos)

set(CMAKE_CXX_STANDARD 20)

add_executable(grafos src/main.cpp src/fgraph/fgraph.cpp src/fgraph/fgraph.h src/dijkstra/dijkstra.cpp src/dijkstra/dijkstra.h src/bellmanford/bellmanford.cpp src/bellmanford/bellmanford.h)
