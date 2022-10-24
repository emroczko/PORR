#pragma once

#include <vector>

class Graph
{
private:
    int verticesCount;
    std::vector<std::pair<int, int>> edges;

public:
    Graph(int verticesCount);
    void addEdges(std::pair<int, int> edge);
    int getEdgesCount();
    void setVerticesCount(int verticesCount);
};