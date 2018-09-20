#ifndef CS205_GOFISH_GOFISH_H
#define CS205_GOFISH_GOFISH_H

#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <random>
#include "Card.h"
using namespace std;

class Deck {
protected:
    vector<Card> deck;
    int numOfCardsDealt;

public:
    //default constructor
    Deck();

    //Getter and Setter
    int getNumOfCardsDealt() const;
    void setNumOfCardsDealt(int numOfCardsDealt);

    //Draws card from the top of the deck
    void drawCard();
    //Suffles the deck
    void shuffleDeck();
    //Deals cards to each player
    void dealCards();
    void removeCardFromDeck(int numberOfCardsToBeRemoved);
    //Prints the deck. Main use for testing
    void printDeck();

};

class Hand: public Deck {
protected:
    vector<Card> playerHand;
    vector<Card> computerHand;
public:
    //default constructor
    Hand();
    Hand(vector<Card> playerHand,vector<Card> computerHand);

    //Getters
    const vector<Card> &getPlayerHand() const;
    const vector<Card> &getComputerHand() const;

    //Setters
    void setPlayerHand(vector<Card> &playerHand, int numOfCards);
    void setComputerHand(vector<Card> &computerHand, int numOfCards);

    void printHands();
};



#endif //CS205_GOFISH_GOFISH_H
