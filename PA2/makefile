# Check for OS Type
UNAME_S := $(shell uname -s)

# Linux
ifeq ($(UNAME_S), Linux)
	CC=g++
	LIBS=-lSDL2 -lGLEW -lGL
# Mac
else
	CC=clang++
	LIBS=-lSDL2 -framework OpenGL -framework Cocoa -lGLEW -stdlib=libc++
endif

# Instructions for adding new files
# Add .cpp files to SRCS
# Make sure .h file is in include folder


# Paths, use this to set Include directories, or library directories; uncomment in all: if used
#PATHI=-I/usr/local/include/ 
#PATHL=-L/usr/local/lib/

#Compiler Flags
CXXFLAGS=-g -Wall -std=c++0x

# Source Files
#SRCS = ../src/main.cpp ../src/camera.cpp ../src/engine.cpp ../src/graphics.cpp ../src/object.cpp ../src/shader.cpp ../src/window.cpp ../src/util.cpp $(wildcard ../imgui/*.cpp)#../src/imgui.cpp
SRCS = $(wildcard ../src/*.cpp)

# .o Compilation
#O_FILES=main.o camera.o engine.o graphics.o object.o shader.o window.o util.o
O_FILES := $(patsubst ../src/%.cpp, %.o, $(SRCS))

# Point to includes of local directories
INCLUDES=-I../include #$(wildcard ../imgui/*.h)


all: $(O_FILES)
	$(CC) $(CXXFLAGS) -o test $(O_FILES) $(LIBS) #$(PATHI) $(PATHL)

# Compile .o files
%.o: ../src/%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ $(INCLUDES)

#main.o: ../src/main.cpp
#	$(CC) $(CXXFLAGS) -c ../src/main.cpp -o main.o $(INCLUDES)

#camera.o: ../src/camera.cpp
#	$(CC) $(CXXFLAGS) -c ../src/camera.cpp -o camera.o $(INCLUDES)

#engine.o: ../src/engine.cpp
#	$(CC) $(CXXFLAGS) -c ../src/engine.cpp -o engine.o $(INCLUDES)

#graphics.o: ../src/graphics.cpp
#	$(CC) $(CXXFLAGS) -c ../src/graphics.cpp -o graphics.o $(INCLUDES)

#object.o: ../src/object.cpp
#	$(CC) $(CXXFLAGS) -c ../src/object.cpp -o object.o $(INCLUDES)

#shader.o: ../src/shader.cpp
#	$(CC) $(CXXFLAGS) -c ../src/shader.cpp -o shader.o $(INCLUDES)

#window.o: ../src/window.cpp
#	$(CC) $(CXXFLAGS) -c ../src/window.cpp -o window.o $(INCLUDES)

#util.o: ../src/util.cpp
#	$(CC) $(CXXFLAGS) -c ../src/util.cpp -o util.o $(INCLUDES)

clean:
	rm -f *~
	rm -f ../include/*~
	rm -f ../src/*~
	-@if rm *.o test 2>/dev/null || true; then echo "Main Removed"; else echo "No Main"; fi

