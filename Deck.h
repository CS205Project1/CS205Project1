#ifndef CS205PROJECT1_DECK_H
#define CS205PROJECT1_DECK_H

#include <vector>
#include <utility>
#include <iostream>
#include <iomanip>
#include "Card.h"
using namespace std;

class Deck {
protected:
    int numOfCardsDealt;

public:
    vector<Card> deck;
    //default constructor
    Deck();

    //Getter and Setter
    int getNumOfCardsDealt() const;
    void setNumOfCardsDealt(int numOfCardsDealt);

    //Prints the deck. Main use for testing
    void printDeck();

};

#endif //CS205PROJECT1_DECK_H
