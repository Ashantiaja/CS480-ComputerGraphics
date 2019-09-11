# PA2 : Interaction

## Project Description
The program allows the user to Increase or Decrease the speed of the cube or pause its movement.

### Program Controls
<kbd>&#x2191;</kbd> Up Arrow : Increases Speed
<kbd>&#x2193</kbd> Down Arrow : Decreases Speed
<kbd>P</kbd> P : Pauses and Unpauses Cube in place

# Dependencies, Building, and Running

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
<!-- ./test -f fragmentShader.txt -v vertexShader.txt -->
Running:
```bash
./test
```

## Ubuntu.cse.unr.edu
OpenGL 3.3 will run on the [ubuntu.cse.unr.edu](https://ubuntu.cse.unr.edu/) website. To do so follow the build instructions, but when running the Tutorial executable use this line to execute.
```bash
/usr/NX/scripts/vgl/vglrun ./Tutorial
```

## Student Notes
Added to Keyboard() function in Engine. Added functions to Object class and Graphics class to facilitate changing the object's movement.
