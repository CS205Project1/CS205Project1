#include <iostream>

#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include <stdlib.h>
using namespace std;

// Returns true if s is a number else return false meaning it's a string
bool isNumber(string s) {
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == 0)
            return false;
    return true;
}

int main() {

    /* ================================== <TESTING> ================================== */
    //Moved to testing.cpp --- To use, add testing.cpp to CMakeLists.txt and remove main.cpp
    /* ================================== </TESTING> ================================== */


    /* =================================== <GAME> ===================================== */

    //Setting up the game
    //Determine lie percent (user input or random??)
    int lies = 50;
    Game smartGame = Game(lies);  //create new game

    //Prompt to Choose Mode - While (not quit)
    string modeChoice;
    cout << " --- Welcome to Go Fish ---" << endl;
    while (modeChoice != "0") {
        string playerUserName;
        cout << "Enter a username: " ;
        cin >> playerUserName;
        smartGame.setPlayerName(playerUserName);
        cout << endl;

        cout << "Please choose one of the following options:" << endl;
        cout << "0 - Quit" << endl;
        cout << "1 - Smart Mode" << endl;
        cout << "2 - Dumb Dumb Mode" << endl;
        cout << ">>> ";
        std::cin >> modeChoice;

    // ------------------- SMART MODE ------------------- //
        if(modeChoice == "1"){

            string userResponse;
            int newGame;
            cout << "Welcome to Smart mode.  It is your turn... "<< endl;
            while(userResponse != "quit") {

                // ------------------- PLAYER TURN ------------------- //
                //Draw card if not enough cards
                while (true) {

                    smartGame.printHand(1);  //Print user hand
                    smartGame.printHand(2);  //Computer hand - should only be displayed when testing

                    //Check for books incase there is a book when they are dealt cards if there is a book print hand
                    bool playerHasBook = smartGame.checkForBook(1);
                    if (playerHasBook) {
                        cout << "---------------------------------------------------------" << endl;
                        cout << "Books found in " << playerUserName << "'s hand. Hand after book has been taken out: " << endl;
                        cout << "---------------------------------------------------------" << endl;
                        smartGame.drawCard(1,(int) smartGame.userHand.size(),0);
                        smartGame.printHand(1);  //Print user hand
                    }
                    bool computerHasBook = smartGame.checkForBook(2);
                    if (computerHasBook){
                        cout << "---------------------------------------------------------" << endl;
                        cout << "Books found in Computer hand. Hand after book has been taken out: " << endl;
                        cout << "---------------------------------------------------------" << endl;
                        smartGame.drawCard(2,(int) smartGame.computerHand.size(),0);
                        smartGame.printHand(2);  //Computer hand - should only be displayed when testing
                    }

                    cout << "For Help, enter '?' --- To Quit, enter 'quit'" << endl;
                    cout << playerUserName << " make a guess >>> ";
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
                            cout << "\nYou got some cards!  Here's Another turn" << endl;
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
                            cout << "\nComputer: 'Go Fish! You must draw a card.'" << endl;
                            cout<<endl;
                            cout << playerUserName << ": You Drew " << endl;
                            smartGame.drawCard(1, (int) smartGame.userHand.size(),1);
                            cout<<endl;
                            if(newGame == 0) {
                                //File output
                                smartGame.fileIO(smartGame.userHand[userIntResponse-1], playerUserName, "Match Not Found",true);
                                newGame++;
                            }else{
                                //File output
                                smartGame.fileIO(smartGame.userHand[userIntResponse-1], playerUserName, "Match Not Found",false);
                            }
                            break; //turn ended break loop
                        }
                    }
                }

                // ------------------- COMPUTER TURN ------------------- //

                if(smartGame.computerHand.size() < 7 and smartGame.getDeckSize() !=0){
                    smartGame.drawCard(2,(int) smartGame.computerHand.size(),0);
                }
                bool turnEndingTrigger = true;
                while (turnEndingTrigger) {
                    turnEndingTrigger = smartGame.askUserSmart();
                }
            }
        }
        else if(modeChoice == "2"){

        }


    }
    return 0;
}