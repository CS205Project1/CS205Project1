#ifndef PROJECT_CARD_H
#define PROJECT_CARD_H

enum Suit {
    Spades, Hearts, Clubs, Diamonds
};

class Card {
private:
    int rank;
    Suit suit;
public:
    Card(int r, Suit s);

    int getRank() const;

    Suit getSuit() const;
};


#endif //PROJECT_CARD_H
