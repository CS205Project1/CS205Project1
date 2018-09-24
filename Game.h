//
// Created by Jean-Baptiste Bolh on 9/17/18.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H

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

    //This function does the following; Shuffle deck, then deal the number of cards specified to playerHand and computerHand, then remove them from the deck.
    void dealCards(int numOfCards);

    //Draws card from the top of the deck and removes it from the deck and adds it to the player or computer hand
    void drawCard(int playerNum); // 1 = Real Player, 2 = computer player

    //Prints the hand. Made it print them out fancy
    void printHand(int playerNum);

    //HONESTLY DON'T KNOW WHY I PUT THIS IN IT MAKES NO SENSE
    //Check to see if the card is in the players hand (response validation)
    bool inHandCheck(string userResponse);

    //Returns true if Computer has matching card
    bool askComputer(string response);

    void takeCards(string card, int playerNum);

    //Suppose to check if there is a book in hand
    void checkForBook();
    void gameLogic();
    void recordGuess(int guess, int playerNum);

};

#endif //UNTITLED_GAME_H
