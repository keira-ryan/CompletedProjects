/*
Keira Ryan
2431681
keiryan@chapman.edu
CPSC 350 Section 2
Programming Assignment 4: Genetic Palindromes
*/

#ifndef DNA_SEQ_H
#define DNA_SEQ_H

#include "DblList.h"
#include <iostream>
#include <string>

using namespace std;

class DNASeq {
    public:
    DNASeq();
    DNASeq(string charString);
    virtual ~DNASeq();
    DNASeq complement();
    DNASeq substring(int s, int e);
    bool isGeneticPalindrome();
    DblList<char>* getSequence();
    bool isValid();
    void printSubstring();

    private:
    DblList<char>* m_sequence;
    bool m_valid;
};

#endif