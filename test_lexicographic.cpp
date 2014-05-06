#include "lexicographic.h"
#include "shortest_path.h"
#include "adjacency_list.h"
#include "tree.h"
#include <iostream>
using namespace std;

int main() {

    int n = 10;
    Vertex* vertex_array = new Vertex[n];
    for (int i = 0; i < n; i++) {
        vertex_array[i].known = 0;
        vertex_array[i].dist = 1000;
        vertex_array[i].path = -1;
    }
    vertex_array[0].path = 9;
    vertex_array[2].path = 1;
    vertex_array[3].path = 2;
    vertex_array[5].path = 4;
    vertex_array[7].path = 6;
    vertex_array[8].path = 7;
    vertex_array[9].path = 7;

    // now we have a vertex array with each vertex
    // create some test paths to see if function
    // is doing what it is supposed to
    cout << "Now testing vertex*& comparison. There should be three 0s:\n";
    cout << lexicographic(vertex_array,3,5) << " ";
    cout << lexicographic(vertex_array,8,9) << " ";
    cout << lexicographic(vertex_array,9,0) << "\n";

    Tree* best_option = new Tree;
    best_option->insert(3,0);
    best_option->insert(7,0);
    best_option->insert(2,0);
    best_option->insert(8,0);

    Tree* test_1= new Tree;
    test_1->insert(5,0);
    test_1->insert(2,0);

    Tree* test_2= new Tree;
    test_2->insert(3,0);
    test_2->insert(9,0);
    test_2->insert(2,0);
    test_2->insert(8,0);

    Tree* test_3= new Tree;
    test_3->insert(3,0);
    test_3->insert(7,0);
    test_3->insert(11,0);
    test_3->insert(1,0);

    Tree* test_4= new Tree;
    test_4->insert(3,0);
    test_4->insert(7,0);
    test_4->insert(9,0);
    test_4->insert(1,0);

    Tree* test_5= new Tree;
    test_5->insert(3,0);
    test_5->insert(7,0);
    test_5->insert(2,0);
    test_5->insert(8,0);
    test_5->insert(1,0);

    // now we have some paths to work with, check
    // if function is doing what it is supposed to
    cout << "Now testing Tree* comparison. There should be five 0s:\n";
    cout << lexicographic(best_option, test_1) << " ";
    cout << lexicographic(best_option, test_2) << " ";
    cout << lexicographic(best_option, test_3) << " ";
    cout << lexicographic(best_option, test_4) << " ";
    cout << lexicographic(best_option, test_5) << "\n";


}
