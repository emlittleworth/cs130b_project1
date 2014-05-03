#include "shortest_path.cpp"


void path_into_tree(Vertex* &vertex_array, int v, Tree* T) {
    if (vertex_array[v].path != -1)
        path_into_tree(vertex_array, vertex_array[v].path, T);
    T->insert(v, vertex_array[v].dist);
}

int lexicographic_order(Vertex* &vertex_array, int v, int w) {
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

