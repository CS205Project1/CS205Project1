#ifndef PROJECT_CARD_H
#define PROJECT_CARD_H

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <string>
using namespace std;

enum Suit{spades, diamonds, clubs, hearts};

class Card {
private:
    int rank;
    Suit suit;
    string name = to_string(rank)+to_string(suit);

public:
    //default constructors
    Card();
    Card(int r, Suit s);

    //Getters
    int getRank() const;
    Suit getSuit() const;
    string getSuitString() const;
    string getName() const;

    //Overloading operator
    friend ostream& operator << (ostream& outs, const Card &c);
};


#endif //PROJECT_CARD_H
