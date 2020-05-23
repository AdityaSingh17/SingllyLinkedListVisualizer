# SingllyLinkedListVisualizer
An OpenGL visualizer for operations on a Singlly Linked List.

## Setting up the environment in Ubuntu 
**Requirement:** GCC Compiler (7.5.0 +)

Use the following commands to get FreeGLUT, open source alternative for OpenGL:
```
sudo apt update
sudo apt-get install freeglut3-dev
sudo apt-get install mesa-utils
sudo apt-get install libxmu-dev libxi-dev
```

**Compilation command:**
```
g++ sllvisualizer.cpp -lGL -lGLU -lglut
```

**Execution command:**
```
./a.out
```
## Running the Visualizer
* The choice of operation is passed to the program by a menu. The menu is accessed by the **right mouse click**, the user then selects the operation to perfom.
* The program takes the necessary input via the terminal and displays the updated Singlly Linked List on the window.
