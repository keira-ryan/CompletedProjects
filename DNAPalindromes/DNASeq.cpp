/*
Keira Ryan
Programming Assignment 4: Genetic Palindromes

The DNASeq class takes string input to check if a given genetic
string is valid. If so, the genetic sequence can be checked if it
is a genetic palindrome, and genetic substrings can also be made
from the sequence
*/

#include "DNASeq.h"

/* Default constructor
- creates an empty sequence
*/
DNASeq::DNASeq() {
    m_sequence = new DblList<char>;
    m_valid = true;
}

/* Overloaded constructor
- takes in a string as a parameter
- initializes the sequence LinkedList, each node
being a respective character of the string parameter
*/
DNASeq::DNASeq(string charString) {
    m_valid = true;
    m_sequence = new DblList<char>;
    for (char& nucleotide: charString) {
        if (nucleotide != 'A' && nucleotide != 'T' && nucleotide != 'G' && nucleotide != 'C') {
            m_valid = false; //if character isn't one of the 4 nucleotides, the sequence is invalid
            break;
        }
        m_sequence->addBack(nucleotide);
    }
}

//Default destructor that deletes the doubly linked list
DNASeq::~DNASeq() {
    delete m_sequence;
}

/* complement method
- creates a DNASeq object, its sequence being the
complement of the original sequence
- returns the new complement as a DNASeq object
*/
DNASeq DNASeq::complement() {
    DNASeq complement = DNASeq();
    if (m_valid) {
        for (int i = 0; i < m_sequence->getSize(); ++i) {
            char complementChar;
            if (m_sequence->get(i) == 'A') { //complement of A is T
                complementChar = 'T';
            } else if (m_sequence->get(i) == 'T') { //complement of T is A
                complementChar = 'A';
            } else if (m_sequence->get(i) == 'G') { //complement of G is C
                complementChar = 'C';
            } else { //complement of C is G
                complementChar = 'G';
            }
            complement.m_sequence->addBack(complementChar);
        }
    }
    return complement;
}

/* getSequence accessor
- returns the sequence's doubly linked list
*/
DblList<char>* DNASeq::getSequence() {
    return m_sequence;
}

/* substring method
- takes in two integers as parameters, the first being the
beginning index of the substring (inclusive), the second
being the end inex of the substring (exclusive)
- returns a new DNASeq object, its sequence being the substring
of the specified index range
*/
DNASeq DNASeq::substring(int s, int e) {
    DNASeq substring = DNASeq();
    for (int i = s; i < e; ++i) {
        substring.m_sequence->addBack(m_sequence->get(i));
    }
    return substring;
}

/* isGeneticPalindrome method
- returns true if the sequence is a genetic palindrome, and false
if not
*/
bool DNASeq::isGeneticPalindrome() {
    if (m_valid == false) { //begins by ensuring the sequence is valid
        return false;
    } else {
        int max = m_sequence->getSize();
        for (int i = 0; i < max; ++i) {
            DNASeq complementSeq = complement();
            //iterates through the comlpement backwards as a genetic palindrome is when
            // the reverse of a sequence's complement is the same as the original sequence
            int complementIndex = (complementSeq.getSequence()->getSize() - i - 1);
            if (complementSeq.getSequence()->get(complementIndex) != m_sequence->get(i)) {
                return false; //if any chararcter does not match up, false is returned
            }
        }
        return true;
    }
}

/* isValid accessor
- returns the sequence's validity as a boolean
*/
bool DNASeq::isValid() {
    return m_valid;
}

/* printSubstring method
- iterates through the substring, printing each character
to the terminal
*/
void DNASeq::printSubstring() {
    for (int i = 0; i < m_sequence->getSize(); i++) {
        std::cout << m_sequence->get(i);
    }
}
