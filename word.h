#ifndef VUOBJPROG5_WORD_H
#define VUOBJPROG5_WORD_H

#include "main.h"

class Word {
private:
    string text;
    int eil;
public:
    Word(string a, int b) : text{a}, eil{b} {};
    string get_text() { return text; };
    int get_eil() { return eil; };
};
#endif //VUOBJPROG5_WORD_H
