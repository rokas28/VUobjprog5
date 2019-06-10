#ifndef VUOBJPROG5_WORD_H
#define VUOBJPROG5_WORD_H

#include "main.h"

class Word {
private:
    string text;
    int eil;
public:
    Word(string a, int b=0) : text{a}, eil{b} {};
    string get_text() const { return text; };
    int get_eil() const { return eil; };
    bool operator< (const Word &word) const { return (this->text < word.text); };
};
#endif //VUOBJPROG5_WORD_H
