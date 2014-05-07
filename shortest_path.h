#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H
#include "adjacency_list.h"
#include "tree.h"

struct Vertex {
    int known;
    long int dist;
    int path;
};

Tree* Dijkstra(int, int, Tree*, AdjacencyList &);

#endif
