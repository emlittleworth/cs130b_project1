#include "adjacency_list.h"
#include "tree.h"
#include "shortest_path.h"
#include "lexicographic.h"
#include <iostream>
using namespace std;

void algorithm1(int n, int m, int k, AdjacencyList &Graph, int** &Groups) {

    Tree* T = new Tree;
    Tree* R_i = new Tree;
    Tree* current_path = new Tree;
    int current_weight, i, j;
    int d_i = 1000;
    int group = 1000;

    // Add vertex in Groups[0] to T
    // and mark as reached
    T->insert(Groups[0][2], 0);
    Groups[0][0] = 1;
    
    while(1) {
        // check if there is at least one group that is unreached
        for(i = 0; i < k; i++) {
            if (!Groups[i][0]) // if there is a group unreached
                break;
        }
        if (i == k) // if i == k, then all groups are reached and we are done
            break;

        d_i = 1000;
        group = 1000;

        for(i = 0; i < k; i++) {
            if (Groups[i][0] == 1) // if group is reached, continue
                continue;

            // find a shortest path from vertex in g_i to vertex in T
            for (j = 2; j < Groups[i][1] + 2; j++) {
                cout << "Working on group g_" << i << " vertex " << Groups[i][j] << "...\n";
                for (int i = 0; i < k; i++) {
                    cout << "Marked? " << Groups[i][0];
                    cout << ", NumVertex: " << Groups[i][1] << " - ";
                    for (int j = 2; j < Groups[i][1]+2; j++) {
                        cout << Groups[i][j] << " ";
                    }
                    cout << "\n";
                } //DEBUG

                // find a shortest path from vertex j in g_i to vertex in T
                current_path = Dijkstra(n, Groups[i][j], T, Graph);
                //cout << current_path->get_first()->get_vertex_id() << "\n";
                //cout << current_path->get_last()->get_vertex_id() << "\n";

                //current_path->print_tree();


                current_weight = current_path->get_total_weight();

                // compare current path to R_i and d_i
                if (current_weight < d_i) {
                    R_i = current_path;
                    d_i = current_weight;
                    group = i;
                } else if (current_weight == d_i) {
                    // use lexicographic order
                    if (lexicographic(current_path, R_i) == 1) {
                        R_i = current_path;
                        d_i = current_weight;
                        group = i;
                    } else if (lexicographic(current_path, R_i) == 2) {
                        if (i < group) {
                            R_i = current_path;
                            d_i = current_weight;
                            group = i;
                        }
                    }
                }
            }
        }

        // add R_i to T and mark group as reached
        T->insert(R_i);
        Groups[group][0] = 1;

        cout << group << "\n";
    }

    //print all vertices in T from smallest values to largest per line
    //print sum of the weight of all the endges in T in one line
    Graph.print_list();

    for (int i = 0; i < k; i++) {
        cout << "Marked? " << Groups[i][0];
        cout << ", NumVertex: " << Groups[i][1] << " - ";
        for (int j = 2; j < Groups[i][1]+2; j++) {
            cout << Groups[i][j] << " ";
        }
        cout << "\n";
    }
    

}
