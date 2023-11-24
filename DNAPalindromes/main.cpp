/*
Keira Ryan
Programming Assignment 4: Genetic Palindromes

The main method creates a PalindromeFinder object using the
command line input as a parameter, then calling on the 
findPalindrome() method to output all results from the 
file's contents to the terminal
*/

#include "DblList.h"
#include "DNASeq.h"
#include "PalindromeFinder.h"

using namespace std;

int main(int argc, char **argv) {
    string inputFile = argv[1];
    PalindromeFinder finder = PalindromeFinder(inputFile);
    finder.findPalindromes();

    return 0;
}
