#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

Deck::Deck() = default;

ostream & operator<<(ostream & out, const Card & c) {
    out << c << endl;
}

Deck::Deck(vector<Card> deck){

    for (int j=1; j<14; j++) {
        for (int i=0; i<4; i++) {
            Suit suit = static_cast<Suit>(i);
            deck.push_back(Card(j,suit));
        }
    }


};

void Deck::shuffleDeck(){
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
};

void Deck::draw(){

};

