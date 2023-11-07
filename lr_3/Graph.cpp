#include "Graph.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>

Graph::Graph(int v) : V(v) {
    adjList.resize(V);
}

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void Graph::removeEdge(int u, int v) {
    for (int i = 0; i < adjList[u].size(); i++) {
        if (adjList[u][i] == v) {
            adjList[u].erase(adjList[u].begin() + i);
            break;
        }
    }

    for (int i = 0; i < adjList[v].size(); i++) {
        if (adjList[v][i] == u) {
            adjList[v].erase(adjList[v].begin() + i);
            break;
        }
    }
}

void Graph::addVertex() {
    V++;
    adjList.resize(V);
}

void Graph::removeVertex(int v) {
    for (int i = 0; i < V; i++) {
        removeEdge(v, i);
    }
    adjList.erase(adjList.begin() + v);
    V--;
}

void Graph::printGraph() const {
    for (int i = 0; i < V; i++) {
        std::cout << "Вершина " << i << " связана с вершинами: ";
        for (int j = 0; j < adjList[i].size(); j++) {
            std::cout << adjList[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::BFS(int startVertex) const {
    std::vector<bool> visited(V, false);
    std::queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    std::cout << "Обход в ширину (BFS): ";
    while (!q.empty()) {
        int vertex = q.front();
        std::cout << vertex << " ";
        q.pop();

        for (int i : adjList[vertex]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    std::cout << std::endl;
}

void Graph::DFS(int startVertex) const {
    std::vector<bool> visited(V, false);
    std::stack<int> s;

    s.push(startVertex);

    std::cout << "Обход в глубину (DFS): ";
    while (!s.empty()) {
        int vertex = s.top();
        s.pop();

        if (!visited[vertex]) {
            std::cout << vertex << " ";
            visited[vertex] = true;
        }

        for (int i : adjList[vertex]) {
            if (!visited[i]) {
                s.push(i);
            }
        }
    }
    std::cout << std::endl;
}

int Graph::getVertexCount() const {
    return V;
}

