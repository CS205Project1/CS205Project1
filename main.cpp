#include <iostream>

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
            int newGame;
            cout << "Welcome to Smart mode.  It is your turn... "<< endl;
            while(userResponse != "quit") {

                // ------------------- PLAYER TURN ------------------- //
                //Draw card if not enough cards
                bool anotherTurn = true;
                while (anotherTurn == true) {
                    while (smartGame.userHand.size() < 7 and smartGame.getDeck() != 0) {
                        smartGame.drawCard(1);
                    }
                    smartGame.printHand(1);  //Print user hand
                    smartGame.printHand(2);  //Computer hand - should only be displayed when testing
                    cout << "For Help, enter '?' --- To Quit, enter 'quit'" << endl;
                    cout << "Make a guess >>> ";
                    cin >> userResponse;  //Capture user response
                    //Infinite loop that will break only if the userResponse is an integer.
                    while (true) {

                        //Break loop if the user response is an number
                        if (isNumber(userResponse)) {
                            break;
                        }

                        //Catch exception if the user response is not an integer
                        try {
                            int x = stoi(userResponse);
                        } catch (invalid_argument &) {
                            while ((userResponse != "?") and (userResponse != "quit") and (userResponse != "b")) {
                                cout << "Invalid Input! Please enter the '?' for help || 'quit' to end game || 'b' to go back to game" << endl;
                                cout << ">>> ";
                                cin >> userResponse;
                            }
                            if (userResponse == "quit") {
                                exit(0);
                            } else if (userResponse == "?") {
                                cout << "print help" << endl;
                                smartGame.printHand(1);  //Print user hand
                            } else if (userResponse == "b") {
                                smartGame.printHand(1);  //Print user hand
                            }
                        }
                    }
                    //Convert user string input into an integer
                    int userIntResponse = stoi(userResponse);

                    //Checking to make sure we asked for a card in the hand!
                    while (userIntResponse > smartGame.userHand.size() || userIntResponse < 0) {
                        cout << "Input not accepted. Please enter the integer value that is below one of the cards" << endl;
                        cout << "Guess again >>> " << endl;
                        cin >> userIntResponse;
                    };

                    //If user asks for a card in their hand
                    if (userIntResponse > 0 && userIntResponse <= smartGame.userHand.size()) {
                        //Checks to see if computer has card and gives more turns if user gets it right
                        if (smartGame.askComputer(userIntResponse)) {
                            smartGame.takeCards(userIntResponse, 2); //Take card from computer(2)
                            cout << "You got some cards!  Here's Another turn" << endl;
                            //Main purpose of this if statement is to only output the table header to a file in the first round
                            //then just add rows than after
                            if(newGame == 0) {
                                //File output
                                smartGame.fileIO(smartGame.userHand[userIntResponse-1], playerUserName, "Match Found",true);
                                newGame++;
                            }else{
                                //File output
                                smartGame.fileIO(smartGame.userHand[userIntResponse-1], playerUserName, "Match Found",false);
                            }
                        } else {
                            cout << "Go Fish" << endl;
                            smartGame.drawCard(1); //User goes fish
                            if(newGame == 0) {
                                //File output
                                smartGame.fileIO(smartGame.userHand[userIntResponse-1], playerUserName, "Match Not Found",true);
                                newGame++;
                            }else{
                                //File output
                                smartGame.fileIO(smartGame.userHand[userIntResponse-1], playerUserName, "Match Not Found",false);
                            }
                            smartGame.printHand(1);  //Print user hand
                            smartGame.printHand(2);  //Computer hand - should only be displayed when testing
                            anotherTurn = false;
                        }
                        smartGame.checkForBook(1); //puts aside books player 1 (adds points)
                        cout << smartGame.getUserScore() << endl;
                    } else {
                        //Do nothing, reprompt
                    }
                }
                // ------------------- COMPUTER TURN ------------------- //
                //Go fish if not enough cards
                while (smartGame.computerHand.size() < 7) {
                    smartGame.drawCard(2);  //Adding a card to the computers deck
                }
                bool turnEndingTrigger = true;
                while (turnEndingTrigger == true) {
                    turnEndingTrigger = smartGame.askUserSmart();
                }
            }
        }
        else if(modeChoice == "2"){

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