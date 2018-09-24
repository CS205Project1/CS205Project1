#include "Card.h"

Card::Card() = default;

Card::Card(int r, char s) {
    rank = r;
    suit = s;
    name = to_string(r)+to_string(s);
}

int Card::getRank() const {
    return rank;
}

char Card::getSuit() const{
    return suit;
}

string Card::getName() const {
    return name;
}

ostream& operator << (ostream& outs, const Card &c) {
    outs << c.rank << c.suit ;
    return outs;
}