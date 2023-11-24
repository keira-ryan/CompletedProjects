/*
Keira Ryan
Programming Assignment 4: Genetic Palindromes
*/

#ifndef PALINDROME_FINDER_H
#define PALINDROME_FINDER_H

#include "DNASeq.h"
#include <fstream>
#include <iostream>

using namespace std;

class PalindromeFinder {
    public:
    PalindromeFinder();
    PalindromeFinder(string inputFile);
    virtual ~PalindromeFinder();
    void findPalindromes();

    private:
    string m_inputFile;

};


#endif
