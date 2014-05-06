#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

class VertexItem {
    public:
        VertexItem();
        VertexItem(int, int);
        void set_id(int);
        int get_id();
        void set_weight(int);
        int get_weight();
        void set_next(VertexItem*);
        VertexItem* get_next();
        void print();
        void print_list_item(VertexItem*);

    private:
        int id;
        int weight;
        VertexItem* next;
};

class AdjacencyList {
    public:
        AdjacencyList(int);
        int get_size();
        VertexItem* get_array_ptr();
        void set_array_ptr(VertexItem*);
        void insert(int, int, int);
        void print_list();
        int get_edge_weight(int, int);
        
    private:
        int size;
        VertexItem* array_ptr;
};

#endif
