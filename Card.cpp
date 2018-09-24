#include "Card.h"

Card::Card() = default;

Card::Card(int r, Suit s) {
    rank = r;
    suit = s;
    name = to_string(r)+to_string(s);
}

int Card::getRank() const {
    return rank;
}

Suit Card::getSuit() const{
    return suit;
}

string Card::getSuitString() const {
    switch(suit){
        case spades:
            return "♠";
        case diamonds:
            return "♦";
        case clubs:
            return "♣";
        case hearts:
            return "♥";
    }
}


string Card::getName() const {
    return name;
}

ostream& operator << (ostream& outs, const Card &c) {
    outs << c.rank << c.suit ;
    return outs;
}