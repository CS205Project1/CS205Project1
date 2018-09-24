#ifndef CS205PROJECT1_GAME_H
#define CS205PROJECT1_GAME_H

#include <vector>
#include <utility>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>
#include "Deck.h"
using namespace std;

class Game {
private:
    int userScore = 0;
    int computerScore = 0;

public:
    Deck deck;
    vector<Card> userHand;
    vector<Card> computerHand;

    //Default constructors
    Game();

    //Getters
    int getUserScore() const;
    int getComputerScore() const;
    vector<Card> getUserHand() const;
    vector<Card> getComputerHand() const;

    //Setters
    void setUserScore(int userScore);
    void setComputerScore(int computerScore);
    void setUserHand(vector<Card> &userHand);
    void setComputerHand(vector<Card> &computerHand);

    //Suffles the deck
    void shuffleDeck();

    //This function does the following; Shuffle deck, then deal the number of cards specified to playerHand and computerHand, then remove them from the deck.
    void dealCards(int numOfCards);

    //Draws card from the top of the deck and removes it from the deck and adds it to the player or computer hand
    void drawCard(int playerNum); // 1 = Real Player, 2 = computer player

    //Prints the hand. Made it print them out fancy
    void printHand(int playerNum);

    //Check to see if the card is in the players hand (response validation)
    bool inHandCheck(string userResponse);
    bool askComputer(string response);

    //Suppose to check if there is a book in hand
    void checkForBook();
    void gameLogic();
    void recordGuess(int guess, int playerNum);

};

#endif //UNTITLED_GAME_H
