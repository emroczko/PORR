#pragma once

#include <vector>
#include <map>

class Graph {
private:
    std::map<int, std::vector<int>> friends;

public:
    void addEdge(std::pair<int, int> edge);
    void countFriends();
    void setVerticesCount(int verticesCount);
};