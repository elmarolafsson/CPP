#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include "rand_word.h"
#include <string.h>

using namespace std;

int main(){
    srand(time(NULL));
    int score = 10;
    int words = 0;
    int counter = 0;
    bool play = true;
    while (play){
        
        Word *B;
        B = new Word;
        char filename[64] = "words.txt";
        B->get_word(filename);
        B->scramble(B->unscrambled, strlen(B->unscrambled));
        bool fail = true;
        while (fail){
            system("clear");
            cout << "For a hint input: ?" << endl;
            cout << "Points: " << score << endl;
            cout << "Word to guess: " << B->scrambled << endl;
            cout << B->dashed << endl;
            char userWord[64];
            cout << "Input your guess: ";
            cin >> userWord;
            if (userWord[0] == '?'){
                 B->compare(B->unscrambled, B->dashed);
                if (B->guess == true){
                    fail = false;
                }
                B->use_hint();
                score--;
            }
            else{
                B->compare(B->unscrambled, userWord);
                if (B->guess == true){
                    cout << "YOU DID IT!" << endl;
                    fail = false;
                    words++;
                    score++;
                }
                else{
                    cout << "try again" << endl;
                    score--;
                    score--;
                }
                char ans;
                cout << "Continue? y/n ";
                cin >> ans;
                if (ans == 'n'){
                    play = false;
                    break;
                }
            }
            if (score == 0){
                cout << "You finished all your points!" << endl;  
                play = false;
                break;
            }
        }
        delete B;
        counter ++;
    }
    cout << "Your total guessed words are: " << words << " And your score is: "<< score << endl; 
    return 0;
}