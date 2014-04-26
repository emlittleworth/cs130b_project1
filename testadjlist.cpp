#include "adjacency_list.cpp"

int main() {
    int s = 4;
    AdjacencyList graph(s);
    VertexItem* p = new VertexItem[s];
    graph.set_array_ptr(p);
    graph.print_list();

    for(int i = 0; i < s; i++) {
        graph.get_array_ptr()[i].set_id(i);
    }

    cout << "\n";
    graph.print_list();
    cout << "\n";

    graph.insert(0, 1, 1);
    graph.insert(1, 2, 2);
    graph.insert(2, 3, 3);
    graph.insert(3, 4, 4);
    graph.insert(0, 4, 9);
    graph.insert(0, 3, 8);
    graph.insert(3, 9, 7);

    graph.print_list();
    

}
