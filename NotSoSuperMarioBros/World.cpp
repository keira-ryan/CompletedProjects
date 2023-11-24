/*
Keira Ryan
Programming Assignment 2: Not So Super Mario Bros.

The World class creates and populates the char*** World that
Mario will travel through depending on the percentage values given
*/

#include "World.h"

World::World() { //default constructor
}

//Overloaded constructor, which creates and populates the world
//according to the value specifications
World::World(int L, int N, int c, int x, int g, int k, int m) {
    m_numberOfLevels = L;
    m_levelDimension = N;
    m_currentLevel = 0;
    m_world = createWorld(c,x,g,k,m);
}

//destructor deletes each element of the 3D array
World::~World() {
    for (int i = 0; i < m_numberOfLevels; ++i) {
        for (int j = 0; j < m_levelDimension; ++j) {
            delete[] m_world[i][j];
        }
        delete[] m_world[i];
    }
    delete[] m_world;
}

//getDimension - returns level dimension
int World::getDimension() {
    return m_levelDimension;
}

//getWorld - returns 3d World array
char*** World::getWorld() {
    return m_world;
}

//getTotalLevels - returns level count of the World
int World::getTotalLevels() {
    return m_numberOfLevels;
}

/*
createWorld
- takes in int values representing percentage of coins, nothing, 
goombas, koopas, and mushrooms, respectively
- returns a 3d array populated with the approximate percentages
of the enemies/items
*/
char*** World::createWorld(int c, int x, int g, int k, int m) {

    //creates and empty 3D array
    char*** world = new char**[m_numberOfLevels];
    for (int i = 0; i < m_numberOfLevels; ++i) {
        world[i] = new char*[m_levelDimension];
        for (int j = 0; j < m_levelDimension; ++j) {
            world[i][j] = new char[m_levelDimension];
        }
    }

    //populates the array with the corresponding characters
    for (int i = 0; i < m_numberOfLevels; ++i) {
        for (int j = 0; j < m_levelDimension; ++j) {
            for (int l = 0; l < m_levelDimension; ++l) {
                int randomNum = (rand() % 100) + 1;
                if (randomNum > 0 && randomNum <= c) {
                    world[i][j][l] = 'c';
                } else if (randomNum > c && randomNum <= (c+x)) {
                    world[i][j][l] = 'x';
                } else if (randomNum > (c+x) && randomNum <= (c+x+g)) {
                    world[i][j][l] = 'g';
                } else if (randomNum > (c+x+g) && randomNum <= (c+x+g+k)) {
                    world[i][j][l] = 'k';
                } else {
                    world[i][j][l] = 'm';
                }

            }
        }
        
        int random1 = rand() % m_levelDimension;
        int random2 = rand() % m_levelDimension;
        if (i != (m_numberOfLevels-1)) {
            world[i][random1][random2] = 'w'; //randomly places warp pipe

        }
        world[i][random2][random1] = 'b'; // randomly places level boss
    }
    return world;
}
