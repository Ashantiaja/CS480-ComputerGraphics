# PA1: Spinning Cube

# Dependencies, Building, and Running

## Project Description
The program allows the user to change the direction of the cube and to stop and start it from spinning.

## Dependency Instructions
For both of the operating systems to run this project installation of these three programs are required [GLEW](http://glew.sourceforge.net/), [GLM](http://glm.g-truc.net/0.9.7/index.html), and [SDL2](https://wiki.libsdl.org/Tutorials).

This project uses OpenGL 3.3. Some computers, such as virtual machines in the ECC, can not run this version. In in order to run OpenGL 2.7 follow the instructions at [Using OpenGL 2.7](https://github.com/HPC-Vis/computer-graphics/wiki/Using-OpenGL-2.7)

### Ubuntu/Linux
```bash
sudo apt-get install libglew-dev libglm-dev libsdl2-dev
```

## Building and Running

### Makefile Instructions 
The makefile works as expected and must be updated with new files added in.

Building:
```bash
mkdir build
cd build
cp ../makefile .
make
./test
```

Running:
```bash
./test -f fragmentShader.txt -v vertexShader.txt
```

## Ubuntu.cse.unr.edu
OpenGL 3.3 will run on the [ubuntu.cse.unr.edu](https://ubuntu.cse.unr.edu/) website. To do so follow the build instructions, but when running the Tutorial executable use this line to execute.
```bash
/usr/NX/scripts/vgl/vglrun ./Tutorial
```

## Student Notes
Moved the shader information into separate textfiles, they are loaded into shader.cpp.
Line added to update for object model, specifically glm::translate. There was slight
confusion in attempting to add translate to the model as opposed to multiplying it.
Adding glm::translate did not yield a desirable outcome. 
