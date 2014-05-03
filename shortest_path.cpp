#include "adjacency_list.cpp"
#include "tree.cpp"
#include "lexicographic.cpp"

/*
Idea:
-make three arrays: known, dist, path
-identify they array itme by the index = vertex number
-therefore, create new arrays each time
-in case there are two or more shortest paths, select in lexicographic order?
    -don't know how to approch this as Dijkstra's ingnores this
    -maybe add a unique flag and create different paths off of that
-need to return shortest path and total distance
    -store path in a tree (maybe called path)?
*/


struct Vertex {
    int known;
    int dist;
    int path;
};

void Dijkstra(int n, int s, Tree* T, AdjacencyList &Graph) {
    int i, smallest_dist, v, w, w_weight;
    VertexItem* neighbor;
    Vertex* vertex_array = new Vertex[n];
    for (i = 0; i < n; i++) {
        vertex_array[i].known = 0;
        vertex_array[i].dist = 1000;
        vertex_array[i].path = -1;
    }

    vertex_array[s].dist = 0;

    while(1) {
        for (i = 0; i < n; i++) {
            if (vertex_array[i].known == 0)
                break;
        }
        if (i == n) break;

        smallest_dist = 1000;
        for (i = 0; i < n; i++) {
            if (vertex_array[i].known == 0) {
                if (vertex_array[i].dist < smallest_dist) 
                    v = i;
            }
        }

        vertex_array[v].known = 1;

        for (neighbor = Graph.get_array_ptr()[v].get_next();
                neighbor != NULL; neighbor = neighbor->get_next()) {
            w = neighbor->get_id();
            w_weight = neighbor->get_weight();
            if (!vertex_array[w].known) {
                if (vertex_array[v].dist + w_weight < vertex_array[w].dist) {
                    vertex_array[w].dist = vertex_array[v].dist + w_weight;
                    vertex_array[w].path = v;
                } else if (vertex_array[v].dist + w_weight == vertex_array[w].dist) {
                    if (lexicographic_order(vertex_array, v, w))
                        vertex_array[w].path = v;
                }
                }
            }
        }
    }


  }

