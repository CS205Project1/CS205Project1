#ifndef PROJECT_CARD_H
#define PROJECT_CARD_H

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <string>
using namespace std;

class Card {
private:
    int rank;
    char suit;
    string name = to_string(rank)+to_string(suit);

public:
    //default constructors
    Card();
    Card(int r, char s);

    //Getters
    int getRank() const;
    char getSuit() const;
    string getName() const;

    //Overloading operator
    friend ostream& operator << (ostream& outs, const Card &c);
};


#endif //PROJECT_CARD_H
