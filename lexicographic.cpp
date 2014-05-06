#include "shortest_path.h"
#include "adjacency_list.h"
#include "tree.h"
#include <iostream>
using namespace std;

void path_into_tree(Vertex* &vertex_array, int v, Tree* &T) {
    if (vertex_array[v].path != -1) {
        path_into_tree(vertex_array, vertex_array[v].path, T);
    }
    T->insert(v, vertex_array[v].dist);
}

int lexicographic(Tree* first_path, Tree* second_path) {
    TreeNode* first_ptr;
    TreeNode* second_ptr;

    first_ptr = first_path->get_first();
    second_ptr = second_path->get_first();

    while(first_ptr != NULL && second_ptr != NULL) {
        if(first_ptr->get_vertex_id() < second_ptr->get_vertex_id())
            return 0;
        else if(first_ptr->get_vertex_id() > second_ptr->get_vertex_id())
            return 1;
        first_ptr = first_ptr->get_next();
        second_ptr = second_ptr->get_next();
    }

    if(first_ptr == NULL && second_ptr != NULL)
        return 0;
    else if(first_ptr != NULL && second_ptr == NULL)
        return 1;
    else
        return 2;
}

int lexicographic(Vertex* &vertex_array, int v, int w) {
    int return_value;

    Tree* v_path = new Tree;
    Tree* w_path = new Tree;
    TreeNode* v_ptr;
    TreeNode* w_ptr;
    path_into_tree(vertex_array, v, v_path);
    v_path->insert(v, 0); // insert v into this path since would be before w
    path_into_tree(vertex_array, w, w_path);

    return_value = lexicographic(v_path, w_path);
    delete v_path;
    delete w_path;
    return return_value;
}
