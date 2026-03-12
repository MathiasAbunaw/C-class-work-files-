// Programmer: Arreyebot Abunaw
// Date: 3/7/2026
// File: HW03.cpp
// Assignment: HW3
// Purpose: this file contains the main function of the
//   program which will create a wordle game
//   with many options for users to chose
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;



// Desc: This function is used to displays a greet message to the user
// Pre: None 
// Post: prints a greeting message to the user

void greet(){
    cout << "Welcome to Wordle For Friends! ^.^"<<endl;
}


// Desc: This function is used to displays the menu of options to the user and the options that they have to choose from
// Pre: None
// Post: prints menu of options the user can pick from within the list 
void menu(){
    cout<<"\nThe Wordle\'s Menu\n***"<<endl;
    cout<<"1. Start a new game (with new players)"<<endl;
    cout<< "2. Start a new round (with existing players)"<<endl;
    cout << "3. Print game summary (of existing players)"<<endl;
    cout << "4. Share result (of last round)"<<endl;
    cout <<"5. Exit the game (are you sure?)\n***"<<endl;
}
// Desc: This function is used to displays submenu of option 1 and 2
// Pre: None 
// Post: prints a submenu for player 1 and player 2 to choose from

void Submenu(){
    cout << "\nPlease choose an option:"<<endl;
    cout <<"1. Guess the word"<<endl;
    cout <<"2. Use the Vanisher (obscure a clue for Player 2)";
}
// Desc: This function is used to displays the user guess word and determine if it guess was correct or position is and letter are correct or within the correct word
// Pre: player 2 guess word 
// Post: prints a player 2 guess with letter that are correct and ones that are not correct or in the wrong placement

void userGuess(string userInput, string correctword, string& feedback){
    if(userInput == correctword){ //This checks whether the user guessInput is equal 
        feedback = "[*] [*] [*] [*] [*]"; //this sets feedback to all correct if the user inputs the ocrrect value
        cout<<"You entered "<<userInput<<". Congratulations, "<<userInput<<" it is!"<<endl;
    }
    else{
        cout<<"You entered "<<userInput<<". Nice try, keep going!"<<endl;
        for(int i=0; i < userInput.length(); i++){
            int find = 0;//check whether we did find a character within the correct word
            cout<<userInput[i]<<": ";
            for (int j=0; j < correctword.length(); j++){
                if(userInput[i] == correctword[j]){
                    if(i == j){
                        ++find;
                        feedback += "[*] ";
                        cout<<"[*]"<<endl;
                    }
                    else{
                        ++find;
                        feedback += "[!] ";
                        cout<<"[!]"<<endl;
                    }
                }
                else if((j == 4) & (find == 0)){
                    feedback += "[x] ";
                    cout<<"[x]"<<endl;
                }
            }
        }
    }
}
// Desc: This function is to use to display users guess with Vanish system in place based on friendship level
// Pre: friendship level 
// Post: displayes the second user guess word and determine if any of the position or character are correct but with vanish system in place based on friendship level

void useVanisher(char friendship, string userInput, string correctword, string& feedback){
    int first = 0; //this will check if this is the first value of this
    if(userInput == correctword){ //This checks whether the user guessInput is equal 
        feedback = "[*] [*] [*] [*] [*]"; //this sets feedback to all correct if the user inputs the ocrrect value
        cout<<"You entered "<<userInput<<". Congratulations, "<<userInput<<" it is!"<<endl;
    }
    else{
        cout<<"You entered "<<userInput<<". Nice try, keep going!"<<endl;
        for(int i=0; i < userInput.length(); i++){
            int find = 0;//check whether we did find a character within the correct word
            cout<<userInput[i]<<": ";
        
            for (int j=0; j < correctword.length(); j++){
                if(userInput[i] == correctword[j]){
                    if(i == j){
                        if ((friendship <= 60) & (first == 0)){
                            ++first;
                            ++find;
                            feedback += "[?] ";
                            cout <<"[?]"<<endl;
                        }
                        else{
                            ++find;
                            feedback += "[*] ";
                            cout<<"[*]"<<endl;
                        }
                    }
                    else{
                        if ((friendship <= 120) & (first == 0)){
                            ++first;
                            ++find;
                            cout <<"[?]"<<endl;
                            feedback += "[?] ";
                        }
                        else{
                            ++find;
                            cout<<"[!]"<<endl;
                            feedback += "[!] ";
                        }
                    }
                }
                else if((j == 4) & (find == 0)){
                    if ((friendship >120) & (first == 0)){
                        ++first;
                        cout <<"[?]"<<endl;
                        feedback += "[?] ";
                    }
                    else{
                        cout<<"[x]"<<endl;
                        feedback += "[x] ";
                    }
                }
            }
        }
    }

}

// Desc: This function is used to displays the summary of the players name, rounds and friendship levels
// Pre: initial friendship, current friendship, players 1 name, player 2 name, and number of round 
// Post: prints the users name, friendship level, and number of rounds played with final friendship

