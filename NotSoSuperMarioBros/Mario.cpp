/*
Keira Ryan
Programming Assignment 2: Not So Super Mario Bros.

The Mario class contains all information and actions Mario needs to take
to traverse through the 3d char*** array world, including all interactions
with the different items and enemies, as well as print functions that allow
for viewing of Mario's current status and location. 
*/

#include "Mario.h"

/* Mario overloaded constructor
- takes in int representing starting life count and reference to the world
Mario will be traveling through
- initializes all count and positional memeber variables, placing Mario in
a random starting location with a power level of 0 and the number of lives 
given by V
*/
Mario::Mario(int V, World& world) {
    totalMoves = 0;
    gameWon = false;

    m_worldObject = world;
    m_world = world.getWorld(); 
    m_levelDimension = world.getDimension();

    m_currentColumn = (rand()%(m_levelDimension));
    m_currentRow = (rand()%(m_levelDimension));
    m_currentLevel = 0;

    m_previousLevel = 0;
    m_previousRow = 0;
    m_previousColumn = 0;

    m_powerLevel = 0;
    m_lifeCount = V;
    m_coinCount = 0;
    m_killStreak = 0;

    m_moveNextTurn = true;
    m_nextMove = "";

    m_printMario = false;
}

Mario::~Mario() { //default destructor
}

/*
takeTurn
- Prints Mario's information before taking his turn to the log
- Reads the character at Mario's current position and causes him to take
action accordingly, printing the results of his action and next move to 
the console
*/
void Mario::takeTurn() {
    string turnLog = "Level: " + to_string(m_currentLevel + 1) + " - Position: Column " + to_string(m_currentColumn + 1) + ", Row " + to_string(m_currentRow + 1);
    turnLog = turnLog + " - PL" + to_string(m_powerLevel) + " - ";
    if (m_world[m_currentLevel][m_currentRow][m_currentColumn] == 'c') {
        collectCoin();
        turnLog = turnLog + "Mario collected a coin - ";
    } else if (m_world[m_currentLevel][m_currentRow][m_currentColumn] == 'm') {
        eatMushroom();
        turnLog = turnLog + "Mario ate a mushroom - ";
    } else if (m_world[m_currentLevel][m_currentRow][m_currentColumn] == 'g') {
        fightGoomba();
        if (m_killStreak > 0) {
            turnLog = turnLog + "Mario fought a Goomba and won - ";
        } else {
            turnLog = turnLog + "Mario fought a Goomba and lost - ";
        }
    } else if (m_world[m_currentLevel][m_currentRow][m_currentColumn] == 'k') {
        fightKoopa();
        if (m_killStreak > 0) {
            turnLog = turnLog + "Mario fought a Koopa and won - ";
        } else {
            turnLog = turnLog + "Mario fought a Koopa and lost - ";
        }
    } else if (m_world[m_currentLevel][m_currentRow][m_currentColumn] == 'b') {
        fightBoss();
        if (m_moveNextTurn == true || gameWon == true) {
            turnLog = turnLog + "Mario fought the level boss and won - ";
        } else {
            turnLog = turnLog + "Mario fought the level boss and lost - ";
        }
    } else if (m_world[m_currentLevel][m_currentRow][m_currentColumn] == 'w') {
        warp();
        turnLog = turnLog + "Mario warped - ";
    } else {
        turnLog = turnLog + "The position is empty - ";
    }
    if (m_moveNextTurn == true && gameWon == false) {
        move(); //Mario will not move if he loses the game or loses to a level boss
    }

    turnLog = turnLog + "Lives: " + to_string(m_lifeCount) + " - Coins: " + to_string(m_coinCount);

    if (m_moveNextTurn == false) {
        turnLog = turnLog + " - Mario will STAY PUT\n";
        m_moveNextTurn == true;
    } else {
        turnLog = turnLog + " - Mario will move " + m_nextMove + "\n";
    }

    totalMoves++;
    cout << turnLog << endl;
}

/*
move
- Updates Mario's position to either one space up, down, left, or right 
depending on a 1 in 4 chance for any of the directions
- functions like a torus, so if Mario moves off of one edge, he appears on the other
*/
void Mario::move() {
    int direction = ((rand() % 4) + 1);
    m_previousLevel = m_currentLevel;
    m_previousColumn = m_currentColumn;
    m_previousRow = m_currentRow;
    if (direction == 1) {
        m_nextMove = "UP";
        if (m_currentRow == 0) { //if on top edge, Mario appears at bottom
            m_currentRow = (m_levelDimension - 1);
        } else {
            m_currentRow--;
        }
    } else if (direction == 2) { //if on bottom edge, Mario appears at top
        m_nextMove = "DOWN";
        if (m_currentRow == (m_levelDimension - 1)) {
            m_currentRow = 0;
        } else {
            m_currentRow++;
        }
    } else if (direction == 3) { //if on left edge, Mario appears at right
        m_nextMove = "LEFT";
        if (m_currentColumn == 0) {
            m_currentColumn = (m_levelDimension - 1);
        } else {
            m_currentColumn--;
        }
    } else if (direction == 4) { //if on right edge, Mario appears at left
        m_nextMove = "RIGHT";
        if (m_currentColumn == (m_levelDimension - 1)) {
            m_currentColumn = 0;
        } else {
            m_currentColumn++;
        }
    }
}

