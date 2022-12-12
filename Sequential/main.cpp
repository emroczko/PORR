#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <chrono>
#include <iomanip>
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
      socialNetwork->addEdge(std::pair<int, int>(id, key));
    }
    ss.clear();
  }

  fileToRead.close();

  return std::move(socialNetwork);
}

inline bool exists (const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

int main(int argc, char** argv)
{
  std::string path_to_datasets = "insert-path-to-datasets-here";
  
  std::vector<std::string> file_names { 
                                        "epinions.txt", 
                                        "gplus.txt", 
                                        "wiki-vote.txt", 
                                        "karate.txt"
                                      };

  for (auto &f: file_names) {

    std::string full_path = path_to_datasets + f;

    if(!exists(full_path)) {
      std::cout << "File " << full_path << " does not exist!" << std::endl;
      continue;
    }
       
    std::unique_ptr<Graph> graph = createGraphFromFile(full_path);
    std::cout << "Graph from "<< f << " created" << std::endl;

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

      float sequential = static_cast<float>(duration_seq.count()) / 1000000;
      float parallel = static_cast<float>(duration_par.count()) / 1000000;

      std::cout << std::fixed << std::setprecision(6)
      << "Sequential : parallel processing: "<< sequential << " : "<< parallel << " seconds" << std::endl;
    }
  }
}