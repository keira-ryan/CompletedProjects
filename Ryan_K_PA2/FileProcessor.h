/*
Keira Ryan
2431681
keiryan@chapman.edu
CPSC 350 Section 2
Programming Assignment 2: Not So Super Mario Bros.
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include "World.h"
#include "Mario.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class FileProcessor {
    public:
    FileProcessor();
    virtual ~FileProcessor();
    void play(std::string inFile, string outFile);

    private:
    int* readFile(std::string inFile);
};

#endif