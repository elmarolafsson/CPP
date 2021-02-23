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
        Word *word;
        word = new Word;
        char filename[64] = "words.txt";
        word->get_word(filename);
        word->scramble(word->unscrambled, strlen(word->unscrambled));
        bool fail = true;
        while (fail){
            system("clear");
            cout << "For a hint input: ?" << endl;
            cout << "Points: " << score << endl;
            cout << "Word to guess: " << word->scrambled << endl;
            cout << word->dashed << endl;
            char userWord[64];
            cout << "Input your guess: ";
            cin >> userWord;
            if (userWord[0] == '?'){
                 word->compare(word->unscrambled, word->dashed);
                if (word->guess == true){
                    fail = false;
                }
                word->use_hint();
                score--;
            }
            else{
                word->compare(word->unscrambled, userWord);
                if (word->guess == true){
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
        delete word;
        counter ++;
    }
    cout << "Your total guessed words are: " << words << " And your score is: "<< score << endl; 
    return 0;
}