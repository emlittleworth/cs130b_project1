#include "adjacency_list.h"
#include <iostream>
using namespace std;



// VertexItem Methods

VertexItem::VertexItem() : id(-1), weight(-1), next(NULL) {} 

VertexItem::VertexItem(int the_id, int the_weight) :
    id(the_id), weight(the_weight), next(NULL) {}

void VertexItem::set_id(int the_id) { id = the_id;}

int VertexItem::get_id() { return id;}

void VertexItem::set_weight(int the_weight) { weight = the_weight;}

int VertexItem::get_weight() { return weight;}

void VertexItem::set_next(VertexItem* other) { next = other;}

VertexItem* VertexItem::get_next() { return next;}

void VertexItem::print() {
    cout << id << " " << weight << " ";
}

void VertexItem::print_list_item(VertexItem* root) {
    root->print();
    if (root->next != NULL) {
        cout << "-> ";
        print_list_item(root->next);
    }
}



// AdjacencyList Methods

AdjacencyList::AdjacencyList(int the_size) : size(the_size), array_ptr(NULL) {}

int AdjacencyList::get_size() { return size;}

VertexItem* AdjacencyList::get_array_ptr() { return array_ptr;}

void AdjacencyList::set_array_ptr(VertexItem* other) { array_ptr = other;}

void AdjacencyList::insert(int first, int second, int weight) {
    // insert makes a new VertexItem node (second, weight) that the
    // VertexItem in the adjacency list points to (linked list)
    VertexItem *p = new VertexItem(second, weight);
    VertexItem *temp;
    for(temp = &array_ptr[first]; temp->get_next() != NULL; temp = temp->get_next()) {}
    temp->set_next(p);
}

void AdjacencyList::print_list() {
    for(int i = 0; i < size; i++) {
        array_ptr[i].print_list_item(&array_ptr[i]);
        cout << "\n";
    }
}

int AdjacencyList::get_edge_weight(int first, int second) {
    VertexItem* ptr;
    for (ptr = array_ptr[first].get_next(); ptr != NULL; ptr = ptr->get_next()) {
        if (ptr->get_id() == second)
            return ptr->get_weight();
    }
    return 0;
}

