#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <vector>
#include <string>
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

    void addShaderInfo(GLenum ShaderType, std::string shaderInfo); 

  private:
    std::string ErrorString(GLenum error);

    //std::vector<std::string> fragShaders;
    //std::vector<std::string> vertShaders;
    string fragShaderInfo;
    string vertShaderInfo;

    Camera *m_camera;
    Shader *m_shader;

    GLint m_projectionMatrix;
    GLint m_viewMatrix;
    GLint m_modelMatrix;

    Object *m_cube;
};

#endif /* GRAPHICS_H */
