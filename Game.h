//
// Created by Jean-Baptiste Bolh on 9/17/18.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H


class Game {
private:
    Hand computerHand;
public:
    Deck d;
    int userScore;
    int computerScore;
    void newGame();

    void getHand();
};


#endif //UNTITLED_GAME_H
