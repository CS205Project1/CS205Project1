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
    vector<Card> userBooks;
    vector<Card> computerBooks;
    /*
     * memory stores the ranks of all cards the user has asked for.
     * the computer will prioritize asking for these values if it can,
     * as it knows the user has them.
     */
    vector<int> memory;

    //Default constructors
    Game();

    //Getters
    int getUserScore() const;
    int getComputerScore() const;
    vector<Card> getUserHand() const;
    vector<Card> getComputerHand() const;
    vector<Card> getUserBooks() const;
    vector<Card> getComputerBooks() const;

    //Setters
    void setUserScore(int userScore);
    void setComputerScore(int computerScore);
    void setUserHand(vector<Card> &userHand);
    void setComputerHand(vector<Card> &computerHand);
    void setUserBooks(vector<Card> &userBooks);
    void setComputerBooks(vector<Card> &computerBooks);

    //Suffles the deck
    void shuffleDeck();

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
    bool askUserSmart(int cardToAskFor);
    bool askUserDumb();

    void takeCards(string card, int playerNum);

    //Suppose to check if there is a book in hand
    void checkForBook(int playerNumber);

    void gameLogic();


    /*===========================MEMORY MANIPULATION===========================*/
    //records the guess to memory
    void recordToMemory(int guess);

    //Deletes that rank from memory
    void deleteFromMemory(int rank);

    //Returns rank of card to ask for, or 0 if nothing in hand matches memory
    int compareHandToMemory();




};

#endif //UNTITLED_GAME_H
