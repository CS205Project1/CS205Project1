#include "Game.h"
using namespace std;

//CONSTRUCTOR
Game::Game() {
    userScore = 0;
    computerScore = 0;
    deck = Deck();
    dealCards(7);
}

//GETTERS
int Game::getUserScore() const {
    return userScore;
}
int Game::getComputerScore() const {
    return computerScore;
}
vector<Card> Game::getUserHand() const {
    return userHand;
}
vector<Card> Game::getComputerHand() const {
    return computerHand;
}
vector<Card> Game::getUserBooks() const {
    return userBooks;
}
vector<Card> Game::getComputerBooks() const {
    return computerBooks;
}


//SETTERS
void Game::setUserScore(int u) {
    Game::userScore = u;
}
void Game::setComputerScore(int c) {
    Game::computerScore = c;
}
void Game::setUserHand(vector<Card> &h) {
    Game::userHand = h;
}
void Game::setComputerHand(vector<Card> &h) {
    Game::computerHand = h;
}
void Game::setComputerBooks(vector<Card> &computerBooks) {
    Game::computerBooks = computerBooks;
}
void Game::setUserBooks(vector<Card> &userBooks) {
    Game::userBooks = userBooks;
}


void Game::shuffleDeck(){
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.deck.begin(), deck.deck.end(), g);
}
//OTHER METHODS
void Game::dealCards(int numOfCards){
    shuffleDeck();
    //iterator
    auto it = next(deck.deck.begin(), numOfCards);

    //moves cards to playerHand vector
    move(deck.deck.begin(), it, back_inserter(userHand));
    //After it's been moved it erases those slots from the deck
    deck.deck.erase(deck.deck.begin(), it);

    //same things below for computerHand
    move(deck.deck.begin(), it, back_inserter(computerHand));
    deck.deck.erase(deck.deck.begin(), it);

}

void Game::drawCard(int playerNum){
    auto it = next(deck.deck.begin(), 1);
    if(playerNum == 1){
        move(deck.deck.begin(), it, back_inserter(userHand));
        deck.deck.erase(deck.deck.begin(), it);
    }else if (playerNum == 2){
        move(deck.deck.begin(), it, back_inserter(computerHand));
        deck.deck.erase(deck.deck.begin(), it);
    }else{
        cout << "CARD NOT DRAWN! For drawCard please specify 1 or 2 (1 = user player. 2 = computer player)" << endl;
    }
}


void Game::printHand(int playerNum){
    if(playerNum == 1) {
        cout << "******************************** Your Hand  **********************************" << endl;
        for (int i = 0; i < userHand.size(); i++) {
            cout << " -----   ";
        };
        cout << endl;
        for (int i = 0; i < userHand.size(); i++) {
            cout << "|     |  ";
        };
        cout << endl;

        for (int i = 0; i < userHand.size(); i++) {
            if(userHand[i].getRank() != 10) {
                cout << "| "  << userHand[i].getRankString() << userHand[i].getSuitString()  << "  |  ";
            }else{
                cout << "| " << userHand[i].getRankString() << userHand[i].getSuitString() << " |  ";
            };
        };
        cout << endl;
        for (int i = 0; i < userHand.size(); i++) {
            cout << "|     |  ";
        };
        cout << endl;
        for (int i = 0; i < userHand.size(); i++) {
            cout << " -----   ";
        };
        cout << endl;
        for (int i = 0; i < userHand.size(); i++) {
            if((i+1) < 10) {
                cout << "   " << i + 1 << "     ";
            }else{
                cout << "   " << i + 1 << "    ";
            }
        };
        cout << endl;

    }else if (playerNum == 2) {
        cout << "******************************  Computer Hand  *******************************" << endl;
        for (int i = 0; i < computerHand.size(); i++) {
            cout << " -----   ";
        };
        cout << endl;
        for (int i = 0; i < computerHand.size(); i++) {
            cout << "|     |  ";
        };
        cout << endl;

        for (int i = 0; i < computerHand.size(); i++) {
            if(computerHand[i].getRank() != 10) {
                cout << "| "  << computerHand[i].getRankString() << computerHand[i].getSuitString()  << "  |  ";
            }else{
                cout << "| " << computerHand[i].getRankString() << computerHand[i].getSuitString() << " |  ";
            };
        };
        cout << endl;
        for (int i = 0; i < computerHand.size(); i++) {
            cout << "|     |  ";
        };
        cout << endl;
        for (int i = 0; i < computerHand.size(); i++) {
            cout << " -----   ";
        };
        cout << endl;
        for (int i = 0; i < computerHand.size(); i++) {
            if((i+1) < 10) {
                cout << "   " << i + 1 << "     ";
            }else{
                cout << "   " << i + 1 << "    ";
            }
        };
        cout << endl;

    }else{
        cout << "CAN'T DISPLAY PLAYER HAND! For printHand(int playerHand) please specify 1 or 2 (1 = user player. 2 = computer player)" << endl;
    }

}

