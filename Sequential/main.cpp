#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void createSocialNetwork(const std::string &fileName)
{
  std::ifstream fileToRead(fileName);
  std::string line;
  int verticesCount = 0;

  while (std::getline(fileToRead, line))
  {

    if (line[0] == '%')
      continue;

    std::stringstream ss(line);

    if (verticesCount == 0)
    {
      ss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
      int vertices, edges;
      ss >> vertices >> edges;
      
      verticesCount = vertices;
      std::cout << "Vertices: " << vertices << " Edges: " << edges << std::endl;
    }
    else
    {
      int id, key;
      ss >> id >> key;

      std::cout << "ID: " << id << " Key: " << key << std::endl;
    }

    ss.clear();
  }

  fileToRead.close();
}

int main()
{
  createSocialNetwork("../Datasets/karate.txt");
}