#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
using namespace std;

#include "graphics_headers.h"
#include "camera.h"
#include "shader.h"
#include "object.h"

class Graphics
{
  public:
    Graphics();
    ~Graphics();
    bool Initialize(int width, int height);
    void Update(unsigned int dt);
    void Render();

    void pauseAll();
    void unpauseAll();
    bool isPaused();

    void setRunSpeed(float);

  private:

    bool paused;
    float runSpeed; // 1x speed vs 2x speed for objects on screen
    
    std::string ErrorString(GLenum error);

    Camera *m_camera;
    Shader *m_shader;

    GLint m_projectionMatrix;
    GLint m_viewMatrix;
    GLint m_modelMatrix;

    Object *m_cube;
};

#endif /* GRAPHICS_H */
