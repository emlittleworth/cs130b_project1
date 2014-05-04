#ifndef LEXICOGRAPHIC_H
#define LEXICOGRAPHIC_H
#include "tree.h"
#include "shortest_path.h"

void path_into_tree(Vertex* &, int, Tree* &);

int lexicographic(Vertex* &, int, int);

int lexicographic(Tree*, Tree*);

#endif
