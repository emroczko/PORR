#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Graph.h"

void createSocialNetwork(const std::string &fileName) {
  std::ifstream fileToRead(fileName);
  std::string line;
  int verticesCount = 0;
  Graph socialNetwork;

  while (std::getline(fileToRead, line))
  {

    if (line[0] == '%')
      continue;

    std::stringstream ss(line);

    if (verticesCount == 0) {
      ss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
      ss >> verticesCount;

      socialNetwork.setVerticesCount(verticesCount);
    }
    else {
      int id, key;
      ss >> id >> key;
      socialNetwork.addEdge(std::pair(id, key));
    }
    ss.clear();
  }

  socialNetwork.countFriends();
  fileToRead.close();
}

int main() {
  createSocialNetwork("../Datasets/karate.txt");
}