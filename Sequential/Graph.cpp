#include "Graph.h"

Graph::Graph(int verticesCount)
{
    this->verticesCount = verticesCount;
}

void Graph::addEdges(std::pair<int, int> edge)
{
    this->edges.push_back(edge);
}

int Graph::getEdgesCount()
{
    return this->edges.size();
}

void Graph::setVerticesCount(int verticesCount)
{
    this->verticesCount = verticesCount;
}