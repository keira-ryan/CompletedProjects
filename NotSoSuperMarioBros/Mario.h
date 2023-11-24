/*
Keira Ryan
Programming Assignment 2: Not So Super Mario Bros.
*/

#ifndef MARIO_H
#define MARIO_H
#include "World.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Mario{
    public:
        Mario(int V, World& world);
        virtual ~Mario();
        void takeTurn();
        void printArray();
        void printLevel(int i);
        int getLifeCount();
        int getCurrentLevel();
        int totalMoves;
        bool gameWon;
        
    private:
        int m_levelDimension;
        int m_currentLevel;
        int m_currentColumn; 
        int m_currentRow;
        int m_lifeCount;
        int m_coinCount;
        int m_powerLevel;
        int m_killStreak;
        int m_previousLevel;
        int m_previousRow;
        int m_previousColumn; 
        bool m_moveNextTurn;
        bool m_printMario;
        char*** m_world;
        string m_nextMove;
        World m_worldObject;
        void move();
        void fightGoomba();
        void fightKoopa();
        void fightBoss();
        void eatMushroom();
        void collectCoin();
        void warp();
        void loseLife();
        void addToStreak();
        

};

#endif
