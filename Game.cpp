#include "Game.h"
using namespace std;

//CONSTRUCTOR
Game::Game() {
    userScore = 0;
    computerScore = 0;
    deck = Deck();
    deck.shuffleDeck();
    dealCards(7);
}

//GETTERS
int Game::getUserScore() const {
    return userScore;
}
int Game::getComputerScore() const {
    return computerScore;
}
vector<Card> Game::getUserHand() const {
    return userHand;
}
vector<Card> Game::getComputerHand() const {
    return computerHand;
}

//SETTERS
void Game::setUserScore(int u) {
    Game::userScore = u;
}
void Game::setComputerScore(int c) {
    Game::computerScore = c;
}
void Game::setUserHand(vector<Card> &h) {
    Game::userHand = h;
}
void Game::setComputerHand(vector<Card> &h) {
    Game::computerHand = h;
}

//OTHER METHODS
void Game::dealCards(int numOfCards){
    //iterator
    auto it = next(deck.deck.begin(), numOfCards);

    //moves cards to playerHand vector
    move(deck.deck.begin(), it, back_inserter(userHand));
    //After it's been moved it erases those slots from the deck
    deck.deck.erase(deck.deck.begin(), it);

    //same things below for computerHand
    move(deck.deck.begin(), it, back_inserter(computerHand));
    deck.deck.erase(deck.deck.begin(), it);

    //Printing hand, then deck for testing purposes.
    //printHand(1);
    //printHand(2);
    //printDeck();
}

void Game::drawCard(int playerNum){
    auto it = next(deck.deck.begin(), 1);
    if(playerNum == 1){
        move(deck.deck.begin(), it, back_inserter(userHand));
        deck.deck.erase(deck.deck.begin(), it);
    }else if (playerNum == 2){
        move(deck.deck.begin(), it, back_inserter(computerHand));
        deck.deck.erase(deck.deck.begin(), it);
    }else{
        cout << "CARD NOT DRAWN! For drawCard please specify 1 or 2 (1 = user player. 2 = computer player)" << endl;
    }
}


void Game::printHand(int playerNum){
    if(playerNum == 1) {
        cout << "******************************** Your Hand  **********************************" << endl;
        for (int i = 0; i < userHand.size(); i++) {
            cout << " -----   ";
        };
        cout << endl;
        for (int i = 0; i < userHand.size(); i++) {
            cout << "|     |  ";
        };
        cout << endl;

        for (int i = 0; i < userHand.size(); i++) {
            if(userHand[i].getRank() != 10) {
                cout << "| "  << userHand[i].getRankString() << userHand[i].getSuitString()  << "  |  ";
            }else{
                cout << "| " << userHand[i].getRankString() << userHand[i].getSuitString() << " |  ";
            };
        };
        cout << endl;
        for (int i = 0; i < userHand.size(); i++) {
            cout << "|     |  ";
        };
        cout << endl;
        for (int i = 0; i < userHand.size(); i++) {
            cout << " -----   ";
        };
        cout << endl;
        for (int i = 0; i < userHand.size(); i++) {
            if((i+1) < 10) {
                cout << "   " << i + 1 << "     ";
            }else{
                cout << "   " << i + 1 << "    ";
            }
        };
        cout << endl;

    }else if (playerNum == 2) {
        cout << "******************************  Computer Hand  *******************************" << endl;
        for (int i = 0; i < computerHand.size(); i++) {
            cout << " -----   ";
        };
        cout << endl;
        for (int i = 0; i < computerHand.size(); i++) {
            cout << "|     |  ";
        };
        cout << endl;

        for (int i = 0; i < computerHand.size(); i++) {
            if(computerHand[i].getRank() != 10) {
                cout << "| "  << computerHand[i].getRankString() << computerHand[i].getSuitString()  << "  |  ";
            }else{
                cout << "| " << computerHand[i].getRankString() << computerHand[i].getSuitString() << " |  ";
            };
        };
        cout << endl;
        for (int i = 0; i < computerHand.size(); i++) {
            cout << "|     |  ";
        };
        cout << endl;
        for (int i = 0; i < computerHand.size(); i++) {
            cout << " -----   ";
        };
        cout << endl;
        for (int i = 0; i < computerHand.size(); i++) {
            if((i+1) < 10) {
                cout << "   " << i + 1 << "     ";
            }else{
                cout << "   " << i + 1 << "    ";
            }
        };
        cout << endl;

    }else{
        cout << "CAN'T DISPLAY PLAYER HAND! For printHand(int playerHand) please specify 1 or 2 (1 = user player. 2 = computer player)" << endl;
    }

}

//I WILL FIX IT TO CHECK FOR A VALID RESPONSE
bool Game::inHandCheck(string userInput){
    bool returnValue = false; //0 - Not found
    for(int i = 0; i < userHand.size(); i++){
        if(userInput == userHand[i].getName()){
            returnValue = true;
        }
    }
    return returnValue;
}

bool Game::askComputer(string response){
    bool returnValue = false;
    int rank = userHand[stoi(response)-1].getRank();
    for(int i = 0; i < computerHand.size(); i++){
        if(rank == computerHand[i].getRank()){
            returnValue = true;
        }
    }
    return returnValue;
}

void Game::takeCards(string card, int playerNum){
    if(playerNum == 2){
        //Player takes from computer
        for(int i = 0; i < computerHand.size(); i++){
            //userHan == computer
            if(computerHand[i].getRank() == userHand[stoi(card)-1].getRank()){
                userHand.push_back(computerHand[i]);
                computerHand.erase(computerHand.begin()+i);
            }
        }
    }
    else{
        //Computer takes from player
        for(int i = 0; i < userHand.size(); i++){
            if(userHand[i].getRank() == computerHand[stoi(card)].getRank()){
                computerHand.push_back(userHand[i]);
                userHand.erase(userHand.begin()+i);
            }
        }
    }
}

/** This function is work in progress. It is suppose to check if there is a book in hand
 **
 */
void Game::checkForBook(){
    printHand(1);
    //cout << computerHand[1].getRank() << endl;
    for(int i = 0; i < userHand.size(); i++) {
        for(int j = 0; j < userHand.size(); j++) {
            if(userHand[i].getRank() == userHand[j].getRank()){
                cout << userHand[i].getRank() << ' == ' << userHand[j+1].getRank() << endl;
            };
        };
    };
}
void Game::gameLogic(){

}
void Game::recordGuess(int guess, int playerNum){

}
