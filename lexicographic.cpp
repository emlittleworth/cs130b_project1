#include "shortest_path.h"
#include "adjacency_list.h"
#include "tree.h"
#include <iostream>
using namespace std;

void path_into_tree(Vertex* &vertex_array, int v, Tree* T) {
    if (vertex_array[v].path != -1)
        path_into_tree(vertex_array, vertex_array[v].path, T);
    T->insert(v, vertex_array[v].dist);
}

int lexicographic(Vertex* &vertex_array, int v, int w) {
    Tree* v_path;
    Tree* w_path;
    TreeNode* v_ptr;
    TreeNode* w_ptr;
    path_into_tree(vertex_array, v, v_path);
    v_path->insert(v, 0); // insert v into this path since would be before w
    path_into_tree(vertex_array, w, w_path);

    v_ptr = v_path->get_first();
    w_ptr = w_path->get_first();
    while(v_ptr != NULL && w_ptr != NULL) {
       if(v_ptr->get_vertex_id() < w_ptr->get_vertex_id())
           return 0;
       else if(v_ptr->get_vertex_id() > w_ptr->get_vertex_id())
           return 1;
       v_ptr = v_ptr->get_next();
       w_ptr = w_ptr->get_next();
    }

    if(v_ptr == NULL && w_ptr != NULL)
        return 0;
    else if(v_ptr != NULL && w_ptr == NULL)
        return 1;
    else
        return 0;
}

int lexicographic(Tree* current_path, Tree* R_i) {
    TreeNode* c_ptr;
    TreeNode* r_ptr;

    c_ptr = current_path->get_first();
    r_ptr = R_i->get_first();

    while(c_ptr != NULL && r_ptr != NULL) {
       if(c_ptr->get_vertex_id() < r_ptr->get_vertex_id())
           return 0;
       else if(c_ptr->get_vertex_id() > r_ptr->get_vertex_id())
           return 1;
       c_ptr = c_ptr->get_next();
       r_ptr = r_ptr->get_next();
    }

    if(c_ptr == NULL && r_ptr != NULL)
        return 0;
    else if(c_ptr != NULL && r_ptr == NULL)
        return 1;
    else
        return 0;
}
