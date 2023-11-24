/*
Keira Ryan
2431681
keiryan@chapman.edu
CPSC 350 Section 2
Programming Assignment 2: Not So Super Mario Bros.

FileProcessor puts all of the pieces of the World and Mario class together,
calling on the createWorld and takeTurn methods within the two classes,
respectively, using the informaation contained within the .txt input file
to write all desired data to the .txt output file
*/

#include "FileProcessor.h"

FileProcessor::FileProcessor() {}

FileProcessor::~FileProcessor() {}

/*
play
- takes in a string for the file to be read and a string for the file to be written to
- creates and runs the entire Mario Bros. game simulation by  creating instances of
  World and Mario, and calling on the takeTurn method until the game is won or lost
*/
void FileProcessor::play(string inputFile, string outputFile) {
    ofstream logFile(outputFile);
    //BEGINNING OF CODE WRITTEN WITH SOURCES IN README AS GUIDE
    streambuf* coutToLog = cout.rdbuf();
    cout.rdbuf(logFile.rdbuf());
    //END OF CODE WRITTEN WITH SOURCES IN README AS GUIDE
    int* fileContents = readFile(inputFile);

    World* world = new World(fileContents[0],fileContents[1], fileContents[3], fileContents[4], fileContents[5], fileContents[6], fileContents[7]);
    Mario* mario = new Mario(fileContents[2], *world);

    mario->printArray(); //prints representation of the World without Mario

    //Incites Mario to keep taking turns until he loses all of his lives or beats the final boss
    while ((mario->getLifeCount() > 0) && (mario->gameWon == false)) {
        mario->takeTurn();
        mario->printLevel(mario->getCurrentLevel());
    } 

    if (mario->gameWon == true) {
        cout << "Mario WON!!!!!! It took " << to_string(mario->totalMoves) << " moves!" << endl;
    } else {
        cout << "Mario lost! It took " << to_string(mario->totalMoves) << " moves." << endl;
    }

    //BEGINNING OF CODE WRITTEN WITH SOURCES IN README AS GUIDE
    cout.rdbuf(coutToLog);
    //END OF CODE WRITTEN WITH SOURCES IN README AS GUIDE
    logFile.close();

    delete[] fileContents;
}

int* FileProcessor::readFile(std::string inFile) {
    //opens txt file to be read 
    ifstream inputFile;
    inputFile.open(inFile);

    string currentLine;
    int* fileContents = new int[8];
    //creates an int array for the file contents to be read to and stored in

    //reads each line and adds it to the file, converting the read contents
    //from a string to an int
    for (int i=0; i < 8; ++i) {
        getline(inputFile, currentLine);
        fileContents[i] = stoi(currentLine); // LINE WRITTEN USING GUIDANCE CITED IN README - stoi used to convert std::string to int
    }

    inputFile.close();
    return fileContents; 
}