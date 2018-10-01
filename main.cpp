#include <iostream>
#include <exception>
#include <stdexcept>
#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include <stdlib.h>
using namespace std;

// Returns true if s is a number else return false meaning it's a string
bool isNumber(string s) {
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
    return true;
}

int main() {

    /* ================================== <TESTING> ================================== */
    //Moved to testing.cpp --- To use, add testing.cpp to CMakeLists.txt and remove main.cpp
    /* ================================== </TESTING> ================================== */


    /* =================================== <GAME> ===================================== */

    //Prompt to Choose Mode - While (not quit)
    string modeChoice;
    cout << " --- Welcome to Go Fish ---" << endl;
    while (modeChoice != "0") {
        string playerUserName;
        cout << "Enter a username: " ;
        cin >> playerUserName;
        cout << endl;

        cout << "Please choose one of the following options:" << endl;
        cout << "0 - Quit" << endl;
        cout << "1 - Smart Mode" << endl;
        cout << "2 - Dumb Dumb Mode" << endl;
        cout << ">>> ";
        std::cin >> modeChoice;


    // ------------------- SMART MODE ------------------- //
        if(modeChoice == "1"){

            //Setting up the game
            Game smartGame = Game();  //create new game
            string userResponse;
            cout << "Welcome to Smart mode.  It is your turn... "<< endl;

            while(userResponse != "quit"){

                // ------------------- PLAYER TURN ------------------- //
                //Draw card if not enough cards
                while(smartGame.userHand.size() < 7){
                    smartGame.drawCard(1);
                }
                smartGame.printHand(1);  //Print user hand
                smartGame.printHand(2);  //Computer hand - should only be displayed when testing

                //Infinite loop that will break only is the userResponse is an integer.
                while(true) {
                    cout << "For Help, enter '?' --- To Quit, enter 'quit'" << endl;
                    cout << "Make a guess >>> ";
                    cin >> userResponse;  //Capture user response

                    //Break loop if the user response is an number
                    if(isNumber(userResponse)){
                        break;
                    }

                    //Catch exception if the user response is not an integer
                    try {
                        int x = stoi(userResponse);
                    }catch (invalid_argument &) {
                        while ((userResponse != "?") and (userResponse != "quit")) {
                            cout << "Input not accepted. Please enter the '?' for help or 'quit' to end game." << endl;
                            cout << ">>> ";
                            cin >> userResponse;
                        }
                        if (userResponse == "quit") {
                            exit(0);
                        } else if (userResponse == "?") {
                            cout << "print help" << endl;
                        }
                    }
                }

                //File output
                smartGame.fileIO(smartGame.userHand[stoi(userResponse)], playerUserName, true);


                // If user wants help
                if(userResponse == "?"){
                    //printHelp()
                }
                //If user asks for a card in their hand
                else if(stoi(userResponse) > 0 && stoi(userResponse) <= smartGame.userHand.size()){
                    //Checks to see if computer has card and gives more turns if user gets it right
                    while (true) {
                        if (smartGame.askComputer(userResponse)) {
                            smartGame.takeCards(userResponse,2); //Take card from computer(2)

                            //SUCCESSFULLY TRADES CARDS!!!
                            //smartGame.printHand(1);
                            //smartGame.printHand(2);

                            cout << "You got some cards!  Here's Another turn" << endl;
                        } else {
                            smartGame.drawCard(1); //User goes fish
                            break;
                        }
                        smartGame.checkForBook(1); //puts aside books player 1 (adds points)
                        cout << smartGame.getUserScore() << endl;
                    }
                }
                else{
                    //Do nothing, reprompt
                }


                // ------------------- COMPUTER TURN ------------------- //
                /*
                 * if there are any values in the memory vector, computer will ask for one
                 * otherwise, choose a random card in its hand and ask for it
                 */
                //Go fish if not enough cards
                while(smartGame.computerHand.size() < 7){
                    smartGame.drawCard(2);
                }
                //Computer checks memory of card

                //If match is found (currently using dumb since memory is not fully implemented
                if (smartGame.askUserDumb()){
                   // smartGame.takeCards();
                    //set any books aside
                }
                else{
                    /*
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
                    */

                }

            }
        }


    }
    return 0;
}




/* =================================== </GAME> ===================================== */



 /*Prompt to Choose Mode
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

}
*/