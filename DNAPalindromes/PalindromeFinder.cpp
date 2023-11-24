/*
Keira Ryan
2431681
keiryan@chapman.edu
CPSC 350 Section 2
Programming Assignment 4: Genetic Palindromes

The PalindromeFinder class reads an input file line by line, 
treating each line as its own potential genetic sequence, 
checking if each sequence is a genetic palindrome, as well as
which substrings greater than a length of 4 are genetic 
palindromes, too, printing these results in increasing size
to the terminal.
*/

#include "PalindromeFinder.h"

//default constructor
PalindromeFinder::PalindromeFinder() {
}

/* Overloaded constructor
- takes in a string parameter representing the name of the
file to be read, storing it in the private inputFile string 
variable
*/
PalindromeFinder::PalindromeFinder(string inputFile) {
    m_inputFile = inputFile;
}

//default destructor
PalindromeFinder::~PalindromeFinder() {
}

/* findPalindromes() method
- opens the PalindromeFinder's inputFile
- reads the file line by line
- checks if each sequence is a genetic palindrome and
outputs results to terminal
- outputs genetic palindrome substrings greater 
than a length of 4 to the terminal in increasing order
*/
void PalindromeFinder::findPalindromes() {
    std::ifstream inFile;
    inFile.open(m_inputFile);

    string currentLine;
    
    while(getline(inFile, currentLine)) { //reads line by line of file
        if (currentLine == "END") { //lets user know that the entire file was read
            cout << "All sequences have been examined." << endl;
        } else { 
            DNASeq currSequence = DNASeq(currentLine); //created linked list of currentLine
            if (currSequence.isValid()) { 
                cout << "The sequence " + currentLine << " is valid!" << endl;
                if (currSequence.isGeneticPalindrome()) {
                    cout << "   The full sequence is also a palindrome!" << endl;
                } else {
                    cout << "   The full sequence is NOT a palindrome." << endl;
                }

                //checks substrings by checking every combination of each size range,
                //the range starting at 5 nucleotides, the maximum range being one less
                //than the total length of the sequence
                int maxRange = currSequence.getSequence()->getSize();
                int range = 5; 
                while (range < maxRange) {
                    int startIndex = 0;
                    int endIndex = startIndex + range;
                    while (endIndex <= maxRange) { 
                        DNASeq substring = currSequence.substring(startIndex, endIndex);
                        if (substring.isGeneticPalindrome()) {
                            cout << "   Its substring ";
                            substring.printSubstring();
                            cout << " is a genetic palindrome!" << endl;
                        }
                        startIndex++; //shifts the substring up one start index
                        endIndex = startIndex + range; //shifts the substring up one end index using range as constant
                    }
                    range++; //increments range once entire sequences has been analyzed 
                }
            } else {
                cout << "The sequence " + currentLine << " is NOT valid!" << endl;
            }
        }
    }

    inFile.close();
}