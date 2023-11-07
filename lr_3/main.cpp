#include "Graph.h"
#include "MenuManager.h"
#include "MenuItem.h"
#include <iostream>
#include <fstream>
#include <functional>

void loadFromFile(Graph& graph) {
    std::string filename = "../graph.txt";
    std::ifstream inFile(filename);
    int u, v;
    while (inFile >> u >> v) {
        graph.addEdge(u, v);
    }
    inFile.close();
}


void displayGraph(const Graph& graph) {
    graph.printGraph();
}

void addVertex(Graph& graph) {
    graph.addVertex();
}

void addEdge(Graph& graph) {
    int u, v;
    std::cout << "Введите вершины ребра: ";
    std::cin >> u >> v;
    graph.addEdge(u, v);
}

void removeVertex(Graph& graph) {
    int v;
    std::cout << "Введите вершину для удаления: ";
    std::cin >> v;
    graph.removeVertex(v);
}

void removeEdge(Graph& graph) {
    int u, v;
    std::cout << "Введите вершины ребра для удаления: ";
    std::cin >> u >> v;
    graph.removeEdge(u, v);
}

void BFS(const Graph& graph) {
    int startVertex;
    std::cout << "Введите начальную вершину: ";
    std::cin >> startVertex;
    graph.BFS(startVertex);
}

void DFS(const Graph& graph) {
    int startVertex;
    std::cout << "Введите начальную вершину: ";
    std::cin >> startVertex;
    graph.DFS(startVertex);
}


void findReachableVerticesDFS(const Graph& graph, int vertex, int maxLength, std::vector<bool>& visited, std::vector<int>& path) {
    visited[vertex] = true;
    path.push_back(vertex);

    if (path.size() <= maxLength) {
        std::cout << vertex << " ";
    }

    for (int neighbor : graph.adjList[vertex]) {
        if (!visited[neighbor]) {
            findReachableVerticesDFS(graph, neighbor, maxLength, visited, path);
        }
    }

    visited[vertex] = false;
    path.pop_back();
}

void findReachableVertices(const Graph& graph) {
    int startVertex, maxLength;
    std::cout << "Введите начальную вершину: ";
    std::cin >> startVertex;
    std::cout << "Введите максимальную длину пути (A): ";
    std::cin >> maxLength;

    std::vector<bool> visited(graph.getVertexCount(), false);
    std::vector<int> path;

    std::cout << "Вершины, к которым можно добраться из вершины " << startVertex << " по пути не длиннее " << maxLength << ": ";
    findReachableVerticesDFS(graph, startVertex, maxLength, visited, path);
    std::cout << std::endl;
}

int main() {
    Graph graph(5);

    MenuManager menuManager;
    menuManager.addMenuItem(MenuItem("Load graph from file", std::bind(loadFromFile, std::ref(graph))));
    menuManager.addMenuItem(MenuItem("Display graph", std::bind(displayGraph, std::cref(graph))));
    menuManager.addMenuItem(MenuItem("Add vertex", std::bind(addVertex, std::ref(graph))));
    menuManager.addMenuItem(MenuItem("Add edge", std::bind(addEdge, std::ref(graph))));
    menuManager.addMenuItem(MenuItem("Remove vertex", std::bind(removeVertex, std::ref(graph))));
    menuManager.addMenuItem(MenuItem("Remove edge", std::bind(removeEdge, std::ref(graph))));
    menuManager.addMenuItem(MenuItem("BFS traversal", std::bind(BFS, std::cref(graph))));
    menuManager.addMenuItem(MenuItem("DFS traversal", std::bind(DFS, std::cref(graph))));
    menuManager.addMenuItem(MenuItem("Find reachable vertices", std::bind(findReachableVertices, std::cref(graph))));

    menuManager.showMenu();

    return 0;
}
