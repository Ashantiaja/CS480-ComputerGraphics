# PA4 - Blender and Model Loading

## Project Description
A board with four walls is rendered onto the screen. The program loads the .obj file for said board. 

# Dependencies, Building, and Running

## Building and Running

### Makefile Instructions 
The makefile works as expected and must be updated with new files added in.

Building:
```bash
mkdir build
cd build
cp ../makefile .
make
./test -m ../src/assets/board.obj
```
<!-- ./test -f fragmentShader.txt -v vertexShader.txt -->
Running:
```bash
./test -m <filepathToObjFile>
```

## Dependency Instructions
For both of the operating systems to run this project installation of these three programs are required [GLEW](http://glew.sourceforge.net/), [GLM](http://glm.g-truc.net/0.9.7/index.html), and [SDL2](https://wiki.libsdl.org/Tutorials).

This project uses OpenGL 3.3. Some computers, such as virtual machines in the ECC, can not run this version. In in order to run OpenGL 2.7 follow the instructions at [Using OpenGL 2.7](https://github.com/HPC-Vis/computer-graphics/wiki/Using-OpenGL-2.7)

### Ubuntu/Linux
```bash
sudo apt-get install libglew-dev libglm-dev libsdl2-dev
```