void Game::printCard(int playerNum){
    for (int i = 0; i < computerHand.size(); i++) {
        cout << " -----   ";
    };
    cout << endl;
    for (int i = 0; i < computerHand.size(); i++) {
        cout << "|     |  ";
    };
    cout << endl;

    for (int i = 0; i < computerHand.size(); i++) {
        if(computerHand[i].getRank() != 10) {
            cout << "| "  << computerHand[i].getRankString() << computerHand[i].getSuitString()  << "  |  ";
        }else{
            cout << "| " << computerHand[i].getRankString() << computerHand[i].getSuitString() << " |  ";
        };
    };
    cout << endl;
    for (int i = 0; i < computerHand.size(); i++) {
        cout << "|     |  ";
    };
    cout << endl;
    for (int i = 0; i < computerHand.size(); i++) {
        cout << " -----   ";
    };
    cout << endl;
    for (int i = 0; i < computerHand.size(); i++) {
        if((i+1) < 10) {
            cout << "   " << i + 1 << "     ";
        }else{
            cout << "   " << i + 1 << "    ";
        }
    };
    cout << endl;
}
//I WILL FIX IT TO CHECK FOR A VALID RESPONSE
bool Game::inHandCheck(string userInput){
    bool returnValue = false; //0 - Not found
    for(int i = 0; i < userHand.size(); i++){
        if(userInput == userHand[i].getName()){
            returnValue = true;
        }
    }
    return returnValue;
}
bool Game::askComputer(int response){
    //bool returnValue = false;
    int rank = userHand[response-1].getRank();
    //computer now "knows" user has this card
    recordToMemory(rank);
    for(int i = 0; i < computerHand.size(); i++){
        if(rank == computerHand[i].getRank()){
            return true;
        }
    }
    return false;
}
bool Game::askUserSmart(int cardToAskFor){
    bool returnValue = false;
    int rank = computerHand[cardToAskFor-1].getRank();
    for(int i = 0; i < userHand.size(); i++){
        if(rank == userHand[i].getRank()){
            returnValue = true;
            //Erase this rank from memory
            deleteFromMemory(rank);
            //take the card from player
            takeCards(rank,1);
        }
    }
    return returnValue;
}
bool Game::askUserDumb(){
    bool returnValue = false;
    int rank = computerHand[1].getRank();
    for(int i = 0; i < userHand.size(); i++){
        if(rank == userHand[i].getRank()){
            returnValue = true;
        }
    }
    return returnValue;
}
void Game::takeCards(int card, int playerNum){
    if(playerNum == 2){
        //Player takes from computer
        for(int i = 0; i < computerHand.size(); i++){
            //userHan == computer
            if(computerHand[i].getRank() == userHand[card-1].getRank()){
                userHand.push_back(computerHand[i]);
                computerHand.erase(computerHand.begin()+i);
            }
        }
    }
    else{
        //Computer takes from player
        for(int i = 0; i < userHand.size(); i++){
            if(userHand[i].getRank() == computerHand[card-1].getRank()){
                computerHand.push_back(userHand[i]);
                userHand.erase(userHand.begin()+i);
                //erase this rank from memory as user no longer has it
                deleteFromMemory(card);
            }
        }
    }
}
/** This function is work in progress. It is suppose to check if there is a book in hand.
 ** when a book is scored, that rank should be erased from the memory vector.
 * Right now it finds and displays all matching pairs.
 *
 * Here is requirements for this method:
 *
 *  - It needs to check to see if there is 4 matching ranks(aka cards)
 *  - If there is then it should add them to separate vector and remove them from the hand so that it can't be used for the rest of the game
 *  - We'll use the vector of books each player has to determine the winner. The player with the most books in their vector will be the winner.
 */
