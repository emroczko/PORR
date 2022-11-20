#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <chrono>
#include "Graph.h"

std::unique_ptr<Graph> createGraphFromFile(const std::string &fileName) {
  std::ifstream fileToRead(fileName);
  std::string line;
  int verticesCount = 0;
  std::unique_ptr<Graph> socialNetwork;

  while (std::getline(fileToRead, line))
  {

    if (line[0] == '%')
      continue;

    std::stringstream ss(line);

    if (verticesCount == 0) {
      ss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
      ss >> verticesCount;

      socialNetwork = std::make_unique<Graph>(verticesCount);
    }
    else {
      int id, key;
      ss >> id >> key;
      socialNetwork->addEdge(std::pair(id, key));
    }
    ss.clear();
  }

  fileToRead.close();

  return std::move(socialNetwork);
}

int main() {
    
    std::unique_ptr<Graph> graph = createGraphFromFile("../Datasets/karate.txt");

    auto start = std::chrono::high_resolution_clock::now();
    graph->countFriends();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
 
    std::cout << "Time of sequential processing: " << duration.count() << " microseconds" << std::endl;
}