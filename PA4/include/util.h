#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "engine.h"

namespace util {

  // Load command line arguments into file
  //void loadToFile(int, char**, std::string );

  // Takes command line flag and argument pair and calls
  // appropriate function to handle it all
  void handleArgument(char const* flag, char const* argument);

  // Loads and puts .obj data into vectors 
  bool loadObj(char const* filepath, vector<glm::vec3> &o_vertices,
	       vector<glm::vec2> &o_uvs, vector<glm::vec3> &o_normals);

  template <typename T>
    void showVector(std::vector<T> toDisplay);


}

#endif
