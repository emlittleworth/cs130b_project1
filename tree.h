#ifndef TREE_H 
#define TREE_H

class TreeNode {
    public:
        TreeNode();
        TreeNode(int, int);
        int get_vertex_id();
        void set_vertex_id(int);
        int get_tree_size();
        void set_tree_size(int);
        TreeNode* get_next();
        void set_next(TreeNode*);

    private:
        int vertex_id;
        int tree_size;
        TreeNode* next;
}

#endif
