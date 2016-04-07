# SudokuSolver
Program to solver sudoku puzzles

How to build:
This program has CMakeLists.txt created for easy build. No Makefiles are required to be written. :D

create a directory in the project folder, that way all the makefiles and build files can be isolated from the source files. This makes it easier to clean up and checkin into repo when new changes are made to source files.

Note: To build this project cmake should be installed in your system
sudo apt-get install cmake  (if using ubuntu or debian package)

1. Create some directory "build" in the project folder
'mkdir build'
2. go into build directory and enter this command to generate Makefiles for this project
'cmake ..'
3. run make
'make'
4. On successful build it should generate executable "sudoku"

rest is self explanatory.
