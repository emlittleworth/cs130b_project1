// Emily Littleworth
// CS 130B Project 1

#include "adjacency_list.cpp"

int main() {
    int n, m, k, algorithm;
    int first, second, weight;
    cin >> n;
    cin >> m;
    cin >> k;
    cin >> algorithm;

    VertexItem* p = new VertexItem[n];
    AdjacencyList Graph(n);
    Graph.set_array_ptr(p);

    // set vertex ids in array to match index
    for(int i = 0; i < n; i++) {
        Graph.get_array_ptr()[i].set_id(i);
    }

    // insert each edge (twice for each edge)
    for (int i = 0; i < m; i++) {
        cin >> first;
        cin >> second;
        cin >> weight;
        Graph.insert(first, second, weight);
        Graph.insert(second, first, weight);
    }

    Graph.print_list();



}
