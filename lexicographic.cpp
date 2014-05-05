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

int lexicographic(Tree* current_path, Tree* R_i) {
    current_path->print_tree();//DEBUG
    R_i->print_tree();//DEBUG

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

int lexicographic(Vertex* &vertex_array, int v, int w) {
    Tree* v_path = new Tree;
    Tree* w_path = new Tree;
    TreeNode* v_ptr;
    TreeNode* w_ptr;
    path_into_tree(vertex_array, v, v_path);
    v_path->insert(v, 0); // insert v into this path since would be before w
    path_into_tree(vertex_array, w, w_path);

    return lexicographic(v_path, w_path);
}
