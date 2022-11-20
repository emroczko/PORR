#pragma once

#include <vector>
#include <map>

class Graph {
private:
    std::map<int, std::vector<int>> friends;

public:
    explicit Graph(int verticesCount) {
        for (int i = 1; i <= verticesCount; ++i) {
            this->friends.insert(std::make_pair(i, std::vector<int>()));
        }
    }
    void addEdge(std::pair<int, int> edge);
    void countFriends();
};

