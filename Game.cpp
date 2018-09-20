#include "Game.h"

Game::Game() = default;

Game::Game(int userScore, int computerScore) {
    userScore = userScore;
    computerScore = computerScore;
};
int Game::getUserScore() const {
    return userScore;
};

void Game::setUserScore(int userScore) {
    Game::userScore = userScore;
};

int Game::getComputerScore() const {
    return computerScore;
};

void Game::setComputerScore(int computerScore) {
    Game::computerScore = computerScore;
}


/** This function is work in progress. It is suppose to check if there is a book in hand
 **
 */
void Game::checkForBook(){
    printHands(1);
    //cout << computerHand[1].getRank() << endl;
    for(int i = 0; i < playerHand.size(); i++) {
        for(int j = 0; j < playerHand.size(); j++) {
            if(playerHand[i].getRank() == playerHand[j].getRank()){
                cout << playerHand[i].getRank() << ' == ' << playerHand[j+1].getRank() << endl;
            };
        };
    };
};
void Game::gameLogic(){

};
void Game::recordGuess(int guess, int playerNum){

};
