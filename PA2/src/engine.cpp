
#include "engine.h"


Engine::Engine(string name, int width, int height)// : io(ImGui::GetIO())
{
  m_WINDOW_NAME = name;
  m_WINDOW_WIDTH = width;
  m_WINDOW_HEIGHT = height;
  m_FULLSCREEN = false;

  //ImGui::CreateContext();
}

Engine::Engine(string name) // : io(ImGui::GetIO())
{
  m_WINDOW_NAME = name;
  m_WINDOW_HEIGHT = 0;
  m_WINDOW_WIDTH = 0;
  m_FULLSCREEN = true;

  //ImGui::CreateContext();

}

Engine::~Engine()
{
  delete m_window;
  delete m_graphics;
  m_window = NULL;
  m_graphics = NULL;
}

bool Engine::Initialize()
{
  // Start a window
  m_window = new Window();
  if(!m_window->Initialize(m_WINDOW_NAME, &m_WINDOW_WIDTH, &m_WINDOW_HEIGHT))
  {
    printf("The window failed to initialize.\n");
    return false;
  }

  // Start the graphics
  m_graphics = new Graphics();
  if(!m_graphics->Initialize(m_WINDOW_WIDTH, m_WINDOW_HEIGHT))
  {
    printf("The graphics failed to initialize.\n");
    return false;
  }

  // Set the time
  m_currentTimeMillis = GetCurrentTimeMillis();


  // No errors
  return true;
}

void Engine::Run()
{
  m_running = true;

  while(m_running)
  {
    ImGui::ShowDemoWindow(&m_running);
    
    // Update the DT
    m_DT = getDT(); //DT has to do with time 

    // Check the keyboard input
    while(SDL_PollEvent(&m_event) != 0)
    {
      Keyboard();
    }

    // Update and render the graphics
    m_graphics->Update(m_DT);
    m_graphics->Render();

    
    //ImGui::Text("Hello, world %d", 123);

    // Swap to the Window
    m_window->Swap();


  }
}

void Engine::Keyboard()
{
  if(m_event.type == SDL_QUIT)
  {
    m_running = false;
  }
  else if (m_event.type == SDL_KEYDOWN)
  {
    static float speed = 1; // Stores speed for graphics for adjustment purposes
    switch(m_event.key.keysym.sym) {
    case SDLK_ESCAPE:
      m_running = false;
      break;
    case SDLK_p: // Pause graphics
      if(m_graphics->isPaused())
	m_graphics->unpauseAll();
      else
	m_graphics->pauseAll();
      break;
    case SDLK_UP: // Increase Speed
      speed++;
      m_graphics->setRunSpeed(speed);
      break;
    case SDLK_DOWN: // Decrease Speed 
      speed--;
      m_graphics->setRunSpeed(speed);
      break;
    }
    
    /* Old code. Now converted to Switch. See above ^ 
    if (m_event.key.keysym.sym == SDLK_ESCAPE)
    {
      m_running = false;
    }
    // Press p to pause and unpause cube movement
    if(m_event.key.keysym.sym == SDLK_UP)
      {}
    */
  }
}

unsigned int Engine::getDT()
{
  long long TimeNowMillis = GetCurrentTimeMillis();
  assert(TimeNowMillis >= m_currentTimeMillis);
  unsigned int DeltaTimeMillis = (unsigned int)(TimeNowMillis - m_currentTimeMillis);
  m_currentTimeMillis = TimeNowMillis;
  return DeltaTimeMillis;
}

long long Engine::GetCurrentTimeMillis()
{
  timeval t;
  gettimeofday(&t, NULL);
  long long ret = t.tv_sec * 1000 + t.tv_usec / 1000;
  return ret;
}
