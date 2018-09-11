#include "Card.h"

int Card::getRank() const {
    return rank;
}

Suit Card::getSuit() const {
    return suit;
}

Card::Card(int r, Suit s) {
    rank = r;
    suit = s;
}
