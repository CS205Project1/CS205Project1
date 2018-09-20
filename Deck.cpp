#include "Deck.h"
using namespace std;

Deck::Deck(){

    char suit[] = {'S', 'H', 'C', 'D'};
    for (int j=1; j<14; j++) {
        for (int i=0; i<4; i++) {
            deck.emplace_back(Card(j,suit[i]));
        }
    }

};

int Deck::getNumOfCardsDealt() const {
    return numOfCardsDealt;
}

void Deck::setNumOfCardsDealt(int numOfCardsDealt) {
    Deck::numOfCardsDealt = numOfCardsDealt;
};

void Deck::shuffleDeck(){
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
};

void Deck::printDeck() {
    for(int i = 0; i < deck.size(); i++){
        cout << i+1 << ". " << deck[i] << endl;
    };
}

Hand::Hand() = default;

Hand::Hand(vector<Card> playerHand,vector<Card> computerHand){
    playerHand = playerHand;
    computerHand = computerHand;
};

const vector<Card> &Hand::getPlayerHand() const {
    return playerHand;
}

void Hand::setPlayerHand(vector<Card> &playerHand) {
    Hand:: playerHand = playerHand;
}

const vector<Card> &Hand::getComputerHand() const {
    return computerHand;
}

void Hand::setComputerHand(vector<Card> &computerHand) {
    Hand::computerHand = computerHand;
}


void Hand::dealCards(int numOfCards){
    //Shuffling the deck before dealing
    shuffleDeck();

    //iterator
    auto it = next(deck.begin(), numOfCards);

    //moves cards to playerHand vector
    move(deck.begin(), it, back_inserter(playerHand));
    //After it's been moved it erases those slots from the deck
    deck.erase(deck.begin(), it);

    //same things below for computerHand
    move(deck.begin(), it, back_inserter(computerHand));
    deck.erase(deck.begin(), it);

    //Printing hand, then deck for testing purposes.
    printHands();
    printDeck();

};

void Hand::drawCard(int playerNum){
    auto it = next(deck.begin(), 1);
    if(playerNum == 1){
        move(deck.begin(), it, back_inserter(playerHand));
        deck.erase(deck.begin(), it);
    }else if (playerNum == 2){
        move(deck.begin(), it, back_inserter(computerHand));
        deck.erase(deck.begin(), it);
    }else{
        cout << "CARD NOT DRAWN! For drawCard please specify 1 or 2 (1 = user player. 2 = computer player)" << endl;
    }
};

void Hand::printHands(){
    cout<< "-------------------" << endl;
    cout << "Player Hand"<<endl;
    for(int i = 0; i < playerHand.size(); i++){
        cout << i+1 << ". " << playerHand[i] << endl;
    };
    cout<< "-------------------" << endl;
    cout << "Computer Hand"<<endl;
    for(int i = 0; i < computerHand.size(); i++){
        cout << i+1 << ". " << computerHand[i] << endl;
    };
    cout<< "-------------------" << endl;
};