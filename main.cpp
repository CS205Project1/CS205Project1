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
            int newGame; //if newGame == 0 means new game started aka round 1. Use if you want to run a peace of code only once at the beginning
            cout << "Welcome to Smart mode.  It is your turn... "<< endl;
            while(userResponse != "quit"){

                // ------------------- PLAYER TURN ------------------- //
                //Draw card if not enough cards
                bool anotherTurn = true;
                while(anotherTurn == true) {
                    while (smartGame.userHand.size() < 7 and smartGame.getDeck() != 0) {
                        smartGame.drawCard(1);
                    }
                    smartGame.printHand(1);  //Print user hand
                    smartGame.printHand(2);  //Computer hand - should only be displayed when testing
                    //Infinite loop that will break only if the userResponse is an integer.
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
                            }else if (userResponse == "b"){
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
                if(userIntResponse > 0 && userIntResponse <= smartGame.userHand.size()){
                    //Checks to see if computer has card and gives more turns if user gets it right
                    while (true) {
                        bool returnValue = smartGame.askComputer(userIntResponse);
                        if (returnValue == true) {
                            smartGame.takeCards(userIntResponse,2); //Take card from computer(2)

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
                            //SUCCESSFULLY TRADES CARDS!!!
                            smartGame.printHand(1);
                            smartGame.printHand(2);

                            cout << "You got some cards!  Here's Another turn" << endl;
                        } else {
                            cout << "-------------------------------" << endl;
                            cout << "Computer: Go Fish! hahahahah..." << endl;
                            cout << "-------------------------------" << endl;
                            smartGame.printHand(1);
                            smartGame.printHand(2);
                            //Main purpose of this if statement is to only output the table header to a file in the first round
                            //then just add rows than after
                            if(newGame == 0) {
                                //File output
                                smartGame.fileIO(smartGame.userHand[userIntResponse-1], playerUserName, "Match Not Found",true);
                                newGame++;
                            }else{
                                //File output
                                smartGame.fileIO(smartGame.userHand[userIntResponse-1], playerUserName, "Match Not Found",false);
                            }
                            smartGame.drawCard(1); //User goes fish
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
                while(smartGame.computerHand.size() < 7){
                    smartGame.drawCard(2);  //Adding a card to the computers deck
                }
                /*turnEndingTrigger = false;
                while(turnEndingTrigger != true)
                    smartGame.askUserSmart();
                */
            }
        }
        else if(modeChoice == "2"){

            }
        }


    }
    return 0;
}



