#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Graph.h"

void createSocialNetwork(const std::string &fileName)
{
  std::ifstream fileToRead(fileName);
  std::string line;
  int verticesCount = 0;
  Graph socialNetwork(verticesCount);

  while (std::getline(fileToRead, line))
  {

    if (line[0] == '%')
      continue;

    std::stringstream ss(line);

    if (verticesCount == 0)
    {
      ss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
      ss >> verticesCount;

      socialNetwork.setVerticesCount(verticesCount);
      // std::cout << "Vertices: " << verticesCount << std::endl;
    }
    else
    {
      int id, key;
      ss >> id >> key;
      socialNetwork.addEdges(std::pair(id, key));

      // std::cout << "ID: " << id << " Key: " << key << std::endl;
    }

    ss.clear();
  }

  std::cout << "Edges count from object: " << socialNetwork.getEdgesCount() << std::endl;
  fileToRead.close();
}

int main()
{
  createSocialNetwork("../Datasets/karate.txt");
}