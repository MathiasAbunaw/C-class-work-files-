// Programmer: Arreyebot Abunaw
// Date: 2/19/2026
// File: HW02.cpp
// Assignment: HW2
// Purpose: this file contains the main function of the
//   program which will encrypt user message
//   then convert your message to secrete unreadable message


#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main(){
    char encryptOrDecrypt;
    string message;
    int shiftValue;
    string Encrypted;
    char repeat;
    do{
        cout << "Do you want to encrypt or decrypt a message? (e/d) "; //Inroder to gain user input if they want to encrypt ir decrypt

        cin >> encryptOrDecrypt;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //This will help remove all the newline space so when I get the entire line 
                                                            // it will not put out an error and take the newline as an input

        if (encryptOrDecrypt == 'e'){ //This checks whether the use wants ti encrypt the message 

            cout << "Enter the message to be encoded: ";
            getline(cin,message); //Inorder to gain the users message 

            cout << "Enter the shift value (1-40): ";
            cin >> shiftValue; //Gets the shift value for the encryptment or dycryptment

            for (int i=0; i < message.length(); i++){ //iterate thorught the message to get the letter

                if (isalpha(message[i])){ //uses this inorder to ignore the spaces within the users messages

                    if (isupper(message[i])){ //This helps to check whether the character is upper chase
                        
                        int position = (message[i] - 'A') + shiftValue; // This will get the number position of the upper case character and then move based on shift number 
                        while (position > 25){ //makes sure the number does not exceed the letter 'Z' for upper case
                            position -= 26;
                        }
                        while (position < 0){ //Makes sure the number does not exceed the letter "A" and instead loops backs to z for upper case
                            position += 26;
                        }

                        char letter = position + 'A'; // This will convert the number back into the letter

                        message[i] = toupper(letter); //And if so it keeps it upper case
                    }
                    else{
                        
                        int position = (message[i] - 'a') + shiftValue; // This will get the number position of the character and then move based on shift number 
                        while (position > 25){ //makes sure the number does not exceed the letter 'z' for lower cases
                            position -= 26;
                        }
                        while (position < 0){ //Makes sure the number does not exceed the letter "a" and instead loops backs to z for lower case
                            position += 26;
                        }
                        char letter = position + 'a'; // This will convert the number back into the letter
                        message[i] = letter; // it keeps it lower cases
                    }

                }
            }
        }
        else if (encryptOrDecrypt == 'd'){

            cout << "Enter the message to be decrypt: ";

            getline(cin,message);

            cout << "Enter the shift value (1-40): ";
            cin >> shiftValue;

            for (int i=0; i < message.length(); i++){ //iterate thought the message

                if (isalpha(message[i])){ //makes sure it is a letter 

                    if (isupper(message[i])){ //checkers whether it is upper case and keeps it the same if needed
                        
                        int position = (message[i] - 'A') - shiftValue; //converts the letter into a number and moves it according to the shift number


                        while (position > 25){ //makes sure the number does not exceed the letter 'Z' for upper cases
                            position -= 26;
                        }
                        while (position < 0){ //Makes sure the number does not exceed the letter "A" and instead loops backs to z for upper case
                            position += 26;
                        }
                        char letter = position + 'A';
                        message[i] = toupper(letter);
                    }
                    else{
                        int position = (message[i] - 'a') - shiftValue; //converts the letter into a number and moves it according to the shift number


                        while (position > 25){ //makes sure the number does not exceed the letter 'z' for lower cases
                            position -= 26;
                        }
                        while (position < 0){ //Makes sure the number does not exceed the letter "a" and instead loops backs to z for lower case
                            position += 26;
                        }
                        
                        char letter = position + 'a';
                        message[i] = letter;
                    }
                }
            }

        }
        cout << "Encrypted message: " << message<<endl;
        cout << "Would you like to continue the program? (y/n): ";
        cin >> repeat;

            
    } while(repeat == 'y');
    cout << "Thanks for using the Oscar Academy of Magic Caesar Cipher Program!\n \nKeep making magic!"<<endl;

}
