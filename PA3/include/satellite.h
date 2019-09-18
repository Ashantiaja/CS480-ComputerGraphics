/* This class inherits from object, but
   adds additional attributes that make it easier
   to configure orbit around another object
*/
#include "object.h"
#include <glm/gtx/matrix_decompose.hpp>
#include <iostream>

class Satellite : public Object {
  friend class Graphics;
 public:
  Satellite(Object*);
  ~Satellite();
    
  Object* originObject;

  // Satellite::setOrbit only takes in offset as origin comes
  // from the object it orbits
  void setOrbit(glm::vec3 offset = glm::vec3(3.0f, 0.0f, 0.0f));

  void Update(unsigned int dt);
  
};
