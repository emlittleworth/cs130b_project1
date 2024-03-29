#include "adjacency_list.h"
#include "tree.h"
#include "shortest_path.h"
#include "lexicographic.h"
#include "merge_sort.h"
#include <iostream>
using namespace std;

void algorithm1(int n, int m, int k, AdjacencyList &Graph, int** &Groups) {

    Tree* T = new Tree;
    Tree* R_i;
    Tree* current_path;
    int current_weight, i, j;
    int d_i = 1000000000;
    int group = 1000;

    // Add vertex in Groups[0] to T
    // and mark as reached
    T->insert(Groups[0][2], 0);
    Groups[0][0] = 1;
    cout << "0\n";
    
    while(1) {
        // check if there is at least one group that is unreached
        for(i = 0; i < k; i++) {
            if (!Groups[i][0]) // if there is a group unreached
                break;
        }
        if (i == k) // if i == k, then all groups are reached and we are done
            break;

        d_i = 1000000000;
        group = 1000;

        for(i = 0; i < k; i++) {
            if (Groups[i][0] == 1)
                continue;

            // find a shortest path from vertex in g_i to vertex in T
            for (j = 2; j < Groups[i][1] + 2; j++) {
                // find a shortest path from vertex j in g_i to vertex in T
                current_path = Dijkstra(n, Groups[i][j], T, Graph);
                //current_path->print_tree();//DEBUGGING
                //current_weight = current_path->get_total_weight();// this doesn't work
                current_weight = current_path->get_last()->get_vertex_weight();
                current_path->set_total_weight(current_weight);// path_into_tree sums them at the end!

                // compare current path to R_i and d_i
                if (current_weight < d_i) {
                    R_i = current_path;
                    d_i = current_weight;
                    group = i;
                } else if (current_weight == d_i) {
                    // originally included this extra comparison, test files show it isn't necessary
                    // use lexicographic order
                    /*if (!lexicographic(current_path, R_i)) {
                        R_i = current_path;
                        d_i = current_weight;
                        group = i;
                    } else if (lexicographic(current_path, R_i) == 2) {*/ 
                        if (i < group) {
                            R_i = current_path;
                            d_i = current_weight;
                            group = i;
                        }
                        else if (i == group) { // if the distances AND groups are equal, lexicographic
                            if (!lexicographic(current_path, R_i)) {
                                R_i = current_path;
                                d_i = current_weight;
                                group = i;
                            }
                        }
                    //}
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
    int* final_array = new int[T->get_tree_size()];
    int* temp = new int[T->get_tree_size()];
    int step = 0;
    TreeNode* final_p;
    for(final_p = T->get_first(); final_p != NULL; final_p = final_p->get_next()) {
        final_array[step] = final_p->get_vertex_id();
        step++;
    }
    merge_sort(final_array, temp, 0, T->get_tree_size()-1);


    for (step = 0; step < T->get_tree_size(); step++)
        cout << final_array[step] << "\n";
    cout << T->get_total_weight() << "\n";

}
