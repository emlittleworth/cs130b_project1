#include "adjacency_list.h"
#include "tree.h"
#include "lexicographic.h"
#include "shortest_path.h"
#include <iostream>
using namespace std;

Tree* Dijkstra(int n, int s, Tree* T, AdjacencyList &Graph) {
    int i, smallest_dist, v, w, w_weight;
    VertexItem* neighbor;
    Tree* return_path = new Tree;
    TreeNode* p;
    Vertex* vertex_array = new Vertex[n];

    // rather than creating a new vertex class, instead will use
    // an array of size n of the vertex struct
    // vertex stuct includes known, dist, and path
    for (i = 0; i < n; i++) {
        vertex_array[i].known = 0;
        vertex_array[i].dist = 1000;
        vertex_array[i].path = -1;
    }

    // for the first vertex, set dist as 0
    vertex_array[s].dist = 0;

    while(1) {
        for (i = 0; i < n; i++) { // check if each vertex is known
            if (!vertex_array[i].known) // if the vertex is not known, break
                break;
        }
        if (i == n) break; // if i == n, all verteces are known, we are done

        smallest_dist = 1000;
        for (i = 0; i < n; i++) {
            if (!vertex_array[i].known) { // if vertex is not known, look at dist
                if (vertex_array[i].dist < smallest_dist) 
                    v = i; // set v to the vertex not known with the smallest dist
            }
        }

        vertex_array[v].known = 1;

        // if v is in tree T, then we can stop
        for (p = T->get_first(); p != NULL; p = p->get_next()) {
            if (p->get_vertex_id() == v) {
                path_into_tree(vertex_array, v, return_path);
                return return_path;
            }
        }

        for (neighbor = Graph.get_array_ptr()[v].get_next();
                neighbor != NULL; neighbor = neighbor->get_next()) {
            w = neighbor->get_id();
            w_weight = neighbor->get_weight();
            if (!vertex_array[w].known) {
                if (vertex_array[v].dist + w_weight < vertex_array[w].dist) {
                    vertex_array[w].dist = vertex_array[v].dist + w_weight;
                    vertex_array[w].path = v;
                } else if (vertex_array[v].dist + w_weight == vertex_array[w].dist) {
                    if (lexicographic(vertex_array, v, w))
                        vertex_array[w].path = v;
                }
            }
        }
    }

    // get path to return
    path_into_tree(vertex_array, v, return_path);
    return return_path;
}

