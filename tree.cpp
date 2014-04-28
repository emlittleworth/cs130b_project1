#include <iostream>
using namespace std;
#include "tree.h"

TreeNode::TreeNode() : vertex_id(-1), tree_size(-1), next(NULL) {}

TreeNode::TreeNode(int v, int s) : vertex_id(v), tree_size(s), next(NULL) {}

int TreeNode::get_vertex_id() { return vertex_id; }

void TreeNode::set_vertex_id(int v) { vertex_id = v; }

int TreeNode::get_tree_size() { return tree_size; }

void TreeNode::set_tree_size(int s) { tree_size = s; }

TreeNode* TreeNode::get_next() { return next; }

void TreeNode::set_next(TreeNode* other) { next = other; }

