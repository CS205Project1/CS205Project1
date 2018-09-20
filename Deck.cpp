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

void Deck::drawCard(){

    //Removing card from top of the deck after it's been drawn by player
    removeCardFromDeck(1);
};

void Deck::dealCards(){
    //Shuffling the deck before dealing
    shuffleDeck();

    Hand h;
    h.setPlayerHand(deck,numOfCardsDealt);
    h.setComputerHand(deck,numOfCardsDealt);

    //Removing the number of cards dealt from top of the deck after it's been dealt to players
    //removeCardFromDeck(numOfCardsDealt*2);
};

void Deck::removeCardFromDeck(int numberOfCardsToBeRemoved){
    //Remove card from top of the deck
    int count = 0;
    while (count < numberOfCardsToBeRemoved) {
        deck.pop_back();
        count++;
    }

};
void Deck::printDeck() {
    for(int i = 0; i < deck.size(); i++){
        cout << deck[i] << endl;
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

void Hand::setPlayerHand(vector<Card> &playerHand,int numOfCards) {
    auto it = next(deck.begin(), numOfCards);
    move(deck.begin(), it, back_inserter(playerHand));
    deck.erase(deck.begin(), it);
}

const vector<Card> &Hand::getComputerHand() const {
    return computerHand;
}

void Hand::setComputerHand(vector<Card> &computerHand, int numOfCards) {
    auto it = next(deck.begin(), numOfCards);
    move(deck.begin(), it, back_inserter(computerHand));
    deck.erase(deck.begin(), it);
}

void Hand::printHands(){
    cout << "Player Hand"<<endl;
    for(auto i : playerHand){
        cout << i << endl;
    };

    cout << "Computer Hand"<<endl;
    for(auto i : computerHand){
        cout << i << endl;
    };
};