void printGameSummary(string player1, string player2, int initialFriendship, int currentFriendship, int rounds){
    int finalFriendship = currentFriendship;
    cout<<"\nGame Summary\n***"<<endl;
    cout <<"Player 1: "<<player1<<endl;
    cout <<"Player 2: "<<player2<<endl;
    cout<<"Number of rounds played: "<<rounds<<endl;
    cout<<"Initial friendship level: "<<initialFriendship<<endl;
    cout<<"Current friendship level: "<<currentFriendship<<endl;
    if(currentFriendship < 20){
        finalFriendship += 2;
        cout<<"Final friendship level: "<< finalFriendship<<"(2 bonus levels added)\n***"<<endl;
    }
    else{
        cout<<"Final friendship level: "<< finalFriendship<<"\n***"<<endl;
    }
}

int main(){
    greet();
    menu();
    int choice; //stores users choice
    cout<<"Please choose an option (1-5):";
    cin >> choice;
    string guessHistory[6]; //This is created inorder to stor the users word guess;
    string feedbackHistory[6]; //This is created inorder to store the feedback of the values as an array of string
    string currentWord; //This is used inorder to store the current word to be used across cases.
    int attempts = 1;
    string play1Name;
    string play2Name;
    int initial_friendship;
    int friendShipLVL;
    int round = 0;
    do{
        switch(choice){
            case 1:{
                round = 0;
                initial_friendship = 0;
                friendShipLVL = 0;
                cout <<"Player 1, please enter your name:";
                cin>>play1Name;
                cout<<"Welcome, "<< play1Name <<"!"<<endl;
                cout <<"Player 2, please enter your name:";
                cin>>play2Name;
                cout<<"Welcome, "<< play2Name <<"!"<<endl;
                cout<<play1Name<<", please rate the friendship level you have with "<<play2Name<<" \n(enter an integer value in [0, 200]):";
                cin >> initial_friendship;
                while(initial_friendship > 200){ //This checks makes sure the users does not have a number not provided above
                    cout <<"Please enter a number within the range from [0, 200]!: ";
                    cin>>initial_friendship;
                }
                friendShipLVL = initial_friendship;
                cout <<"Hooray, that\'s an admirable friendship between you two!\n\nLet the game begin now!"<<endl;
            
            }
            case 2:{
                if((play1Name == "") && (play2Name == "")){ //This is used inorder to check whether there were already pasted data by checking is plyaerNames where already recorded
                    cout<<"Sorry, no existing player info found. Please start a new game and choose again: ";
                    cin >> choice;
                    break;
                }
                else if((round >= 1) && (choice == 2)){
                    string guessHistory[6]; //This is created inorder to stor the users word guess;
                    string feedbackHistory[6]; //This is created inorder to store the feedback of the values as an array of string
                    cout<<"\nAlright! Round "<<round<<" with "<< play1Name <<" and "<< play2Name<<"!"<<endl;
                }
                string word;
                cout<<"I need the key word from you (yes, you may whisper into\nmy ears… and remember, it has to be a valid five-letter word\nall UPPERCASE):";
                cin >> word;
                while((word.length() != 5) || (word.find_first_of("0123456789") != string::npos)){ //This checks makes sure the users does not have a number as well as the length of the word being 5
                    if (word.length() != 5){
                        cout << "Invalid length!"<<endl;
                        cout <<"Please enter exactly five letters (A-Z only):";
                        cin >> word;
                    }
                    else{
                        cout << "Invalid characters!"<<endl;
                        cout <<"Please enter exactly five letters (A-Z only):";
                        cin >> word;
                    }   
                }
                transform(word.begin(), word.end(), word.begin(), ::toupper); //Turnes the lower case letter into upper case letter
                currentWord = word;
                cout<<"Got it, "<<play1Name<<"! The key word is now securely processed and saved.\n"<<endl;
                cout <<"Get ready, "<<play2Name<<"! It\'s now time to Wordle with "<<play1Name<<"!  You will have a total of 6 attempts to guess the word correctly.\n"<<endl;
                
                int vanishCounter = 2;
            
                attempts = 1; //number of attempts guess
                bool guessCorrect = false;
                string guess;
                while((attempts <= 6) && (!guessCorrect)){
                    Submenu();
                    cout<<"[remaining "<<vanishCounter<<"/2]";
                    string menuOption; //menu option storer
                    cin>>menuOption;
                    while((menuOption != "1") && (menuOption != "2")){ //This checks makes sure the users does not have a number not provided above
                        cout <<"Please enter a valid option provided above!: ";
                        cin>>menuOption;
                    }

                    if((menuOption == "2") && (vanishCounter > 0)){ //this checkes if they choose option 2 and they have vanish
                        cout <<"***"<<play1Name<<" has activated The Vanisher!***"<<endl;
                        cout<<"Friendship: "<< friendShipLVL<<"/200"<<endl;
                        if (friendShipLVL <= 60){
                            cout<<"Hiding first occurrence of [*] in this guess"<<endl;
                        }
                        else if(friendShipLVL <= 120){
                            cout<<"Hiding first occurrence of [!] in this guess"<<endl;
                        }
                        else{
                            cout<<"Hiding first occurrence of [x] in this guess"<<endl;
    
                        }
                    }
                    else if((menuOption == "2") && (vanishCounter == 0)){
                        cout<<"***\n"<<play1Name<<", you\'ve already used up the Vanisher!\nNo more vanishing allowed!\n***"<<endl;
                        continue;
                        
                    }
                    cout << "\nThis is your attempt #"<<attempts<<", "<<play2Name<<", please enter a valid five-letter word (all UPPERCASE):";
                    cin >> guess;
                    cout<<"\n"<<endl;
                    transform(guess.begin(), guess.end(), guess.begin(), ::toupper);// this turnes their guess word into uppercase
                    while((guess.length() != 5) || (guess.find_first_of("0123456789") != string::npos)){ //This checks makes sure the users does not have a number as well as the length of the word being 5
                        if (guess.length() != 5){
                            cout << "Invalid length!"<<endl;
                            cout <<"Please enter exactly five letters (A-Z only):";
                            cin >> guess;
                        }
                        else{
                            cout << "Invalid characters!"<<endl;
                            cout <<"Please enter exactly five letters (A-Z only):";
                            cin >> guess;
                        }   
                    }
                    string feedback = "";
                    if((menuOption == "2") && (vanishCounter > 0)){
                        useVanisher(friendShipLVL, guess, word, feedback);
                        feedbackHistory[attempts - 1] = feedback; //This will store the user guess and attemp with an array
                        guessHistory[attempts - 1] = guess; //THis will help store the users guesses
                        --vanishCounter;
                        ++attempts;
                    }
                    else{
                        userGuess(guess, word, feedback);
                        feedbackHistory[attempts - 1] = feedback; //This will store the user guess and attemp with an array
                        guessHistory[attempts - 1] = guess;
                        vanishCounter;
                        ++attempts;
                    }
                    if (guess == word){
                        guessCorrect = true;
                        ++round;
                    }   
                }
                if(guessCorrect == false){
                    cout<<"\nOut of attempts. The correct word was \""<<word<<"\"."<<endl;
                    ++round;
                }

                
                cout<<"\nRound "<<round<<" Summary\n"<<"***"<<endl;
                cout <<"Player 1: "<< play1Name<<endl;
                cout <<"Player 2: "<< play2Name<<endl;
                cout << "Friendship Level: "<<friendShipLVL<< "-> "<<friendShipLVL + (attempts -1)<<endl;
                cout <<"***"<<endl;

                friendShipLVL = friendShipLVL + (attempts - 1);


                menu();
                cout<<"Please choose an option (1-5):";
                cin >> choice;
                continue;
                break;
                
            }
            case 3:{
                if((play1Name == "") && (play2Name == "")){ //This is used inorder to check whether there were already pasted data by checking is plyaerNames where already recorded
                    cout<<"Sorry, no round records found. Please choose again: ";
                    cin >> choice;
                    break;
                }
                else{
                    printGameSummary(play1Name, play2Name, initial_friendship, friendShipLVL, round);
                    menu();
                    cout<<"Please choose an option (1-5):";
                    cin >> choice;
                    continue;
                }
            }
            case 4:{
                if((play1Name == "") && (play2Name == "")){ //This is used inorder to check whether there were already pasted data by checking is plyaerNames where already recorded
                    cout<<"Sorry, no round records found. Please choose again: ";
                    cin >> choice;
                    break;
                }
                else{

                    cout<<"Wordle For Friends - Share\n***"<<endl;
                    cout<<"Players: "<<play1Name<<" (P1) vs "<< play2Name<<" (P2)"<<endl;
                    cout<<"Round: "<<round<<" Result: "<<(attempts - 1)<<"/6 Key word: "<<currentWord<<"\n\nGuesses:"<<endl;
                    for(int i=0; i < 6; i++){
                        if(feedbackHistory[i] != ""){ //This checkes whether or not the list is empthy
                            cout<<i+1<<") "<<guessHistory[i]<<" "<<feedbackHistory[i]<<endl; //This is used inorder to print the feedback and guess round history 
                        }

                    }

                    cout<<"***"<<endl;
                    
                    menu();

                    cout<<"Please choose an option (1-5):";

                    cin >> choice;
                    continue;
                }
                break;
            }
            default:
                cout<<choice<<" is not a valid option! Please choose again:";
                cin >> choice;
        }
    }while(choice != 5);
    cout<<"OK, good bye! See you soon, Wordle Wordle!\nRemember, a real friend is one who always Wordles with you\nwhen the rest of the world won\'t!"<<endl; 
    
}

