#include "adjacency_list.h"
#include "tree.h"
#include "shortest_path.h"
#include "lexicographic.h"
#include "merge_sort.h"
#include "other.h"
#include <iostream>
using namespace std;

void algorithm2(int n, int m, int k, AdjacencyList &Graph, int** &Groups) {

    Tree* T = new Tree;
    Tree* C = NULL;
    Tree* R_i = NULL;
    Tree* current_path = NULL;
    TreeNode* ptr = NULL;
    int current_weight, i, j, current_t_i, t_i, real_weight;
    int d_i = 1000;
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

        d_i = 1000;
        t_i = 1;
        group = 1000;

        for(i = 0; i < k; i++) {
            if (Groups[i][0] == 1)
                continue;

            // find a shortest path from vertex in g_i to vertex in T
            for (j = 2; j < Groups[i][1] + 2; j++) {
                // find a shortest path from vertex j in g_i to vertex in T
                current_path = Dijkstra(n, Groups[i][j], T, Graph);
                current_weight = current_path->get_last()->get_vertex_weight();
                current_path->set_total_weight(current_weight);// path_into_tree sums them at the end!
                current_t_i = num_groups_in_path(current_path, Groups, k);
                // the number of "not reached" groups that current_path visits

                // compare current path to R_i and d_i
                // not sure to include this or not
                /*
                if (current_weight < d_i) {
                    R_i = current_path;
                    d_i = current_weight;
                    group = i;
                } else if (current_weight == d_i) {
                    // use lexicographic order
                    if (!lexicographic(current_path, R_i)) {
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
                */

                // now comapre based off of d_i/t_i
                if ((float)current_weight/current_t_i < (float)d_i/t_i) {
                    R_i = current_path;
                    d_i = current_weight;
                    t_i = current_t_i;
                    group = i;
                } else if ((float)current_weight/current_t_i == (float)d_i/t_i) {
                    if (i < group) {
                        R_i = current_path;
                        d_i = current_weight;
                        t_i = current_t_i;
                        group = i;
                    }
                }
                
                cout << "group " << i << " current_path ";
                current_path->print_tree();
                cout << "with current_weight = " << current_weight << " and current_t_i = " << current_t_i << "\n"; // DEBUG
                cout << "R_i ";
                R_i->print_tree();
                cout << "with d_i = " << d_i << " and t_i = " << t_i << "\n"; // DEBUG
                
            }
        }

        // add R_i to T and mark group as reached
        //real_weight = R_i->find_total_weight(Graph); // total_weight for trees isn't totally working
        //R_i->set_total_weight(real_weight);
        T->insert(R_i);
        // create C - a collection of all the groups visited by path R_i that are not currently reached
        C = groups_in_path(R_i, Groups, k);
        // mark all the groups in C as marked
        for (ptr = C->get_first(); ptr != NULL; ptr = ptr->get_next()) {
            Groups[ptr->get_vertex_id()][0] = 1;
        }

        // create array from nodes in C, then sort the array
        int* C_array = new int[C->get_tree_size()];
        int* temp = new int[C->get_tree_size()];
        int step = 0;
        TreeNode* array_c;
        for(array_c = C->get_first(); array_c != NULL; array_c = array_c->get_next()) {
            C_array[step] = array_c->get_vertex_id();
            step++;
        }
        merge_sort(C_array, temp, 0, C->get_tree_size()-1);
        for (step = 0; step < C->get_tree_size(); step++) {
            cout << C_array[step] << "\n";
        }
        delete[] C_array;
        delete[] temp;
    }

    // print all vertices in T from smallest values to largest per line
    // create array from nodes in T, then sort the array
    // print sum of the weight of all the endges in T in one line
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
