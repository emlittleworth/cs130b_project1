#ifndef TREE_H 
#define TREE_H

class TreeNode {
    friend class Tree;
    public:
        TreeNode();
        TreeNode(int, int);
        int get_vertex_id();
        void set_vertex_id(int);
        int get_vertex_weight();
        void set_vertex_weight(int);
        TreeNode* get_next();
        void set_next(TreeNode*);

    private:
        int vertex_id;
        int vertex_weight;
        TreeNode* next;
};

class Tree {
    public:
        Tree();
        Tree(Tree*);
        TreeNode* get_first();
        void set_first(TreeNode*);
        TreeNode* get_last();
        void set_last(TreeNode*);
        int get_tree_size();
        int get_total_weight();
        void insert(int, int);
        void insert(Tree*);
        void printTree();

    private:
        TreeNode* first;
        TreeNode* last;
        int tree_size;
        int total_weight;

};

#endif
