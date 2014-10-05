Group Steiner Tree Problem
==========================

### Problem
Given an *n*-node, positive edge weighted (undirected) graph *G* with *m* edges, and *k* groups of vertices, find a group Steiner Tree in *G* such that the sum of the weight of the edges in it is least possible amongst all other group Steiner Trees for *G*. A *group Steiner Tree* is a set *T* of edges in a graph *G* such that *T* is within the edges of *G* and every group has at least one vertex in *T*.

### Implementation
The graph is represented using an adjacency list. The main algorithm is derived from Dijkstra's graph search algorithm.
