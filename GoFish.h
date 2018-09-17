#ifndef CS205_GOFISH_GOFISH_H
#define CS205_GOFISH_GOFISH_H

#include <vector>
using namespace std;

enum Suit {H,D,C,S};

class Card {
    private:
        int rank;
        Suit suit;
    public:
        Card();
        Card(int r, Suit s);

        int getRank() const;

        Suit getSuit() const;
};

class Deck {
    private:
        vector<Card> deck;
    public:
        Deck();
        Deck(vector<Card> deck);

        void draw();

};

#endif //CS205_GOFISH_GOFISH_H
