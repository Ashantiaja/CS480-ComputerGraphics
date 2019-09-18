#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"

class Object
{
  public:
    Object();
    ~Object();
    virtual void Update(unsigned int dt);
    void Render();

    glm::mat4 GetModel();

    void setPaused(bool);
    void setRotationalVelocity(float);
    // The greater the number passed in.. the slower the object goes..
    void setOrbit(glm::vec3 origin = glm::vec3(0.0, 1.0, 0.0)		\
		  , glm::vec3 offset = glm::vec3(3.0f, 0.0f, 0.0f));
    //glm::vec4 getObject    

  protected:
    bool isPaused; // remove later.
    float rotationalVelocity;
    glm::vec3 origin;
    glm::vec3 offset;
					       
    
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;

    float angle;
};

#endif /* OBJECT_H */
