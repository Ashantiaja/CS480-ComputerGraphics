#include "satellite.h"

Satellite::Satellite(Object* obj) : originObject(obj) {
  
}

Satellite::~Satellite() {

}

void Satellite::setOrbit(glm::vec3 offset) {
  this->offset = offset;
}

void Satellite::Update(unsigned int dt) {
  //Same as object::Update, but must update origin

  glm::vec3 otherScale;
  glm::quat rotation;
  glm::vec3 translation;
  glm::vec3 skew;
  glm::vec4 perspective;
  glm::decompose(originObject->GetModel(), otherScale, rotation, translation, skew,perspective);
  
  origin = translation;
  glm::vec3 axis = glm::cross(glm::vec3(translation.x,0,0), glm::vec3(0,0,translation.z));
  //std::cout << translation.x << " " << translation.y << " " << translation.z <<  std::endl;
  //axis of rotation is the cross product of translationx and translationz vectors
 
  //Object::Update(dt);
  angle += rotationalVelocity * (dt * M_PI/1000);

  model = glm::mat4(1.0f);

  // Put object at same spot as object it will orbit
  model *= glm::translate(origin);

  // Rotate around axis at center of other object
  model *= glm::rotate(angle, abs(axis));
  //std::cout << axis.y << std::endl;

  // Offset from the orbited object
  model *= glm::translate(offset);

  // Scale it down
  model *= glm::scale(scale);


}
