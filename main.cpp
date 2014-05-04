// Emily Littleworth
// CS 130B Project 1

#include "adjacency_list.h"
#include "tree.h"
#include "algorithm1.h"
#include <iostream>
using namespace std;


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
        int *temp = new int[group_size + 2];
        // make the array with extra space to have a 
        // visited/unvisited flag at the beginning
        // Groups[i][0] = marked?
        // Groups[i][1] = number of vertices in group
        // note: array size = Groups[i][1] + 2
        Groups[i] = temp;
        Groups[i][0] = 0;
        Groups[i][1] = group_size;
        for (int j = 2; j < Groups[i][1]+2; j++) {
            cin >> vertex;
            Groups[i][j] = vertex;
        }
    }


    Graph.print_list();

    for (int i = 0; i < k; i++) {
        cout << "Marked? " << Groups[i][0];
        cout << ", NumVertex: " << Groups[i][1] << " - ";
        for (int j = 2; j < Groups[i][1]+2; j++) {
            cout << Groups[i][j] << " ";
        }
        cout << "\n";
    }

    // prepare to create the tree
    TreeNode* TreeFirst, TreeLast;

    algorithm1(n, m, k, Graph, Groups);



}
