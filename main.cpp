//  Sedak Puri
//  main.cpp
//  Game Project 3
//  Compiler = XCode
//  Created by Sedak Puri on 7/12/18.
//  Copyright © 2018 Sedak Puri. All rights reserved.

#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int WORDLISTLENGTH = 13;
string vocabulary[WORDLISTLENGTH] = {"cat", "hat", "professor", "computers", "science", "harvard", "macintosh", "lunch", "exam", "developer", "failure", "depression", "anxiety"};
vector<char> lettersGuessed;
string chosenWord, restructuredWord;
int numGuesses, guessesUntilVictory;

//Prototype
void display(char g);
void startGame();

int main() {
    //Setup
    srand(static_cast<int>(time(nullptr)));
    chosenWord = vocabulary[rand() % WORDLISTLENGTH + 1];
    for(int i = 0; i < chosenWord.size(); i++){
        restructuredWord += '_';
    }
    
    //Taking in Guesses
    do{
        cout<<"Hello user! Welcome ot Hangman! Enter a the ammount of guesses you want! (1+)\n";\
        cin>>numGuesses;
    } while(numGuesses <= 0);
    guessesUntilVictory = numGuesses;      //Assuming worst case for initialization
    
    //Begin the game!
    startGame();
    return 0;
}

//Function to control the game!
void startGame(){
    //Gameloop
    while(true){
        string guess;
        //Breaking Case (Game Over)
        if (numGuesses == 0){
            cout<<"Sorry user, you are out of guesses! Game over! The word was: "<<chosenWord<<"\n";
            return;
        }
        cout<<"Enter a letter to guess!\n";
        cin>>guess;
        if(guess.length() > 1){
            cout<<"Invalid input! One Letter! Guess not counted!";
            continue;
        }
        
        //Case the letter has already been guessed
        bool guessedAlready = false;
        for(char c: lettersGuessed){
            if(c == guess[0]){
                guessedAlready = true;
            }
        }
        if (guessedAlready){
            continue;
        } else {
            display(guess[0]);
            lettersGuessed.push_back(guess[0]);
            numGuesses--;
        }
        
        //Display guesses and used letters w/ Option 2 implimented
        cout<<"Guesses Remaining: "<<numGuesses<<endl;
        cout<<"Used Letters: ";
        for(char c: lettersGuessed){
            cout<<c<<" ";
        }
        cout<<endl;
        
        //Breaking Case (Game Won) w/ Option 4 implimented
        if (restructuredWord == chosenWord){
            cout<<"Congratulations user! You won the game! The word was: "<<chosenWord<<endl<<"It only took you: "<<(guessesUntilVictory - numGuesses)<<" guesses! (not counting repeated letters guessed)"<<endl;
            return;
        }
    }
}

//Function to reformat the word and display it
void display(char g){
    string newWord = "";
    for(int i = 0; i < chosenWord.length(); i++){
        if(chosenWord[i] == g){
            newWord += g;
        } else if (restructuredWord[i] != '_'){
            newWord += restructuredWord[i];
        } else {
            newWord += '_';
        }
    }
    restructuredWord = newWord;
    cout<<"\n"<<restructuredWord<<endl;
}
