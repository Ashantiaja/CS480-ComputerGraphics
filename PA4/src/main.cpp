#include <iostream>

#include "engine.h"
#include "util.h"

int main(int argc, char **argv)
{
  BasicObject objInfo; // will store board info for later model loading
  // Check if there are any arguments
  //cout << "argc: " << argc << endl;
  for(int i = 1 ; i < argc-1; i += 2) { // i = 1, 3, 5, 7 etc
    //util::handleArgument(argv[i], argv[i+1]);
    //cout << string(argv[i]) << " " << string(argv[i+1]) << endl;
    if(argv[i][1] == 'm') {
      // Load model
      if(util::loadObj(argv[i+1], objInfo.vertices, objInfo.uvs, objInfo.normals)) {
	cout << argv[i+1] << " loaded." << endl;
      }
      else
	cout << argv[i+1] << " not loaded." << endl;
    }
  } // End for : end argument handling
  // Load the names of the files/shaders passed in into seperate file
  // util::loadToFile(argc, argv);

  // Start an engine and run it then cleanup after
  Engine *engine = new Engine("PA4", 800, 600);
  
  if(!engine->Initialize())
  {
    printf("The engine failed to start.\n");
    delete engine;
    engine = NULL;
    return 1;
  }
  engine->getGraphics()->setBoard(objInfo);
  engine->Run();
  delete engine;
  engine = NULL;
  return 0;
}
