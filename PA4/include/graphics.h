#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <vector>
using namespace std;

#include "graphics_headers.h"
#include "camera.h"
#include "shader.h"
#include "object.h"
#include "satellite.h"

struct BasicObject {
  vector<glm::vec3> vertices;
  vector<glm::vec2> uvs;
  vector<glm::vec3> normals;
};

class Graphics
{
  // keystrokes from engine directly effect
  // objects in graphics
  friend class Engine;

  public:
    Graphics();
    ~Graphics();
    bool Initialize(int width, int height);
    void Update(unsigned int dt);
    void Render();

    void setBoard(const BasicObject& x);
    void pauseAll();
    void unpauseAll();
    
    void setRunSpeed(float);

  private:

        float runSpeed; // 1x speed vs 2x speed for objects on screen
    
    std::string ErrorString(GLenum error);

    Camera *m_camera;
    Shader *m_shader;

    GLint m_projectionMatrix;
    GLint m_viewMatrix;
    GLint m_modelMatrix;

    BasicObject board;
    Object *m_cube;
    Satellite *m_moon;
};

#endif /* GRAPHICS_H */
