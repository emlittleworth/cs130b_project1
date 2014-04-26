#include "adjacency_list.cpp"

int main() {
    int s = 4;
    AdjacencyList graph(s);
    VertexItem* p = new VertexItem[s];
    graph.set_array_ptr(p);
    graph.get_array_ptr()[0].get_id();
    graph.get_array_ptr()[s-1].get_id();
    graph.print_list();


}
