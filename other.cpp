#include "other.h"
#include <iostream>
using namespace std;

int num_groups_in_path(Tree* &T, int** &Groups, int k) {
    TreeNode* p;
    int i, j;
    int sum = 0;
    int* hashy = new int[k];
    for (i = 0; i < k; i++) {
        hashy[i] = 0;
    }
    for (p = T->get_first(); p != NULL; p = p->get_next()) {
        for (i = 0; i < k; i++) {
            if (Groups[i][0] == 1)
                continue;
            for (j = 2; j < Groups[i][1]+2; j++) {
                if (p->get_vertex_id() == Groups[i][j]) {
                    hashy[i] = 1;
                }
            }
        }
    }
    for (i = 0; i < k; i++) {
        sum += hashy[i];
    }
    delete[] hashy;
    return sum;
}

Tree* groups_in_path(Tree* &T, int** &Groups, int k) {
    Tree* new_tree = new Tree;
    TreeNode* p;
    int i, j;
    for (p = T->get_first(); p != NULL; p = p->get_next()) {
        for (i = 0; i < k; i++) {
            if (Groups[i][0]) {
                continue;
            }
            for (j = 2; j < Groups[i][1]+2; j++) {
                if (p->get_vertex_id() == Groups[i][j]) {
                    new_tree->insert(i, 0);
                    break;
                }
            }
        }
    }
    return new_tree;
}

