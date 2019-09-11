#include <iostream>
#include <fstream>
#include <string>

#include "engine.h"

int main(int argc, char **argv)
{
  std::string fragShaderInfo = ""; // Stores information for fragment shader
  std::string vertShaderInfo = "";

  // Process command line arguments
  for(int i = 1; i < argc; i++) {

    // Check for flag -f for fragment shader
    if(argv[i][0] == '-' && argv[i][1] == 'f') {
      i++; // move from flag to file
      std::fstream fragFile; 
      std::string fileName = argv[i];

      //Attempt to open file
      fragFile.open(fileName);
      if(!fragFile.is_open()) { // if unable to open file
	std::cout << "File " << argv[i] << " unable to be opened." << std::endl;
	return 0;
      }

      // Once successfully opened, read into string

      std::string buffer = "";
      while(!fragFile.eof()) {
	std::getline(fragFile, buffer);
	fragShaderInfo.append(buffer + "\n");
      }
      // Close original file
      fragFile.close();
    }

    // Check for flag -v for vertex shader
    if(argv[i][0] == '-' && argv[i][1] == 'v') {
      i++; // move from flag to file
      std::fstream vertFile; 
      std::string fileName = argv[i];

      //Attempt to open file
      vertFile.open(fileName);
      if(!vertFile.is_open()) { // if unable to open file
	std::cout << "File " << argv[i] << " unable to be opened." << std::endl;
	return 0;
      }

      // Once successfully opened, read into string

      std::string buffer = "";
      while(!vertFile.eof()) {
	std::getline(vertFile, buffer);
	vertShaderInfo.append(buffer + "\n");
      }
      // Close original file
      vertFile.close();
    }
  }
  
  // Start an engine and run it then cleanup after
  Engine *engine = new Engine("Tutorial Window Name", 800, 600);

  // Put shader info into engine
  engine->setShader(GL_VERTEX_SHADER, vertShaderInfo);
  engine->setShader(GL_FRAGMENT_SHADER, fragShaderInfo);
  
  if(!engine->Initialize())
  {
    printf("The engine failed to start.\n");
    delete engine;
    engine = NULL;
    return 1;
  }
  engine->Run();
  delete engine;
  engine = NULL;
  return 0;
}
