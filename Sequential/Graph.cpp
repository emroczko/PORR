#include "Graph.h"
#include <iostream>
#include <vector>
#include <map>

void Graph::countFriends() {
    for (int u = 0; u < vertices_count; u++) {
        int counter = 0;
        for (int v = 0; v < vertices_count; v++)
            if (adjacency_matrix[u][v])
                ++counter;   
        // std::cout << "Standard: Person: " << u + 1 << " has " << counter << " friends" << std::endl;
    }
}

void Graph::countFriendsEfficiently(int threads_number) {
    #pragma omp parallel for num_threads(threads_number) collapse(2)
    for (int u = 0; u < vertices_count; u++) {
        int counter = 0;
        for (int v = 0; v < vertices_count; v++)
            if (adjacency_matrix[u][v])
                ++counter; 
        // std::cout << "Standard: Person: " << u << " has " << counter << " friends" << std::endl;
    }
}