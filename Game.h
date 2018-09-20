//
// Created by Jean-Baptiste Bolh on 9/17/18.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H


#include "Deck.h"

class Game : public Hand {
private:
    int userScore = 0;
    int computerScore = 0;
public:
    //Default constructors
    Game();
    Game(int userScore, int computerScore);

    //Getters
    int getUserScore() const;
    int getComputerScore() const;
    //Setters
    void setUserScore(int userScore);
    void setComputerScore(int computerScore);

    //Suppose to check if there is a book in hand
    void checkForBook();

    void gameLogic();
    void recordGuess(int guess, int playerNum);

};

#endif //UNTITLED_GAME_H
