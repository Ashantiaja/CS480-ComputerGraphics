/*
  This file will store various utility functions for use around the program
  until they are eventually refactored into another appropriate spot. 
 */

#include "util.h"

/* void util::loadToFile(int argc, char** argv, std::string outFile) {
  
   } */

// This takes in a flag and then it's corresponding argument and
// redirects to the proper function that will handle that
// specific file
void util::handleArgument(char const* flag, char const* argument) {
  // Move c-style strings to std::string for ease of use
  string arg(argument);
  string flg(flag);

  /*
    -m <file.obj> // Loads a object file 
    -f <fragmentShader> // Loads fragment shader
    -v <vertexShader> // Loads a vertex shader
    Question : How is the info from the file brought to other
    objects in the program?
    flg[0] should be -, 
   */
  
  if(flag[1] == 'm') { // Load model
    vector<glm::vec3> vertices;
    vector<glm::vec2> uvs;
    vector<glm::vec3> normals;
    if(util::loadObj(argument, vertices, uvs, normals)) {
      cout << arg << " loaded successfully." << endl;
    }
    else {
      cout << arg << " not loaded." << endl;
    }
  }
  /*
    else if(flg[1] == f) {

}
else if(flg[1] == v) {

}
   */
}

bool util::loadObj(char const* filepath, vector<glm::vec3> &o_vertices,
	       vector<glm::vec2> &o_uvs, vector<glm::vec3> &o_normals) {
  
  // Open File
  FILE* fileptr = fopen(filepath, "r");
  if(fileptr == NULL)
    return false; // Failed to open

  //Process contents
  vector<glm::vec3> vertices; //'array' of glm::vec3 vertices
  vector<glm::vec2> uvs;
  vector<glm::vec3> normals;
  vector<unsigned int> vertexIndices, uvIndices, normalIndices;
  std::string vertex1, vertex2, vertex3;
  unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
  int read = 1;

  while(read != EOF) {
    char header[10]; // v vt vn f s usemtl
    // Read input one at a time until something recognizable is found
    read = fscanf(fileptr, "%s", header); 
    if(read == EOF)
      break;

    // Line designates vertex
    if(strcmp(header, "v") == 0) {
      glm::vec3 tempVertex;
      fscanf(fileptr, "%f %f %f\n", &tempVertex.x, &tempVertex.y, &tempVertex.z);
      vertices.push_back(tempVertex);
    }
    else if(strcmp(header, "vt") == 0) {
      glm::vec2 uv;
      fscanf(fileptr,"%f %f\n", &uv.x, &uv.y);
      uvs.push_back(uv);
    }
    else if(strcmp(header, "vn") == 0) {
      glm::vec3 norm;
      fscanf(fileptr, "%f %f %f\n", &norm.x, &norm.y, &norm.z);
      normals.push_back(norm);
    }
    else if(strcmp(header, "f") == 0) {


      int matches = fscanf(fileptr, "%d/%d/%d %d/%d/%d %d/%d/%d\n",
			   &vertexIndex[0], &uvIndex[0], &normalIndex[0],
			   &vertexIndex[1], &uvIndex[1], &normalIndex[1],
			   &vertexIndex[2], &uvIndex[2], &normalIndex[2]);

      if (matches != 9) {
	cout << "File unable to be read." << endl;
	return false;
      }


    vertexIndices.push_back(vertexIndex[0]);
    vertexIndices.push_back(vertexIndex[1]);
    vertexIndices.push_back(vertexIndex[2]);
    uvIndices    .push_back(uvIndex[0]);
    uvIndices    .push_back(uvIndex[1]);
    uvIndices    .push_back(uvIndex[2]);
    normalIndices.push_back(normalIndex[0]);
    normalIndices.push_back(normalIndex[1]);
    normalIndices.push_back(normalIndex[2]);
    }
    
  } // End while : end file contents processing

  // Debugging : display vertices
  /*
  for(unsigned int i = 0; i < vertices.size(); i++) {
    cout << vertices[i].x << " "
	 << vertices[i].y << " "
	 << vertices[i].z << endl;
  }

  for(unsigned int i = 0; i < uvs.size(); i++) {
    cout << uvs[i].x << " "
	 << uvs[i].y << endl;
	
  }

  for(unsigned int i = 0; i < normals.size(); i++) {
    cout << normals[i].x << " "
	 << normals[i].y << " "
	 << normals[i].z << endl;
  }
  */

  // Copy and Process vertices for openGL
  for(unsigned int i = 0; i < vertexIndices.size(); i++) {
    unsigned int vertexIndex = vertexIndices[i];
    glm::vec3 vert = vertices[vertexIndex-1];
    o_vertices.push_back(vert);
  }

  for(unsigned int i = 0; i < uvIndices.size(); i++) {
    unsigned int uvIndex = uvIndices[i];
    glm::vec2 uv = uvs[uvIndex-1];
    o_uvs.push_back(uv);
  }

  for(unsigned int i = 0; i < normalIndices.size(); i++) {
    unsigned int normalIndex = normalIndices[i];
    glm::vec3 norm = normals[normalIndex-1];
    o_vertices.push_back(norm);
  }

  fclose(fileptr);
  return true;
}

/*
template <typename T>
void util::showVector(vector<T> toDisplay) {
  for(unsigned int i = 0; i < toDisplay.size(); i++) {
    
  }
  }*/