/*
fightGoomba
- Generates 80% chance that Mario will defeat the goomba
- If he loses, he goes down a power level, and if at PL0, he 
loses a life, moving on no matter what
*/
void Mario::fightGoomba() {
    int rollDice = (rand() % 5) + 1;
    if (rollDice > 1) { //Mario wins
        m_world[m_currentLevel][m_currentRow][m_currentColumn] = 'x';
        addToStreak();
    } else { //Mario loses
        if (m_powerLevel > 0) {
            m_powerLevel--;
        } else {
            loseLife();
        } 
    }
}

/*
fightKoopa
- Generates 65% chance that Mario will defeat the koopa
- If he loses, he goes down a power level, and if at PL0, he 
loses a life, moving on no matter what
*/
void Mario::fightKoopa() {
    int rollDice = (rand() % 100) + 1;
    if (rollDice > 35) { //Mario wins
        m_world[m_currentLevel][m_currentRow][m_currentColumn] = 'x';
        addToStreak();
    } else { //Mario loses
        if (m_powerLevel > 0) {
            m_powerLevel--;
        } else {
            loseLife();
        } 
    }
}

/*
fightBoss
- Generates 50% chance that Mario will defeat the goomba
- If he loses, he goes down two power levels, and if at PL0 or PL1, he 
loses a life and stays until he beats the boss
- If Mario wins, he moves on a level, or if at the final level, Mario wins
*/
void Mario::fightBoss() {
    int flipCoin = rand() % 2;
    if (flipCoin == 1) { //Mario wins
        m_moveNextTurn = true;
        m_world[m_currentLevel][m_currentRow][m_currentColumn] = 'x';
        if ((m_currentLevel + 1) >= (m_worldObject.getTotalLevels())) {
            gameWon = true;
            m_moveNextTurn = false;
        } else {
            m_currentLevel++;
        }
        addToStreak();
    

    } else { //Mario loses
        m_moveNextTurn = false;
        if (m_powerLevel < 2) {
            loseLife();
        }
        m_powerLevel = 0;
    }
}

/*
eatMushroom
- increases Mario's PL by 1
*/
void Mario::eatMushroom() {
    if (m_powerLevel < 2) {
        m_powerLevel++;
        m_world[m_currentLevel][m_currentRow][m_currentColumn] = 'x';
    } else {
        m_world[m_currentLevel][m_currentRow][m_currentColumn] = 'x';
    }
}

/*
collectCoin
- increases Mario's coin count by 1
- If Mario has 20 coins or more, he gains a life and his
coin count is reset
*/
void Mario::collectCoin() {
    m_coinCount++; 
    if (m_coinCount >= 20) {
        m_coinCount = 0;
        m_lifeCount++;
    }
    m_world[m_currentLevel][m_currentRow][m_currentColumn] = 'x';
} 

/*
warp
- Mario moves on to the next level
*/
void Mario::warp() {
    m_currentLevel++;
}

/*
loseLife
- Mario's life count decreases by 1 and his kill count
is reset because he must have lost to an enemy
*/
void Mario::loseLife() {
    m_lifeCount--;
    m_killStreak = 0;
}

/*
addToStreak
- increments Mario's kill streak
- If his kill streak reaches 7 on the same life,
Mario gains a life and his streak is reset
*/
void Mario::addToStreak() {
    m_killStreak++;
    if (m_killStreak >= 7) {
        m_lifeCount++;
        m_killStreak = 0;
    }
}

/*
getLifeCount
- returns Mario's current number of lives
*/
int Mario::getLifeCount() {
    return m_lifeCount;
}

/*
getCurrentLevel
- returns the number of the Level Mario is currently on
*/
int Mario::getCurrentLevel() {
    return m_currentLevel;
}

/*
printArray
- Prints a representation of the enitre populated world
that Mario will be traveling through
*/
void Mario::printArray() {
    cout << "World: " << endl;
    for (int i = 0; i < m_worldObject.getTotalLevels(); ++i) {
        printLevel(i);        
    }
    m_printMario = true;
}

/*
printLevel
- takes in int parameter for the current level
- prints the level, i, with Mario being represented as 'H' 
*/
void Mario::printLevel(int i) {
    for (int j = 0; j < m_levelDimension; ++j) {
            for (int k = 0; k < m_levelDimension; ++k) {
                if (m_moveNextTurn == true && m_lifeCount != 0 && m_printMario == true && m_previousLevel == i && m_previousColumn == k && m_previousRow == j) {
                    cout << "H "; //prints H if Mario did not fight a boss and will be moving next turn
                } else if (m_moveNextTurn == false && m_currentLevel == i && m_currentColumn == k && m_currentRow == j) {
                    cout << "H "; //prints H for Mario if he fought the boss and is staying in place, either because he lost or won the enitre game
                } else {
                cout << m_world[i][j][k] << " "; //prints every non-Mario character
                }
            }
            cout << "\n";
        }
    cout << "\n";
}