void Game::checkForBook(int playerNumber){
    //Create an array to hold matching rank count
    int rankCount [13] = {0,0,0,0,0,0,0,0,0,0,0,0,0}; //Holds 13 ranks

    //User Check
    if(playerNumber == 1){
        //Loop through each card in hand and add matching ranks
        for(int i = 0; i < userHand.size(); i++){
            //Add one to rankCount@ current card rank (-1 because of arrays)
            rankCount[userHand[i].getRank()-1] = rankCount[userHand[i].getRank()-1] + 1;
        }

        for (int i = 0; i < 13; i++)
            cout << rankCount[i] << ", ";

        //Loop through rankCount to see if any have 4 --- i+1 = rank
        for(int i = 0; i < 13; i++){
            //If a book is in the hand (4 of a kind), loop through hand and remove those cards
            if(rankCount[i] == 4){
                deleteFromMemory(i);
                int cardsRemoved = 0;
                for(int j = 0; j < userHand.size(); j++){
                    //If the rank matches, remove the card
                    if(userHand[j].getRank() == i+1){
                        userHand.erase(userHand.begin()+j);
                        cardsRemoved++;
                    }
                }
                //Add one to user score
                userScore++;
            }
        }
    }
    //Computer Check -- SAME AS USER HAND
    else{
        //Loop through each card in hand and add matching ranks
        for(int i = 0; i < computerHand.size(); i++){
            //Add one to rankCount@ current card rank (-1 because of arrays)
            rankCount[computerHand[i].getRank()-1] = rankCount[computerHand[i].getRank()-1] + 1;
        }

        for (int i = 0; i < 13; i++)
            cout << rankCount[i];

        //Loop through rankCount to see if any have 4 --- i+1 = rank
        for(int i = 0; i < 13; i++){
            //If a book is in the hand (4 of a kind), loop through hand and remove those cards
            if(rankCount[i] == 4){
                int cardsRemoved = 0;
                for(int j = 0; j < computerHand.size(); j++){
                    //If the rank matches, remove the card
                    if(computerHand[j].getRank() == i+1){
                        computerHand.erase(computerHand.begin()+j);
                        cardsRemoved++;
                    }
                }
                //Add one to computer score
                computerScore++;
            }
        }
    }
}

//FILE IO
void Game::fileIO(Card chosenCard, string playerUserName, string matchStatus, bool newGame){
    ofstream f("gameRecords.txt", ios_base::app);
    if (f.is_open()) {

        if(newGame) {
            f << "\n\n================================== NEW GAME ==================================" << endl;
            f << "Player Username: " << playerUserName << endl;
            f << "------------------------------------------------------------------------------" << endl;
            f << setw(17) << "Player Turn" << setw(8) << "|" << setw(20) << "Guess/Choice" << setw(11) << "|" << setw(18) << "Match Status" << endl;
            f << "------------------------------------------------------------------------------" << endl;
        };
        if ((chosenCard.getRank() == 1 or chosenCard.getRank() > 10) and !newGame) {
            f << setw(13) << playerUserName << setw(12) << "|" << setw(15) << chosenCard.getRankString()
              << chosenCard.getSuitString() << setw(15) << "|" << setw(19) << matchStatus << endl;
        }else if (!newGame){
            f << setw(13) << playerUserName << setw(12) << "|" << setw(15) << chosenCard.getRank()
              << chosenCard.getSuitString() << setw(15) << "|" << setw(19) << matchStatus << endl;
        };

        f.close();
    }
};

//MEMORY STUFF
void Game::recordToMemory(int guess){
    memory.push_back(guess);  //Saves the users guess to memory
}

void Game::deleteFromMemory(int rank){
    for(int i = 0; i < memory.size(); i++){
        if(memory[i]==rank){
            memory.erase(memory.begin()+i);
        }
    }
}

int Game::compareHandToMemory(){
    for(int i = 0; i < memory.size(); i++){
        for(int j = 0; j < computerHand.size(); j++){
            if(memory[i] == computerHand[j].getRank()){
                return memory[i];
            }
        }
    }
    return 0;
}