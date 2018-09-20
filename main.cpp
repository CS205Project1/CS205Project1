#include <iostream>

#include "Card.h"
#include "Deck.h"
#include "Game.h"
Deck d;
Hand h;
Game g;
int main() {
    Deck(); //construct the deck

    /**
     * The code below is mainly for testing the methods
     */
//    d.printDeck(); //print the deck
//    cout<< "-------------------" << endl;
//    d.shuffleDeck(); //this will shuffle the deck, but it's not necessary to use outside of testing
//    cout<< "-------------------" << endl;
//    d.printDeck(); //again mainly for testing purposes
//    cout<< "-------------------" << endl;
    h.dealCards(7); //When this is called it will shuffle the cards. Deal the cards. And print them, but that can be changed when needed
//    h.drawCard(1); //this will draw a card. use the parameter 1 to draw card for human player and user 2 to draw card for computer
//    h.printHands(1); //1 = print hand for human player
//    h.printHands(2); // 2 = print hand for computer player
//    h.printDeck();    //this will print the deck after the cards have been dealt and removed from the deck.

    /**
     * Working on the method below. The problem I am encountering is the vectors for playerHand and computerHand are empty
     * even after the cards have been dealt. Now it is populated when you print it in by calling h.pringHands(), but it's empty
     * when you use the printHands function in the checkForBook() function. I feel like I am missing a very simple point there,
     * so some help would be cool.
     */
//    g.checkForBook();
//
//







/*
    //Prompt to Choose Mode - While (not quit)
    std::string modeChoice;
    std::cout << " --- Welcome to Go Fish ---" << std::endl;
    while (modeChoice != "0") {
        std::cout << "Please choose one of the following options:" << std::endl;
        std::cout << "0 - quit" << std::endl;
        std::cout << "1 - Smart Mode" << std::endl;
        std::cout << "2 - Dumb Dumb Mode" << std::endl;

        std::cin >> modeChoice;


// ------------------- SMART MODE ------------------- //
        if(modeChoice == "1"){

            //Setting up the game
            //smartGame = Game() - create new game
            //user = User()
            //computer = Computer()
            std::string userResponse;


            std::cout << "Welcome to Smart mode.  Is is your turn... "<< std::endl;
            std::cout << "For Help, enter \"?\" --- To Quit, enter \"quit\"" << std::endl;
            //printHand() - Prints current hand
            std::cin >> userResponse;


            while(userResponse != "quit"){

                // ------------------- PLAYER TURN ------------------- //
                //checkCardCount(user) - will check to see if cards are needed for a full hand/draws any missing
                // If user wants help
                if(userResponse == "?"){
                    //printHelp()
                }

                //If user asks for a card in their hand
                else if(userResponse.inHandCheck() == true){ //Checks to see if response matches card in hand

                    //Checks to see if computer has card and gives more turns if user gets it right
                    bool anotherTurn = true;
                    while(anotherTurn == true)
                        if(askComputer(userResponse)==true){
                            //user.takeCards(userResponse,Computer)
                            //user.bookCheck() - puts aside books (adds points)
                            std::cout << "Here's Another turn" << std::endl;
                        }
                        else{
                            //player.goFish()
                            anotherTurn = false;
                        }
                }
                else{
                    std::cout << "For Help, enter \"?\" --- To Quit, enter \"quit\"" << std::endl;
                }


                // ------------------- COMPUTER TURN ------------------- //

            }


        }
    }
    return 0;
}



 Prompt to Choose Mode
 While (not quit){

    If (Choose Smart){
    
        Create New Game
        Deal() - Each player receives 7 cards. (2 players)

        ----- Users Turn -----
        Go fish if not enough cards.
        User is presented his cards and options
        The user asks the computer for a card he needs to make a book (set of 4)
        If (the computer has the card){
            he answers "Yes, I do"
            and gives the all cards of that rank to the user.
            User gets a point for every book and the book is put aside
            User gets another turn
        }
        Else (computer does not have that card){
            answers "Go Fish"
            and the user draws a card from the deck.
            Computers Turn (Goes fish if they don't have enough cards)
        }

        ----- Computers Turn -----
        Go fish if not enough cards.
        Computer checks memory of cards
        If (match is found){
            asks player for that card
            set any books aside
        }
        Else{
            Ask user for card
            If (the player has the card){
                player answers "Yes, I do"
                and gives the all cards of that rank to the user.
                User gets another turn
                User gets a point for every book and the book is put aside
            }
            Else (user does not have that card){
                answers "Go Fish"
                computer draws a card from the deck.
                Users Turn (Goes fish if they don't have enough cards)
            }
        }
    }
    Else_if (Choose Not Smart){

    }
    else_if (Choose Quit) {

    }
    Else {
    //Reprompt
    }
}

//Students play until the deck is empty, and all students have emptied their hands.
*/
}
