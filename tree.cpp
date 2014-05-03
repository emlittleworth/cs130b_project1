#include <iostream>
using namespace std;
#include "tree.h"

// class TreeNode methods

TreeNode::TreeNode() : vertex_id(-1), vertex_weight(-1), next(NULL) {}

TreeNode::TreeNode(int v, int w) : vertex_id(v), vertex_weight(w), next(NULL) {}

int TreeNode::get_vertex_id() { return vertex_id; }

void TreeNode::set_vertex_id(int v) { vertex_id = v; }

int TreeNode::get_vertex_weight() { return vertex_weight; }

void TreeNode::set_vertex_weight(int w) { vertex_weight = w; }

TreeNode* TreeNode::get_next() { return next; }

void TreeNode::set_next(TreeNode* other) { next = other; }


// class Tree methods

Tree::Tree() : first(NULL), last(NULL), tree_size(0), total_weight(0) {}

TreeNode* Tree::get_first() { return first; }

void Tree::set_first(TreeNode* other) { first = other; }

TreeNode* Tree::get_last() { return last; }

void Tree::set_last(TreeNode* other) { last = other; }

int Tree::get_tree_size() { return tree_size; }

int Tree::get_total_weight() { return total_weight; }

void Tree::insert(int vertex_id, int vertex_weight) {
    TreeNode* p = new TreeNode(vertex_id, vertex_weight);
    if (tree_size == 0) {
        first = p;
        last = p;
        tree_size = 1;
        total_weight = vertex_weight;
    } else {
        last->next = p;
        last = p;
        tree_size += 1;
        total_weight += vertex_weight;
    }
}

void Tree::insert(Tree* other) {
    TreeNode *p;
    for(p = other->get_first(); p != NULL; p->get_next()) {
        TreeNode* temp = new TreeNode(p->get_vertex_id(), p->get_vertex_weight());
        last->next = temp;
        last = temp;
        tree_size += 1;
        total_weight += p->get_vertex_weight();
    }
}



