// Emily Littleworth
// CS 130B Project 1

#include "adjacency_list.cpp"

int main() {
    int n, m, k, algorithm;
    int first, second, weight;
    int group_size, vertex;
    cin >> n;
    cin >> m;
    cin >> k;
    cin >> algorithm;

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
    for (int i = 0; i < m; i++) {
        cin >> first;
        cin >> second;
        cin >> weight;
        Graph.insert(first, second, weight);
        Graph.insert(second, first, weight);
    }

    // store groups
    // create array of k pointers
    int** Groups = new int*[k];

    // create array for each group
    for (int i = 0; i < k; i++) {
        cin >> group_size;
        int *temp = new int[group_size];
        Groups[i] = temp;
        Groups[i][0] = group_size;
        for (int j = 1; j <= Groups[i][0]; j++) {
            cin >> vertex;
            Groups[i][j] = vertex;
        }
    }

    Graph.print_list();

    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= Groups[i][0]; j++) {
            cout << Groups[i][j] << " ";
        }
        cout << "\n";
    }



}
