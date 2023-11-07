#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
private:
    int V;

public:
    Graph(int v);

    void addEdge(int u, int v);
    void removeEdge(int u, int v);
    void addVertex();
    void removeVertex(int v);
    void printGraph() const;
    void BFS(int startVertex) const;
    void DFS(int startVertex) const;

    int getVertexCount() const;

    std::vector<std::vector<int>> adjList;
};

#endif
