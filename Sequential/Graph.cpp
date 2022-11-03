#include "Graph.h"
#include <iostream>
#include <vector>
#include <map>

void Graph::addEdge(std::pair<int, int> edge) {
    friends[edge.first].push_back(edge.second);
    friends[edge.second].push_back(edge.first);
}

void Graph::countFriends() {
    for (auto &i : this->friends){
        std::cout << "Person: " << i.first << " has " << i.second.size() << " friends" << std::endl;
    }
}

void Graph::setVerticesCount(int verticesCount) {
    for (int i = 1; i <= verticesCount; ++i) {
        this->friends.insert(std::make_pair(i, std::vector<int>()));
    }
}