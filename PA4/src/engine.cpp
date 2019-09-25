
#include "engine.h"


Engine::Engine(string name, int width, int height)// : io(ImGui::GetIO())
{
  m_WINDOW_NAME = name;
  m_WINDOW_WIDTH = width;
  m_WINDOW_HEIGHT = height;
  m_FULLSCREEN = false;

}

Engine::Engine(string name) // : io(ImGui::GetIO())
{
  m_WINDOW_NAME = name;
  m_WINDOW_HEIGHT = 0;
  m_WINDOW_WIDTH = 0;
  m_FULLSCREEN = true;

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
    
    // Update the DT
    m_DT = getDT(); //DT has to do with time 


    
    // Check the keyboard input
    while(SDL_PollEvent(&m_event) != 0)
    {
      Keyboard();
      Mouse();
    }

    // Update and render the graphics
    m_graphics->Update(m_DT);
    m_graphics->Render();

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
    switch(m_event.key.keysym.sym) {
    case SDLK_ESCAPE:
      m_running = false;
      break;
    case SDLK_x: // Go all
      m_graphics->unpauseAll();
      break;
    case SDLK_z: // Stop all
      m_graphics->pauseAll();
      break;
    case SDLK_w: // Increase speed of planet
      m_graphics->m_cube->increaseSpeed();
      break;
    case SDLK_s: // Decrease speed of planet
      m_graphics->m_cube->decreaseSpeed();
      break;
    case SDLK_d: // Reverse Direction of planet
      m_graphics->m_cube->reverseRotation();
      break;
    case SDLK_a: //Start/Stop planet
      if(m_graphics->m_cube->getRotationalVelocity() != 0) 
	m_graphics->m_cube->setPaused(true);
      else
	m_graphics->m_cube->setPaused(false);
      break;
    case SDLK_UP: // Increase speed of moon
      m_graphics->m_moon->increaseSpeed();
      break;
    case SDLK_DOWN: // Decrease speed of moon
      m_graphics->m_moon->decreaseSpeed();
      break;
    case SDLK_RIGHT: // Reverse Direction of moon
      m_graphics->m_moon->reverseRotation();
      break;
    case SDLK_LEFT: // Start/Stop Moon
      if(m_graphics->m_moon->getRotationalVelocity() != 0) 
	m_graphics->m_moon->setPaused(true);
      else
	m_graphics->m_moon->setPaused(false);
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

void Engine::Mouse() {
  if(m_event.type == SDL_QUIT) {
    m_running = false;
  }
  else if (m_event.type == SDL_MOUSEBUTTONUP)  {
    /*switch(m_event.button) {
    case SDL_BUTTON_LEFT: // Reverse planet direction
       m_graphics->m_cube->reverseRotation();
      break;
    case SDL_BUTTON_RIGHT: // Reverse moon direction
       m_graphics->m_moon->reverseRotation();
      break;
    }
    */
    if(m_event.button.button == SDL_BUTTON_LEFT) {
       m_graphics->m_cube->reverseRotation();
    }
    else if (m_event.button.button == SDL_BUTTON_RIGHT) {
       m_graphics->m_moon->reverseRotation();
    }
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

Graphics* Engine::getGraphics() {
  return m_graphics;
}
