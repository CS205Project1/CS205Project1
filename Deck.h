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
    //removes card from the deck
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
    void setPlayerHand(vector<Card> &playerHand);
    void setComputerHand(vector<Card> &computerHand);

    //This function does the following; Shuffle deck, then deal the number of cards specified to playerHand and computerHand, then remove them from the deck.
    void dealCards(int numOfCards);

    //Prints the hand for testing purposes
    void printHands();
};


#endif //CS205_GOFISH_GOFISH_H