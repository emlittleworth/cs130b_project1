#include "adjacency_list.h"
#include "tree.h"
#include "lexicographic.h"
#include "shortest_path.h"
#include <iostream>
using namespace std;

int main() {
    Tree* T = new Tree;
    Tree* new_path = new Tree;
    T->insert(5,0);
    int n = 6;

    // create adjacency list
    VertexItem* p = new VertexItem[n];
    AdjacencyList Graph(n);
    Graph.set_array_ptr(p);

    // set vertex ids in array to match index
    for(int i = 0; i < n; i++) {
        Graph.get_array_ptr()[i].set_id(i);
    }

    // insert each edge (twice for each edge)
    // into adjacency list
    Graph.insert(1-1,4-1,1);
    Graph.insert(1-1,2-1,4);
    Graph.insert(4-1,3-1,3);
    Graph.insert(4-1,2-1,3);
    Graph.insert(4-1,1-1,2);
    Graph.insert(2-1,1-1,2);
    Graph.insert(2-1,3-1,9);
    Graph.insert(2-1,5-1,1);
    Graph.insert(3-1,6-1,10);
    Graph.insert(3-1,5-1,9);
    Graph.insert(5-1,2-1,5);
    Graph.insert(5-1,3-1,7);
    Graph.insert(5-1,6-1,8);

    new_path = Dijkstra(n,0,T,Graph);
    new_path->print_tree();

}
