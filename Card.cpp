#include "Card.h"

Card::Card() = default;

Card::Card(int r, char s) {
    rank = r;
    suit = s;
};

int Card::getRank() const {
    return rank;
};

char Card::getSuit() const{
    return suit;
};

ostream& operator << (ostream& outs, const Card &c) {
    outs << c.rank << c.suit ;
    return outs;
};