#pragma once

#include <vector>
#include <map>

class Graph {
private:
    bool** adjacency_matrix;
    int vertices_count;

public:
    explicit Graph(int vertices_count) {
        this->vertices_count = vertices_count;

        adjacency_matrix = new bool*[vertices_count];
        for (int i = 0; i < vertices_count; i++) {
            adjacency_matrix[i] = new bool[vertices_count];
            for (int j = 0; j < vertices_count; j++)
                adjacency_matrix[i][j] = false;
        }
    }

    void addEdge(std::pair<int, int> edge) { 
        adjacency_matrix[edge.first - 1][edge.second - 1] = true;
        adjacency_matrix[edge.second - 1][edge.first - 1] = true;
    }

    void countFriends();
    void countFriendsEfficiently(int threads_number);
};

