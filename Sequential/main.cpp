#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <chrono>
#include "Graph.h"

#define MAX_THREADS 10

std::unique_ptr<Graph> createGraphFromFile(const std::string &fileName)
{
  std::ifstream fileToRead(fileName);
  std::string line;
  int verticesCount = 0;
  std::unique_ptr<Graph> socialNetwork;

  while (std::getline(fileToRead, line))
  {

    if (line[0] == '%')
      continue;

    std::stringstream ss(line);

    if (verticesCount == 0)
    {
      ss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
      ss >> verticesCount;

      socialNetwork = std::make_unique<Graph>(verticesCount);
    }
    else
    {
      int id, key;
      ss >> id >> key;
      socialNetwork->addEdge(std::pair(id, key));
    }
    ss.clear();
  }

  fileToRead.close();

  return std::move(socialNetwork);
}

int main()
{

  std::unique_ptr<Graph> graph = createGraphFromFile("../Datasets/gplus.txt");
  std::cout << "Graph created" << std::endl;

  for (int threads = 1; threads <= MAX_THREADS; threads++)
  {
    auto start_seq = std::chrono::high_resolution_clock::now();
    graph->countFriends();
    auto stop_seq = std::chrono::high_resolution_clock::now();
    auto duration_seq = std::chrono::duration_cast<std::chrono::microseconds>(stop_seq - start_seq);
    
    auto start_par = std::chrono::high_resolution_clock::now();
    graph->countFriendsEfficiently(threads);
    auto stop_par = std::chrono::high_resolution_clock::now();
    auto duration_par = std::chrono::duration_cast<std::chrono::microseconds>(stop_par - start_par);

    std::cout << "Sequential : parallel processing: " << duration_seq.count() << " : "<< duration_par.count() << " microseconds" << std::endl;
  }
}