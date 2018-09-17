#ifndef CS205_GOFISH_GOFISH_H
#define CS205_GOFISH_GOFISH_H

#include <vector>
#include "Card.h"
using namespace std;

class Deck {
    private:
        vector<Card> deck;
    public:
        Deck();
        Deck(vector<Card> deck);

        void draw();

};

#endif //CS205_GOFISH_GOFISH_H
