/*
Keira Ryan
2431681
keiryan@chapman.edu
CPSC 350 Section 2
Programming Assignment 2: Not So Super Mario Bros.
*/

#ifndef WORLD_H
#define WORLD_H
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class World {
    public:
        World();
        World(int L, int N, int c, int x, int g, int k, int m);
        virtual ~World();
        char*** createWorld(int c, int x, int g, int k, int m);
        char*** getWorld();
        int getDimension();
        int getTotalLevels();

    private:
        char*** m_world;
        int m_numberOfLevels;
        int m_currentLevel; 
        int m_levelDimension;
};

#endif