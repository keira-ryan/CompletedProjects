/*
Keira Ryan
2431681
keiryan@chapman.edu
CPSC 350 Section 2
Programming Assignment 2: Not So Super Mario Bros.

main uses the command line arguments as parameters for the play method
of FileProcessor to call all pieces into motion
*/

#include "FileProcessor.h"
#include "World.h"
#include "Mario.h"
#include <fstream>

int main(int argc, char **argv) {
    srand(time(0)); //seeds all rand() calls in the code
    string logName = argv[2];
    string inputFile = argv[1];

    FileProcessor file = FileProcessor();
    file.play(inputFile, logName);

    return 0;
}