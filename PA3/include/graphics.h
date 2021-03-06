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

    Object *m_cube;
    Satellite *m_moon;
};

#endif /* GRAPHICS_H */
