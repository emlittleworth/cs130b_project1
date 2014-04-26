#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

class VertexItem {
    public:
        VertexItem();
        VertexItem(int, int, VertexItem*);
        void set_id(int);
        int get_id();
        void set_weight(int);
        int get_weight();
        void set_next(VertexItem*);
        VertexItem* get_next();

    private:
        int id;
        int weight;
        VertexItem* next;
}

class AdjacencyList {
    public:
        AdjacencyList(int);
        int get_size();
        void insert(int, int, int);
        void printlist();
        
    private:
        int size;
        VertexItem adj_array[];

}

#endif
