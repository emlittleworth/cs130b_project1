#include "adjacency_list.cpp"
#include "tree.cpp"

void algorithm1(int n, int m, int k, AdjacencyList &Graph, int** &Groups) {

    Tree* T, R_i, current_path;
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
            if (Groups[i][0] == 0)
                break;
        }
        if (i == k)
            break;

        d_i = 1000;
        group = 1000;

        for(i = 0; i < k; i++) {
            if (Groups[i][0] == 1) // if group is reached, continue
                continue;

            // find a shortest path from vertex in g_i to vertex in T
            for (j = 2; j < Groups[i][1] + 2; j++) {
                // find a shortest path from vertex j in g_i to vertex in T
                current_path = Dijkstra(Groups[i][j], T, Graph);
                current_weight = current_path.get_total_weight();

                // compare current path to R_i and d_i
                //
                // 
                // need delete calls?????
                //
                //
                if (current_weight < d_i) {
                    R_i = current_path;
                    d_i = current_weight;
                    group = i;
                } else if (current_weight == d_i) {
                    // use lexicographic order
                    if (lexicographic_order(current_path, R_i) == 1) {
                        R_i = current_path;
                        d_i = current_weight;
                        group = i;
                    } else if (lexicographic_order(current_path, R_i) == 2) {
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
    

}