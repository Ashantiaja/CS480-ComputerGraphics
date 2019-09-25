# PA3 - Moons

## Project Description
Two cubes are rendered on the screen. One moves in a circle while the other orbits it. The orbit direction and speeds of the two can be changed independently of each other.

### Program Controls

Planet Cube :

<kbd>W</kbd> : Increases speed of the main cube.

<kbd>S</kbd> : Slows the speed of the main cube.

<kbd>A</kbd> : Stops/Starts movement of the main cube.

<kbd>D</kbd> : Reverses direction of the main cube.

Left Mouse Button : Reverses direction of the main cube.


Moon Cube :

<kbd>&#x2191;</kbd> Up Arrow : Increases speed of the moon cube.

<kbd>&#x2193;</kbd> Down Arrow : Decreases speed of the moon cube.

<kbd>&#x2190;</kbd> Left Arrow : Stops/starts movement of the moon cube

<kbd>&#x2192;</kbd> Right Arrow : Reverses direction of the moon cube

Right Mouse Button : Reverses direction of the moon cube.


Misc :

<kbd>Z</kbd> Z : Stop all

<kbd>X</kbd> X : Start all

### Extra Credit
Controls are provided for adjusting the speed of the moon under section Program Controls.
Additionally, the moon is scaled at 0.6 of the size of the main planet cube.


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
./test
```
<!-- ./test -f fragmentShader.txt -v vertexShader.txt -->
Running:
```bash
./test
```

## Dependency Instructions
For both of the operating systems to run this project installation of these three programs are required [GLEW](http://glew.sourceforge.net/), [GLM](http://glm.g-truc.net/0.9.7/index.html), and [SDL2](https://wiki.libsdl.org/Tutorials).

This project uses OpenGL 3.3. Some computers, such as virtual machines in the ECC, can not run this version. In in order to run OpenGL 2.7 follow the instructions at [Using OpenGL 2.7](https://github.com/HPC-Vis/computer-graphics/wiki/Using-OpenGL-2.7)

### Ubuntu/Linux
```bash
sudo apt-get install libglew-dev libglm-dev libsdl2-dev
```
