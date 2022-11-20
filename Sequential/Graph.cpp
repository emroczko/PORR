#include "Graph.h"
#include <iostream>
#include <vector>
#include <map>

void Graph::addEdge(std::pair<int, int> edge) {
    friends[edge.first].push_back(edge.second);
    friends[edge.second].push_back(edge.first);
}

void Graph::countFriends() {
    std::map<int, int> friends_count;

    for (auto &i : this->friends){
        friends_count.insert(std::pair(i.first, i.second.size()));
        //std::cout << "Person: " << i.first << " has " << i.second.size() << " friends" << std::endl;
    }
}

void Graph::countFriendsEfficiently(int threads_number) {
    std::map<int, int> friends_count;
     
    #pragma omp parallel for num_threads(threads_number)
    for (auto &i : this->friends){
        friends_count.insert(std::pair(i.first, i.second.size()));
        //std::cout << "Person: " << i.first << " has " << i.second.size() << " friends" << std::endl;
    }
}