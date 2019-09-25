#include "graphics.h"

Graphics::Graphics()
{

}

Graphics::~Graphics()
{

}

bool Graphics::Initialize(int width, int height)
{
  // Used for the linux OS
  #if !defined(__APPLE__) && !defined(MACOSX)
    // cout << glewGetString(GLEW_VERSION) << endl;
    glewExperimental = GL_TRUE;

    auto status = glewInit();

    // This is here to grab the error that comes from glew init.
    // This error is an GL_INVALID_ENUM that has no effects on the performance
    glGetError();

    //Check for error
    if (status != GLEW_OK)
    {
      std::cerr << "GLEW Error: " << glewGetErrorString(status) << "\n";
      return false;
    }
  #endif

  // For OpenGL 3
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  // Init Camera
  m_camera = new Camera();
  if(!m_camera->Initialize(width, height))
  {
    printf("Camera Failed to Initialize\n");
    return false;
  }

  // Create the object
  m_cube = new Object();
  m_moon = new Satellite(m_cube);

  // Set up the shaders
  m_shader = new Shader();
  if(!m_shader->Initialize())
  {
    printf("Shader Failed to Initialize\n");
    return false;
  }

  // Add the vertex shader
  if(!m_shader->AddShader(GL_VERTEX_SHADER))
  {
    printf("Vertex Shader failed to Initialize\n");
    return false;
  }

  // Add the fragment shader
  if(!m_shader->AddShader(GL_FRAGMENT_SHADER))
  {
    printf("Fragment Shader failed to Initialize\n");
    return false;
  }

  // Connect the program
  if(!m_shader->Finalize())
  {
    printf("Program to Finalize\n");
    return false;
  }

  // Locate the projection matrix in the shader
  m_projectionMatrix = m_shader->GetUniformLocation("projectionMatrix");
  if (m_projectionMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_projectionMatrix not found\n");
    return false;
  }

  // Locate the view matrix in the shader
  m_viewMatrix = m_shader->GetUniformLocation("viewMatrix");
  if (m_viewMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_viewMatrix not found\n");
    return false;
  }

  // Locate the model matrix in the shader
  m_modelMatrix = m_shader->GetUniformLocation("modelMatrix");
  if (m_modelMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_modelMatrix not found\n");
    return false;
  }

  //enable depth testing
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  // Other Init
  runSpeed = 1;
  m_moon->setScale(0.6f);

    
  return true;
}

void Graphics::Update(unsigned int dt)
{
  // Update the object
  m_cube->Update(dt);
  m_moon->Update(dt);
}

void Graphics::Render()
{
  //clear the screen
  glClearColor(0.0, 0.0, 0.2, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Start the correct program
  m_shader->Enable();

  // Send in the projection and view to the shader
  glUniformMatrix4fv(m_projectionMatrix, 1, GL_FALSE, glm::value_ptr(m_camera->GetProjection())); 
  glUniformMatrix4fv(m_viewMatrix, 1, GL_FALSE, glm::value_ptr(m_camera->GetView())); 

  // Original line of code : for reference
  //glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_cube->GetModel()) );  

  /*
  // Render the objects
  // Moon
  const  GLfloat* modelMatrices = glm::value_ptr(m_moon->GetModel());
  m_moon->Render();
  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, modelMatrices );

  // Planet
  modelMatrices = glm::value_ptr(m_cube->GetModel());
  m_cube->Render();
  glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, modelMatrices );
  */

  // Board
  //glm::vec3* start = &(board.vertices);
  //  static GLuint VB;
  //  glGenBuffers(1, &VB);
  //glBindBuffer(GL_ARRAY_BUFFER, VB);
  glBufferData(GL_ARRAY_BUFFER, board.vertices.size() * sizeof(glm::vec3), &(board.vertices[0]), GL_STATIC_DRAW);
  //glDrawElements(GL_TRIANGLES, board.vertices.size(), GL_UNSIGNED_INT, 0);


  // Get any errors from OpenGL
  auto error = glGetError();
  if ( error != GL_NO_ERROR )
  {
    string val = ErrorString( error );
    std::cout<< "Error initializing OpenGL! " << error << ", " << val << std::endl;
  }
}

std::string Graphics::ErrorString(GLenum error)
{
  if(error == GL_INVALID_ENUM)
  {
    return "GL_INVALID_ENUM: An unacceptable value is specified for an enumerated argument.";
  }

  else if(error == GL_INVALID_VALUE)
  {
    return "GL_INVALID_VALUE: A numeric argument is out of range.";
  }

  else if(error == GL_INVALID_OPERATION)
  {
    return "GL_INVALID_OPERATION: The specified operation is not allowed in the current state.";
  }

  else if(error == GL_INVALID_FRAMEBUFFER_OPERATION)
  {
    return "GL_INVALID_FRAMEBUFFER_OPERATION: The framebuffer object is not complete.";
  }

  else if(error == GL_OUT_OF_MEMORY)
  {
    return "GL_OUT_OF_MEMORY: There is not enough memory left to execute the command.";
  }
  else
  {
    return "None";
  }
}

// =============================
// OTHER PUBLIC FUNCTIONS
// ============================

// For set of functions related to pause, refactor later
// Bc it won't scale well, and implementation of
// stop all objects is not ideal

void Graphics::setBoard(const BasicObject& x) {
  /*    for(unsigned int i = 0; i < x.vertices.size(); i++) {
    cout << i << " " <<  x.vertices[i].x << " " << x.vertices[i].y << " " << x.vertices[i].z << endl;
    }*/
  //cout << x.vertices.size() << endl;
  board.vertices = x.vertices;
  board.uvs = x.uvs;
  board.normals = x.normals;
  
}

// Desc: Pauses all objects under Graphics instance
void Graphics::pauseAll() {
  m_cube->setPaused(true);
  m_moon->setPaused(true);
}

// Desc: Unpauses all objects
void Graphics::unpauseAll() {
  m_cube->setPaused(false);
  m_moon->setPaused(false);
}

void Graphics::setRunSpeed(float newSpeed) {
  if(newSpeed == 0)
    {
      runSpeed = newSpeed;
      pauseAll();
      return;
    }
  unpauseAll();
  
  runSpeed = newSpeed;
  m_cube->setRotationalVelocity(runSpeed);
  m_moon->setRotationalVelocity(runSpeed);
  
}
